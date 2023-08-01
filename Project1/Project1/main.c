#include "School.h"
#include <stdio.h>
#include <stdlib.h>


School_t * school;


void insertStudentToClass(School_t* school, Student_t* student)
{
    int layerIndex = student->_layer - 1;
    int classIndex = student->_class - 1;

    student->next = school->layers[layerIndex]->classes[classIndex]->students;
    school->layers[layerIndex]->classes[classIndex]->students = student;
}


/*
    Read the file of the student (students_with_class.txt) and print it to the scren.
*/
School_t* readFile()
{
    school = createSchool("yatmal");

    FILE* file = fopen("students_with_class.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        char firstName[20];
        char lastName[20];
        char phoneNumber[20];
        int layer = 0;
        int classNum = 0;
        int grades[10];

        sscanf(buffer, "%19s %19s %19s %d %d", firstName, lastName, phoneNumber, &layer, &classNum);

        int offset = snprintf(NULL, 0, "%s %s %s %d %d", firstName, lastName, phoneNumber, layer, classNum);

        for (int i = 0; i < 10; i++)
            sscanf(buffer + offset + i * 3, "%d", &grades[i]);

        // Create and initialize the student
        Student_t* student = createStudent(firstName, lastName, phoneNumber, layer, classNum, grades);
        insertStudentToClass(school, student);
        printStudent(student);
        //free(student); 
    }

    fclose(file);
    return school;
}


int main()
{
    School_t* school = readFile();

    for (int i = 0; i < 12; ++i)
        freeLayer(school->layers[i]);
    free(school);

    return 0;
}