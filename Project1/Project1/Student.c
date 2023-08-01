#include"Student.h"
#include <stdlib.h>
#include <stdio.h>



Student_t* createStudent(char* firstName, char* lastName, char* phone, int layer, int stud_class, int* numbers)
/*
    Student c-tor.
    Calculate the average grade of the student based on the values from "numbers" param.
*/
{
    Student_t* student = (Student_t *)malloc(sizeof(Student_t));
    int totalGrade = 0;

    strncpy(student->_firstName, firstName, 50);
    strncpy(student->_lastName, lastName, 50);
    strncpy(student->phoneNumber, phone, 11);
    student->_layer = layer;
    student->_class = stud_class;

    for (int i = 0; i < 10; ++i)
    {
        student->grades[i] = numbers[i];
        totalGrade += numbers[i];
    }
    student->average = totalGrade / 10;

    return student;
}



/*
    Print the student details.
*/
void printStudent(Student_t* student)
{
    printf("Name: %s %s\n", student->_firstName, student->_lastName);
    printf("Phone: %s\n", student->phoneNumber);
    printf("Grades: ");
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", student->grades[i]);
    }
    printf("\n");
    printf("Average: %d\n", student->average);
    printf("\n");
}


/*
    student d-tor.
    Free students linked-list recursively.
*/
void freeStudent(Student_t* student)
{
    if (student->next != NULL)
        freeStudent(student->next);
    free(student);
}

