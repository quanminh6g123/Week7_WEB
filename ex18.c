#include <stdio.h>
#define MAX_ELEMENT 100
typedef struct phoneaddress_t
{
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;
int main()
{
    FILE *fp;
    phoneaddress contact[MAX_ELEMENT];
    int i, n, irc;
    printf("How many contacts do you want to enter (<100)? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("*****Please enter the information of contact %d******\n", i + 1);
        printf("Please enter the name of the contact %d: ",i+1);
        scanf("%s", contact[i].name);
        printf("Please enter the telephone of the contact %d: ",i+1);
        scanf("%s", contact[i].tel);
        printf("Please enter the email of the contact %d: ",i+1);
        scanf("%s", contact[i].email);
    }
    if ((fp = fopen("phonebook.dat", "w+b")) == NULL)
    {
        printf("Cannot open %s.\n", "phonebook.dat");
        return -1;
    }
    irc = fwrite(contact, sizeof(phoneaddress), n, fp);
    printf("fwrite return code = %d\n", irc);
    fclose(fp);
    if((fp=fopen("phonebook.dat","r+b"))==NULL)
    {
        printf("Cannot open %s.\n","phonebook.dat");
        return -1;
    }
    phoneaddress contactR[MAX_ELEMENT];
    irc = fread(contactR,sizeof(phoneaddress),n,fp);
    printf(" fread return code = %d\n",irc);
    printf("****Data of %d contacts in the file****\n",n);
    for (i=0;i<n;i++)
    {
        printf("Name: %s   ; Tel: %s   ; Email: %s\n",contactR[i].name,contactR[i].tel,contactR[i].email);
    }
    fclose(fp);
}