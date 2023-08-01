#include"Student.h"
#include <stdlib.h>
#include <stdio.h>



Student_t* createStudent(char* firstName, char* lastName, char* phone, int* numbers)
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
    for (int i = 0; i < 10; ++i)
    {
        student->grades[i] = numbers[i];
        totalGrade += numbers[i];
    }
    student->average = totalGrade / 10;

    return student;
}



void printStudent(Student_t* student)
/*
    Print the student details.
*/
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

