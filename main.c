#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void edit2(void);
void menu(void);
void see(void);
void new_account(void);
void view(void);
void edit(void);
void erase(void);
void transact(void);
 struct client{
    int acc_num;
    char name[30];
    long national_id;
    long pass;
    int phone_num;
  char birth[20];
 char address[40];
 char citizenship_number[5];
    double money;
    char type[20];
  char date_of_deposit[100];

   };
struct client account;
int clear_input_buffer()
{
int ch;
while(((ch=getchar())!=EOF) && (ch != '\n'));
return ch;
}

int main(){
    menu();


    return 0;
}

void menu(void) {
    printf("WellCome to our bank\n1- for new account press (n)\n2-for see accounts press (s)\n3-for edit press (e)\n4-for erase press (r)\n5-for transact press (t)\n");
char c;

scanf(" %c",&c);
  if(c=='n')
   new_account();
   else if(c=='s')
    see();
    else if(c=='r')
        erase();
    else if(c=='e')
       edit();
       else if(c=='t')
        transact();
}

void new_account(){
    int a,tst2,tst3,tst4,tst1,m;
char c;

FILE *fptr;
    fptr=fopen("pr.txt","rb+");


   int i=0;

do{
    fseek(fptr,i*(sizeof(account)),SEEK_SET);
     a=fread(&account,sizeof(account),1,fptr);
if(account.acc_num==0)
    a=0;


     i++;

}while(a==1);
 account.acc_num=i;
printf("your account number is : %d\n",i);
   clear_input_buffer();


        printf("\nenter your name to the third\n");

  gets(account.name);

       do{
printf("\nenter your national id\n");
tst1=scanf("%ld",&account.national_id);

clear_input_buffer();
    }while(tst1==0);
  do{
 printf("\nenter your password maximum 8 digit\n");
          tst2=scanf("%ld",&account.pass);

clear_input_buffer();
    }while(tst2==0);


  do{
printf("\nenter your phone number\n");
    tst3=scanf("%d",&account.phone_num);

clear_input_buffer();
    }while(tst3==0);


    printf("\nenter your date of birth\n");
    scanf("%s",account.birth);
   printf("\nenter your address\n");
   scanf("%s",account.address);
   printf("\nenter your citizenship number\n");
   scanf("%s",account.citizenship_number);
     do{

         printf("\nenter the amount of deposit\n");
     tst4=scanf("%lf",&account.money);
clear_input_buffer();
    }while(tst4==0);

     printf("\nenter the type of deposit for current press (c) , for saving press (s) , for invesment press (i)\n");

    scanf("%c",&c);
    if(c=='s')
        strcpy(account.type,"saving");
    else if(c=='i')
        strcpy(account.type,"investment");
    else if(c=='c')
        strcpy(account.type,"current");
time_t now=time(&now);
  struct tm* dt=localtime(&now);

    strftime(account.date_of_deposit,sizeof(account.date_of_deposit),"%d/%m/%Y - %H:%M:%H",dt);
view();



char t;
printf("are you sure that is your information?(y or n)\n");
   scanf(" %c",&t);
if(t=='y'){

    fseek(fptr,(account.acc_num-1)* sizeof(account),SEEK_SET);
    fwrite(&account,sizeof(account),1,fptr);
    fclose(fptr);
    printf("___________________________________________________________________________\n");
menu();
}
else
    new_account();

}





void see(void){
    int x,a;
    char c;
    FILE *fptr;
    fptr=fopen("pr.txt","ab+");
     int i=0;
     printf("enter your account number\n");
     scanf("%d",&x);
     fseek(fptr,(x-1)*(sizeof(account)),SEEK_SET);
     a=fread(&account,sizeof(account),1,fptr);
if(x==0||a==0||account.acc_num==0){

       printf("the account is not exist! to back to menu press (m) , to Continue press(c)\n");
     scanf(" %c",&c);


                  if(c=='m'){
                     printf("___________________________________________________________________________\n");
menu();
                  }
else if(c=='c')
     see();
}
   else{




    printf("enter your password\n");
       long tst;
                 scanf("%ld",&tst);



     if(tst==account.pass)
view();




      else{

      printf("the password is wrong! to back to menu press (m) , to Continue press(c)\n");
     scanf(" %c",&c);


                  if(c=='m'){
                     printf("___________________________________________________________________________\n");
menu();
                  }
else if(c=='c')
     see();
      }


                     printf("___________________________________________________________________________\n");


menu();


   }

}


void view(void){
printf("\nyour account number is :%d\nyour name is : %s \nyour nationality id is : %ld \nyour password is : %ld\nyour phone number is :%d\nyour date of birth is : %s\nyour address is: %s\nyour citizenship number is : %s\nyour cash: %lf\nyour type of deposit is: %s\nthe date of deposit is :%s\n",account.acc_num,account.name,account.national_id,account.pass,account.phone_num,account.birth,account.address,account.citizenship_number,account.money,account.type,account.date_of_deposit);

}
void edit(void){
 int x,a;
char c;
    printf("enter the account number\n");
    scanf("%d",&x);
    FILE *fptr;
    fptr=fopen("pr.txt","rb+");
    fseek(fptr,(x-1)*(sizeof(account)),SEEK_SET);
     a=fread(&account,sizeof(account),1,fptr);

if(x==0||a==0||account.acc_num==0){

        printf("the account is not exist! to back to menu press (m) , to Continue press(c)\n");
     scanf(" %c",&c);


                  if(c=='m'){
                     printf("___________________________________________________________________________\n");
menu();
                  }
else if(c=='c')
     edit();
}
   else{
 printf("enter your password\n");
       long tst;
                 scanf("%ld",&tst);



     if(tst==account.pass){
  printf("\nenter your phone number\n");
    scanf("%d",&account.phone_num);
    printf("\nenter your address\n");
   scanf("%s",account.address);
    fseek(fptr,(x-1)*(sizeof(account)),SEEK_SET);


    fwrite(&account,sizeof(account),1,fptr);
    fclose(fptr);
    view();
                     printf("___________________________________________________________________________\n");
main();
     }
    else{
       printf("the password is wrong! to back to menu press (m) , to Continue press(c)\n");
     scanf(" %c",&c);


                  if(c=='m'){
                     printf("___________________________________________________________________________\n");
menu();
                  }
else if(c=='c')
     edit();
    }
menu();
}
}



void erase(void){
    int x,a;
    char c;

printf("enter the account number\n");
    scanf("%d",&x);
    FILE *fptr;
    fptr=fopen("pr.txt","rb+");
     int i=0;
 fseek(fptr,(x-1)*(sizeof(account)),SEEK_SET);
     a=fread(&account,sizeof(account),1,fptr);
if(x==0||a==0||account.acc_num==0){

       printf("the account is not exist! to back to menu press (m) , to Continue press(c)\n");
     scanf(" %c",&c);


                  if(c=='m'){
                     printf("___________________________________________________________________________\n");
menu();
                  }
else if(c=='c')
     erase();
}
   else{

    printf("enter your password\n");
       long tst;
                 scanf("%ld",&tst);



     if(tst==account.pass){
 struct client account={0," ",0,0,0," "," ","",0.0," ",""};

        fseek(fptr,(x-1)*(sizeof(account)),SEEK_SET);

    fwrite(&account,sizeof(account),1,fptr);
    fclose(fptr);
                         printf("___________________________________________________________________________\n");

    menu();
     }
    else{
        printf("the password is wrong! to back to menu press (m) , to Continue press(c)\n");
     scanf(" %c",&c);


                  if(c=='m'){
                     printf("___________________________________________________________________________\n");
menu();
                  }
else if(c=='c')
     erase();
    }

}
printf("___________________________________________________________________________\n");
menu();
                  }

void transact(void){
    int x,a;
char c;

    printf("enter the account number\n");
    scanf("%d",&x);
    FILE *fptr;
    fptr=fopen("pr.txt","rb+");
fseek(fptr,(x-1)*(sizeof(account)),SEEK_SET);
     a=fread(&account,sizeof(account),1,fptr);
 if(x==0||a==0||account.acc_num==0){

       printf("the account is not exist! to back to menu press (m) , to Continue press(c)\n");
     scanf(" %c",&c);


                  if(c=='m'){
                     printf("___________________________________________________________________________\n");
menu();
                  }
else if(c=='c')
     transact();
}
else{


    printf("enter your password\n");
       long tst;
                 scanf("%ld",&tst);



     if(tst==account.pass){

            char tst2;
    printf("1-to deposit press (d)\n2-for with draw press (w)\n");
    clear_input_buffer();
    scanf("%c",&tst2);
    if(tst2=='w'){
        double withdraw;
        printf("your current cash is :%lf \n",account.money);
        printf("enter the quantity to withdraw\n");


        scanf("%lf",&withdraw);
        if(withdraw<=account.money){
                        account.money=account.money-withdraw;


    time_t now=time(&now);
  struct tm* dt=localtime(&now);

    strftime(account.date_of_deposit,sizeof(account.date_of_deposit),"%d/%m/%Y - %H:%M:%H",dt);
        fseek(fptr,(x-1)*sizeof(account),SEEK_SET);

        fwrite(&account,sizeof(account),1,fptr);

        printf("your cash now is : %lf\n",account.money);
       fclose(fptr);
                            printf("___________________________________________________________________________\n");

        menu();
        }
     else{
        printf("you have not enough money! to back to menu press (m) , to Continue press(c)\n");
     scanf(" %c",&c);


                  if(c=='m'){
                     printf("___________________________________________________________________________\n");
menu();
                  }
else if(c=='c')
     transact();
     }

     }
     else if(tst2=='d'){
            double deposit;
                    printf("enter the quantity to deposit\n");

        scanf("%lf",&deposit);
        time_t now=time(&now);
  struct tm* dt=localtime(&now);
 account.money=account.money+deposit;
    strftime(account.date_of_deposit,sizeof(account.date_of_deposit),"%d/%m/%Y - %H:%M:%H",dt);
    fseek(fptr,(x-1)*sizeof(account),SEEK_SET);
                fwrite(&account,sizeof(account),1,fptr);

                printf("your cash now is : %lf\n",account.money);
       fclose(fptr);
                     printf("___________________________________________________________________________\n");

menu();
    }







     }
    else{
       printf("the password is wrong! to back to menu press (m) , to Continue press(c)2\n");
     scanf(" %c",&c);


                  if(c=='m'){
                     printf("___________________________________________________________________________\n");
menu();
                  }
else if(c=='c')
    transact();
    }

printf("___________________________________________________________________________\n");
menu();
                  }




fclose(fptr);

}
