#include <stdio.h>
#define MAX_ITEM 100

int main() {
    int item_num;
    int item[MAX_ITEM] = {0};
    int plus[MAX_ITEM] = {0};
    int min[MAX_ITEM] = {0};
    int num_id[MAX_ITEM];
    int id;

    printf("상품의 종류를 입력해주세요:");
    scanf("%d", &item_num);

    if (item_num < 1 || item_num > 100){
        printf("1에서 100 사이의 값을 입력해주세요:\n");
        return 1;
    }

    for (int i = 0; i < item_num; i++){
        num_id[i] = i + 1;
    }

    printf("\n상품들의 입고 수량을 입력해주세요:\n");
    for (int i = 0; i < item_num; i++) {
        scanf("%d", &plus[i]);
        item[i] = plus[i];
    }

    printf("\n상품들의 판매 수량을 입력해주세요:\n");
    for (int i = 0; i < item_num; i++){
        scanf("%d", &min[i]);

        if (min[i] > item[i]) {
            printf("판매 수량이 재고보다 많습니다. 다시 입력해주세요\n");
        } else {
            item[i] -= min[i];
        }
    }

    printf("\n확인할 상품의 ID를 입력하세요: ");
    scanf("%d", &id);

    if (id < 1 || id > item_num){
        printf("올바른 상품 ID를 입력해주세요.\n");
        return 1;
    }
    printf("상품 ID %d의 재고 수량: %d\n", id, item[id - 1]);

    printf("\n각 상품의 재고 수량: ");
        for (int i = 0; i < item_num; i++) {
            printf("%d ", item[i]);
    }

    return 0;

}