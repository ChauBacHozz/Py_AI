#include <stdio.h>
#include <stdlib.h>
int main() {
    int n = 0;
    printf("Nhap so phan tu cua day so nguyen: ");
    scanf("%d", &n);
    int * ptr = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int number = 0;
        printf("Nhap vao so nguyen: ");
        scanf("%d", &number);
        * (ptr + i) = number;
        

    }
    printf("Day so nguyen la: ");
    for (int i = 0; i < n; i++) {
        printf("%d", * (ptr + i));
        printf("\t");
    }
    for (int i = 0; i < n-1; i++){
        for (int j = n-1; j > i; j--){
            if (* (ptr + i) > * (ptr + j)) {
                int temp;
                temp = * (ptr + i);
                * (ptr + i) = * (ptr + j);
                * (ptr + j) = temp;
            }
        }
    }
    printf("\nDay so nguyen sau khi sap xep la: ");
    for (int i = 0; i < n; i++) {
        printf("%d", * (ptr + i));
        printf("\t");
    }
    free(ptr);

    return 0;
    
}