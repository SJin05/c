#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct point{
    int x;
    int y;
}POINT;

POINT makePoint(void){
    POINT p;
    scanf("%d %d", &p.x, &p.y);
    return p;
}

void makeRandomPoints(POINT p[], int size){
    srand(time(NULL));
    for(int i=0;i<size;i++){
        p[i].x = rand() % 100;
        p[i].y = rand() % 100;
    }
}

void printPoints(POINT p[], int size){
    for(int i=0;i<size;i++)
        printf("point[%d] = x : %d, y : %d\n", i, p[i].x, p[i].y);
}

void saveFile(POINT p[], int size){
    FILE* fp;
    fp = fopen("struct.bin", "wb");
    if(fp == NULL) exit(-1);
    fwrite(p, sizeof(POINT), size, fp);
    fclose(fp);
}

void loadFile(POINT p[], int size){
    FILE* fp;
    fp = fopen("struct.bin", "rb");
    if(fp == NULL) exit(-1);
    fread(p, sizeof(POINT), size, fp);
    fclose(fp);
}


int main(){
    FILE* fp;
    POINT p[10];
    POINT p2;
    int pi;

    //파일에서 좌표 읽기 및 출력
    loadFile(p, 10);
    printPoints(p, 10);

    fp=fopen("struct.bin", "rb");
    if(fp == NULL)exit(-1);
    
    fseek(fp, sizeof(POINT)*3, SEEK_SET);//파일 포인터 3번째 POINT로 이동
    pi = ftell(fp); //파일 포인터 위치 저장
    printf("pi = %d\n", pi);
    fread(&p2, sizeof(POINT), 1, fp);
    printf("p2 -> x : %d, y : %d\n", p2.x, p2.y);

    
    fseek(fp, sizeof(POINT)*-2, SEEK_END); //파일 끝에서 두 번째 POINT로 이동
    printf("pi = %d\n", ftell(fp)); //현재 위치 출력
    fread(&p2, sizeof(POINT), 1, fp);
    printf("p2 -> x : %d, y : %d\n", p2.x, p2.y);

    //파일 크기 출력
    fseek(fp,0,SEEK_END);
    printf("size = %ld\n", ftell(fp));
    fclose(fp);
    return 0;
}
