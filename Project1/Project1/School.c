#include "School.h"
#include <stdlib.h>
#include <stdio.h>

/*
    School c-tor.
*/
School_t * createSchool(char* sname)
{
    School_t* school = NULL;
    school = (School_t*)malloc(sizeof(School_t));

    for (int i = 0; i < 12; ++i)
    {
        struct Layer_t* layer = createLayer();
        school->layers[i] = layer;
    }
    strncpy(school->_name, sname, 50);
     
    return school;  
}


void printSchool(School_t* school)
{
    for (int i = 0; i < 12; ++i)
    {
        printf("Layer %d students:\n", i + 1);
        printLayer(school->layers[i]);
    }
}