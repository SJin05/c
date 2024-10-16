//큰수 -> 작은수
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
int main(){

    int number[SIZE];
    int most;
    int temp;
    srand(time(NULL));

    for(int i=0; i<SIZE; i++){
        number[i] = (rand() % 10000) +1;
    }

    //수 비교
    for(int i=0; i<SIZE-1; i++){
        most = i; //처음 수
        for(int j=i+1; j<SIZE; j++){
            if(number[most] < number[j])
                most = j; //다음 수 
        }
        //수 교환
        temp = number[i];
        number[i] = number[most];
        number[most] = temp;
    }

    for(int i=0; i<SIZE; i++){
        printf("%5d\t", number[i]);
        if((i+1) % 10 == 0) printf("\n");
    }

    return 0;
}
