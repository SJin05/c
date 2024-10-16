#include <stdio.h>
#include <math.h> //sqrt와 pow 함수를 사용하기 위함

struct point{ //point라는 구조체 정의 //2차원 평면에서 점을 표현하기 위함
    int x;
    int y;
};

double dist(struct point p1, struct point p2){ //dist 함수 -> 두 점(p1과 p2)을 입력받아 그 사이의 거리를 계산
    double distance;
    return sqrt(pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2)); //pow 함수를 사용하여 제곱 계산 //sqrt 함수를 사용하여 제곱근 계산
}

int main()
{
    struct point p1 = {10,20};
    struct point p2;

    p1.x = 20; //p1.x는 20, p1.y는 20
    p2.x = 30;
    p2.y = 40; //p2.x를 30, p2.y를 40

    printf("p1.x = %d, p1.y = %d\n", p1.x, p1.y);
    printf("p2.x = %d, p2.y = %d\n", p2.x, p2.y);

    printf("distance of p1, p2 = %lf", dist(p1, p2));

    return 0;
}
