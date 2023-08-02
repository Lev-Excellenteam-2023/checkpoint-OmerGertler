# pragma once
# include"Layer.h"

struct School_t
{
    Layer_t *layers[12];
    char _name[50];
} typedef School_t;

School_t* createSchool(char* name);
