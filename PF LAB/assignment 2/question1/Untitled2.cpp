#include <stdio.h>
#include <string.h>

void insertItem(int codes[], char names[][50], float costs[], int stock[], int *total) {
    int code, i;
    char name[50];
    float cost;
    int qty;
    printf("Enter Code: ");
    scanf("%d", &code);
    for (i = 0; i < *total; i++) {
        if (codes[i] == code) {
            printf("Duplicate Code\n");
            return;
        }
    }
    printf("Enter Name: ");
    scanf(" %[^\n]", name);
    printf("Enter Cost: ");
    scanf("%f", &cost);
    printf("Enter Quantity: ");
    scanf("%d", &qty);
    codes[*total] = code;
    strcpy(names[*total], name);
    costs[*total] = cost;
    stock[*total] = qty;
    (*total)++;
}

void sellItem(int codes[], int stock[], int total) {
    int code, sold, i, found = 0;
    printf("Enter Code: ");
    scanf("%d", &code);
    for (i = 0; i < total; i++) {
        if (codes[i] == code) {
            found = 1;
            printf("Enter Quantity Sold: ");
            scanf("%d", &sold);
            if (sold > stock[i]) printf("Not enough stock\n");
            else {
                stock[i] -= sold;
                printf("Sale Done. Remaining: %d\n", stock[i]);
            }
            break;
        }
    }
    if (!found) printf("Item not found\n");
}

void stockAlert(int codes[], char names[][50], float costs[], int stock[], int total) {
    int i, flag = 0;
    printf("Low Stock Items (<5):\n");
    for (i = 0; i < total; i++) {
        if (stock[i] < 5) {
            printf("Code: %d | Name: %s | Cost: %.2f | Quantity: %d\n", codes[i], names[i], costs[i], stock[i]);
            flag = 1;
        }
    }
    if (!flag) printf("No low-stock items.\n");
}

int main() {
    int codes[100], stock[100], total = 0;
    char names[100][50];
    float costs[100];
    int opt;
    do {
        printf("\n1. Insert Item\n2. Sell Item\n3. Low Stock Alert\n4. Exit\nEnter Option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1: insertItem(codes, names, costs, stock, &total); break;
            case 2: sellItem(codes, stock, total); break;
            case 3: stockAlert(codes, names, costs, stock, total); break;
            case 4: printf("Goodbye\n"); break;
            default: printf("Invalid Option\n");
        }
    } while (opt != 4);
    return 0;
}

