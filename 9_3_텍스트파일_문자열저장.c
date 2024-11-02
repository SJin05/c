#include <stdio.h>

int getLine(char* line)
{
    int ch;
    int i = 0;
    while((ch=getchar()) != '\n') line[i++] = ch;
    line[i] = '\0'; //입력이 끝난 후 line 배열의 마지막에 \0을 추가하여 문자열의 끝을 표시
    return i;
}

int main()
{
    char input[100];
    FILE* fp;

    if((fp = fopen("output.txt", "w")) == NULL){
        printf("error...");
        return 0;
    }
    for(int i=0;i<5;i++){
        getLine(input);
        fputs(input, fp);
        fputs("\n", fp);
    }

    fclose(fp);
    return 0;
}
