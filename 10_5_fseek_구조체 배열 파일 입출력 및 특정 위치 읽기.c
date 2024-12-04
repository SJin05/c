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

    //파일에서 좌표 읽기
    loadFile(p, 10);
    printPoints(p, 10);

    //특정 위치의 데이터 읽기
    fp=fopen("struct.bin", "rb");
    if(fp == NULL)exit(-1);

    //파일 시작 기준 4번째 POINT 읽기 (0부터 시작하므로 3번째 인덱스)
    fseek(fp, sizeof(POINT)*3, SEEK_SET);
    fread(&p2, sizeof(POINT), 1, fp);
    printf("p2 -> x : %d, y : %d\n", p2.x, p2.y);

    //파일 끝에서 두 번째 POINT 읽기
    fseek(fp, sizeof(POINT)*-2, SEEK_END);
    fread(&p2, sizeof(POINT), 1, fp);
    printf("p2 -> x : %d, y : %d\n", p2.x, p2.y);
    fclose(fp);
    return 0;
}
