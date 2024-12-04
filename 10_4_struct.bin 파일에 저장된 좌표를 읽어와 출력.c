#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct point{
    int x;
    int y;
}POINT; //2차원 좌표를 저장하기 위함

//사용자가 입력한 x, y 값을 구조체에 저장하고 반환
POINT makePoint(void){
    POINT p;
    scanf("%d %d", &p.x, &p.y); //정수를 입력받음
    return p;
}

void makeRandomPoints(POINT p[], int size){ //size 개의 랜덤 좌표를 생성해 POINT 배열에 저장
    srand(time(NULL)); //난수 초기화를 현재 시간을 기준으로 설정
    for(int i=0;i<size;i++){
        p[i].x = rand() % 100; //0부터 99 사이의 난수를 생성
        p[i].y = rand() % 100;
    }
}

void printPoints(POINT p[], int size){ //POINT 배열의 좌표를 출력
    for(int i=0;i<size;i++)
        printf("point[%d] = x : %d, y : %d\n", i, p[i].x, p[i].y);
}

void saveFile(POINT p[], int size){ //POINT 배열을 바이너리 파일 struct.bin에 저장
    FILE* fp;
    fp = fopen("struct.bin", "wb");
    if(fp == NULL) exit(-1);
    fwrite(p, sizeof(POINT), size, fp); //POINT 구조체 배열 p를 파일에 쓰기
    fclose(fp);
}

void loadFile(POINT p[], int size){ //struct.bin 파일에서 POINT 배열을 읽어옴
    FILE* fp;
    fp = fopen("struct.bin", "rb");
    if(fp == NULL) exit(-1);
    fread(p, sizeof(POINT), size, fp); //구조체 배열을 파일에서 읽기
    fclose(fp);
}
int main(){
    POINT p[10]; //크기가 10인 POINT 배열을 선언
    //makeRandomPoints(p, 10);
    loadFile(p, 10); //struct.bin에서 10개의 좌표를 불러옴
    printPoints(p, 10); //불러온 좌표를 출력
    //saveFile(p, 10);
    return 0;
}
