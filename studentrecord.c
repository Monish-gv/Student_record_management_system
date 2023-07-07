#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void menu();
void add();
void view();
void search();
void modify();
void deleterec();
struct student
{
    char name[20];
    char mobile[10];
    int rollno;
    char course[20];
    char branch[20];
};
int main()
{

    printf("<--:Student Record Management System:-->");

    menu();
    return 0;
}
void menu()
{
    int choice;

    printf("\n<--:MENU:-->");

    printf("\nEnter appropriate number to perform following task.");

    printf("\n1 : Add Record.");

    printf("\n2 : View Record.");
 
    printf("\n3 : Search Record.");

    printf("\n4 : Modify Record.");

    printf("\n5 : Delete.");

    printf("\n6 : Exit.");

    printf("\nEnter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        exit(1);
        break;

    default:

        printf("Invalid Choice.");
    }
}
void add()
{
    FILE *fp;
    struct student std;
   

    fp = fopen("record.txt","ab+");
    if(fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
   
        printf("<--:ADD RECORD:-->\n");
     
        printf("\nEnter details of student.");
     
        printf("\nEnter Name : ");

        scanf("%s",std.name);
        
        printf("\nEnter Mobile Number : ");
        scanf("%s",std.mobile);
       
        printf("\nEnter Roll No : ");
        scanf("%d",&std.rollno);
      
      
        printf("\nEnter Course : ");
        scanf(" %s",std.course);
      
        printf("\nEnter Branch : ");
        scanf("%s",std.branch);    
     
        fwrite(&std,sizeof(std),1,fp);
    
    fclose(fp);

    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct student std;
  
    printf("\n<--:VIEW RECORD:-->");
  
    printf("\nS.No   Name of Student       Mobile No   Roll No  Course      Branch");
   
    printf("--------------------------------------------------------------------\n");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
       
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        printf("%-7d%-22s%-12s%-9d%-12s%-12s",i,std.name,std.mobile,std.rollno,std.course,std.branch);
        i++;
        j++;
    }
    fclose(fp);
  
    menu();
}
void search()
{
    FILE *fp;
    struct student std;
    char stname[20];
  
    printf("\n<--:SEARCH RECORD:-->");
  
    printf("\nEnter name of student : ");
  
    scanf("%s",stname);
   
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1)
    {
        if(strcmp(stname,std.name) == 0)
        {
        
            printf("\nName : %s",std.name);
       
            printf("\nMobile Number : %s",std.mobile);
        
            printf("\nRoll No : %d",std.rollno);
        
            printf("\nCourse : %s",std.course);
        
            printf("\nBranch : %s",std.branch);
        }
        
    }
    if(strcmp(stname,std.name) != 0)
        printf("record does'nt exists");
    fclose(fp);
    menu();
}
void modify()
{
    char stname[20];
    FILE *fp;
    struct student std;
   
    printf("<--:MODIFY RECORD:-->");
  
    printf("\nEnter name of student to modify: ");
  
    scanf("%s",stname);
 
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name) == 0)
        {
           
            printf("\nEnter name: ");
            scanf("%s",std.name);
      
            printf("\nEnter mobile number : ");
            scanf("%s",std.mobile);
          
            printf("\nEnter roll no : ");
            scanf("%d",&std.rollno);
         
            printf("\nEnter Course : ");
            scanf("%s",std.course);
          
            printf("\nEnter Branch : ");
            scanf("%s",std.branch);
           
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
       
    }
    if(strcmp(stname,std.name) != 0)
        printf("record does not exists");
    fclose(fp);
 
    menu();
}
void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct student std;
  
    printf("\n<--:DELETE RECORD:-->");
  
    printf("\nEnter name of student to delete record : ");
  
    scanf("%s",stname);
   
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(stname,std.name)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
  
    menu();
}
