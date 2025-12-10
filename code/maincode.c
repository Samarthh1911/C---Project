#include <stdio.h>
#include <string.h>

struct Student {
    int sapId;
    int rollNumber;
    char studentName[50];
    float sgpa[8];
    float cgpa;
};

struct Student list[100];
int total = 0;

void add() {
    float sum = 0;

    printf("\nEnter SAP ID: ");
    scanf("%d", &list[total].sapId);

    printf("Enter Roll No: ");
    scanf("%d", &list[total].rollNumber);

    printf("Enter Name: ");
    scanf(" %[^\n]", list[total].studentName);

    printf("Enter SGPA of 8 semesters:\n");
    for (int i = 0; i < 8; i++) {
        printf("Sem %d: ", i + 1);
        scanf("%f", &list[total].sgpa[i]);
        sum += list[total].sgpa[i];
    }

    list[total].cgpa = sum / 8;
    total++;

    printf("\nStudent added successfully!\n");
}

void showOne(int i) {
    printf("\nSAP ID: %d\n", list[i].sapId);
    printf("Roll No: %d\n", list[i].rollNumber);
    printf("Name: %s\n", list[i].studentName);
    printf("CGPA: %.2f\n", list[i].cgpa);
}

void showAll() {
    if (total == 0) {
        printf("\nNo records available.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        showOne(i);
        printf("----------------------\n");
    }
}

void search() {
    int id;
    printf("\nEnter SAP ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < total; i++) {
        if (list[i].sapId == id) {
            showOne(i);
            return;
        }
    }

    printf("Student not found.\n");
}

void removeRecord() {
    int id;
    printf("\nEnter SAP ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < total; i++) {
        if (list[i].sapId == id) {

            for (int j = i; j < total - 1; j++) {
                list[j] = list[j + 1];
            }

            total--;
            printf("Record deleted successfully!\n");
            return;
        }
    }

    printf("Student not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== Student Record System =====\n");
        printf("1. Add Student\n");
        printf("2. Show All Records\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add(); break;
            case 2: showAll(); break;
            case 3: search(); break;
            case 4: removeRecord(); break;
            case 5: printf("\nExiting... Goodbye!\n"); break;
            default: printf("\nInvalid option! Try again.\n");
        }

    } while(choice != 5);

    return 0;
}

