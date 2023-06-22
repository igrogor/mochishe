#include <stdio.h>
int f1();

int f2();

int f3();

int main() {
    f1();

    switch (f1()) {
        case 0:
            f2();
            break;
        case 1:
            f3();
            break;
        default:
            return 1;
            break;
    }

    return 0;
}

int f1() {
    int n;
    char c;
    scanf("%d%c", &n, &c);
    if (c != '\n') {
        return 1;
    }
    return n;
}

int f2() {
    char str[10];

    for (int i = 0; str[i] != '\n'; i++) {
        scanf("%c", &str[i]);
    }
    for (int i = 1; str[i] != '\n'; i += 2) {
        if (str[i] != ' ') {
            printf("n/a");
            return 1;
        }
    }
    for (int i = 0; str[i - 5] != '\n'; i += 2) {
        printf("%x ", str[i]);
    }

    return 0;
}

int f3() { return 0; }
