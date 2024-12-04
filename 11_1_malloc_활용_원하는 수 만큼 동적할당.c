//원하는 수 만큼 동적할당

#include <stdio.h>
#include <stdlib.h>

int main(){

    char* pChar;
    int* pInt;
    int count;

    scanf("%d", &count); //크기만큼 정수 배열을 동적으로 할당
    pInt = (int*)malloc(count*sizeof(int)); //malloc: count * sizeof(int) 바이트만큼 메모리를 할당
    //void* 반환형을 int*로 변환

    for(int i = 0; i<count; i++) pInt[i] = rand() % 100;
    for(int i = 0; i<count; i++) printf("%d ", pInt[i]);

    pChar = (char*)pInt; //포인터 형변환: int* → char*

    while(getchar() != '\n');

    gets(pChar);//문자열 입력
    puts(pChar);//문자열 출력

    free(pInt);//동적으로 할당한 메모리를 해제

    return 0;
}

//5
//Hello World

//72 19 83 45 11
//Hello World
