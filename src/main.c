#include <stdio.h>
#include "header.h"

int main()
{
    int response;
    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Add Student details\n");
        printf("2. Show All student details\n");
        printf("3. Search Student by SAP ID\n");
        printf("4. Delete Student details\n");
        printf("5. Sort students by SAP ID\n");
        printf("6. Sort students by Name\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &response);

        switch (response)
        {
        case 1:
            add();
            break;
        case 2:
            showAll();
            break;
        case 3:
            search();
            break;
        case 4:
            removeRecord();
            break;
        case 5:
            sortBySAP();
            break;
        case 6:
            sortByName();
            break;
        case 7:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}
