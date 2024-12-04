//구조체 배열 동적 생성

#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int x;
    int y;
}POINT;

int main(){
    POINT* points;
    int count;
    scanf("%d", &count); //사용자가 구조체 배열의 크기를 입력
    
    points = (POINT*)malloc(sizeof(POINT) * count); //입력된 크기만큼 메모리를 할당 -> POINT 구조체 하나의 크기

    for(int i = 0; i<count; i++){
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
    for(int i = 0; i<count; i++){
        printf("x - %d, y - %d\n", points[i].x, points[i].y);
    }
    free(points);
    return 0;
}

//5

//x - 23, y - 45
//x - 67, y - 12
//x - 89, y - 34
//x - 12, y - 76
//x - 43, y - 98
