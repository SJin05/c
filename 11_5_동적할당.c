//동적으로 구조체 배열을 생성, 출력, 클리어, 파일 저장 및 로드를 수행

#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int x;
    int y;
}POINT;

int inputMenu(void){
    int input;
    printf("1. 만들기, 2. 출력하기, 3. 클리어, 4. 파일저장, 5. 파일로드, -1. 종료 : ");
    scanf("%d", &input);
    return input;
}

//동적으로 메모리 할당하여 새로운 POINT 구조체를 만들고 x와 y 값을 랜덤하게 설정
POINT* makePoint(void){
    POINT* p = (POINT*)malloc(sizeof(POINT));
    p->x = rand() % 100;
    p->y = rand() % 100;
    return p;
}

//동적으로 생성된 POINT 구조체들을 출력
void printPoint(POINT* p[], int size){
    for(int i = 0; i<size; i++)
        printf("x:%d, y:%d\n", p[i]->x, p[i]->y);
}

//동적으로 할당된 메모리를 해제
void freePoints(POINT* p[], int size){
    for(int i = 0; i<size; i++) free(p[i]);
}

//동적으로 생성된 POINT 구조체 배열을 파일에 저장
int saveFile(POINT* p[], int count){
    FILE* fp;
    fp = fopen("points.bin", "ab"); //ab 모드로 파일을 열어 덧붙이기 방식으로 저장
    if(fp == NULL) return 0;

    for(int i=0;i<count;i++)
        fwrite(p[i], sizeof(POINT), 1, fp); //fwrite를 사용하여 points.bin 파일에 구조체 데이터를 저장
    fclose(fp);
    return 1;
}

//파일에서 구조체 데이터를 읽어오는 함수
int loadFile(POINT* p[], int max){
    FILE* fp;
    int fSize, fCount;
    fp = fopen("points.bin", "rb");
    if(fp == NULL) return 0;

    fseek(fp, 0, SEEK_END);
    fSize=ftell(fp);
    fCount = fSize / sizeof(POINT);
    rewind(fp);

    for(int i=0;i<fCount;i++){
        if(i == max) break;
        p[i] = (POINT*)malloc(sizeof(POINT));
        fread(p[i],sizeof(POINT), 1, fp);
    }
    fclose(fp);
    return fCount;
}
//파일의 크기를 구한 후, 구조체의 개수를 계산하고, 각 구조체를 동적으로 할당하여 points 배열에 저장
//읽은 개수를 반환하여 로드된 POINT의 수를 알 수 있음

int main(){
    int menu;
    int count = 0;
    POINT* points[100]; //주소값을 저장하는 배열

    do{
        menu = inputMenu();
        switch(menu){
            case 1:
                points[count] = makePoint();
                count++;
                break;
            case 2:
                printPoint(points, count);
                break;
            case 3:
                system("clear"); //window - system("cls")
                break;
            case -1:
                freePoints(points, count);
                printf("프로그램을 종료합니다.\n");
                break;
            case 4:
                if(!saveFile(points, count)) printf("file open error...\n");
                else printf("file writing success..\n");
                break;
            case 5:
                count = loadFile(points, 100);
                break;
        }
    }while(menu > 0);

    return 0;
}
