#include "Layer.h"
#include <stdlib.h>
#include <stdio.h>

/*
    layer c-tor.
*/
Layer_t* createLayer()
{
    Layer_t* layer;
    layer = (Layer_t*)malloc(sizeof(Layer_t));

    for (int i = 0; i < 10; ++i)
    {
        struct Class_t* newClass = createClass();
        layer->classes[i] = newClass;
    }

    return layer;
}


/*
    layer d-tor.
*/
void freeLayer(Layer_t* layer)
{
    for (int i = 0; i < 10; ++i)
        freeClass(layer->classes[i]);
    free(layer);
}
