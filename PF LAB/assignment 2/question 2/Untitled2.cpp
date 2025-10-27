#include <stdio.h>
#include <string.h>

void getClient(char n[], char c[]) {
    printf("Enter Customer Name: ");
    scanf(" %[^\n]", n);
    printf("Enter CNIC: ");
    scanf(" %[^\n]", c);
}

void showItems(int codes[], int qty[], float rate[], int total) {
    int i;
    printf("\nCode\tStock\tPrice\n");
    for (i = 0; i < total; i++)
        printf("%03d\t%d\t%.2f\n", codes[i], qty[i], rate[i]);
}

void addToBag(int codes[], int qty[], float rate[], int total, int bagCode[], int bagQty[], int *bagCount) {
    int code, q, i, found = 0;
    printf("Enter product code: ");
    scanf("%d", &code);
    for (i = 0; i < total; i++) {
        if (codes[i] == code) {
            found = 1;
            printf("Enter quantity: ");
            scanf("%d", &q);
            if (q > qty[i]) {
                printf("Not enough stock\n");
                return;
            }
            qty[i] -= q;
            bagCode[*bagCount] = code;
            bagQty[*bagCount] = q;
            (*bagCount)++;
            printf("Added to cart\n");
            break;
        }
    }
    if (!found) printf("Invalid code\n");
}

float calcBill(int codes[], float rate[], int bagCode[], int bagQty[], int bagCount) {
    float total = 0;
    int i, j;
    for (i = 0; i < bagCount; i++) {
        for (j = 0; j < 4; j++) {
            if (bagCode[i] == codes[j])
                total += rate[j] * bagQty[i];
        }
    }
    return total;
}

void showSlip(char n[], char c[], float t, float d) {
    printf("\n--- INVOICE ---\n");
    printf("Name: %s\nCNIC: %s\n", n, c);
    printf("Total Bill (No Discount): %.2f\n", t);
    printf("Total Bill (After Discount): %.2f\n", d);
}

int main() {
    int codes[4] = {1,2,3,4};
    int qty[4] = {50,10,20,8};
    float rate[4] = {100,200,300,150};
    int bagCode[100], bagQty[100], bagCount = 0;
    char n[50], c[20], promo[20];
    int opt;
    float t, d;
    do {
        printf("\n1. Customer Info\n2. Show Inventory\n3. Add Item\n4. Total Bill\n5. Invoice\n6. Exit\nEnter option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                getClient(n, c);
                break;
            case 2:
                showItems(codes, qty, rate, 4);
                break;
            case 3:
                addToBag(codes, qty, rate, 4, bagCode, bagQty, &bagCount);
                break;
            case 4:
                t = calcBill(codes, rate, bagCode, bagQty, bagCount);
                printf("Enter Promo Code: ");
                scanf(" %[^\n]", promo);
                if (strcmp(promo, "Eid2025") == 0)
                    d = t * 0.75;
                else
                    d = t;
                printf("Bill before discount: %.2f\n", t);
                printf("Bill after discount: %.2f\n", d);
                break;
            case 5:
                showSlip(n, c, t, d);
                break;
            case 6:
                printf("Goodbye\n");
                break;
            default:
                printf("Invalid Option\n");
        }
    } while (opt != 6);
    return 0;
}

