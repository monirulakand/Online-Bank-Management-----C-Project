#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
struct passw
{
    char pass[20];
};
struct passw P;

struct bank
{

    char name[100];
    char address[100];
    char citizenship[100];
    char phone[100];
    char acc_type[100];
    char date_of_b[100];
    char acc_no[100];
    int age;
    float amount;
}B,B1;


int main()
{
    system("cls");
    system("COLOR 17");
    printf("\n\n\t\t\t\t\t**********************************************");
    printf("\n\t\t\t\t\t ********************************************\n");
    printf("\t\t\t\t\t  ** WELCOME TO BANKING MANAGEMENT SYSTEM **");
    printf("\n\t\t\t\t\t ********************************************\n");
    printf("\t\t\t\t\t**********************************************\n");
    while(home()){}
    return 0;
}

int home()
{
 int choice;
 printf("\n\n\n\n\t\t============================================\n");
 printf("\n\t\t  * Press [1] To Go Admin Site");
 printf("\n\t\t  * Press [2] To Go Customer Site");
 printf("\n\t\t  * Press [0] To Exit");
 printf("\n\n\n\t\t  >> Choose A Option :");
 fflush(stdin);
 while(scanf("%d",&choice))
 {
     if(choice==1 || choice==2 || choice==0)
     {
         if(choice==1)
         {
             A_pass_c();
             break;
         }
         if(choice==2)
         {
            c_pass_c();
             break;
         }
         if(choice==0)
         {
             ext();
             break;
         }
     }
     printf("\n\t\t  **Invalid Input :");
     fflush(stdin);
 }
}


int ext()
{
    int c_ext;
    printf("\n\t\t  ** Press [1] to Cancel Exit");
    printf("\n\t\t  ** Press [2] to Confirm Exit");
    printf("\n\n\t\t  ** Choose a option :");
    fflush(stdin);
    while(scanf("%d",&c_ext))
    {
        if(c_ext==1 || c_ext==2)
        {
           if(c_ext==1)
           {
             main();
             break;
           }
           if(c_ext==2)
           {
             printf("\n\t\t  ***Thanks For Using***\n");
             printf("\n\t\t  ***Press Any Key To Exit Success***\n");
             exit(EXIT_SUCCESS);
             break;
           }

        }
        printf("\n\t\t  ** Invalid Input :");
        fflush(stdin);
    }

    return 0;
}


int c_pass_c()
{
    char pasword[10],usrname[10], ch;
    char chek[10]={'c','u','s','t','o','m','e','r'};

    int i,valid=0;
    fflush(stdin);
    printf("\n\t\t  Enter Customer Password : ");

    for(i=0;i<8;i++)
    {
     ch = getch();
     pasword[i] = ch;
     ch = '*' ;
     printf("%c",ch);
   }
   pasword[i] = 'ch';
   for(i=0;i<8;i++)
   {
     if(pasword[i]==chek[i])
     {
      valid=valid+1;
     }
   }
    if(valid==8)
    {
     C_home();
    }
    else
    {
      printf("\n\t\t  !!!Wrong Password Try Again!!!\n");
      c_pass_c();
    }

    return 0;
}

int C_home()
{
    system("cls");
    system("COLOR 57");
    printf("\n\t\t  [CUSTOMER HOME]");
    printf("\n\t\t  ** Press [1] To View Your Account Info");
    printf("\n\t\t  ** Press [0] To Exit Software");
    int c_go;
    printf("\n\n\t\t  >> Choose A Option :");
    fflush(stdin);
    while(scanf("%d",&c_go))
    {
        if(c_go==1 || c_go==0)
        {
         if(c_go==1)
         {
             c_search();
             break;
         }

         if(c_go==0)
         {
           ext();
           break;
         }
        }
     printf("\n\t\t  **Invalid Input :");
     fflush(stdin);
    }
    return 0;
}

int c_search()
{
    FILE *fp_tdt;
    int tdt=0;
    fp_tdt=fopen("Account info.txt","r");
    while(fread(&B, sizeof(B), 1, fp_tdt))
    {
     tdt=tdt+1;
    }
    c_search1(tdt);
    fclose(fp_tdt);
    return 0;
}

int c_search1(int tdt)
{
    FILE *c_srch;
    int lp_c=0;
    c_srch=fopen("Account info.txt","r");
    char A_C[50];
    fflush(stdin);
    printf("\n\t\t\t  >> Enter Account Number :");
    gets(A_C);
    while(fread(&B, sizeof(B), 1, c_srch))
    {
        if(strcmp(A_C,B.acc_no)==0)
        {
        printf("\a\a\a\a\a\n\t\t  **Account Number Matching**\n");
        printf("\n\t\t  Name: %s\n\t\t  Address: %s\n\t\t  Citizenship: %s\n\t\t  Phone Number: %s\n\t\t  Account Type: %s\n\t\t  Date Of Birth: %s\n\t\t  Account Number: %s\n\t\t  Age: %d\n\t\t  Amount: %.2f\n",B.name,B.address,B.citizenship,B.phone,B.acc_type,B.date_of_b,B.acc_no,B.age,B.amount);
        break;
        }
        lp_c=lp_c+1;
        if(lp_c==tdt)
        {
         printf("\a\a\a\a\a\n\t\t  ## Account Number Not Matching ##\n");
        }

    }
    fclose(c_srch);

    int n_src;
    fflush(stdin);
    printf("\n\t\t  * Press [1] To View Another Account Info");
    printf("\n\t\t  * Press [2] To Back Home Page");
    printf("\n\t\t  * Press [0] To Exit Software");
    printf("\n\n\t\t  >> Choose A Option :");
    while(scanf("%d",&n_src))
    {
      if(n_src==1 || n_src==2 || n_src==0)
      {
       if(n_src==1)
       {
          c_search();
          break;
       }
       if(n_src==2)
       {
          main();
          break;
       }
       if(n_src==0)
       {
          ext();
          break;
       }
      }
     printf("\n\t\t  ** Invalid Input :");
     fflush(stdin);
    }

    return 0;
}


int A_pass_c()
{
    char pasword[10],usrname[10], ch;
    char chek[10]={'a','d','m','i','n','1','2','3'};

    int i,valid=0;
    fflush(stdin);
    printf("\n\t\t  Enter Admin Password : ");

    for(i=0;i<8;i++)
    {
     ch = getch();
     pasword[i] = ch;
     ch = '*' ;
     printf("%c",ch);
   }
   pasword[i] = 'ch';
   for(i=0;i<8;i++)
   {
     if(pasword[i]==chek[i])
     {
      valid=valid+1;
     }
   }
    if(valid==8)
    {
     A_home();
    }
    else
    {
      printf("\n\t\t  !!!Wrong Password Try Again!!!\n");
      A_pass_c();
    }

    return 0;
}

int A_home()
{
    system("cls");
    system("COLOR 57");
    printf("\n\t\t  [ADMIN HOME]");
    printf("\n\t\t  =========================================");

    printf("\n\t\t  * Press [1] To Create A New Account");
    printf("\n\t\t  * Press [2] To View All Account Info");
    printf("\n\t\t  * Press [3] To View A Account Info");
    printf("\n\t\t  * Press [4] To Delete A Account Info");
    printf("\n\t\t  * Press [5] To Deposit A Account Balance");
    printf("\n\t\t  * Press [6] To Withdraw A Account Balance");
    printf("\n\t\t  * Press [0] To Exit Software");

    printf("\n\t\t  =========================================");
    int A_go;
    fflush(stdin);
    printf("\n\n\t\t\t  >> Choose A Option :");
    while(scanf("%d",&A_go))
    {
        if(A_go==1 || A_go==2 || A_go==3 || A_go==4 || A_go==5 || A_go==6 || A_go==0)
        {
          if(A_go==1)
          {
           n_account();
           break;
          }
          if(A_go==2)
          {
            show_all_account();
            break;
          }
          if(A_go==3)
          {
            c_search();
            break;
          }
          if(A_go==4)
          {
            delet();
            break;
          }
          if(A_go==5)
          {
            deposit_account();
            break;
          }
          if(A_go==6)
          {
            Withdraw_account();
            break;
          }
          if(A_go==0)
          {
            ext();
            break;
          }
        }
        printf("\n\t\t  **Invalid Input**");
        fflush(stdin);
    }
    return 0;
}

int n_account()
{
    int accc;

    char name1[100];
    char address1[100];
    char citizenship1[100];
    char phone1[100];
    char acc_type1[100];
    char date_of_b1[100];
    char acc_no1[100];
    int age1;
    float amount1;

    char flag[100]="Change1";

    FILE *fp;
    fp=fopen("Account info.txt","a");
    if(fp==NULL)
    {
        printf("Error");
        exit(1);
    }
    fflush(stdin);
    printf("\n\n\t\t  =========================================\n");
    printf("\n\t\t  Enter Name :");
    gets(B.name);
    printf("\t\t  Enter Address :");
    gets(B.address);
    printf("\t\t  Enter Citizenship :");
    gets(B.citizenship);
    printf("\t\t  Enter Phone Number :");
    gets(B.phone);
    printf("\t\t  Enter Account Type :");
    gets(B.acc_type);
    printf("\t\t  Enter Date Of Birth :");
    gets(B.date_of_b);
    printf("\t\t  Enter Account Number :");
    gets(B.acc_no);
    printf("\t\t  Enter Age :");
    scanf("%d",&B.age);
    printf("\t\t  Enter Amount :");
    scanf("%f",&B.amount);


    strcpy(name1,B.name);
    strcpy(address1,B.address);
    strcpy(citizenship1,B.citizenship);
    strcpy(phone1,B.phone);
    strcpy(acc_type1,B.acc_type);
    strcpy(date_of_b1,B.date_of_b);
    strcpy(acc_no1,B.acc_no);
    age1=B.age;
    amount1=B.amount;

    strcpy(B.acc_no,flag);

    accc=A_Matcing(acc_no1);

    strcpy(B.name,name1);
    strcpy(B.address,address1);
    strcpy(B.citizenship,citizenship1);
    strcpy(B.phone,phone1);
    strcpy(B.acc_type,acc_type1);
    strcpy(B.date_of_b,date_of_b1);
    strcpy(B.acc_no,acc_no1);
    B.age=age1;
    B.amount=amount1;

    fwrite(&B, sizeof(B), 1, fp);
    printf("\n\t\t\t *******************************");
    printf("\n\t\t\t ** Account Create Successful **\n");
    printf("\t\t\t *******************************\n");
    fclose(fp);

    int nw_ac;
    fflush(stdin);
    printf("\n\t\t===============================================");
    printf("\n\n\t\t  * Press [1] To Create Another Account");
    printf("\n\t\t  * Press [2] To Back Home Page");
    printf("\n\t\t  * Press [0] To Exit");
    printf("\n\n\t\t===============================================");
    printf("\n\n\t\t\t  >> Choose A Option :");
    while(scanf("%d",&nw_ac))
    {
      if(nw_ac==1 || nw_ac==2 || nw_ac==0)
      {
        if(nw_ac==1)
        {
            n_account();
            break;
        }
        if(nw_ac==2)
        {
            A_home();
            break;
        }
        if(nw_ac==0)
        {
            ext();
            break;
        }
      }
      printf("\n\t\t  **Invalid Input :");
      fflush(stdin);
    }

    return 0;
}


int A_Matcing(char acc_n[100])
{
    int back;

    FILE *ac_m;
    ac_m=fopen("Account info.txt","r");
    while(fread(&B, sizeof(B), 1, ac_m))
    {
        if(strcmp(acc_n,B.acc_no)==0)
        {
            printf("\n\t\t  [This Account Number Already Used]\n\t\t  [Try With Another Account Number]\n");
            n_account();
            break;
        }
    }

    fclose(ac_m);
    return back;
}

int show_all_account()
{
    FILE *fp1;
    fp1=fopen("Account info.txt","r");
    while(fread(&B, sizeof(B), 1, fp1))
    {
        printf("\n\t\t  Name: %s\n\t\t  Address: %s\n\t\t  Citizenship: %s\n\t\t  Phone Number: %s\n\t\t  Account Type: %s\n\t\t  Date Of Birth: %s\n\t\t  Account Number: %s\n\t\t  Age: %d\n\t\t  Amount: %.2f\n",B.name,B.address,B.citizenship,B.phone,B.acc_type,B.date_of_b,B.acc_no,B.age,B.amount);
    }
    fclose(fp1);

    int b_h;
    fflush(stdin);
    printf("\n\t\t  * Press [1] To Back Home");
    printf("\n\t\t  * Press [0] To Exit");
    printf("\n\n\t\t  >> Choose A Option :");
    while(scanf("%d",&b_h))
    {
        if(b_h==1 || b_h==0)
        {
           if(b_h==1)
           {
             A_home();
             break;
           }
           if(b_h==0)
           {
               ext();
               break;
           }
        }
        printf("\n\t\t  **Invalid Input :");
        fflush(stdin);
    }

   return 0;
}


int delet()
{
    FILE *fpdlt,*fpdlt1;
    struct bank B,B1;
    int found=0;
    char acn[100];
    fpdlt=fopen("Account info.txt","r");
    fpdlt1=fopen("Delete info.txt","w");
    fflush(stdin);
    printf("\n\t\t  Enter The Account Number You Want To Delete:");
    gets(acn);
    while(1)
    {
        fread(&B1, sizeof(B1), 1, fpdlt);
        if(feof(fpdlt))
        {
            break;
        }
        if(strcmp(acn,B1.acc_no)==0)
        {
            found=1;
        }
        else
        {
            fwrite(&B1, sizeof(B1), 1, fpdlt1);
        }
    }
        fclose(fpdlt);
        fclose(fpdlt1);
        if(found==0)
        {
            printf("\n\t\t  [Sorry Account Not Found]\n\n");
        }
        else
        {
            fpdlt=fopen("Account info.txt","w");
            fpdlt1=fopen("Delete info.txt","r");
            while(1)
            {
                fread(&B1, sizeof(B1), 1, fpdlt1);
                if(feof(fpdlt1))
                {
                    break;
                }
                fwrite(&B1, sizeof(B1), 1, fpdlt);
            }
           printf("\n\t\t  [!Account Delete Successful!]\n\n");
        }
    fclose(fpdlt);
    fclose(fpdlt1);

    int n_acdlt;
    fflush(stdin);
    printf("\n\t\t  * Press [1] To Delete Another Account Info");
    printf("\n\t\t  * Press [2] To Back Home Page");
    printf("\n\t\t  * Press [0] To Exit");
    printf("\n\n\t\t  >> Choose A Option :");
    while(scanf("%d",&n_acdlt))
    {
        if(n_acdlt==1 || n_acdlt==2 || n_acdlt==0)
        {
           if(n_acdlt==1)
           {
             delet();
             break;
           }
           if(n_acdlt==2)
           {
               A_home();
               break;
           }
           if(n_acdlt==0)
           {
               ext();
               break;
           }
        }
        printf("\n\t\t  **Invalid Input :");
        fflush(stdin);
    }

    return 0;
}


int deposit_account()
{
    FILE *fpd_acc,*fpd_acc1;
    struct bank B,B1;
    int found=0;
    char dacn[100];
    float deposit;
    fpd_acc=fopen("Account info.txt","r");
    fpd_acc1=fopen("Deposit.txt","w");
    fflush(stdin);
    printf("\n\t\t  Enter The Account Number You Want To Deposit Balance:");
    gets(dacn);
    printf("\n\t\t  Enter How Many Balance You Want To Deposit:");
    scanf("%f",&deposit);
    while(1)
    {
        fread(&B1, sizeof(B1), 1, fpd_acc);
        if(feof(fpd_acc))
        {
            break;
        }
        if(strcmp(dacn,B1.acc_no)==0)
        {
            found=1;
            B1.amount=B1.amount+deposit;
            fwrite(&B1, sizeof(B1), 1, fpd_acc1);
        }
        else
        {
            fwrite(&B1, sizeof(B1), 1, fpd_acc1);
        }
    }
        fclose(fpd_acc);
        fclose(fpd_acc1);
        if(found==0)
        {
            printf("\n\t\t  [Sorry Account Not Found]\n\n");
        }
        else
        {
            fpd_acc=fopen("Account info.txt","w");
            fpd_acc1=fopen("Deposit.txt","r");
            while(1)
            {
                fread(&B1, sizeof(B1), 1, fpd_acc1);
                if(feof(fpd_acc1))
                {
                    break;
                }
                fwrite(&B1, sizeof(B1), 1, fpd_acc);
            }
           printf("\n\t\t  [!Account Deposit Successful!]\n\n");
        }
    fclose(fpd_acc);
    fclose(fpd_acc1);

    int n_acdlt;
    fflush(stdin);
    printf("\n\t\t  * Press [1] To Deposit Another Account Balance");
    printf("\n\t\t  * Press [2] To back Home Page");
    printf("\n\t\t  * Press [0] To Exit");
    printf("\n\n\t\t  >> Choose A Option :");
    while(scanf("%d",&n_acdlt))
    {
        if(n_acdlt==1 || n_acdlt==2 || n_acdlt==0)
        {
           if(n_acdlt==1)
           {
             deposit_account();
             break;
           }
           if(n_acdlt==2)
           {
               A_home();
               break;
           }
           if(n_acdlt==0)
           {
               ext();
               break;
           }
        }
        printf("\n\t\t  **Invalid Input :");
        fflush(stdin);
    }

    return 0;
}


int Withdraw_account()
{
    FILE *fpd_acc2,*fpd_acc3;
    struct bank B,B1;
    int found=0;
    int flag=0;
    char dacn[100];
    float deposit;
    fpd_acc2=fopen("Account info.txt","r");
    fpd_acc3=fopen("Withdraw.txt","w");
    fflush(stdin);
    printf("\n\t\t  Enter The Account Number You Want To Withdraw Balance:");
    gets(dacn);
    printf("\n\t\t  Enter How Many Balance You Want To Withdraw:");
    scanf("%f",&deposit);
    while(1)
    {
        fread(&B1, sizeof(B1), 1, fpd_acc2);
        if(feof(fpd_acc2))
        {
            break;
        }
        if(strcmp(dacn,B1.acc_no)==0)
        {
            found=1;
            if(deposit>B1.amount)
            {
                flag=1;
                printf("\n\t\t  [There Is No Balance]\n");
                fwrite(&B1, sizeof(B1), 1, fpd_acc3);
            }
            else
            {
            B1.amount=B1.amount-deposit;
            fwrite(&B1, sizeof(B1), 1, fpd_acc3);
            }

        }
        else
        {
            fwrite(&B1, sizeof(B1), 1, fpd_acc3);
        }
    }
        fclose(fpd_acc2);
        fclose(fpd_acc3);
        if(found==0)
        {
            printf("\n\t\t  [Sorry Account Not Found]\n\n");
        }
        else
        {
            fpd_acc2=fopen("Account info.txt","w");
            fpd_acc3=fopen("Withdraw.txt","r");
            while(1)
            {
                fread(&B1, sizeof(B1), 1, fpd_acc3);
                if(feof(fpd_acc3))
                {
                    break;
                }
                fwrite(&B1, sizeof(B1), 1, fpd_acc2);
            }
            if(flag==1)
            {
             printf("\n\t\t  [!Account Withdraw Not Successful!]\n\n");
            }
            else
            {
             printf("\n\t\t  [!Account Withdraw Successful!]\n\n");
            }

        }
    fclose(fpd_acc2);
    fclose(fpd_acc3);

    int n_acdlt;
    fflush(stdin);
    printf("\n\t\t  * Press [1] To Withdraw Another Account Balance");
    printf("\n\t\t  * Press [2] To Back Home Page");
    printf("\n\t\t  * Press [0] To Exit");
    printf("\n\n\t\t  >> Choose A Option :");
    while(scanf("%d",&n_acdlt))
    {
        if(n_acdlt==1 || n_acdlt==2 || n_acdlt==0)
        {
           if(n_acdlt==1)
           {
             Withdraw_account();
             break;
           }
           if(n_acdlt==2)
           {
               A_home();
               break;
           }
           if(n_acdlt==0)
           {
               ext();
               break;
           }
        }
        printf("\n\t\t  **Invalid Input :");
        fflush(stdin);
    }

    return 0;
}






