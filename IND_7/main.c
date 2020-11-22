// IND - 4

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct wordArray {  // array for collecting indexes
    int start_index;
    int end_index;
    int wrd_len;
};

int isValid(char *array, int arrayLength) {  // check if array contains only 1, 0 and space
    for(int i = 0; i < arrayLength; i++) {
        if(array[i] == '1') continue;
        if(array[i] == '0') continue;
        if(array[i] == ' ') continue;
        return -1;
    }
    return 0;
}

struct wordArray word[100]; // declare array to use in all functions
int startIndexCounter = 0;  // declare global variable to use in all functions
int endIndexCounter = 0;    // declare global variable to use in all functions
int wordCounter = 0;        // declare global variable to use in all functions

int identifyGroup(char *array, int arrayLength) {    // here is some magic, identifying start index and end index of group
    // check if first symbol in array contains 1 or 0 -> moving to start index
    if (array[0] == '0' || array[0] == '1') {
        startIndexCounter++;
        word[0].start_index = 0;
    }
    // check for start of group
    for(int i = 0; i < arrayLength; i++) {
        if((array[i] == '1' || array[i] == '0') && array[i - 1] == ' ') {   // if current position contains 1 or 0 AND previous position contains space
            startIndexCounter++;
            word[startIndexCounter - 1].start_index = i;
        }
    }
    // check for ending of group
    for(int i = 0; i < arrayLength; i++) {
        if((array[i] == '1' || array[i] == '0') && array[i + 1] == ' ') {   // if current position contains 1 or 0 AND previous position doesn't contain space
            endIndexCounter++;
            word[endIndexCounter - 1].end_index = i;
        }
    }
    // check if last element contains 0 or 1
    if (array[arrayLength - 1] == '0' || array[arrayLength - 1] == '1') {
        word[endIndexCounter].end_index = arrayLength - 1;
    }
    return 0;
}

int makeAnser() {
    for(int i = 0; i < startIndexCounter; i++) { // startIndexCounter goes as count of groups
        word[i].wrd_len = (word[i].end_index - word[i].start_index) + 1;    //
        if(word[i].wrd_len == 5) { 
            wordCounter++;
        }
        printf("word[%d].wrd_len = %d\n",i,word[i].wrd_len);
    }
    printf("total %d words with 5 symbols\n",wordCounter);
    return 0;
}

int main() {
    printf("Type array: ");
    char array[256];
    fgets(array,100,stdin);
    int arrayLength = strlen(array) - 1;
    if(isValid(array, arrayLength)) {
        printf("Incorrect symbols found in array!\n");
        return -1;
    } else {
        identifyGroup(array, arrayLength);
        makeAnser();
    }
    return 0;
}


