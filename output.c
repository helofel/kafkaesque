#include <stdio.h>
#include <unistd.h>
#include "Entity.h"


void inorder(struct node * root)
{
    if(root != NULL) // checking if the root is not null
    {
        inorder(root->left_child); // visiting left child
        printf(" First name: %s \n", root -> data -> first_name);
        printf(" Last name:  %s \n", root -> data -> last_name);
        printf(" Age:        %d \n", root -> data -> age);
        printf(" Gender:     %s \n", root -> data -> gender);
        printf(" ID:         %ld \n", root -> data -> system_id); // printing data at root
        printf("\n");
        inorder(root->right_child);// visiting right child
    }
}
