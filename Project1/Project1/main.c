#include "School.h"
#include <stdio.h>
#include <stdlib.h>


School_t * school;


void insertStudentToClass(School_t* school, Student_t* student)
{
    int layerIndex = student->_layer - 1;
    int classIndex = student->_class - 1;

    student->next = school->layers[layerIndex]->classes[classIndex]->students;
    //while (student->next->average > student->average)
    //{
    //    Student_t* tmp;
    //    tmp->next = student->next->next;
    //    student->next = tmp->next;
    //    student->next->next = student;
    //}
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
        //printStudent(student);
        //free(student); 
    }

    fclose(file);
    return school;
}


/*
* Insert a new student with details from the user.
*/
void insertNewStudent(School_t* school)
{
    char firstName[20];
    char lastName[20];
    char phoneNumber[20];
    int layer = 0;
    int classNum = 0;
    int grades[10];

    printf("Insert First Name: %s\n", firstName);
    fgets(firstName, sizeof(firstName), stdin);
    printf("Insert Last Name: %s\n", lastName);
    fgets(lastName, sizeof(lastName), stdin);
    printf("Insert Phone Number: %s\n", phoneNumber);
    fgets(phoneNumber, sizeof(phoneNumber), stdin);
    printf("Insert Layer:\n");
    scanf("%d", &layer);
    printf("Insert Class:\n");
    scanf("%d", &classNum);
    printf("Insert 10 Grades: ");
    for (int i = 0; i < 10; ++i)
    {
        scanf("%d", &grades[i]);
    }
    printf("\n");

    Student_t* student = createStudent(firstName, lastName, phoneNumber, layer, classNum, grades);
    insertStudentToClass(school, student);
    printStudent(student);
}


//void deleteStudent(School_t* school)
//{
//    char firstName[20];
//    char lastName[20];
//    printf("Insert First Name: %s\n", firstName);
//    fgets(firstName, sizeof(firstName), stdin);
//    printf("Insert Last Name: %s\n", lastName);
//    fgets(lastName, sizeof(lastName), stdin);
//
//    Student_t* it;
//    int found = 0;
//    for (int i = 0; i < 12 && found == 0; ++i)
//    {
//        for (int j = 0; j < 10 && found == 0; ++j)
//        {
//            it = school->layers[i]->classes[j]->students;
//            if (strcmp(it->next->_firstName, firstName) == 0 && strcmp(it->next->_lastName, lastName) == 0) // names are equal
//            {
//                Student_t* tmp;
//                tmp = it->next;
//                it->next = tmp->next;
//                free(tmp);
//                found = 1;
//                printf("Student deletes successfuly\n");
//            }
//        }
//    }
//    if(found == 0)
//        printf("This student is not exist\n");
//}


/*
* Print the menu to the screan.
*/
void printMenu()
{
    printf("MENU: \n");
    printf("----------\n");
    printf("Enter 1 to insert a new student\n");
    printf("Enter 2 to delete student\n");
    printf("Enter 3 to update student details\n");
    printf("Enter 4 to show student details\n");
    printf("Enter 5 to show the 10'th first students of specific course\n");
    printf("Enter 6 to show the students that have to be excelled from school\n");
    printf("Enter 7 to show the average of a specific courese\n");
    printf("Enter 8 to import data to DB\n");
    printf("Enter 0 to exit\n\n");
}


int main()
{
    int choise = -1;
    School_t* school = readFile();

    while (choise != 0)
    {
        printMenu();
    }

    for (int i = 0; i < 12; ++i)
        freeLayer(school->layers[i]);
    free(school);

    return 0;
}