#include"Student.h"


Student_t* createStudent(char* firstName, char* lastName, int phone, int* numbers)
{
    Student_t* student = malloc(sizeof(Student_t));
    int totalGrade = 0;

    student->firstName = firstName;
    student->lastName = lastName;
    student->phone = phone;
    for(int i = 0; i < 10; ++i)
    {
        student->grades[i] = numbers[i];
        totalGrade += numbers[i];
    }
    student->average = totalGrade / 10;
    
    return student;
}