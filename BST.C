#include <stdio.h>
#include <stdlib.h>
#include "Entity.h"

/*
   struct node
   {
   int data; //node will store an integer
   struct node *right_child; // right child
   struct node *left_child; // left child
   };
   */


struct node * search(struct node * root, int id)
{
    if(root==NULL || root -> data -> system_id==id) //if root->data is x then the element is found
        return root;
    else if(id > root->data -> system_id) // x is greater, so we will search the right subtree
        return search(root->right_child, id);
    else //x is smaller than the data, so we will search the left subtree
        return search(root->left_child, id);
}

//function to find the minimum value in a node
struct node * find_minimum(struct node * root)
{
    if(root == NULL)
        return NULL;
    else if(root -> left_child != NULL) // node with minimum value will have no left child
        return find_minimum(root -> left_child); // left most element will be minimum
    return root;
}

//function to create a node
struct node * new_node(char * first_name, char * last_name, int id)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p -> data = malloc(sizeof(Entity));
    p -> data -> first_name = first_name;
    p -> data -> last_name = last_name;
    p -> data -> system_id = id;
    p -> left_child = NULL;
    p -> right_child = NULL;

    return p;
}

struct node * insert(struct node * root, struct node * node)
{
    //searching for the place to insert
    if(root == NULL)
        return new_node(NULL, NULL, -1);
    else if(node -> data -> system_id > root -> data -> system_id) // x is greater. Should be inserted to right
        root -> right_child = insert(root -> right_child, node);
    else // x is smaller should be inserted to left
        root -> left_child = insert(root -> left_child, node);
    return root;
}

// funnction to delete a node
struct node* delete_node(struct node * root, int x)
{
    //searching for the item to be deleted
    if(root == NULL)
        return NULL;
    if (x > root -> data -> system_id)
        root->right_child = delete_node(root->right_child, x);
    else if(x < root -> data -> system_id)
        root->left_child = delete_node(root->left_child, x);
    else
    {
        //No Children
        if(root->left_child == NULL && root->right_child == NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete_node(root->right_child, temp -> data -> system_id);
        }
    }
    return root;
}

/*
void inorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        inorder(root->left_child); // visiting left child
        printf(" %ld ", root -> data -> system_id); // printing data at root
        inorder(root->right_child);// visiting right child
    }
}








   int main()
   {

   20
   /    \
   /      \
   5       30
   /   \     /\
   /     \   /  \
   1      15 25  40
   /          \
   /            \
   9             45
   /   \          /
   /     \        /
   7      12      42

   struct node *root;
   root = new_node(20);
   insert(root,5);
   insert(root,1);
   insert(root,15);
   insert(root,9);
   insert(root,7);
   insert(root,12);
   insert(root,30);
   insert(root,25);
   insert(root,40);
   insert(root, 45);
   insert(root, 42);

   inorder(root);
   printf("\n");

   root = delete(root, 1);

   20
   /    \
   /      \
   5       30
   \     /\
   \   /  \
   15 25   40
   /           \
   /             \
   9              45
   /   \           /
   /     \         /
   7      12       42


   root = delete(root, 40);

   20
   /    \
   /      \
   5       30
   \     /\
   \   /  \
   15 25  45
   /       / 
   /       /   
   9       42    
   /   \          
   /     \        
   7      12      


   root = delete(root, 45);

20
/    \
        /      \
        5       30
        \     /\
            \   /  \
            15 25  42
            /          
            /            
            9            
            /   \          
            /     \        
            7      12      

            root = delete(root, 9);
            inorder(root);

            20
            /    \
                /      \
                5       30
                \     /\
                    \   /  \
                    15 25  42
                    /          
                    /            
                    12            
                    /             
                    /             
                    7            

                    printf("\n");

                    return 0;
                    } 
*/
