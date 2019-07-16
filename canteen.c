#include<stdio.h>
#include<string.h>

void print_token(char name[],int cost,int number);

struct item
{
	char item_name[40];
	int price;
	int avl;
};

struct accounts
{
	char USNid[11];
	int balance;
};

void main()
{
	struct item menu_items[100];
	struct accounts acc_list[100];
	int t=1,choice,ch2,ch3,ch4,dd,mm,yy,i,x,k,qty,daytotal,accs,money,flag;
	char sss[10],tUSN[11];

	printf("------------------------------------\n");
	printf("CANTEEN MANAGEMENT SYSTEM\n");
	printf("------------------------------------\n");
	printf("\nEnter the date:\n");
	printf("DD:");
	scanf("%d",&dd);
	printf("MM:");
	scanf("%d",&mm);
	printf("YY:");
	scanf("%d",&yy);
	printf("\nEnter today's menu:\n");
	daytotal=0;
	accs=0; //flaw
	i=0;

	do
	{
		printf("\nName of the item: ");
		//scanf("%s",sss);
		//gets(menu_items[i].item_name);
		scanf("%s",menu_items[i].item_name);
		printf("Price:");
		scanf("%d",&menu_items[i].price);
		menu_items[i].avl=1;
		wrong_entry:
		printf("\n\nWhat do you want to do?:\n1-Next item\n2-Exit menu entry and open for the day\nEnter choice:");
		scanf("%d",&choice);
		if(choice==1)
		{
			i++;
			continue;
		}
		else if(choice==2)
			t=0;
		else
		{
			printf("\nInvalid choice");
			goto wrong_entry;
		}
	}while(t==1);

	k=i;

	printf("\n------------------------------------\n");
	printf("CANTEEN IS NOW OPEN.\n");
	printf("------------------------------------\n");

	t=1;

	while(t==1)
	{
		printf("\nActions:\n1-Open billing\n2-Update menu\n3-Handle accounts\n4-Close the canteen for the day\n");
		printf("Enter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: printf("\nMenu:\n");
					for(i=0;i<=k;i++)
					{	
						if(menu_items[i].avl==1)
							printf("%d-%s : Rs. %d\n",i+1,menu_items[i].item_name,menu_items[i].price);
					}

					printf("Enter item and quantity:");
					for(;;)
					{
						scanf("%d%d",&ch2,&qty);
						if(ch2<=k+1&&ch2>0&&menu_items[ch2-1].avl==1)
							break;
						else
							printf("Item not present. Enter item and quantity again:");
					}

					printf("Select mode of payment:\n1-Cash\n2-Online banking\n3-Canteen Account\nEnter your choice:");
					payment:
					scanf("%d",&ch3);

					switch(ch3)
					{
						
						case 1: daytotal+=menu_items[ch2-1].price*qty;
								print_token(menu_items[ch2-1].item_name,menu_items[ch2-1].price,qty);
								break;

						case 2: daytotal+=menu_items[ch2-1].price*qty;
								print_token(menu_items[ch2-1].item_name,menu_items[ch2-1].price,qty);
								break;

						case 3: printf("Enter USN:");
								scanf("%s",tUSN);

								flag=0;

								for(i=0;i<accs;i++)
								{
									if(strcmp(tUSN,acc_list[i].USNid)==0)
									{
										flag=1;

										if(acc_list[i].balance>(menu_items[ch2-1].price*qty))
										{
											acc_list[i].balance-=menu_items[ch2-1].price*qty;
											daytotal+=menu_items[ch2-1].price*qty;
											print_token(menu_items[ch2-1].item_name,menu_items[ch2-1].price,qty);
										}

										else
										{
											printf("Amount is not enough.\n");
										}
									}
								}

								if(flag==0)
									printf("Account does not exist.\n");
								
								break;
						default:printf("\nInvalid choice. Enter again:");
								goto payment;
								break;
					}
					break;

			case 2: printf("\nOptions:\n1-Add item\n2-Change price\n3-Change availability\nEnter your choice:");
					enter_choice:
					scanf("%d",&ch2);
					
					switch(ch2)
					{
						case 1: k++;
								printf("\nName of the item: ");
								scanf("%s",menu_items[k].item_name);
								printf("Price:");
								scanf("%d",&menu_items[k].price);
								menu_items[k].avl=1;
								break;

						case 2: for(i=0;i<=k;i++)
								{	
									printf("%d-%s : Rs. %d\n",i+1,menu_items[i].item_name,menu_items[i].price);
								}

								printf("\nEnter item number:");
								select_item:
								scanf("%d",&ch3);

								if(!(ch3<=1+k&&ch3>0))
								{
									printf("Item not present. Enter again:");
									goto select_item;
								}

								printf("Enter new price:");
								scanf("%d",&money);

								menu_items[ch3-1].price=money;
								
								break;

						case 3: for(i=0;i<=k;i++)
								{	
									printf("%d-%s : Rs. %d\n",i+1,menu_items[i].item_name,menu_items[i].price);
								}

								printf("\nEnter item number:");
								select_item2:
								scanf("%d",&ch3);
								
								if(!(ch3<=k+1&&ch3>0))
								{
									printf("Item not present. Enter again:");
									goto select_item2;
								}

								printf("Select:\n1-Available\n2-Unavailable\nEnter your choice:");
								scanf("%d",&ch4);
								
								menu_items[ch3-1].avl=ch4;
								
								break;
						default:printf("Invalid choice. Please enter again:");
								goto enter_choice;
								break;
					}

					break;

			case 3: printf("\nOptions:\n1-Create\n2-Update\n3-Check balance\nEnter your choice:");
					rechoose_accs:
					scanf("%d",&ch2);

					switch(ch2)
					{
						case 1: printf("Enter USN:");
								scanf("%s",acc_list[accs].USNid);
								printf("Enter money deposited:");
								scanf("%d",&acc_list[accs].balance);
								accs++;
								break;

						case 2: printf("Enter USN:");
								scanf("%s",tUSN);
								
								flag=0;
								
								for(i=0;i<accs;i++)
								{
									if(strcmp(tUSN,acc_list[i].USNid)==0)
									{
										printf("Enter money deposited:");
										scanf("%d",&money);
										
										flag=1;
										
										acc_list[i].balance+=money;
										
										break;
									}
								}

								if(flag==0)
									printf("Account does not exist.\n");
								
								break;

						case 3: printf("Enter USN:");
								scanf("%s",tUSN);
								
								flag=0;
								
								for(i=0;i<accs;i++)
								{
									if(strcmp(tUSN,acc_list[i].USNid)==0)
									{
										printf("Balance:%d\n",acc_list[i].balance);
										
										flag=1;
										
										break;
									}
								}

								if(flag==0)
									printf("Account does not exist.\n");
								
								break;

						default:printf("Invalid choice. Please choose again:");
								goto rechoose_accs;
					}

					break;

			case 4: t=0;
					break;

			default:printf("\nInvalid choice.\n");
					break;
		}
	}
	
	printf("\n\nTotal amount for the day=%d",daytotal);
	printf("\n\n------------------------------------\n");
	printf("CANTEEN IS NOW CLOSED.\n");
	printf("------------------------------------\n");
}

void print_token(char name[],int cost,int number)
{
	printf("------------------------------------\n");
	printf("CANTEEN NAME\n\nItem\t\t-\tCost\n%s\t\t-\t%d\n",name,cost*number);
	printf("------------------------------------\n");
	return;
}
