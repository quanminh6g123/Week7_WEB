#include <stdio.h>
#include <ctype.h>
void CharReadWrite(FILE *fin, FILE *fout)
{
    int c;
    while ((c = fgetc(fin)) != EOF)
    {
        fputc(c, fout);
        putchar(c);
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
        CharReadWrite(fptr1, fptr2);
        fclose(fptr1);
        fclose(fptr2);
    }
    return 0;
}