#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

typedef struct {												
	char name			[256];												
	char secondName		[256];										
	int  roomNumber;												
} student;


void menuAddStudent		();
void addStudent			();
void menuEditStudentData();
void makeEditData		();
void menuDisplayStudents();
int  countAllStudents	();


void menu() {
	printf("\n1. Add student\n2. Edit student\n3. Display students\n0. Exit\n");
	int menuChosenItem;
	scanf("%d", &menuChosenItem);

	switch (menuChosenItem) {
	case 1:
		menuAddStudent();
		break;
	case 2:
		menuEditStudentData();
		break;
	case 3:
		menuDisplayStudents();
		break;
	case 0:
		exit(0);
	default:
		printf("Incorrect number.");
	}

}

void menuAddStudent() {

	printf("How much students to add: ");
	int valueOfStudentsToAdd;
	scanf("%d", &valueOfStudentsToAdd);
	addStudent(valueOfStudentsToAdd);

}

void addStudent(int valueOfStudentsToAdd) {									
	FILE* FILE_STUDENTS;
	FILE_STUDENTS = fopen("students_list.txt", "a+");				
	int totalStudents = countAllStudents();		
	student* STUDENTS = malloc(totalStudents * sizeof(*STUDENTS));	

	for (int i = 0; i < valueOfStudentsToAdd; i++) {						
		printf("\n==================================== NEW STUDENT ====================================\n");

		printf("\nName: ");
		scanf("%s", (STUDENTS + i)->name);						

		printf("\nSecond Name: ");
		scanf("%s", (STUDENTS + i)->secondName);						

		printf("\nRoom of %s: ", &(STUDENTS + i)->name);
		scanf("%d", &(STUDENTS + i)->roomNumber);					

		fprintf(FILE_STUDENTS, "%s %s %d\n",
										(STUDENTS + i)->name,
										(STUDENTS + i)->secondName,
										(STUDENTS + i)->roomNumber);

		printf("\n====================================================================================\n");
	}
	fclose(FILE_STUDENTS);
	free(STUDENTS);
	menu();
}

void menuEditStudentData() {
	menuDisplayStudents();
	FILE* FILE_STUDENTS;
	FILE_STUDENTS = fopen("students_list.txt", "r");

	int totalStudents = countAllStudents();		
	student* STUDENTS = malloc(totalStudents * sizeof(*STUDENTS));	

	printf("\n Enter student number to edit: \n");
	int studentID;
	scanf("%d", &studentID);
	studentID--; // Коррекция числа, т.к. исчисление в файле идет с 0;


	int i = 0;
	while (fscanf(FILE_STUDENTS, "%s %s %d",
	 									(STUDENTS + i)->name,
	  									(STUDENTS + i)->secondName,
	   								   &(STUDENTS + i)->roomNumber) != EOF) {
		i++;
	}

	printf("\n\nStudent ID: %d \n Student name: %s \n Student second name %s \n Student room number %d \n\n",
	 																										studentID,
	  																										(STUDENTS + studentID)->name,
	   																										(STUDENTS + studentID)->secondName,
	    																									(STUDENTS + studentID)->roomNumber);
				

	fclose(FILE_STUDENTS);
	makeEditData(studentID, totalStudents, &STUDENTS);


}

void makeEditData(int studentID, int totalStudents, student *STUDENTS) {
	
	FILE* FILE_STUDENTS;
	FILE_STUDENTS = fopen("students_list.txt", "w");


	printf("1. Change name\n2. Change second name\n3. Change room number\n");

	
	int editValue;
	scanf("%d", &editValue);
	switch (editValue) {
	case 1:
		printf("Enter new name: ");
		char* newName = malloc(sizeof(*newName));
		scanf("%s", newName);
		strcpy((STUDENTS + studentID)->name, newName);											
	
		
		for (int i = 0; i < totalStudents; i++) {
			fprintf(FILE_STUDENTS, "%s %s %d\n",
			 								(STUDENTS + i)->name,
			  								(STUDENTS + i)->secondName,
			   								(STUDENTS + i)->roomNumber);	
		}

		break;
	case 2:
		printf("Enter new second name: ");
		char* newSecondName = malloc(sizeof(*newSecondName));
		scanf("%s", newSecondName);
		strcpy((STUDENTS + studentID)->secondName, newSecondName);

		for (int i = 0; i < totalStudents; i++) {
			fprintf(FILE_STUDENTS, "%s %s %d\n",
											(STUDENTS + i)->name,
			 								(STUDENTS + i)->secondName,
			  								(STUDENTS + i)->roomNumber);	
		}

		break;
		
	case 3:
		printf("Enter new room number: ");
		int* newRoomNumber = malloc(sizeof(*newRoomNumber));
		scanf("%d", &newRoomNumber);
		(STUDENTS + studentID)->roomNumber = newRoomNumber;
		for (int i = 0; i < totalStudents; i++) { 
			fprintf(FILE_STUDENTS, "%s %s %d\n", 
											(STUDENTS + i)->name,
			 								(STUDENTS + i)->secondName,
			  								(STUDENTS + i)->roomNumber);	
		}

		break;
	}

	fclose(FILE_STUDENTS);
}

void menuDisplayStudents() {											
	FILE* FILE_STUDENTS;
	FILE_STUDENTS = fopen("students_list.txt", "r");				

	size_t valueOfAllStudents = countAllStudents();
	student* STUDENTS = malloc(valueOfAllStudents * sizeof(*STUDENTS));

	printf("\n==================================== STUDENTS ===================================\n");
	int i = 0;
	while (fscanf(FILE_STUDENTS, "%s %s %d",
										(STUDENTS + i)->name,
										(STUDENTS + i)->secondName,
									   &(STUDENTS + i)->roomNumber) != EOF) {	

		printf("\n\nStudent ID: %d \n Student name: %s \n Student second name %s \n Student room number %d \n\n",
																												i + 1,
																												(STUDENTS + i)->name,
																												(STUDENTS + i)->secondName,
																												(STUDENTS + i)->roomNumber);
		i++;
	}
	printf("\n=================================================================================\n");
 
	fclose(FILE_STUDENTS);
	free(STUDENTS);
}

int countAllStudents() {
	FILE* FILE_STUDENTS;
	FILE_STUDENTS = fopen("students_list.txt", "r");				
	char scanElement;
	int count = 0;
	for (scanElement = getc(FILE_STUDENTS); scanElement != EOF; scanElement = getc(FILE_STUDENTS))
		if (scanElement == '\n'){
			count++;
		}
		count; 
	fclose(FILE_STUDENTS);
	return count;
}

void main() {
	menu();
}