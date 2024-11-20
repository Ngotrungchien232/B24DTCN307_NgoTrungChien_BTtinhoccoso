#include <stdio.h>
#include <ctype.h>
#include <string.h>

void chuanHoaXau(char s[]) {
    int n = strlen(s);
    
    // Lo?i b? kho?ng tr?ng th?a ? d?u và cu?i xâu
    int i = 0, j = n - 1;
    while (isspace(s[i])) i++;
    while (isspace(s[j])) j--;
    s[j + 1] = '\0';
    
    // Chu?n hóa các t? trong xâu
    int flag = 1; // Ðánh d?u v? trí d?u t? m?i
    for (int k = i; k <= j; k++) {
        if (isspace(s[k])) {
            flag = 1;
        } else {
            if (flag) {
                s[k] = toupper(s[k]);
                flag = 0;
            } else {
                s[k] = tolower(s[k]);
            }
        }
    }
    
    // Lo?i b? kho?ng tr?ng th?a gi?a các t?
    int index = 0;
    for (int k = i; k <= j; k++) {
        if (!isspace(s[k]) || (k > i && !isspace(s[k - 1]))) {
            s[index++] = s[k];
        }
    }
    s[index] = '\0';
}

int main() {
    int t;
    scanf("%d", &t);
    getchar(); // Ð?c ký t? '\n' sau s? t
    for (int i = 0; i < t; i++) {
        char s[100];
        fgets(s, 100, stdin);
        s[strcspn(s, "\n")] = '\0'; // Lo?i b? ký t? '\n' cu?i xâu
        chuanHoaXau(s);
        printf("%s\n", s);
    }
    return 0;
}

