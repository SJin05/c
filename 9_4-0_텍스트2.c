#include <stdio.h>

int getLine(char* line)
{
    int ch;
    int i = 0;
    while((ch=getchar()) != '\n') line[i++] = ch;
    line[i] = '\0';
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
    while(!feof(fp)){
        fgets(input, 100, fp);
        printf("%s", input);
        //우리가 원하는 작업 가능
    }

    fclose(fp);
    return 0;
}