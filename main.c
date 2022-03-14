#include <stdio.h>
#include<string.h>

int SizeFinder(char inputChar[15]) {
    int i = 0;
    while (inputChar[i] != '\0') {
        i++;
    }
    return i;
}

int main() {
    char a, b[12];
    int  stringmatch = 0;//length of string by user
    FILE *fr;
    int stringMatch = 0;//length of word by reading and user are equal
    printf("Enter character which you want to check its a keyword or not:\n");
    scanf(" %s", &b);
    int inputSize = SizeFinder(b);
    fr = fopen("keywords.txt", "r");
    if (fr == NULL) {
        printf("Error opening file!");
        return 0;
    }
    while ((a = fgetc(fr)) != EOF) {

        if (a == ' ' || a == '\n' || a == '\t') {
            if (inputSize == stringmatch) {
                stringMatch = 1;
            }
            stringmatch = 0;
        } else if (a == b[stringmatch]) {
            stringmatch++;
        } else {
            stringmatch = 0;
        }
    }


    if (stringMatch == 1) {
        printf("string match!!\n");
    } else {
        printf("no match!!\n");
    }
    fclose(fr);
    return 0;

}