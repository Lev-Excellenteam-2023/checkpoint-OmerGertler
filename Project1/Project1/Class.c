#include "Class.h"
#include <stdio.h>
#include <stdlib.h>

Class_t* createClass()
/*
    class c-tor.
*/
{
    Class_t* newClass;
    newClass = (Class_t*)malloc(sizeof(Class_t));
    newClass->students = NULL;
    return newClass;
}


/*
    class d-tor.
*/
void freeClass(Class_t* _class)
{
    freeStudent(_class->students);
    free(_class); 
}
