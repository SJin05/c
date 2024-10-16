#include <stdio.h>
#include <math.h>

typedef struct point{ //x와 y 좌표
    int x;
    int y;
}POINT;

typedef struct{
    POINT center; //중심점
    double radius; //반지름
}CIRCLE;

typedef struct rect{
    POINT lb; //좌하단 점
    POINT rt; //우상단 점
}RECT;

double dist(struct point p1, struct point p2){
    double distance;
    return sqrt(pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2));
}

int main()
{
    CIRCLE c1 = {{10, 10}, 4.5}; //(10, 10) 중심과 반지름 4.5로 초기화
    CIRCLE c2; //
    c2.radius = 5.5;
    c2.center.x = 10;
    c2.center.y = 20; //c2라는 원을 선언 후 중심을 (10, 20)으로 설정, 반지름을 5.5로 설정
    POINT point = {10,15}; //point라는 점을 (10, 15)로 설정
    double distance;

    printf("CIRCLE1 = (%d, %d), r : %lf\n", c1.center.x, c1.center.y, c1.radius);
    printf("CIRCLE2 = (%d, %d), r : %lf\n", c2.center.x, c2.center.y, c2.radius);
    printf("point = (%d, %d)\n", point.x, point.y);

    distance = dist(c1.center, point); //c1의 중심과 point 간의 거리 계산
    if(distance <= c1.radius){ //거리와 반지름 비교
        printf("원 안에 있습니다.\n");
    } else{
        printf("원 밖에 있습니다.\n");
    }
    return 0;
}
