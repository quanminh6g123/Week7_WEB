#include <stdio.h>
#define MAX_LEN 80

int main()
{
    int num;
    FILE *fptr;
    char filename[] = "test.txt";
    char buff[MAX_LEN + 1];
    if ((fptr = fopen(filename, "r")) == NULL)
        printf("Cannot open %s.\n", filename);
    else
    {
        num = fread(buff, sizeof(char), MAX_LEN, fptr);
        buff[num * sizeof(char)] = '\0';
        printf("%s", buff);
    }
}
