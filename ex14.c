#include <stdio.h>
#include <ctype.h>
#define MAX_LEN 100
void LineReadWrite(FILE *fin, FILE *fout)
{
    char buff[MAX_LEN];
    while (fgets(buff,MAX_LEN,fin) != NULL)
    {
        fputs(buff, fout);
        puts(buff);
    }
}
int main()
{
    FILE *fptr1, *fptr2;
    char filename1[] = "docfile.txt";
    char filename2[] = "ghifile.txt";
    if ((fptr1 = fopen(filename1, "r")) == NULL)
    {
        printf("Cannot open %s.\n", filename1);
    }
    else if ((fptr2 = fopen(filename2, "w")) == NULL)
    {
        printf("Cannot open %s.\n", filename2);
    }
    else
    {
        LineReadWrite(fptr1, fptr2);
        fclose(fptr1);
        fclose(fptr2);
    }
    return 0;
}