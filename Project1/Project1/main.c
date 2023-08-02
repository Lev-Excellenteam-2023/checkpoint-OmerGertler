#include "School.h"
#include <stdio.h>
#include <stdlib.h>


School_t * school;

enum menu_inputs {
    Insert = '0',
    Delete = '1',
    Edit = '2',
    Search = '3',
    Showall = '4',
    Top10 = '5',
    UnderperformedStudents = '6',
    Average = '7',
    Export = '8',
    Exit = '9'
};

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

    printf("Insert First Name:\n");
    scanf("%19s", firstName);  //scanf("%19", firstName, sizeof(firstName));
    printf("Insert Last Name:\n");
    scanf("%19s", lastName);
    printf("Insert Phone Number:\n");
    scanf("%19s", phoneNumber);
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


void deleteStudent(School_t* school)
{
    Student_t* it = findStudentByName(school);

    Student_t* tmp;
    tmp = it->next;
    it->next = tmp->next;
    free(tmp);
    printf("Student deletes successfuly\n");
}


void editStudentGrade(School_t* school)
{
    int number, grade;
    Student_t* student = findStudentByName(school);
    printf("Enter course number (1-10): \n");
    scanf("%d", &number);
    printf("Enter new grade (0-100): \n");
    scanf("%d", &grade);

    student->grades[number] = grade;
}


void searchStudent(School_t* school)
{
    Student_t* student = findStudentByName(school);
    printStudent(student);
}


Student_t* findStudentByName(School_t* school)
{
    char firstName[20];
    char lastName[20];
    printf("Insert First Name: %s\n", firstName);
    fgets(firstName, sizeof(firstName), stdin);
    printf("Insert Last Name: %s\n", lastName);
    fgets(lastName, sizeof(lastName), stdin);

    Student_t* it;
    int found = 0;
    for (int i = 0; i < 12 && found == 0; ++i)
    {
        for (int j = 0; j < 10 && found == 0; ++j)
        {
            it = school->layers[i]->classes[j]->students;
            if (strcmp(it->next->_firstName, firstName) == 0 && strcmp(it->next->_lastName, lastName) == 0) // names are equal
            {
                found == 1;
            }
        }
    }
    if (found == 0)
        printf("This student is not exist\n");
    return it;
}


void printAllStudents(School_t* school)
{
    printSchool(school);
}


void printTopNStudentsPerCourse(School_t* school)
{
    int layerIndex, course;
    Student_t* student = findStudentByName(school);
    printf("Enter layer number (1-12): \n");
    scanf("%d", &layerIndex);
    printf("Enter course index (1-10): \n");
    scanf("%d", &course);

    Layer_t* layer = school->layers[layerIndex];
    Student_t* students[10];
    int topIndex = 0, lowIndex = 0;

    for (int i = 0; i < 10; ++i)
    {
        Student_t* it = layer->classes[i]->students;
        while(it =! NULL)
        {

        }
    }
}


/*
* Print the menu to the screan.
*/
void printMenu()
{
    printf("\n|School Manager<::>Home|\n");
    printf("--------------------------------------------------------------------------------\n");
    //printf("Welcome to ( %s ) School!\nYou have inserted ( %zu ) students.\n\n", school.name, school.numOfStudents);
    printf("\t[0] |--> Insert\n");
    printf("\t[1] |--> Delete\n");
    printf("\t[2] |--> Edit\n");
    printf("\t[3] |--> Search\n");
    printf("\t[4] |--> Show All\n");
    printf("\t[5] |--> Top 10 students per course\n");
    printf("\t[6] |--> Underperformed students\n");
    printf("\t[7] |--> Average per course\n");
    printf("\t[8] |--> Export\n");
    printf("\t[9] |--> Exit\n");
    printf("\n\tPlease Enter Your Choice (0-9): ");
}


int main()
{
    School_t* school = readFile();

    char input;
    do {
        printMenu();
        input = getc(stdin);
        fflush(stdin);
        getc(stdin);
        switch (input) {
        case Insert:
            insertNewStudent(school);
            break;
        case Delete:
            deleteStudent(school);
            break;
        case Edit:
            editStudentGrade(school);
            break;
        case Search:
            searchStudent(school);
            break;
        case Showall:
            printAllStudents(school);
            break;
        case Top10:
            printTopNStudentsPerCourse(school);
            break;
        case UnderperformedStudents:
            //printUnderperformedStudents(school);
            break;
        case Average:
            //printAverage(school);
            break;
        case Export:
            //exportDatabase(school);
            break;
        case Exit:
            //handleClosing(school);
            break;
        default:
            printf("\nThere is no item with symbol \"%c\".Please enter a number between 1-10!\nPress any key to continue...",
                input);
            getc(stdin);
            getc(stdin);
            break;
        }
    } while (input != Exit);

    for (int i = 0; i < 12; ++i)
        freeLayer(school->layers[i]);
    free(school);

    return 0;
}