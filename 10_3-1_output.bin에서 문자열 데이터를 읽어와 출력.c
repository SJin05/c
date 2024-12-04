//바이너리 파일 output.bin에서 문자열 데이터를 읽어와 출력

#include <stdio.h>
#define SIZE 100

int main(){
    char input[SIZE];
    FILE* fp = NULL;
    int i = 0;
    if((fp=fopen("output.bin", "rb")) == NULL){
        printf("error...");
        return 0;
    }

    while(!feof(fp)){ //파일의 끝(EOF)에 도달할 때까지 반복
        fread(&input[i], sizeof(char), 1, fp); //input[i] 위치에 1바이트씩 읽어서 저장
        i++;
    }
    input[--i] = '\0'; //--i -> i 값을 하나 감소시켜 마지막 읽은 바이트를 무시
    //feof로 인해 마지막 반복에서 EOF 이후 한 번 더 읽으므로, 이를 무시하고 널 문자를 추가
    puts(input);

    fclose(fp);

    return 0;
}
