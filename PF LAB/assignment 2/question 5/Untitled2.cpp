#include <stdio.h>
#include <string.h>

void flipBits(char *text) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        text[i] ^= (1 << 1);
        text[i] ^= (1 << 4);
    }
}

void revStr(char *text) {
    int i, j;
    char tmp;
    i = 0;
    j = strlen(text) - 1;
    while (i < j) {
        tmp = text[i];
        text[i] = text[j];
        text[j] = tmp;
        i++;
        j--;
    }
}

void makeCode(char msg[]) {
    revStr(msg);
    flipBits(msg);
    printf("Encoded: %s\n", msg);
}

void undoCode(char msg[]) {
    flipBits(msg);
    revStr(msg);
    printf("Decoded: %s\n", msg);
}

int main() {
    char txt[200];
    int opt;
    do {
        printf("\n1. Encode Message\n2. Decode Message\n3. Exit\nChoose: ");
        scanf("%d", &opt);
        getchar();
        switch (opt) {
            case 1:
                printf("Enter Message: ");
                fgets(txt, sizeof(txt), stdin);
                txt[strcspn(txt, "\n")] = '\0';
                makeCode(txt);
                break;
            case 2:
                printf("Enter Encoded Message: ");
                fgets(txt, sizeof(txt), stdin);
                txt[strcspn(txt, "\n")] = '\0';
                undoCode(txt);
                break;
            case 3:
                printf("Goodbye\n");
                break;
            default:
                printf("Invalid Option\n");
        }
    } while (opt != 3);
    return 0;
}

