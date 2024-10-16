#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
int main(){

    int number[SIZE];
    int total = 0;
    int max,min;
    float avg = 0.0;
    srand(time(NULL));

    for(int i=0; i<SIZE; i++){
        number[i] = (rand() % 100) +1;
    }

    for(int i=0; i<SIZE; i++){
        printf("%3d\t", number[i]); //3자리 포멧으로 오른쪽 정렬
        if((i+1) % 10 == 0) printf("\n"); //10 출력 후 줄바꿈
    }
    
    //평균
    for(int i=0; i<SIZE; i++){
        total += number[i];
    }
    avg = (float)total / SIZE; //total을 실수로 취급해라 (형변환)

    //최댓값 최솟값
    max = 0;
    min = 0;

    for(int i=1; i<SIZE; i++){
        if(number[max] < number[i]) 
            max = i;
        if(number[min] > number[i]) 
            min = i;
    }

    printf("avg = %f, max = %d, min = %d\n", avg, number[max], number[min]);

    return 0;
}
