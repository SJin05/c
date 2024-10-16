#include <stdio.h>
#include <stdlib.h> //rand()에 의해 작성됨
#include <time.h> //시간 관리 함수
int main(){

    int number[10]; //number 이라는 이름의 배열 선언 (크기=10)

    srand(time(NULL)); //랜덤값의 초기패턴을 바꿔주고 싶을 때 사용 (=시간에 따라 생성되는 난수가 다름)

    for(int i=0; i <10; i++){
        number[i] = (rand() % 100) +1; 
        //난수를 100으로 나눈 나머지 값을 반환 (= 0에서 99 사이의 값을 생성)
        //1을 더해 최종적으로 1에서 100 사이의 값을 생성
    }


    for(int i=0; i <10; i++){
        printf("number = %d\n", number[i]);
    }

    return 0;
}
