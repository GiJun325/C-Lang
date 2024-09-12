#include <stdio.h>

int main() {
    int num;
    int store[100];
    int sale[100];
    int id;

    printf("상품 개수 입력 : ");
    if (scanf("%d", &num) != 1) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }
    int list[num];

    if (num <= 0 || num > 100) {
        printf("상품 개수는 1에서 100 사이여야 합니다.\n");
        return 1;
    }

    printf("상품 별 입고 수량 입력 : ");
    for (int i = 0; i < num; i++) {
        if (scanf("%d", &store[i]) != 1) {
            printf("잘못된 입력입니다.\n");
            return 1;
        }
    }

    printf("상품 별 판매 수량 입력 : ");
    for (int i = 0; i < num; i++) {
        if (scanf("%d", &sale[i]) != 1) {
            printf("잘못된 입력입니다.\n");
            return 1;
        }
    }

    for (int i = 0; i < num; i++) {
        list[i] = store[i] - sale[i];
    }

    printf("id 입력 : ");
    if (scanf("%d", &id) != 1) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    if (id < 1 || id > num) {
        printf("유효한 ID는 1에서 %d 사이여야 합니다.\n", num);
        return 1;
    }

    printf("%d\n", list[id - 1]);
    for (int i = 0; i < sizeof(list) / sizeof(int); i++)
    {
        printf("%d ", list[i]);   
    }

    return 0;
}
