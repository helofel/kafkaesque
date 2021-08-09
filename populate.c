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

    printf("Set root\n");

    //while(first_name != NULL && last_name != NULL){
    while(counter < population){  
        first_name = va_arg(ap, char *);
        last_name = va_arg(ap, char *);

        insert(root_entity, new_node(first_name, last_name, counter));

        printf("inserted new node\n");
        ++counter;
    }
    va_end(ap);

    if(counter != population - 1){
        return NULL;
    }
    return root_entity; 
}
