#include <stdio.h>
#include <string.h>

struct Student {
    int sapId, rollNumber;
    char studentName[50];
    float sgpa[8];
    float cgpa;
};

struct Student list[100];
int total = 0;


void add()
{
    float sum = 0;
    printf("\nEnter SAP ID: ");
    scanf("%d", &list[total].sapId);
    printf("Enter Roll No: ");
    scanf("%d", &list[total].rollNumber);

    printf("Enter Name: ");
    scanf(" %[^\n]", list[total].studentName);

    printf("Enter SGPA of 8 semesters:\n");
    for (int i = 0; i < 8; i++)
    {
        printf("Sem %d: ", i + 1);
        scanf("%f", &list[total].sgpa[i]);
        sum += list[total].sgpa[i];
    }

    list[total].cgpa = sum / 8;
    total++;

    printf("Student added!\n");
}

void showOne(int i)
{
    printf("\nSAP: %d\n", list[i].sapId);
    printf("Roll: %d\n", list[i].rollNumber);
    printf("Name: %s\n", list[i].studentName);
    printf("CGPA: %.2f\n", list[i].cgpa);
}

void showAll()
{
    if (total == 0)
    {
        printf("No records yet.\n");
        return;
    }

    for (int i = 0; i < total; i++)
    {
        showOne(i);
        printf("------------------\n");
    }
}

void search()
{
    int id;
    printf("Enter SAP to search: ");
    scanf("%d", &id);

    for (int i = 0; i < total; i++)
    {
        if (list[i].sapId == id)
        {
            showOne(i);
            return;
        }
    }
    printf("Student not found.\n");
}

void removeRecord()
{
    int id;
    printf("Enter SAP to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < total; i++)
    {
        if (list[i].sapId == id)
        {
            for (int j = i; j < total - 1; j++)
                list[j] = list[j + 1];

            total--;
            printf("Record deleted.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void sortBySAP()
{
    for (int i = 0; i < total - 1; i++)
    {
        for (int j = 0; j < total - i - 1; j++)
        {
            if (list[j].sapId > list[j + 1].sapId)
            {
                struct Student temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    printf("Sorted by SAP!\n");
}

void sortByName()
{
    for (int i = 0; i < total - 1; i++)
    {
        for (int j = 0; j < total - i - 1; j++)
        {
            if (strcmp(list[j].studentName, list[j + 1].studentName) > 0)
            {
                struct Student temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    printf("Sorted by Name!\n");
}


int main()
{
    int choice;

    while (1)
    {
        printf("\n====== Student Record System ======\n");
        printf("1. Add Student\n");
        printf("2. Show All\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Sort by SAP\n");
        printf("6. Sort by Name\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: add(); break;
        case 2: showAll(); break;
        case 3: search(); break;
        case 4: removeRecord(); break;
        case 5: sortBySAP(); break;
        case 6: sortByName(); break;
        case 7: return 0;
        default: printf("Invalid choice!\n");
        }
    }
}
