#include <stdio.h>
#include <unistd.h>
#include "Entity.h"
#include <fcntl.h>

FILE * setup_document(char * data_file){
    int data_file_fd = open(data_file, O_CREAT | O_RDWR | O_APPEND | O_TRUNC, S_IRWXU);
    FILE *fp = fdopen(data_file_fd, "a+");    
    return fp;
}

void inorder(struct node * root, FILE * fp)
{
    if(root != NULL) // checking if the root is not null
    {
        inorder(root->left_child, fp); // visiting left child
        printf(" First name: %s \n", root -> data -> first_name);
        printf(" Last name:  %s \n", root -> data -> last_name);
        printf(" Age:        %d \n", root -> data -> age);
        printf(" Gender:     %s \n", root -> data -> gender);
        printf(" ID:         %ld \n", root -> data -> system_id); // printing data at root
        printf("\n");
        fprintf(fp, "%s,%s,%d,%s,%ld\n", root -> data -> first_name, root -> data -> last_name, root -> data -> age, root -> data -> gender, root -> data -> system_id);
        inorder(root->right_child, fp);// visiting right child
    }
}

