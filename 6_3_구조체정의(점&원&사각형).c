#include <stdio.h>
#include <math.h>

//구조체를 사용하여 점, 원, 사각형을 표현
typedef struct point{
    int x;
    int y;
}POINT; //POINT라는 구조체 정의

typedef struct{
    POINT center;
    double radius;
}CIRCLE; //CIRCLE이라는 구조체 정의

typedef struct rect{
    POINT lb;
    POINT rt;
}RECT; //RECT라는 구조체 정의

double dist(struct point p1, struct point p2){
    double distance;
    return sqrt(pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2));
}

int main()
{
    struct point p1 = {10,20};
    struct point p2;

    p1.x = 20;
    p2.x = 30;
    p2.y = 40;

    printf("p1.x = %d, p1.y = %d\n", p1.x, p1.y);
    printf("p2.x = %d, p2.y = %d\n", p2.x, p2.y);

    printf("distance of p1, p2 = %lf", dist(p1, p2));

    return 0;
}
