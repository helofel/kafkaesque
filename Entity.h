#include <stdbool.h>
#include <unistd.h>

#ifndef ENTITY_H
#define ENTITY_H

#define ZERO 0

typedef struct {
    char* first_name;
    char* last_name;
    int age;
    char * gender;
    long system_id;
    
    bool has_shelter;
    bool has_food;
    bool has_healthcare;
    bool has_pet;
    bool has_clothing;
    bool has_hygiene_items; 
    bool connected; 
} Entity;


struct node
{
    Entity* data;  //node will store a entity
    struct node *right_child; // right child
    struct node *left_child; // left child
};

typedef struct {
    char** address; 
} Housing;

typedef struct {
    char** food;
    time_t consumption_date;
} Food;

typedef struct {
    bool active;
    char* healthcare;
    time_t start_date;
    time_t end_date;
} HealthCare;

typedef struct {
    bool needs_food; 
    bool active_insurance;
    char* breed;
    int age;
    int weight;
} Pet; 

typedef struct {
    char** clothes;
} Clothing;

typedef struct {
    char** items;
} Hygiene; 

typedef struct {
    char** device_id;
    bool is_active;
} Connection;

typedef struct {
    char** level; 
    bool enrolled; 
} Education; 

struct node * populate(int, ...);
struct node * search(struct node *, int);
struct node * find_minimum(struct node *);
struct node * new_node(char *, char *, int);
struct node * insert(struct node *, struct node *);
struct node * delete_node(struct node *, int);
void inorder(struct node *);

#endif
