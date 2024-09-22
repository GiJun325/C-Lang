#include <stdio.h>

void stock_input(int* stock, int size);
void sell_input(int* stock, int* sold, int size);
void show_status(int* stock, int* sold, int size);

int main() {
    int stock[5] = { 0 };  // ��ǰ�� ��� ������ �����ϴ� �迭 (�ʱⰪ 0)
    int sold[5] = { 0 };   // ��ǰ�� �Ǹ� ������ �����ϴ� �迭 (�ʱⰪ 0)
    int choice;

    while (1) {
        printf("[���θ� ���� ���α׷�]\n");
        printf("���ϴ� �޴��� �����ϼ���.\n");
        printf("1. �԰�\n");
        printf("2. �Ǹ�\n");
        printf("3. ��ǰ��Ȳ\n");
        printf("4. ����\n");
        printf("> ");
        scanf_s("%d", &choice);

        if (choice == 1) {  // �԰�
            stock_input(stock, 5);
        }
        else if (choice == 2) {  // �Ǹ�
            sell_input(stock, sold, 5);
        }
        else if (choice == 3) {  // ��ǰ ��Ȳ ���
            show_status(stock, sold, 5);
        }
        else if (choice == 4) {  // ����
            printf("���α׷��� �����մϴ�.\n");
            break;
        }
        else {
            printf("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.\n");
        }
    }

    return 0;
}

void stock_input(int* stock, int size) {
    int choice, product_id, amount;
    printf("�԰���� �Է�: ��ü ��ǰ �԰���� �Է� 1, ���� ��ǰ �Է� 2�� ����: ");
    scanf_s("%d", &choice);

    if (choice == 1) {  // ��ü ��ǰ �԰�
        printf("��ü ��ǰ�� �԰������ �Է��ϼ��� (��: 10 12 9 4 9): ");
        for (int i = 0; i < size; i++) {
            scanf_s("%d", &amount);
            *(stock + i) += amount;
        }
    }
    else if (choice == 2) {  // ���� ��ǰ �԰�
        printf("��ǰID�� �Է��ϼ��� (1-5): ");
        scanf_s("%d", &product_id);
        if (product_id >= 1 && product_id <= size) {
            printf("�԰������ �Է��ϼ���: ");
            scanf_s("%d", &amount);
            *(stock + product_id - 1) += amount;
        }
        else {
            printf("�߸��� ��ǰID�Դϴ�.\n");
        }
    }
}

void sell_input(int* stock, int* sold, int size) {
    int choice, product_id, amount;
    printf("�Ǹż��� �Է�: ��ü ��ǰ �Ǹż��� �Է� 1, ���� ��ǰ �Է� 2�� ����: ");
    scanf_s("%d", &choice);

    if (choice == 1) {  // ��ü ��ǰ �Ǹ�
        printf("��ü ��ǰ�� �Ǹż����� �Է��ϼ��� (��: 10 12 9 4 9): ");
        for (int i = 0; i < size; i++) {
            scanf_s("%d", &amount);
            if (*(stock + i) >= amount) {
                *(stock + i) -= amount;
                *(sold + i) += amount;
            }
            else {
                printf("��ǰ %d�� ��� �����մϴ�.\n", i + 1);
            }
        }
    }
    else if (choice == 2) {  // ���� ��ǰ �Ǹ�
        printf("��ǰID�� �Է��ϼ��� (1-5): ");
        scanf_s("%d", &product_id);
        if (product_id >= 1 && product_id <= size) {
            printf("�Ǹż����� �Է��ϼ���: ");
            scanf_s("%d", &amount);
            if (*(stock + product_id - 1) >= amount) {
                *(stock + product_id - 1) -= amount;
                *(sold + product_id - 1) += amount;
            }
            else {
                printf("��ǰ %d�� ��� �����մϴ�.\n", product_id);
            }
        }
        else {
            printf("�߸��� ��ǰID�Դϴ�.\n");
        }
    }
}

void show_status(int* stock, int* sold, int size) {
    int total_sold = 0, total_stock = 0, most_sold = 0, least_sold = 0;
    int most_sold_id = 0, least_sold_id = 0;

    printf("��ǰ ��Ȳ\n");

    for (int i = 0; i < size; i++) {
        printf("��ǰ %d: ��� = %d, �Ǹż��� = %d\n", i + 1, *(stock + i), *(sold + i));
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
            printf("��ǰ ID %d : ������(%d)\n", i + 1, *(stock + i));
        }
    }

    double sales_rate = (double)total_sold / (total_sold + total_stock) * 100;

    printf("�� �Ǹŷ�: %d (�Ǹ��� %.2f%%)\n", total_sold, sales_rate);
    printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", most_sold_id, most_sold);
    printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", least_sold_id, least_sold);
}
