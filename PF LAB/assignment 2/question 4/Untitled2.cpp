#include <stdio.h>
#define SZ 5

void addItem(int s[], int *t) {
    int v;
    if (*t == SZ - 1) {
        printf("Overflow\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &v);
    (*t)++;
    s[*t] = v;
    printf("Pushed %d\n", v);
}

void remItem(int s[], int *t) {
    if (*t == -1) {
        printf("Underflow\n");
        return;
    }
    printf("Popped %d\n", s[*t]);
    (*t)--;
}

void topItem(int s[], int t) {
    if (t == -1) {
        printf("Empty\n");
        return;
    }
    printf("Top: %d\n", s[t]);
}

void showAll(int s[], int t) {
    int i;
    if (t == -1) {
        printf("Empty\n");
        return;
    }
    printf("Stack: ");
    for (i = t; i >= 0; i--) printf("%d ", s[i]);
    printf("\n");
}

int main() {
    int s[SZ], t = -1, ch;
    do {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nChoose: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: addItem(s, &t); break;
            case 2: remItem(s, &t); break;
            case 3: topItem(s, t); break;
            case 4: showAll(s, t); break;
            case 5: printf("Bye\n"); break;
            default: printf("Invalid\n");
        }
    } while (ch != 5);
    return 0;
}

