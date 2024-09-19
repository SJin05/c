#include <stdio.h>
#define MAX_ITEM 5 

int item[MAX_ITEM] = {0};
int plus[MAX_ITEM] = {0};
int min[MAX_ITEM] = {0};
int total_item = 0;
int total_sold = 0;
double total_sold_rate = 0.0;
int max_sold = 0, min_sold = 0;
int max_id = 0, min_id = 0;
int menu_num;

void inputItem();
void outputItem();
void itemStatus();

int main() {
    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("원하는 메뉴를 선택하세요. (1. 입고 2. 판매 3. 상품현황 4. 종료)\n> ");
        scanf("%d", &menu_num);

        if (menu_num == 1) {
            inputItem();
        } else if (menu_num == 2) {
            outputItem();
        } else if (menu_num == 3) {
            itemStatus();
        } else if (menu_num == 4) {
            printf("프로그램을 종료합니다.\n");
            break;
        } else {
            printf("메뉴를 다시 선택해주세요.\n");
        }
    }
    return 0;
}

void inputItem() {
    int pickNumber;
    printf("입고수량 입력: 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택\n> ");
    scanf("%d", &pickNumber);

    if (pickNumber == 1) {
        printf("전체 상품의 입고수량을 입력하세요 (총 %d개의 상품):\n", MAX_ITEM);
        for (int i = 0; i < MAX_ITEM; i++) {
            scanf("%d", &plus[i]);
            item[i] += plus[i];
            total_item += plus[i];
        }
    } else if (pickNumber == 2) {
        int id, num;
        printf("상품ID (1~%d): ", MAX_ITEM);
        scanf("%d", &id);
        printf("입고수량: ");
        scanf("%d", &num);

        if (id > 0 && id <= MAX_ITEM) {
            item[id - 1] += num;
            total_item += num;
        } else {
            printf("잘못된 상품 ID입니다.\n");
        }
    } else {
        printf("잘못된 선택입니다.\n");
    }
}


void outputItem() {
    int pickNumber;
    printf("판매수량 입력: 전체 상품 판매수량 입력시 1, 개별 상품 입력시 2 선택\n> ");
    scanf("%d", &pickNumber);

    if (pickNumber == 1) {
        printf("전체 상품의 판매수량을 입력하세요 (총5개의 상품): \n");
        for (int i = 0; i < MAX_ITEM; i++) {
            scanf("%d", &min[i]);

            if (min[i] > item[i]) {
                printf("다시 입력해주세요\n");
            } else {
                item[i] -= min[i];
                total_sold += min[i];
            }
        }
    } else if (pickNumber == 2) {
        int id, num;
        printf("상품ID (1~%d): ", MAX_ITEM);
        scanf("%d", &id);
        printf("판매수량: ");
        scanf("%d", &num);

        if (id > 0 && id <= MAX_ITEM) {
            if (num > item[id - 1]) {
                printf("다시 입력해주세요\n");
            } else {
                item[id - 1] -= num;
                total_sold += num;
            }
        } else {
            printf("잘못된 상품 ID입니다.\n");
        }
    } else {
        printf("잘못된 선택입니다.\n");
    }

    max_sold = min[0];
    min_sold = min[0];
    max_id = min_id = 1;

    for (int i = 1; i < MAX_ITEM; i++) {
        if (min[i] > max_sold) {
            max_sold = min[i];
            max_id = i + 1;
        }

        if (min[i] < min_sold) {
            min_sold = min[i];
            min_id = i + 1;
        }
    }

    if (total_item > 0) {
        total_sold_rate = (double)total_sold / total_item * 100;
    }
}

void itemStatus() {
    printf("\n재고 수량: ");
    for (int i = 0; i < MAX_ITEM; i++) {
        printf("%d ", item[i]);
    }

    printf("\n총 판매량: %d (판매율 %.2f%%)", total_sold, total_sold_rate);
    printf("\n가장 많이 판매된 상품: ID %d, 판매량 %d", max_id, max_sold);
    printf("\n가장 적게 판매된 상품: ID %d, 판매량 %d", min_id, min_sold);

    for (int i = 0; i < MAX_ITEM; i++) {
        if (item[i] <= 2) {
            printf("\n상품 ID %d: 재고부족(%d)", i + 1, item[i]);
        }
    }
}
