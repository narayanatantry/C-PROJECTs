



#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void main_screen()
void menu_card()
void account()
void billing()
struct MENU
{
    char item[15]; 
    
};
struct ACCOUNT
{
    char USN[10];
    int MONEY;
    
};
struct BILL
{
    int final amount;
    
};
void main()
{
    int MENUCARD;
    MENUCARD = sub.
    
   
}

void menu_card(char itemname[15])
{
    int i;
    struct MENU m[150];
    printf("enter the menu items \n");
    for(i=0;i<n;i++)
    {
        scanf("%s",&m[i].item);
    }
printf("            MENU\n\n");
printf("------------------------------ \n");
    for(i=0;i<n;i++)
    { 
        printf("%d. %s", i,m[i].item);


    }

}

void main_screen()
{
    int i,MSC, ACC;
    char items2[100]
    printf("                GLOBAL CANTEEN \n\n\n ");
    printf("1. BUY                  ");
    printf("2. ACOUNT \n");
    printf("ENTER 1 for BUY or 2 for updating the account:");
    scanf(" %d \n"&i);
    if(i==1)
    {
        MSC = sub.menu_card()
    }
    else
    {
      ACC = sub.account()
    }

}

void account(char USN[10], int MONEY)
{
    int t,i,n,num,money; 
    struct ACCOUNT a[10];
    char yes_no[10]
    printf("1.NEW USER\n");
    printf("2.EXISISTEN \n");
    printf("enter your choice 1 or 2");
    scanf("%d",&t);
    if(t==1 || t==2)
    {
        if(t==1)
        {
            printf("enter the USN\n");
            for(i=0;i<n;i++)
            {
                scanf("%s",&a[i].USN);
                
            }
            printf("ENTER THE AMOUNT TO DEPOSSITE\n\n ");
            scanf("%d",&money);

            printf("THE DETAILS ARE : \n ");
            for(i=0;i<n;i++)
            {
                printf("%s",a[i].USN);
            }
                printf("%d\n",money);
                printf("ERRORS YES/NO\n");
                scanf("%s"&yes_no);
                yes_no = toupper(yes_no); // converting  the yes or no to avoid confusion 

                if(yes_no=="Y" || yes_no=="YES" || yes_no=="YE")
                {
                    //?
                }
                else
                {
                    printf("PROCEED")
                }

        }
       else
        {    printf("ENTER USN\n");
    printf(" ____________\n");
    scanf("|%s|  ",&a[i].USN);
    printf("_____________\n");
    printf("THE BALANCE AMOUNT:  ",);

        }
    
    
    }
}
