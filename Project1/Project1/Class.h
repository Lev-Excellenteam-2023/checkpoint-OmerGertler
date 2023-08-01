# pragma once
# include"Student.h"

struct Class_t
{
    struct Student_t *students;

} typedef Class_t;

Class_t* createClass();

void freeClass(Class_t* _class);
