#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void editString();

void main() {
    char uneditedString[256];
    printf("Enter string: \n");
    scanf("%s", uneditedString);
    printf("%s", uneditedString);
    editString(uneditedString);
}

void editString(char *uneditedString) {
    int stringLen = strlen(uneditedString);
    int counter = 0;
    for (size_t i = 0; i < stringLen; i++) {
        if(uneditedString[i] == '!') {
            counter++;
            if (counter %2 == 0) uneditedString[i] = '$';
        }
    }
    if (counter == 0) {
        printf("No symbols to edit\n");
    }
    printf("\nEdited string: %s", uneditedString);
}