#include <stdio.h>

int main() {
    int num;
    int store[100];  
    int sale[100];   
    int id;
    int total_sales = 0;
    int max_sales = 0;
    int max_sales_id = 0;
    int min_sales;
    int min_sales_id = 0;
    
    printf("상품 개수 입력 : ");
    if (scanf("%d", &num) != 1 || num <= 0 || num > 100) {
        printf("상품 개수는 1에서 100 사이여야 합니다.\n");
        return 1;
    }

    printf("상품 별 입고 수량 입력 : ");
    for (int i = 0; i < num; i++) {
        if (scanf("%d", &store[i]) != 1 || store[i] < 0) {
            printf("잘못된 입력입니다.\n");
            return 1;
        }
    }

    printf("상품 별 판매 수량 입력 : ");
    for (int i = 0; i < num; i++) {
        if (scanf("%d", &sale[i]) != 1 || sale[i] < 0) {
            printf("잘못된 입력입니다.\n");
            return 1;
        }

        total_sales += sale[i]; 

        if (sale[i] > max_sales) {
            max_sales = sale[i];
            max_sales_id = i + 1;
        }

        if (i == 0 || sale[i] < min_sales) {
            min_sales = sale[i];
            min_sales_id = i + 1;
        }
    }

    printf("id 입력 : ");
    if (scanf("%d", &id) != 1 || id < 1 || id > num) {
        printf("유효한 ID는 1에서 %d 사이여야 합니다.\n", num);
        return 1;
    }

    printf("ID %d의 남은 재고: %d\n", id, store[id - 1] - sale[id - 1]);

    printf("\n상품별 남은 재고 및 판매율:\n");
    for (int i = 0; i < num; i++) {
        int remaining_stock = store[i] - sale[i];
        float sales_rate = (store[i] != 0) ? ((float)sale[i] / store[i]) * 100 : 0;
        printf("상품 ID %d: 남은 재고 = %d, 판매율 = %.2f%%\n", i + 1, remaining_stock, sales_rate);
    }

    printf("\n총 판매량 : %d\n", total_sales);

    printf("가장 많이 판매된 상품 ID: %d, 판매량: %d\n", max_sales_id, max_sales);
    printf("가장 적게 판매된 상품 ID: %d, 판매량: %d\n", min_sales_id, min_sales);

    printf("\n재고 부족 상품:\n");
    for (int i = 0; i < num; i++) {
        int remaining_stock = store[i] - sale[i];
        if (remaining_stock <= 2) {
            printf("상품 ID %d : 재고 부족 (%d)\n", i + 1, remaining_stock);
        }
    }

    return 0;
}
