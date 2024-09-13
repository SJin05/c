#include <stdio.h>
#define MAX_ITEM 100

int main() {
    int item_num;
    int item[MAX_ITEM] = {0};
    int plus[MAX_ITEM] = {0};
    int min[MAX_ITEM] = {0};
    int num_id[MAX_ITEM];
    int total_item = 0;
    int total_sold = 0;
    double total_sold_rate = 0.0;
    int max_sold, min_sold = 0;
    int max_id, min_id = 0;
    


    printf("상품의 개수를 입력해주세요: ");
    scanf("%d", &item_num);

    if (item_num < 1 || item_num > 100){
        printf("1에서 100 사이의 값을 입력해주세요.\n");
        return 1;
    }
    //상품의 개수에 따라 상품 ID 설정
    for (int i = 0; i < item_num; i++){ 
        num_id[i] = i + 1;
    }


    printf("\n상품 별 입고수량을 입력해주세요:\n");
    for (int i = 0; i < item_num; i++) {
        scanf("%d", &plus[i]);
        item[i] = plus[i];
        total_item += plus[i];
    }


    printf("\n상품들의 판매 수량을 입력해주세요:\n");
    for (int i = 0; i < item_num; i++){
        scanf("%d", &min[i]);

        if (min[i] > item[i]) {
            printf("판매 수량이 재고보다 많습니다. 다시 입력해주세요\n");
        } else {
            item[i] -= min[i];
            total_sold += min[i];
        }
    } 


    max_sold = min[0];
    min_sold = min[0];
    max_id = min_id = num_id[0];

    for (int i = 1; i < item_num; i++) {

        if (min[i] > max_sold) {
        max_sold = min[i];
        max_id = num_id[i];
        }

        if (min[i] < min_sold) {
        min_sold = min[i];
        min_id = num_id[i];
        }
    }

    if (total_item > 0) {
        total_sold_rate = (double)total_sold / total_item * 100;
    }


    printf("\n재고 수량: ");
        for (int i = 0; i < item_num; i++) {
            printf("%d ", item[i]);
    }


    printf("\n총 판매량: %d (판매율 %.2f%%)", total_sold, total_sold_rate);


    printf("\n가장 많이 판매된 상품: ID %d, 판매량 %d", max_id, max_sold);
    printf("\n가장 적게 판매된 상품: ID %d, 판매량 %d", min_id, min_sold);


    for (int i = 0; i < item_num; i++) {
        if (item[i] <= 2) {
            printf("\n상품 ID %d: 재고부족(%d)", num_id[i], item[i]);
        }
    }
    return 0;
}
