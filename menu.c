#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct product
{
    char name[10];
    char weight[10];
    char price[10];
} pros[1000];
int count = 0;
int ID;
int convert(char num[]);
int back = 3;
void mainmenu();
void showmenu1();
void showmenu0();
int ShowAll();
void Add();
void Revise();
void Delete();
void Buy();
void Service();
void Search();
void searchbycolor();
void searchbyname();
void searchbyweight();
void turnover();
void shoppingcar();
void account();
void deletes(char name[]);

int main()
{
    int n;
    char password[20];
    char *correctpassword = "123456";
backtomain:
    mainmenu(); // show main menu

    if (ID == 0)
    {
        printf("Please enter your password to gain access to product management:\n");
        scanf("%s", password);
        // enter password
        while (strcmp(password, correctpassword) != 0)
        {
            printf("Password entered incorrectly, please try again:\n");
            scanf("%s", password);
        }
        // Determine if the password is correct

    backtomenu0:
        showmenu0();
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            ShowAll();
            break;
        case 2:
            Add();
            break;
        case 3:
            Revise();
            break;
        case 4:
            Delete();
            break;
        case 5:
            turnover();
            break;
        case 6:
            exit(0);
        default:
            break;
        }
    } // Show supplier side menu
    else
    {
    backtomenu1:
        showmenu1();
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            ShowAll();
            break;
        case 2:
            Buy();
            break;
        case 3:
            Search();
            break;
        case 4:
            shoppingcar();
            break;
        case 5:
            account();
            break;
        case 6:
            exit(0);
            break;
        default:
            break;
        }
    } // Show consumer menu
    printf("\n\n\n");
    printf("Press 0 to return to the main menu, 1 to return to the supplier, and 2 to return to the consumer ");
    scanf("%d", &back);
    if (back == 0)
        goto backtomain;
    else if (back == 1)
        goto backtomenu0;
    else if (back == 2)
        goto backtomenu1;

    return 0;
}

void mainmenu()
{

    system("cls");
    printf("\n\n\n\n\n");
    printf("\t-------------------------------------\n");
    printf("\t ~~~~ Welcome to Foodie Goodie ~~~~ \n");
    printf("\t-------------------------------------\n");
    printf("\t|                                   |\n");
    printf("\t|                                   |\n");
    printf("\t| Please select your identity first |\n");
    printf("\t|                                   |\n");
    printf("\t|                                   |\n");
    printf("\t-------------------------------------\n");
    printf("   \n Please choose your id(0 for supplier, 1 for consumer):");
    scanf("%d", &ID);
} // show main menu

void showmenu1()
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t----------------------------------------------------\n");
    printf("\t ~~~~ Welcome to Foodie Goodie ~~~~ \n");
    printf("\t----------------------------------------------------\n");
    printf("\t|\t1- Display all product information         |\n");
    printf("\t|\t2- Direct purchase of goods                |\n");
    printf("\t|\t3- Query(search) product information       |\n");
    printf("\t|\t4- Add items to cart                       |\n");
    printf("\t|\t5- Checkout the items in the shopping cart |\n");
    printf("\t|\t6- Exit                                    |\n");
    printf("\t----------------------------------------------------\n");
    printf("\n      ENTER YOUR CHOICE(1-6):");
}
// show consumer menu

void showmenu0()
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t-------------------------------------------------\n");
    printf("\t ~~~~ Welcome to Foodie Goodie ~~~~ \n");
    printf("\t-------------------------------------------------\n");
    printf("\t|\t1- Display all product information      |\n");
    printf("\t|\t2- Add products                         |\n");
    printf("\t|\t3- Modify product information           |\n");
    printf("\t|\t4- Off the shelf product                |\n");
    printf("\t|\t5- View sold list and turnover          |\n");
    printf("\t|\t6- Exit                                 |\n");
    printf("\t-------------------------------------------------\n");
    printf("\n      ENTER YOUR CHOICE(1-6):");
}
// Show supplier menu
