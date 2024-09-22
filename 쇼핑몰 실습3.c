#include <stdio.h>

void stock_input(int* stock, int size);
void sell_input(int* stock, int* sold, int size);
void show_status(int* stock, int* sold, int size);

int main() {
    int stock[5] = { 0 };  // 상품의 재고 수량을 저장하는 배열 (초기값 0)
    int sold[5] = { 0 };   // 상품의 판매 수량을 저장하는 배열 (초기값 0)
    int choice;

    while (1) {
        printf("[쇼핑몰 관리 프로그램]\n");
        printf("원하는 메뉴를 선택하세요.\n");
        printf("1. 입고\n");
        printf("2. 판매\n");
        printf("3. 상품현황\n");
        printf("4. 종료\n");
        printf("> ");
        scanf_s("%d", &choice);

        if (choice == 1) {  // 입고
            stock_input(stock, 5);
        }
        else if (choice == 2) {  // 판매
            sell_input(stock, sold, 5);
        }
        else if (choice == 3) {  // 상품 현황 출력
            show_status(stock, sold, 5);
        }
        else if (choice == 4) {  // 종료
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 입력입니다. 다시 선택해주세요.\n");
        }
    }

    return 0;
}

void stock_input(int* stock, int size) {
    int choice, product_id, amount;
    printf("입고수량 입력: 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택: ");
    scanf_s("%d", &choice);

    if (choice == 1) {  // 전체 상품 입고
        printf("전체 상품의 입고수량을 입력하세요 (예: 10 12 9 4 9): ");
        for (int i = 0; i < size; i++) {
            scanf_s("%d", &amount);
            *(stock + i) += amount;
        }
    }
    else if (choice == 2) {  // 개별 상품 입고
        printf("상품ID를 입력하세요 (1-5): ");
        scanf_s("%d", &product_id);
        if (product_id >= 1 && product_id <= size) {
            printf("입고수량을 입력하세요: ");
            scanf_s("%d", &amount);
            *(stock + product_id - 1) += amount;
        }
        else {
            printf("잘못된 상품ID입니다.\n");
        }
    }
}

void sell_input(int* stock, int* sold, int size) {
    int choice, product_id, amount;
    printf("판매수량 입력: 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택: ");
    scanf_s("%d", &choice);

    if (choice == 1) {  // 전체 상품 판매
        printf("전체 상품의 판매수량을 입력하세요 (예: 10 12 9 4 9): ");
        for (int i = 0; i < size; i++) {
            scanf_s("%d", &amount);
            if (*(stock + i) >= amount) {
                *(stock + i) -= amount;
                *(sold + i) += amount;
            }
            else {
                printf("상품 %d의 재고가 부족합니다.\n", i + 1);
            }
        }
    }
    else if (choice == 2) {  // 개별 상품 판매
        printf("상품ID를 입력하세요 (1-5): ");
        scanf_s("%d", &product_id);
        if (product_id >= 1 && product_id <= size) {
            printf("판매수량을 입력하세요: ");
            scanf_s("%d", &amount);
            if (*(stock + product_id - 1) >= amount) {
                *(stock + product_id - 1) -= amount;
                *(sold + product_id - 1) += amount;
            }
            else {
                printf("상품 %d의 재고가 부족합니다.\n", product_id);
            }
        }
        else {
            printf("잘못된 상품ID입니다.\n");
        }
    }
}

void show_status(int* stock, int* sold, int size) {
    int total_sold = 0, total_stock = 0, most_sold = 0, least_sold = 0;
    int most_sold_id = 0, least_sold_id = 0;

    printf("상품 현황\n");

    for (int i = 0; i < size; i++) {
        printf("상품 %d: 재고 = %d, 판매수량 = %d\n", i + 1, *(stock + i), *(sold + i));
        total_sold += *(sold + i);
        total_stock += *(stock + i);

        if (i == 0 || *(sold + i) > most_sold) {
            most_sold = *(sold + i);
            most_sold_id = i + 1;
        }

        if (i == 0 || *(sold + i) < least_sold) {
            least_sold = *(sold + i);
            least_sold_id = i + 1;
        }

        if (*(stock + i) <= 2) {
            printf("상품 ID %d : 재고부족(%d)\n", i + 1, *(stock + i));
        }
    }

    double sales_rate = (double)total_sold / (total_sold + total_stock) * 100;

    printf("총 판매량: %d (판매율 %.2f%%)\n", total_sold, sales_rate);
    printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", most_sold_id, most_sold);
    printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", least_sold_id, least_sold);
}
