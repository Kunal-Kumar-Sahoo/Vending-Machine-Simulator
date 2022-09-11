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

typedef struct TrashStack {
    int top;
    Product trash[CAPACITY];
} TrashStack;

TrashStack bin = {-1, {}};

typedef struct CashStack {
    int top;
    int cash[5];
    /*
        Denomination    Corresponding index
        200             0
        100             1
        50              2
        20              3
        10              4
    */
} CashStack;

CashStack availableCash = {-1, {}};

typedef struct ProductStack {
    int top;
    char name[50];
    float MRP;
    Product p[CAPACITY];
} ProductStack;

ProductStack *initialize(char name[], float MRP) {
    ProductStack *s = (ProductStack *)malloc(sizeof(ProductStack));
    strcpy(s->name, name);
    s->MRP = MRP;
    s->top = -1;
    return s;
}

bool checkUnderflow(ProductStack *s) {
    return s->top == -1;
}

bool checkOverflow(ProductStack *s) {
    return s->top == CAPACITY-1;
}

void push_to_stock(ProductStack *s, Product p) {
    if(checkOverflow(s)) {
        printf("Product ProductStack is full. Please refill later\n");
        return;
    }
    s->p[++s->top] = p;
}

void clear_bin() {
    bin.top = -1;
}

void throwaway(Product p) {
    if(bin.top == CAPACITY-1)
        clear_bin();
    bin.trash[++bin.top] = p;
}

Product pop(ProductStack *s) {
    if(checkUnderflow(s)) {
        printf("Sorry product is not available\n");
        Product tmp = {-1, {-1, -1, -1}};
        return tmp;
    }
    Product p = s->p[s->top--];
    if(isExpired(p)) {
        printf("This product is expired. Fetching a new one\n");
        throwaway(pop(s));
    }
    return pop(s);
}

int main() {
    clear_bin();
    availableCash = {-1, {10, 10, 10, 10, 10}};

    printf("Enter number of products: ");
    int no_of_products; scanf("%d", &no_of_products);
    
    ProductStack arr[no_of_products];

    return 0;
}
