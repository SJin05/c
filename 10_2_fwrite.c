//fwrite -> 바이너리 데이터를 파일에 기록

#include <stdio.h>
#define SIZE 100

int main(){
    char input[SIZE]; //사용자로부터 입력받을 문자열을 저장할 배열
    FILE* fp = NULL;

    if((fp=fopen("output.bin", "wb")) == NULL){
        printf("error...");
        return 0;
    }
    gets(input); //사용자로부터 문자열을 입력받음
    //fputs(input, fp);

    fwrite(input, strlen(input), 1, fp);

    fclose(fp);

    return 0;
}
