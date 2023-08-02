# pragma once
# include"Class.h"

struct Layer_t
{
    Class_t *classes[10];
}typedef Layer_t;


Layer_t* createLayer();

void freeLayer(Layer_t* layer);

