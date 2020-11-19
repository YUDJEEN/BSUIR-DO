#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

typedef struct {												
	char  name       [256];
    char  birthDate  [256];
    int   group;
    float physics;
    float math;
    float chemistry;
    float computerScience;
    float average;
} student;

// ================================== //
void menu();
void rewriteFile();
int countAllStudents();
void scanFile();
void addStudent();
void editStudent();
void editName();
void editBirth();
void editGroup();
void editMarks();
void displayStudents();
void displayTask();
// ================================== //

void main() {
    menu();
}

void menu() {
    student student[1024];
    scanFile(student);
    int totalStudents = countAllStudents();
	printf("\n1. Add student\n2. Edit student\n3. Display students\n4. Display task\n0. Exit\n");
	int menuChosenItem;
	scanf("%d", &menuChosenItem);
	switch (menuChosenItem) {
	case 1: addStudent(student, totalStudents);  break;
    case 2: editStudent(student, totalStudents); break;
    case 3: displayStudents(student, totalStudents);            break;
    case 4: displayTask(student, totalStudents); break;
    case 0: exit(0);                             break;
	default:
		printf("Incorrect number.\n");
        menu();
	}
}

int countAllStudents() {
	FILE* FILE_STUDENTS;
	FILE_STUDENTS = fopen("students_list.txt", "r");				
	char scanElement;
	int count = 0;
	for (scanElement = getc(FILE_STUDENTS); scanElement != EOF; scanElement = getc(FILE_STUDENTS))
	scanElement == '\n' ? count++ : count;
	fclose(FILE_STUDENTS);
	return count;
}

void rewriteFile(int totalStudents, student *student) {
    FILE* FILE_STUDENTS;
	FILE_STUDENTS = fopen("students_list.txt", "w");
	for (int i = 0; i < totalStudents; i++) {
		fprintf(FILE_STUDENTS, "%s %s %d %.1f %.1f %.1f %.1f %.1f\n", student[i].name,
			  					                                         student[i].birthDate,
			   						                                     student[i].group,
                                                                         student[i].physics,
                                                                         student[i].math,
                                                                         student[i].chemistry,
                                                                         student[i].computerScience,
                                                                         student[i].average);
	}

    fclose(FILE_STUDENTS);
}

void scanFile(student *student) {
    FILE* FILE_STUDENTS;
	FILE_STUDENTS = fopen("students_list.txt", "r");
	int i = 0;
	while (fscanf(FILE_STUDENTS, "%s %s %d %f %f %f %f %f",  student[i].name, 
                                                                student[i].birthDate, 
                                                                &student[i].group, 
                                                                &student[i].physics, 
                                                                &student[i].math, 
                                                                &student[i].chemistry, 
                                                                &student[i].computerScience, 
                                                                &student[i].average) != EOF ){
		i++;
	}
    fclose(FILE_STUDENTS);
}

void addStudent(student *student, int totalStudents) {
    FILE* FILE_STUDENTS;
    FILE_STUDENTS = fopen("students_list.txt", "a+");
    printf("\nName: ");
    scanf("%s", student->name);
    printf("\nBirth date: ");
    scanf("%s", student->birthDate);
    printf("\nGroup: ");
    scanf("%d", &student->group);
    printf("\nPhysics semester mark: ");
    scanf("%f", &student->physics);
    printf("\nMath semester mark: ");
    scanf("%f", &student->math);
    printf("\nChemistry semester mark: ");
    scanf("%f", &student->chemistry);
    printf("\nComputer science mark: ");
    scanf("%f", &student->computerScience);
    student->average = (student->physics + student->math + student->chemistry + student->computerScience) / 4;
    fprintf(FILE_STUDENTS, "%s %s %d %.1f %.1f %.1f %.1f %.1f\n", student->name,
                                                                     student->birthDate,
                                                                     student->group,
                                                                     student->physics,
                                                                     student->math,
                                                                     student->chemistry,
                                                                     student->computerScience,
                                                                     student->average);
    fclose(FILE_STUDENTS);
}

void editStudent(student *student, int totalStudents) {
    scanFile(student);
    printf("Enter student ID: ");
    int ID;
    scanf("%d", &ID);
    ID--;
    printf("1.Edit name\n2.Edit date of birth\n3.Edit group\n4.Edit marks\n");
    int editValue;
    scanf("%d", &editValue);
    switch (editValue)
    {
    case 1 : editName(student, ID, totalStudents);  break;
    case 2 : editBirth(student, ID, totalStudents); break;
    case 3 : editGroup(student, ID, totalStudents); break;
    case 4 : editMarks(student, ID, totalStudents); break;
    default: printf("wrong number!");               exit(0);
    }

}

void editName(student *student, int ID, int totalStudents) {
	printf("Enter new name: ");
	char newName[256];
	scanf("%s", newName);
	strcpy(student[ID].name, newName);
    rewriteFile(totalStudents, student);
}

void editBirth(student *student, int ID, int totalStudents) {
	printf("Enter new birth date: ");
	char newBirthDate[256];
	scanf("%s", newBirthDate);
	strcpy(student[ID].birthDate, newBirthDate);
    rewriteFile(totalStudents, student);
}

void editGroup(student *student, int ID, int totalStudents) {
	printf("Enter new group: ");
	int newGroup;
	scanf("%d", &newGroup);
    student[ID].group = newGroup;
    rewriteFile(totalStudents, student);    
}

void editMarks(student *student, int ID, int totalStudents) {
    printf("1.Edit physics mark\n2.Edit math mark\n3.Edit chemistry mark\n4.Edit computer science mark\n");
    int editValue;
    scanf("%d", &editValue);
    switch (editValue)
    {
    case 1:
	    printf("Enter new mark: ");
	    float newPhysicsMark;
	    scanf("%f", &newPhysicsMark);
        student[ID].physics = newPhysicsMark;
        student[ID].average = (student[ID].physics + student[ID].math + student[ID].chemistry + student[ID].computerScience) / 4;

        rewriteFile(totalStudents, student);         
        break;
    case 2:
	    printf("Enter new mark: ");
	    float newMathMark;
	    scanf("%f", &newMathMark);
        student[ID].math = newMathMark;
        student[ID].average = (student[ID].physics + student[ID].math + student[ID].chemistry + student[ID].computerScience) / 4;
        rewriteFile(totalStudents, student);         
        break;        
    case 3:
	    printf("Enter new mark: ");
	    float newChemistryMark;
	    scanf("%f", &newChemistryMark);
        student[ID].chemistry = newChemistryMark;
        student[ID].average = (student[ID].physics + student[ID].math + student[ID].chemistry + student[ID].computerScience) / 4;
        rewriteFile(totalStudents, student);                 
        break;
    case 4:
	    printf("Enter new mark: ");
	    float newCSMark;
	    scanf("%f", &newCSMark);
        student[ID].computerScience = newCSMark;
        student[ID].average = (student[ID].physics + student[ID].math + student[ID].chemistry + student[ID].computerScience) / 4;
        rewriteFile(totalStudents, student);         
        break;        
    default:
        printf("wrong number!");
        exit(0);
    }    
}

void displayStudents(student *student, int totalStudents) {
	FILE* FILE_STUDENTS;
	FILE_STUDENTS = fopen("students_list.txt", "r");				
	int i = 0;
	while (fscanf(FILE_STUDENTS, "%s %s %d %f %f %f %f %f", 
                                                            student[i].name, 
                                                            student[i].birthDate, 
                                                            &student[i].group, 
                                                            &student[i].physics, 
                                                            &student[i].math, 
                                                            &student[i].chemistry, 
                                                            &student[i].computerScience, 
                                                            &student[i].average) != EOF ){
        printf("\n\nStudent ID: %d\nStudent name: %s\nStudent birth date: %s\nStudent group: %d\nStudent marks:\nPhysics: %.1f\nMath: %.1f\nChemistry: %.1f\nComputer Science: %.1f\nAverage: %.1f\n\n",
        i + 1,
                                                            student[i].name,
                                                            student[i].birthDate,
                                                            student[i].group,
                                                            student[i].physics,
                                                            student[i].math,
                                                            student[i].chemistry,
                                                            student[i].computerScience,
                                                            student[i].average);
		i++;
	}

	fclose(FILE_STUDENTS);
}

void displayTask(student *student, int totalStudents) {
    printf("Input first letter of student to find: ");
    char scanString[24];
    scanf("%s", scanString);
    char firstLetter = scanString[0];              // dont mind this, just regular c

    printf("Students with average mark > 8: \n");

    for (size_t i = 0; i < totalStudents; i++){
        if (student[i].name[0] == firstLetter) {
            if (student[i].math > 7 && student[i].physics > 7 && student[i].chemistry > 7 && student[i].computerScience > 7) {
            printf("\n\nStudent ID: %d\nStudent name: %s\nStudent birth date: %s\nStudent group: %d\nStudent marks:\nPhysics: %.1f\nMath: %.1f\nChemistry: %.1f\nComputer Science: %.1f\nAverage: %.1f\n",
                                                            i + 1,
                                                            student[i].name,
                                                            student[i].birthDate,
                                                            student[i].group,
                                                            student[i].physics,
                                                            student[i].math,
                                                            student[i].chemistry,
                                                            student[i].computerScience,
                                                            student[i].average);
            }
        }
    }
}
    