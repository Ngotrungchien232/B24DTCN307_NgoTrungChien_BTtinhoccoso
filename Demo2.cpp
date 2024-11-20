#include <stdio.h>
#include <string.h>

// C?u trúc luu tr? thông tin thí sinh
typedef struct {
    int ma;
    char ten[100];
    char ngaySinh[20];
    float diem1, diem2, diem3;
    float tongDiem;
} ThiSinh;

void nhapThiSinh(ThiSinh *ts, int ma) {
    ts->ma = ma;
    getchar(); // Ð?c ký t? '\n' tru?c khi nh?p tên
    fgets(ts->ten, 100, stdin);
    ts->ten[strcspn(ts->ten, "\n")] = '\0'; // Lo?i b? ký t? '\n' cu?i xâu
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
    
    // Nh?p thông tin thí sinh
    for (int i = 0; i < n; i++) {
        nhapThiSinh(&thiSinh[i], i + 1);
    }
    
    // Tìm di?m cao nh?t
    float maxDiem = 0;
    for (int i = 0; i < n; i++) {
        if (thiSinh[i].tongDiem > maxDiem) {
            maxDiem = thiSinh[i].tongDiem;
        }
    }
    
    // In ra các thí sinh có di?m cao nh?t
    for (int i = 0; i < n; i++) {
        if (thiSinh[i].tongDiem == maxDiem) {
            inThiSinh(thiSinh[i]);
        }
    }
    
    return 0;
}

