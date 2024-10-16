#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 100

typedef struct point{ //POINT라는 구조체 정의
    int x;
    int y;
} POINT;

//점의 배열에 무작위로 생성된 좌표 값을 채워 넣음
void input_random_point(POINT* p, int size)
{
    srand(time(NULL));

    for(int i=0; i<SIZE; i++){
        (p+i)->x = rand() % 101; //POINT 타입의 포인터로, (p+i)는 i번째 점을 가르킴
        (p+i)->y = rand() % 101;
    }
}

//두 개의 POINT 구조체 값을 서로 바꿉
void swap_point(POINT* p1, POINT* p2)
{
    POINT temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

//점 배열을 출력
void print_point_array(POINT p[], int size)
{
    for(int i=0; i<SIZE; i++){
        printf("p[%3d] : (%3d, %3d)\n", i, p[i].x, p[i].y);
        //p[i].x와 p[i].y -> 배열 p의 i번째 요소의 x좌표와 y좌표
    }
}

//선택 정렬 알고리즘을 사용해 점 배열을 정렬
void selection_sort_point(POINT* point, int size)
{
    int least;
    for(int i=0; i<SIZE-1; i++){
        least = i;
        for(int j=i+1; j<SIZE; j++){
            if(point[least].x > point[j].x) least = j;
            else if((point+least)->x == point[j].x && point[least].y > point[j].y)
                least = j;
        }
        swap_point(&point[i], point+least);
        //swap_point 함수를 호출하여 현재 요소와 least 인덱스의 요소를 교환
    }
}

int main()
{
    POINT point[SIZE] = {0};
    POINT temp = {0,0};
    int least;

    input_random_point(point, SIZE); //점 배열에 무작위로 값을 채움
    print_point_array(point, SIZE); //초기화된 점 배열을 출력
    selection_sort_point(point, SIZE); //점 배열을 정렬
    printf("-----after sorting-----\n");
    print_point_array(point, SIZE); //정렬된 배열을 출력
    return 0;
}
