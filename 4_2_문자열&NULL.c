#include <stdio.h>

int main()
{
    //'\0'은 문자열의 끝을 나타냄
    char message[5] = {'a','b','c','\0'};
    char message2[5] = {'a','b','c','d','\0'};

    printf("message = %s, message2 = %s", message, message2);

    return 0;
}
