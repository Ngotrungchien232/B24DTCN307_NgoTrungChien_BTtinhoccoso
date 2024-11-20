#include <stdio.h>
#include <string.h>

// C?u tr�c luu tr? th�ng tin th� sinh
typedef struct {
    int ma;
    char ten[100];
    char ngaySinh[20];
    float diem1, diem2, diem3;
    float tongDiem;
} ThiSinh;

void nhapThiSinh(ThiSinh *ts, int ma) {
    ts->ma = ma;
    getchar(); // �?c k� t? '\n' tru?c khi nh?p t�n
    fgets(ts->ten, 100, stdin);
    ts->ten[strcspn(ts->ten, "\n")] = '\0'; // Lo?i b? k� t? '\n' cu?i x�u
    fgets(ts->ngaySinh, 20, stdin);
    ts->ngaySinh[strcspn(ts->ngaySinh, "\n")] = '\0';
    scanf("%f %f %f", &(ts->diem1), &(ts->diem2), &(ts->diem3));
    ts->tongDiem = ts->diem1 + ts->diem2 + ts->diem3;
}

void inThiSinh(ThiSinh ts) {
    printf("%d %s %s %.1f\n", ts.ma, ts.ten, ts.ngaySinh, ts.tongDiem);
}

int main() {
    int n;
    scanf("%d", &n);
    ThiSinh thiSinh[n];
    
    // Nh?p th�ng tin th� sinh
    for (int i = 0; i < n; i++) {
        nhapThiSinh(&thiSinh[i], i + 1);
    }
    
    // T�m di?m cao nh?t
    float maxDiem = 0;
    for (int i = 0; i < n; i++) {
        if (thiSinh[i].tongDiem > maxDiem) {
            maxDiem = thiSinh[i].tongDiem;
        }
    }
    
    // In ra c�c th� sinh c� di?m cao nh?t
    for (int i = 0; i < n; i++) {
        if (thiSinh[i].tongDiem == maxDiem) {
            inThiSinh(thiSinh[i]);
        }
    }
    
    return 0;
}

