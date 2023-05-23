#include <stdio.h>

int main()
{
    int choose;
    printf("Please enter your choice: ");
    scanf("%d", &choose);
    do
    {
        printf("+=============MENU============+\n");
        printf("|1. TextToDat                 |\n");
        printf("|2. Display Dat file          |\n");
        printf("|3. Search and Update         |\n");
        printf("|4. Quit                      |\n");
        printf("+=============================+\n");

        if (choose < 1 || choose > 4)
        {
            printf("Invalid choice, please enter again \n");
        }
        if (choose == 1)
        {
        }
        if (choose == 2)
        {
        }
        if (choose == 3)
        {
        }
        if (choose == 4)
        {
            printf("Thank you for using: \n");
        }

    } while (choose != 4);
    return 0;
}