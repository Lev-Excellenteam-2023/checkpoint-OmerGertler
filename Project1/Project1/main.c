#include "School.h"
#include <stdio.h>
#include <stdlib.h>


School_t * school;


void readFile()
/*
    Read the file of the student (students_with_class.txt) and print it to the scren.
*/
{
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
        char layer[3];
        char class[3];
        int grades[10];

        sscanf(buffer, "%19s %19s %19s %2s %2s", firstName, lastName, phoneNumber, layer, class);

        int offset = snprintf(NULL, 0, "%s %s %s %s %s", firstName, lastName, phoneNumber, layer, class);

        for (int i = 0; i < 10; i++)
            sscanf(buffer + offset + i * 3, "%d", &grades[i]);

        // Create and initialize the student
        Student_t* student = createStudent(firstName, lastName, phoneNumber, grades);

        printStudent(student);
        free(student); 
    }


    fclose(file);
}


int main()
{
    school = createSchool("yatmal");
    readFile();
    return 0;
}