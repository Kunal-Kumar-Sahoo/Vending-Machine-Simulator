#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CAPACITY 10

typedef struct Date {
    short date, month, year;
} Date;

Date curr_date;

typedef struct Product {
    int id;
    Date expiry;
} Product;

typedef struct Stack {
    int top;
    char name[50];
    float MRP;
    Product p[10];
} Stack;

Stack *initialize(char name[], float MRP) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    strcpy(s->name, name);
    s->MRP = MRP;
    s->top = -1;
    return s;
}

bool checkUnderflow(Stack *s) {
    return s->top == -1;
}

bool checkOverflow(Stack *s) {
    return s->top == CAPACITY-1;
}

void push_to_stock(Stack *s, Product p) {
    if(checkOverflow(s)) {
        printf("Product stack is full. Please refill later\n");
        return;
    }
    s->p[++s->top] = p;
}

Product pop(Stack *s) {
    if(checkUnderflow(s)) {
        printf("Sorry product is not available\n");
        Product tmp = {-1, {-1, -1, -1}};
        return tmp;
    }
    Product p = s->p[s->top--];
    if(isExpired(p)) {
        printf("This product is expired. Fetching a new one\n");
        pop(s);
    }
    return p;
}

int main() {
    printf("Enter number of products: ");
    int no_of_products; scanf("%d", &no_of_products);
    
    Stack arr[no_of_products];

    return 0;
}
