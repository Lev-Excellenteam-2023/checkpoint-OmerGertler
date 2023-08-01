#include "School.h"
#include <stdlib.h>
#include <stdio.h>

School_t * createSchool(char* sname)
/*
    School c-tor.
*/
{
    School_t* school;
    school = (School_t*)malloc(sizeof(School_t));

    strncpy(school->_name, sname, 50);
     
    return school;
}
