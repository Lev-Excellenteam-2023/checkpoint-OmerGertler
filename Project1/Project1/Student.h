# pragma once

struct Student_t
{
    char _firstName[50];
    char _lastName[50];
    int _layer;
    int _class;
    char phoneNumber[11];
    int grades[10];
    int average;

    struct Student_t* next;

} typedef Student_t;

Student_t* createStudent(char* firstName, char* lastName, char* phone, int layer, int stud_class, int* numbers);

void printStudent(Student_t* student);

void freeStudent(Student_t* student);
