#include <stdio.h>
#include <string.h> //strlen, strcpy, strcat 등을 사용하기 위함

int main()
{
    char src[100];
    char dest[100];
    int length;
    
    gets(src); //엔터를 누를 때까지 입력된 모든 문자열을 읽어옴, 읽은 문자열의 마지막에는 자동으로 '\0'이 추가되어 문자열의 끝을 표시
    
    length = strlen(src); //널 문자는 계산에 포함되지 않음

    printf("length of src = %d\n", length);
    strcpy(dest, src); //src 문자열을 dest 배열로 복사
    printf("src = %s, dest = %s\n", src, dest);
    strcat(dest, src); //src 문자열을 dest 문자열의 끝에 연결
    printf("src = %s, dest = %s\n", src, dest);

    return 0;

}
