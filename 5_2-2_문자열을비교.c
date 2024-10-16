#include <stdio.h>
#include <string.h>

int main()
{
    char src[100]; //입력받은 문자열을 src 배열에 저장
    char dest[100]; //입력받은 두 번째 문자열을 dest 배열에 저장
    int result;
    gets(src);
    gets(dest);

    result = strcmp(src, dest); //src와 dest 문자열을 비교
    printf("result = %d\n", result);
    //0: 두 문자열이 같음.
    //양수: src가 dest보다 큼.
    //음수: src가 dest보다 작음.

    return 0;
}
