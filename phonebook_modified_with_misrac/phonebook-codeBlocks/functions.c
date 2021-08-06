#include "functions.h"
void menu(void)
{
system("cls");
printf("\t\t WELCOME TO PHONEBOOK");
printf("\n\n\t\t\t MENU\t\t\n\n");
printf("\t1.Add Record \t2.List   \t3.Modify \n\t4.Search \t5.Delete \t\n\n");
printf("\nPlease Enter the Number you Want to Choose \n");
__int32_t x=0;
scanf("%d",&x);
#include "functions.h"
void menu(void)
{
system("cls");
printf("\t\t WELCOME TO PHONEBOOK");
printf("\n\n\t\t\t MENU\t\t\n\n");
printf("\t1.Add Record \t2.List   \t3.Modify \n\t4.Search \t5.Delete \t\n\n");
printf("\nPlease Enter the Number you Want to Choose \n");
__int32_t x=0;
scanf("%d",&x);

switch(x)
{
    case 1:{
        Add_Record();
        break;
    }

    case 2:{
        List_File(); //you will have to tab any key to see all records in file then tab any key to go back to main selection menu
        break;
    }

    case 3: {
        Modify_Record();
        break;
    }

    case 4: {
        Search_File();
        break;
    }

    case 5:{
        Delete_Record();
        break;
    }
    default:

    {
        system("cls");
        printf("\nEnter 1 to 5 only");
        printf("\n Enter any key");
        getch();
        menu();
    }
    break;
}
}

void Add_Record(void){
    FILE *files;
    phonebook x={0,};
    files=fopen("project.txt","ab+");
    printf("\n Enter your Name: ");
    scanf("%s",x.Name);
    printf("\nEnter your Email Address:");
    scanf("%s",x.Email);
    printf("\nEnter your Phone Number:");
    scanf("%ld",& x.PhoneNumber);
    fwrite(&x,(size_t)sizeof(x),(size_t)1,files);
    fprintf(files,"%s",x.Name);
    fflush(stdin);
    printf("\nNew Record Has Been Successfully Saved");
    fclose(files);
    printf("\n Enter any key");
    getch();
    menu();
}
void List_File(void)
{
    phonebook x={0};
    FILE *files;
    files=fopen("project.txt","rb");
    if(files==NULL)
    {
    printf("\n File opening error in listing :");
    exit(1);
    }
    while((__int32_t)fread(&x,(size_t)sizeof(x),(size_t)1,files)==1)
    {
        printf("\n\n\n YOUR RECORD INFORMATION IS\n\n ");
        printf("\n Name=%s \n E-mail=%s \n phone number=%ld",x.Name,x.Email,x.PhoneNumber);
    }
    fclose(files);
    printf("\n Enter any key");
    getch();
    menu();
}


void Search_File(void)
{
    phonebook x={0};
    FILE *files;
    char name[100]={0};
    __int32_t flag=0;
    files=fopen("project.txt","rb");
    if(files==NULL)
    {
    printf("\n error in opening \n");
    exit(1);
    }
    printf("\nEnter the Name of Person you want to Search\n");
    scanf("%s",name);
    while((__int32_t)fread(&x,(size_t)sizeof(x),(size_t)1,files)==1)
    {
        if(strcmp(x.Name,name)==0)
        {
            printf("\n Information About %s",name);
            printf("\n Name=%s \n E-mail=%s \n phone number=%ld",x.Name,x.Email,x.PhoneNumber);
            flag=1;
        }

    }
    if(flag!=1){
        printf("\n Record is not found");
    }

    fclose(files);
    printf("\n Enter any key");
    getch();
    menu();
}

void Delete_Record(void)
{
    phonebook x={0};
    FILE *files,*file_temp;
    __int32_t fl=0;
    char name[100]={0};
    files=fopen("project.txt","rb");
    if(files==NULL)
    {
        printf("CONTACT'S DATA NOT ADDED YET.");
    }

    else {

        file_temp=fopen("temp","wb+");
        if(file_temp==NULL) {
            printf("file opaning error");
        }
        else {
            printf("\n Enter CONTACT'S NAME:");
            scanf("%s",name);
            while((__int32_t)fread(&x,(size_t)sizeof(x),(size_t)1,files)==1) {
                if(strcmp(x.Name,name)!=0) {
                    fwrite(&x,(size_t)sizeof(x),(size_t)1,file_temp);
                }
                else if(strcmp(x.Name,name)==0) {
                    fl=1;
                }
                else{

                }
                }
            fclose(files);
            fclose(file_temp);
            if(fl!=1) {
                printf("NO CONACT'S RECORD TO DELETE.");
                remove("temp");
                }
            else {
                remove("project.txt");
                rename("temp","project.txt");
                printf("RECORD DELETED SUCCESSFULLY.");
                }
            }
    }
    printf("\n Enter any key");
    getch();
    menu();
}

void Modify_Record(void)
{
    FILE *files;
    __int8_t fl=0;
    phonebook x={0};
    phonebook y={0};
    char name[50]={0};
    files=fopen("project.txt","rb+");
    if(files==NULL)
    {
        printf("CONTACT'S DATA NOT ADDED YET.");
        exit(1);
    }
    else {

        printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
        scanf("%s",name);
        while((__int32_t)(fread(&x,(size_t)sizeof(x),(size_t)1,files))==1) {
            if(strcmp(name,x.Name)==0) {
                printf("\n Enter updated Name: ");
                scanf("%s",y.Name);
                printf("\nEnter updated Email Address:");
                scanf("%s",y.Email);
                printf("\nEnter updated Phone Number:");
                scanf("%ld",& y.PhoneNumber);
                fseek(files,(__int32_t)-sizeof(x),(__int32_t)SEEK_CUR);
                fwrite(&y,(size_t)sizeof(x),(size_t)1,files);
                fl=1;
                break;
                }
                fflush(stdin); }
        if(fl==1) {
            printf("\n your data id modified");
        }
        else {
            printf(" \n   Record is not found");
        }
        fclose(files);
        }
        printf("\n Enter any key");
        getch();
        menu();
}



switch(x)
{
    case 1:{
        Add_Record();
        break;
    }

    case 2:{
        List_File(); //you will have to tab any key to see all records in file then tab any key to go back to main selection menu
        break;
    }

    case 3: {
        Modify_Record();
        break;
    }

    case 4: {
        Search_File();
        break;
    }

    case 5:{
        Delete_Record();
        break;
    }
    default:

    {
        system("cls");
        printf("\nEnter 1 to 5 only");
        printf("\n Enter any key");
        getch();
        menu();
    }
    break;
}
}

void Add_Record(void){
    FILE *files;
    phonebook x={0,};
    files=fopen("project.txt","ab+");
    printf("\n Enter your Name: ");
    scanf("%s",x.Name);
    printf("\nEnter your Email Address:");
    scanf("%s",x.Email);
    printf("\nEnter your Phone Number:");
    scanf("%ld",& x.PhoneNumber);
    fwrite(&x,(size_t)sizeof(x),(size_t)1,files);
    fprintf(files,"%s",x.Name);
    fflush(stdin);
    printf("\nNew Record Has Been Successfully Saved");
    fclose(files);
    printf("\n Enter any key");
    getch();
    menu();
}
void List_File(void)
{
    phonebook x={0};
    FILE *files;
    files=fopen("project.txt","rb");
    if(files==NULL)
    {
    printf("\n File opening error in listing :");
    exit(1);
    }
    while((__int32_t)fread(&x,(size_t)sizeof(x),(size_t)1,files)==1)
    {
        printf("\n\n\n YOUR RECORD INFORMATION IS\n\n ");
        printf("\n Name=%s \n E-mail=%s \n phone number=%ld",x.Name,x.Email,x.PhoneNumber);
    }
    fclose(files);
    printf("\n Enter any key");
    getch();
    menu();
}


void Search_File(void)
{
    phonebook x={0};
    FILE *files;
    char name[100]={0};
    __int32_t flag=0;
    files=fopen("project.txt","rb");
    if(files==NULL)
    {
    printf("\n error in opening \n");
    exit(1);
    }
    printf("\nEnter the Name of Person you want to Search\n");
    scanf("%s",name);
    while((__int32_t)fread(&x,(size_t)sizeof(x),(size_t)1,files)==1)
    {
        if(strcmp(x.Name,name)==0)
        {
            printf("\n Information About %s",name);
            printf("\n Name=%s \n E-mail=%s \n phone number=%ld",x.Name,x.Email,x.PhoneNumber);
            flag=1;
        }

    }
    if(flag!=1){
        printf("\n Record is not found");
    }

    fclose(files);
    printf("\n Enter any key");
    getch();
    menu();
}

void Delete_Record(void)
{
    phonebook x={0};
    FILE *files,*file_temp;
    __int32_t fl=0;
    char name[100]={0};
    files=fopen("project.txt","rb");
    if(files==NULL)
    {
        printf("CONTACT'S DATA NOT ADDED YET.");
    }

    else {

        file_temp=fopen("temp","wb+");
        if(file_temp==NULL) {
            printf("file opaning error");
        }
        else {
            printf("\n Enter CONTACT'S NAME:");
            scanf("%s",name);
            while((__int32_t)fread(&x,(size_t)sizeof(x),(size_t)1,files)==1) {
                if(strcmp(x.Name,name)!=0) {
                    fwrite(&x,(size_t)sizeof(x),(size_t)1,file_temp);
                }
                else if(strcmp(x.Name,name)==0) {
                    fl=1;
                }
                else{

                }
                }
            fclose(files);
            fclose(file_temp);
            if(fl!=1) {
                printf("NO CONACT'S RECORD TO DELETE.");
                remove("temp");
                }
            else {
                remove("project.txt");
                rename("temp","project.txt");
                printf("RECORD DELETED SUCCESSFULLY.");
                }
            }
    }
    printf("\n Enter any key");
    getch();
    menu();
}

void Modify_Record(void)
{
    FILE *files;
    __int8_t fl=0;
    phonebook x={0};
    phonebook y={0};
    char name[50]={0};
    files=fopen("project.txt","rb+");
    if(files==NULL)
    {
        printf("CONTACT'S DATA NOT ADDED YET.");
        exit(1);
    }
    else {

        printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
        scanf("%s",name);
        while((__int32_t)(fread(&x,(size_t)sizeof(x),(size_t)1,files))==1) {
            if(strcmp(name,x.Name)==0) {
                printf("\n Enter updated Name: ");
                scanf("%s",y.Name);
                printf("\nEnter updated Email Address:");
                scanf("%s",y.Email);
                printf("\nEnter updated Phone Number:");
                scanf("%ld",& y.PhoneNumber);
                fseek(files,(size_t)-sizeof(x),SEEK_CUR);
                fwrite(&y,(size_t)sizeof(x),(size_t)1,files);
                fl=1;
                break;
                }
                fflush(stdin); }
        if(fl==1) {
            printf("\n your data id modified");
        }
        else {
            printf(" \n   Record is not found");
        }
        fclose(files);
        }
        printf("\n Enter any key");
        getch();
        menu();
}


