#include <stdio.h>
#include <ctype.h>
#include <string.h>

void chuanHoaXau(char s[]) {
    int n = strlen(s);
    
    // Lo?i b? kho?ng tr?ng th?a ? d?u v� cu?i x�u
    int i = 0, j = n - 1;
    while (isspace(s[i])) i++;
    while (isspace(s[j])) j--;
    s[j + 1] = '\0';
    
    // Chu?n h�a c�c t? trong x�u
    int flag = 1; // ��nh d?u v? tr� d?u t? m?i
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
    
    // Lo?i b? kho?ng tr?ng th?a gi?a c�c t?
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
    getchar(); // �?c k� t? '\n' sau s? t
    for (int i = 0; i < t; i++) {
        char s[100];
        fgets(s, 100, stdin);
        s[strcspn(s, "\n")] = '\0'; // Lo?i b? k� t? '\n' cu?i x�u
        chuanHoaXau(s);
        printf("%s\n", s);
    }
    return 0;
}

