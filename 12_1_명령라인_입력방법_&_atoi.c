//첫번째 코드
//커맨드 라인 인자를 처리
//argc는 입력된 인자의 개수를 나타내며, argv는 입력된 인자들의 문자열 배열
#include <stdio.h>

int main(int argc, char* argv[]){
    for(int i=0; i<argc; i++){
        puts(argv[i]);
    }
    return 0;
}



//2번째 코드
//커맨드 라인에서 입력된 두 숫자를 더하는 예제
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int a, b; 

    a = atoi(argv[1]); //atoi -> 숫자형식 문자를 숫자로 바꿈
    b = atoi(argv[2]);

    printf("a+b = %d", a+b);
    return 0;
}
