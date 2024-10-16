#include <stdio.h>
#include <string.h>

int main()
{
    char input[200] = "";
    int count[26] = {0}; //소문자 'a'부터 'z'까지의 각 문자의 출현 횟수를 저장하기 위한 배열
    int upper_count[26] = {0}; //대문자 'A'부터 'Z'까지의 각 문자의 출현 횟수를 저장하기 위한 배열
    int num_count[10] = {0}; //숫자 '0'부터 '9'까지의 각 문자의 출현 횟수를 저장하기 위한 배열
    int special_count = 0; //특수문자의 출현 횟수를 세기 위한 변수
    int ch; //사용자의 입력을 저장하기 위한 변수
    int i = 0; //문자열의 길이를 추적

    while((ch = getchar()) != EOF){ //문자를 입력받고 입력이 종료될 때까지 (EOF - End Of File) 반복
        input[i++] = ch;
    }

    i = 0;
    while(input[i] != '\0'){ //input[i]가 널 문자('\0')에 도달할 때까지 반복
        if(input[i] >= 'a' && input[i] <= 'z'){ //현재 문자가 소문자인지 확인
            count[input[i] -'a']++; //각 소문자의 위치를 찾아서 그 위치의 카운트를 1 증가
            //input[i]가 'b'라고 가정해보면,
            //input[i] - 'a'는 b - a로, 결과는 1이 된다.
            //따라서 count[1]++가 실행되어, 'b'의 카운트가 1 증가.
        }
        else if(input[i] >= 'A' && input[i] <= 'Z'){
            upper_count[input[i] - 'A']++;
        }
        else if (input[i] >= '0' && input[i] <= '9') {
            num_count[input[i] - '0']++;
        }
        else if (input[i] >= 32 && input[i] <= 126) { //ASCII 값이 32부터 126 사이에 해당하면 특수문자 카운트 증가
            special_count++;
        }
        i++;
    }

    printf("\n입력문자열 : %s\n", input);

    for (int i = 0; i < 26; i++) {
            printf("%c 출현 횟수 : %d\n", 'a' + i, count[i]);
    }
    for (int i = 0; i < 26; i++) {
            printf("%c 출현 횟수 : %d\n", 'A' + i, upper_count[i]);
    }
    for (int i = 0; i < 10; i++) {
            printf("%d 출현 횟수 : %d\n", i, num_count[i]);
    }
    printf("특수문자 출현 횟수 : %d\n", special_count);

    return 0;
}
