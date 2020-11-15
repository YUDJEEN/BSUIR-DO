#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void main()
{
	//get array size
	int arraySize;
	printf("Array size: ");
	scanf("%d", &arraySize);
	// init array
	int* minToMaxArray;
	minToMaxArray = (int*)malloc(arraySize * sizeof(int));
	// get array
	for (int i = 0; i < arraySize; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &minToMaxArray[i]);
	}
	// create array copy for bubble sort
	// init new array
	int* sortedMinToMaxArray;
	sortedMinToMaxArray = (int*)malloc(arraySize * sizeof(int));
	// copy old array to new array
	for (int i = 0; i < arraySize; i++) {
		sortedMinToMaxArray[i] = minToMaxArray[i];
	}
	// sort new array
	printf("bubble sort \n");
	int sortingTempInt;
	for (int i = 0; i < arraySize - 1; i++)	// 0 1 2
	{
		for (int j = (arraySize - 1); j > i; j--) // 4 3 2
		{
			if (sortedMinToMaxArray[j - 1] > sortedMinToMaxArray[j])	// f.e. arr = 5 ; if 4 el > 5 el
			{
				sortingTempInt = sortedMinToMaxArray[j - 1];		// set 4 el
				sortedMinToMaxArray[j - 1] = sortedMinToMaxArray[j];	// swap them
				sortedMinToMaxArray[j] = sortingTempInt;			// ...
			}
		}
	}
	// print sorted array
	for (int i = 0; i < arraySize; i++) {
		printf("a[%d]: %d \n", i, sortedMinToMaxArray[i]);
	}
	// get lowest and highest number from array
	int lowestNumber = sortedMinToMaxArray[0];
	printf("lowestNumber: %d\n", lowestNumber);
	int highestNumber = sortedMinToMaxArray[arraySize - 1];
	printf("highestNumber: %d\n", highestNumber);
	// startpoint - adress of lowest number in array
	int startPoint;
	for (int i = 0; i < arraySize; i++) {
		if (minToMaxArray[i] == lowestNumber) {
			startPoint = i;
			break;
		}
	}
	printf("start point: %d \n", startPoint);
	// endpoint - adress of highest number in array
	int endPoint;
	for (int i = 0; i < arraySize; i++) {
		if (minToMaxArray[i] == highestNumber) {
			endPoint = i;
			break;
		}
	}
	printf("end point: %d \n", endPoint);
	// summ of numbers
	int summ = 1;
	if (startPoint < endPoint) {
		for (int i = startPoint + 1; i < endPoint; i++) {
			summ *= minToMaxArray[i];
		}
	}
	else {
		for (int i = startPoint - 1; i > endPoint; i--) {
			summ *= minToMaxArray[i];
		}
	}
	printf("summ: %d\n", summ);
	free(minToMaxArray);
	free(sortedMinToMaxArray);
}