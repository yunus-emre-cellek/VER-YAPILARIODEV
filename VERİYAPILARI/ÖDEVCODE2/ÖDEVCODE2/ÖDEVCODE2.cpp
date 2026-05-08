#include <stdio.h>

int main() {
    int dizi[] = { 80, 60, 3, 9, 57, 11 };
    int i, j, temp;
    int n = 6;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (dizi[i] < dizi[j]) {
                temp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }
        }
    }

    printf("Yeni Siralama: ");

    for (i = 0; i < n / 2; i++) {
        printf("%d %d ", dizi[i], dizi[n - 1 - i]);
    }

    return 0;
}