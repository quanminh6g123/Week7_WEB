#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int MAX_LEN = 100;
typedef struct grade
{
    long ID;
    char name[30];
    float midtermGrade;
    float finalGrade;
} grade;

int numOfGrades = 0;
void searchByID(grade *ptr)
{
    long i, ID, counter = 0;
    grade result;
    printf("Please enter student's ID: ");
    scanf("%d", &ID);
    for (i = 0; i < numOfGrades; i++)
    {
        if ((ptr + i)->ID == ID)
        {
            result = *(ptr + i);
        };
    };
    printf("Result:\nID: %ld\nName: %s\nmid-term: %.2f\nfinal: %.2f\n", result.ID, result.name, result.midtermGrade, result.finalGrade);
}

void writeFile(char fileName[MAX_LEN], grade *ptr, int n)
{
    FILE *file = fopen(fileName, "w+b");
    int i, code;
    for (i = 0; i < numOfGrades; i++)
    {
        code = fwrite(ptr + i, sizeof(int), n, file);
    };
    fclose(file);
};

void readFile(char fileName[MAX_LEN], grade *ptr, int n)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("no such file.");
        return;
    }
    grade result[10];
    fscanf(file, "%*s %*s %*s %*s ");
    while (fscanf(file, "%ld %s %f %f ", &(ptr + numOfGrades)->ID, &(ptr + numOfGrades)->name, &(ptr + numOfGrades)->midtermGrade, &(ptr + numOfGrades)->finalGrade) == 4)
    {
        numOfGrades++;
    };
    fclose(file);
};
void displayDatFile(char fileName[MAX_LEN], grade *ptr, int n)
{
    FILE *file = fopen(fileName, "r");
    int i, code;
    grade output[MAX_LEN];
    code = fread(output, sizeof(int), n, file);
    printf("*** Data File ***\n");
    for (i = 0; i < numOfGrades; i++)
    {
        printf("%ld %s %.1f %.1f\n", output[i].ID, output[i].name, output[i].midtermGrade, output[i].finalGrade);
    };
    fclose(file);
}

void searchByName(grade *ptr)
{
    int i, counter = 0;
    char name[30];
    grade result[MAX_LEN];
    printf("Please enter student's Name: ");
    scanf("%s", name);
    printf("Result: \n");
    for (i = 0; i < numOfGrades; i++)
    {
        if (strcmp(name, (ptr + i)->name) == 0)
        {
            result[counter] = *(ptr + i);
            printf("ID: %ld | Name: %s | mid-term: %.2f | final: %.2f\n", result[counter].ID, result[counter].name, result[counter].midtermGrade, result[counter].finalGrade);
            counter++;
        };
    };
}

void updateGrade(grade *ptr)
{
    long ID;
    int i, pos;
    float mid, fin;
    grade student;
    printf("Enter student's ID: ");
    scanf("%d", &ID);
    printf("Enter student's midterm grade: ");
    scanf("%f", &mid);
    printf("Enter student's final grade: ");
    scanf("%f", &fin);
    for (i = 0; i < numOfGrades; i++)
    {
        if ((ptr + i)->ID == ID)
        {
            pos = i;
        };
    };
    (ptr + i)->midtermGrade = mid;
    (ptr + i)->finalGrade = fin;
    printf("Change:\nID: %ld\nName: %s\nmid-term: %.2f\nfinal: %.2f\n", student.ID, student.name, student.midtermGrade, student.finalGrade);
}

void displayMenu(char ofileName[MAX_LEN], char ifileName[MAX_LEN], grade *p)
{
    int choice = 0, search;
    while (true)
    {
        printf("+=============MENU============+\n");
        printf("|1. TextToDat                 |\n");
        printf("|2. Display Dat file          |\n");
        printf("|3. Search and Update         |\n");
        printf("|4. Quit                      |\n");
        printf("+=============================+\n");
        printf("Your choice is: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            readFile(ofileName, p, MAX_LEN);
            writeFile(ifileName, p, MAX_LEN);
            printf("Transfered from %s to %s", ofileName, ifileName);
            break;
        case 2:
            displayDatFile(ifileName, p, MAX_LEN);
            break;
        case 3:
            printf("You want to search by ID (1) or by name (2): ");
            scanf("%d", &search);
            switch (search)
            {
            case 1:
                searchByID(p);
                break;
            case 2:
                searchByName(p);
                break;
            }
            break;
        case 4:
            updateGrade(p);
            writeFile(ifileName, p, MAX_LEN);
            break;
        case 5:
            printf("Bye");
            return;
        default:
            printf("Invalid choice");
            break;
        };
    }
}

int main()
{
    char outFile[100] = "transcript.txt", inFile[100] = "grade.dat";
    grade *p;
    p = (grade *)malloc(MAX_LEN * sizeof(grade));
    printf("Running");
    displayMenu(outFile, inFile, p);
}