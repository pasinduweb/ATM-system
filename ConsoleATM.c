/*
 ***Mini ATM System using C programming***
 */
#include <stdio.h>

//global variable declaration
int menuAns, ans;
float deposit = 0, withdraw = 0;
float balance = 500000.00; //assume bank balance

//prototype
void fnMenu();
float fnCheckBalance(void);
float fnMoneyDeposit(void);
float fnMoneyWithdrawal(void);
float fnDisplayDepositSlip(void);
float fnDisplayWithdrawalSlip(void);
float Exit(void);
void fnInvalidMsg();

int main(void)
{
	//start of the program
	int pin;
	int c = 1;	//local variable

	printf("\n\t\t _ _ _ _ _ _ _ _ _ _ _ _\n");
	printf("\t\t|                        |\n");
	printf("\t\t| WELCOME TO COMBANK ATM |\n");
	printf("\t\t|_ _ _ _ _ _ _ _ _ _ _ _ |\n");

	while (c <= 3)	//loop to check pin number
	{
		printf("\n\n\tEnter Pin Number to Continue: ");	//Pin is: 1234
		scanf("%d", &pin);	//id can find asteric symbol when input
		system("cls");

		if (pin == 1234)
		{
			fnMenu();
		}
		else
		{
			printf("\t\nWrong Pin Number! Please try again with a correct pin.\n\n");
		}
		c++;
	}

	printf("#Time out! Close the system and try again!\n");	//if input time > 3 this will print

	//menu();	//calling to menu() func to main - starting the program

}

void fnMenu()
{
	printf("---------------------------------------------------\n");
	printf("\n\n\n\t    *WELCOME TO COMBANK ATM *\n");
	printf("\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
	printf("\t|\t\t\t\t  |\n");
	printf("\t|\tCheck Balance\t-> 1 \t  |\n");
	printf("\t|\tCash Deposit\t-> 2 \t  |\n");
	printf("\t|\tCash Withdrawl\t-> 3 \t  |\n");
	printf("\t|\tExit\t\t-> 4 \t  |\n");
	printf("\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n\n\n\n\n\n");
	printf("---------------------------------------------------\n");

	printf("Enter Service Number: ");
	scanf("%d", &menuAns);
	system("cls");
	switch (menuAns)
	{
		case 1:
			fnCheckBalance();
			break;

		case 2:
			fnMoneyDeposit();
			break;

		case 3:
			fnMoneyWithdrawal();
			break;

		case 4:
			Exit();
			break;

		default:
			fnInvalidMsg();
			break;
	}
}

float fnCheckBalance(void)
{
	printf("\n\n\t\tYour Account Balance: RS.%.2f\n\n", balance);
	printf("\n\nDo You Need Any Other Service\?\n");	//asking if the user need more services
	printf("\tYes -> 1\n \tNo -> 2\n");
	scanf("%d", &ans);
	system("cls");

	if (ans == 1)	//redirection to the menu
	{
		fnMenu();
	}
	else if (ans == 2)
	{
		Exit();
	}
}

float fnMoneyDeposit(void)
{
	printf("Enter The Amount To Be Deposit: RS.");	//asking to input the amount of deposition
	scanf("%f", &deposit);
	system("cls");

	printf("\n\n\t\tThe Amount You Deposited: RS.%.2f\n", deposit);	//showing the deposited amount
	balance = balance + deposit;
	printf("\t\tCurrently Available Balance In Your Account: RS.%.2f\n\n\n", balance);	//showing the updated balance

	printf("To get the Receipt enter 1: ");	//asking if the user need more services
	scanf("%d", &ans);
	system("cls");

	if (ans == 1)	//redirection to the menu
	{
		fnDisplayDepositSlip();
		printf("Please get your receipt.\n");
	}

	printf("Do You Need To Continue\n");
	printf("\tYes -> 1\n \tNo -> 2\n");
	scanf("%d", &ans);
	system("cls");

	if (ans == 1)
	{
		fnMenu();
	}
	else if (ans == 2)
	{
		Exit();
	}
}

float fnMoneyWithdrawal(void)
{
	printf("Enter The Amount Of Withdrawl: RS.");
	scanf("%f", &withdraw);
	system("cls");
	//if(balance < withdraw){
	//printf("error\n");
	//}

	//else{
	printf("The Amount You Withdrawed: RS.%.2f\n", withdraw);	//asking the amount of withdrawl
	balance = balance - withdraw;	//withdrawing process
	printf("Currently Available Balance In Your Account: RS.%.2f\n\n", balance);	//showing the updated balance

	printf("Do You Need a Receipt? \nThis will charge RS.5.00 from your account.\n");	//asking if the user need more services
	printf("\tYes -> 1\n \tNo -> 2\n");
	scanf("%d", &ans);
	system("cls");
	//}

	if (ans == 1)	//redirection to the menu
	{
		fnDisplayWithdrawalSlip();
		printf("Please get your receipt.\n");
	}
	else if (ans == 2)
	{
		Exit();
	}

	//system("cls");
	printf("Do You Need To Continue\n");	//asking if the user need more services
	printf("\tYes -> 1\n \tNo -> 2\n");
	scanf("%d", &ans);
	system("cls");

	if (ans == 1)	//redirection to the menu
	{
		fnMenu();
	}
	else if (ans == 2)
	{
		Exit();
	}
}

float Exit(void)
{
	int goto_menu = 1;
	printf("\n\n\t\tTHANK YOU FOR BANKING!!\n\n\n");

	printf("Press 1 to goto Main Menu: ");
	scanf("%d", &goto_menu);
	system("cls");
	if (goto_menu == 1)
	{
		fnMenu();
	}
}

float fnDisplayDepositSlip(void)
{
	printf("---------------------------------\n");
	printf("---------COMMERCIAL BANK---------\n");
	printf("---------------------------------\n\n");
	//printf("  TIME\t DATE\n");
	//printf("  10:30\t   30/03/2021\n");	//system time and data goes here(if needs)
	printf("BANK CODE : 23847\t\n");
	printf("BRANCH    : KURUNEGALA\t\n\n");
	printf("---------------------------------\n");
	printf("          CASH DEPOSITE          \n");
	printf("---------------------------------\n\n");
	printf("DEPOSITE AMOUNT:Rs.%.2f \n", deposit);	//deposite amount goes here
	printf("FEE            :Rs.5.00 \n\n");	//receipt fee goes here
	printf("ACTUAL BAL   :Rs.%.2f \n", balance);	//balances goes here
	printf("AVAILABLE BAL:Rs.%.2f \n", balance - 5);
	printf("---------------------------------\n\n");
	printf("      THANK YOU FOR BANKING      \n\n");
}

float fnDisplayWithdrawalSlip(void)
{
	printf("---------------------------------\n");
	printf("---------COMMERCIAL BANK---------\n");
	printf("---------------------------------\n\n");
	//printf("  TIME\t DATE\n");
	//printf("  10:30\t   30/03/2021\n");	//system time and data goes here(if need)
	printf("BANK CODE : 23847\t\n");
	printf("BRANCH    : KURUNEGALA\t\n\n");
	printf("---------------------------------\n");
	printf("         CASH WITHDRAWAL       \n");
	printf("---------------------------------\n\n");
	printf("WITHDRAWAL AMOUNT:Rs.%.2f \n", withdraw);	//withdrawal amount goes here
	printf("FEE              :Rs.5.00 \n\n");	//receipt fee goes here
	printf("ACTUAL BAL   :Rs.%.2f \n", balance);	//balances goes here
	printf("AVAILABLE BAL:Rs.%.2f \n", balance - 5);
	printf("---------------------------------\n\n");
	printf("      THANK YOU FOR BANKING      \n\n");
}

void fnInvalidMsg()
{
	int tryagain = 1;
	printf("Invalid Input! \nEnter 1 to Try from the beginning: ");
	scanf("%d", &tryagain);
	system("cls");
	if (tryagain == 1)
	{
		fnMenu();
	}
	else
	{
		printf("Again wrong input! \nClose the system and try again.\n");
	}
}
