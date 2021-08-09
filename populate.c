#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "Entity.h"

struct node *  populate(int population, ...){

    va_list ap;
    struct node * root_entity;
    int counter = ZERO;

    char* first_name;
    char* last_name;

    va_start(ap, population);

    first_name = va_arg(ap, char *); 
    last_name = va_arg(ap, char *);

    if(first_name == NULL || last_name == NULL){
        return NULL; 
    }

    root_entity = new_node(first_name, last_name, counter++);


    while(counter < population){  
        first_name = va_arg(ap, char *);
        last_name = va_arg(ap, char *);

        struct node * temp = new_node(first_name, last_name, counter);
        insert(root_entity, temp);

        ++counter;
    }
    va_end(ap);

    return root_entity; 
}
