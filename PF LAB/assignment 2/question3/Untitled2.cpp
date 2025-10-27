#include <stdio.h>

#define R 3
#define C 3

void modGrid(int arr[R][C]) {
    int r, c, flag, act;
    printf("Enter row and column: ");
    scanf("%d%d", &r, &c);
    printf("Enter bit (0=Power,1=Overload,2=Maintain): ");
    scanf("%d", &flag);
    printf("Enter 1 to set or 0 to clear: ");
    scanf("%d", &act);
    if (act == 1) arr[r][c] |= (1 << flag);
    else arr[r][c] &= ~(1 << flag);
}

void viewGrid(int arr[R][C]) {
    int r, c, val;
    printf("Enter row and column: ");
    scanf("%d%d", &r, &c);
    val = arr[r][c];
    printf("\nSector [%d,%d]\n", r, c);
    printf("Power: %s\n", (val & 1) ? "ON" : "OFF");
    printf("Overload: %s\n", (val & 2) ? "YES" : "NO");
    printf("Maintenance: %s\n", (val & 4) ? "YES" : "NO");
}

void diagGrid(int arr[R][C]) {
    int r, c, cnt = 0;
    for (r = 0; r < R; r++) {
        for (c = 0; c < C; c++) {
            if ((arr[r][c] & 2) || (arr[r][c] & 4)) cnt++;
        }
    }
    printf("Flagged Sectors: %d\n", cnt);
}

int main() {
    int arr[R][C] = {0};
    int ch;
    do {
        printf("\n1. Update Status\n2. Query Sector\n3. Run Diagnostic\n4. Exit\nChoose: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: modGrid(arr); break;
            case 2: viewGrid(arr); break;
            case 3: diagGrid(arr); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid Option\n");
        }
    } while (ch != 4);
    return 0;
}

