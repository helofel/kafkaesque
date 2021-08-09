#include "Entity.h"

int main(int argc, char** argv){
    char first_name_one[5] = {'J', 'O','H','N','\0'};
    char last_name_one[7] = {'M','W','A','U','R','A','\0'};
    char first_name_two[6] = {'M','O','S','E','S','\0'};
    char last_name_two[7] = {'M','W','A','U','R','A','\0'};
 
    inorder(populate(2, &first_name_one, &last_name_one, &first_name_two, &last_name_two));

    return 0;
}
