# pragma once

typedef struct Student
{
    char* _firstName;
    char* _lastName;
    int phoneNumber;
    int* grades;
    int average;    
}Student_t;

Student_t* createStudent(char* firstName, char* lastName, int phone, int* numbers); 
