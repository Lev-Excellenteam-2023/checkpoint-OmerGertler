# pragma once

struct Student_t
{
    char _firstName[50];
    char _lastName[50];
    char phoneNumber[11];
    int grades[10];
    int average;
} typedef Student_t;

Student_t* createStudent(char* firstName, char* lastName, char* phone, int* numbers);

void printStudent(Student_t* student);
