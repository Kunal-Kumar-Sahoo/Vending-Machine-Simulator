#include<stdio.h>
#include<stdbool.h>

int inputMoney(){
    int deno; int money=0;
    while(true){
        printf("Enter the money:");
        scanf("%d", &deno);
        switch(deno){
            case 100:
            case 50:
            case 20:
            case 10:
            money += deno;
            break;
            default:
                printf("Invalid note\n");
                return money;
        }
    }
}

void chooseProduct(){
    printf("Choose the product\n");
    printf("1. Kurkure\n");
    printf("2. All Seasons\n");
    printf("3. Budweiser Magnum\n");
    printf("4. Smirnoff\n");
    printf("5. Bira Long Island Summer\n");
    int n; scanf("%d", &n);
    switch(n){
        case 1:
            printf("Go to 0");
            break;
        case 2:
            printf("Go to 1");
            break;
        case 3:
            printf("Go to 2");
            break;
        case 4:
            printf("Go to 3");
            break;
        case 5:
            printf("Go to 4");
            break;
        
    }
}

int main(){
    chooseProduct();
}