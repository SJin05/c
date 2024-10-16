#include <stdio.h>
#include <time.h>
#include <stdlib.h> //rand()와 srand()를 사용하기 위함

#define SIZE 100

typedef struct point{
    int x;
    int y;
} POINT;

int main(){
    POINT point[SIZE] = {0};
    POINT temp = {0,0}; //점을 교환할 때 사용할 임시 변수
    int least; //정렬 중 현재 가장 작은 값을 가진 인덱스를 저장하기 위한 변수

    srand(time(NULL));

    for(int i=0; i<SIZE; i++){
        point[i].x = rand() % 101;
        point[i].y = rand() % 101;
        //0에서 100 사이의 랜덤 숫자를 생성하여 각 점의 x와 y 좌표에 저장
    }

    for(int i=0; i<SIZE; i++){
        printf("point[%3d] : (%3d, %3d)\n", i, point[i].x, point[i].y);
    }

    //정렬
    for(int i=0; i<SIZE-1; i++){ //i는 현재 정렬을 진행할 인덱스
        least = i; //가장 작은 x 좌표를 가진 점의 인덱스를 저장하는 변수
        for(int j=i+1; j<SIZE; j++){ //j는 비교할 다음 점의 인덱스
            if(point[least].x > point[j].x) least = j; // x 좌표 기준으로 비교
            else if(point[least].x == point[j].x && point[least].y > point[j].y)
            //두 점의 x 좌표가 같다면, y 좌표를 비교하여 작은 값을 가진 점을 찾음
                least = j; //y 좌표가 더 작은 점을 선택하기 위함
        }
        //가장 작은 값을 찾았으면 현재 위치와 교환
        temp = point[least]; //현재 가장 작은 점을 temp에 저장
        point[least] = point[i];
        point[i] = temp;
    }

    //정렬된 점 출력
    printf("----- after sorting -----\n");
    for(int i=0; i<SIZE; i++){
        printf("point[%3d] : (%3d, %3d)\n", i, point[i].x, point[i].y);
    }

    return 0;

}
