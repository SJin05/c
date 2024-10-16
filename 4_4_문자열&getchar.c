#include <stdio.h>

int main()
{
    int ch;
    char message[100];
    int i = 0;

    while((ch = getchar()) != '\n'){ //줄바꿈 하지 않는 이상 문자 입력 가능
        message[i++] = ch;
    }
    message[i] = '\0'; //문자열은 반드시 null로 끝난다
    printf("%s", message);
    return 0;
}
