#include <stdio.h>
#include <stdlib.h>
#include "Entity.h"

int main(int argc, char** argv){

    /*----------------------------------------------------------------------------------*/
    char brocky_f[] = "Brocky";
    char brocky_l[] = "Brockton";
    int brocky_a = 21;
    char brocky_g[] = "MALE";

    char paulette_f[] = "Paulette";
    char paulette_l[] = "McCarney";
    int paulette_a = 16;
    char paulette_g[] = "FEMALE";

    char evelyn_f[] = "Evelyn";
    char evelyn_l[] = "Merit";
    int evelyn_a = 18;
    char evelyn_g[] = "FEMALE";

    char bil_f[] = "Bil";
    char bil_l[] = "Bassam";
    int bil_a = 56;
    char bil_g[] = "MALE";

    char linus_f[] = "Linus";
    char linus_l[] = "MacKettrick";
    int linus_a = 70;
    char linus_g[] = "MALE";

    char dionysus_f[] = "Dionysus";
    char dionysus_l[] = "Attwoul";
    int dionysus_a = 26;
    char dionysus_g[] = "MALE";

    char ruby_f[] = "Ruby";
    char ruby_l[] = "Caffery";
    int ruby_a = 14;
    char ruby_g[] = "FEMALE";

    char zita_f[] = "Zita";
    char zita_l[] = "Bremley";
    int zita_a = 32;
    char zita_g[] = "FEMALE";

    char sophey_f[] = "Sophey";
    char sophey_l[] = "Sacco";
    int sophey_a = 28;
    char sophey_g[] = "FEMLAE";

    char nikolos_f[] = "Nikolos";
    char nikolos_l[] = "Vedyaev";
    int nikolos_a = 66;
    char nikolos_g[] = "MALE";

    char coretta_f[] = "Coretta";
    char coretta_l[] = "Stute";
    int coretta_a = 22;
    char coretta_g[] = "FEMALE";

    char leupold_f[] = "Leupold";
    char leupold_l[] = "Dodshun";
    int leupold_a = 26;
    char leupold_g[] = "MALE";

    /*------------------------------------------------------------------------------------*/




    struct node * root_entity; 

    FILE * fp = setup_document("DATA.csv");

    int auto_populate; 
    char first_name[10];
    char last_name[10];
    int age;
    char gender[8];
    //ID; 
    int done = 1;

    if(fp == NULL){
        printf("Document was not found or created");
    }

    printf("Enter 1 to auto-populate...");
    scanf("%d", &auto_populate);

    if(auto_populate == 1){
        root_entity =  populate(
                12, &leupold_f, &leupold_l, leupold_a, &leupold_g, 
                &coretta_f, &coretta_l, coretta_a, &coretta_g,
                &nikolos_f, &nikolos_l, nikolos_a, &nikolos_g,
                &sophey_f, &sophey_l, sophey_a, &sophey_g,
                &zita_f, &zita_l, zita_a, &zita_g,
                &ruby_f, &ruby_l, ruby_a, &ruby_g,
                &dionysus_f, &dionysus_l, dionysus_a, &dionysus_g,
                &linus_f, &linus_l, linus_a, &linus_g,
                &bil_f, &bil_l, &bil_a, bil_g,
                &evelyn_f, &evelyn_l, evelyn_a, &evelyn_g,
                &paulette_f, &paulette_l, paulette_a, &paulette_g,
                &brocky_f, &brocky_l, brocky_a, &brocky_g);

        inorder(root_entity, fp);
    } else {
        printf("**************************************\n");
        printf("**************************************\n");
        printf("*                                    *\n");
        printf("*                                    *\n");
        printf("*                                    *\n");
        printf("*                                    *\n");
        printf("*                                    *\n");
        printf("*                                    *\n");
        printf("***************FORMAT*****************\n");
        printf("*First Name                          *\n");
        printf("*Last  Name                          *\n");
        printf("*Age                                 *\n");
        printf("*Gender                              *\n");
        printf("*EXIT PROGRAM  [ENTER 0]             *\n");
        printf("**************************************\n");
        printf("**************************************\n");


        while(done == 1){
            printf("First  name::");
            scanf("%s", first_name);
            printf("  Last name::");
            scanf("%s", last_name);
            printf("        Age::");
            scanf("%d", &age);
            printf("     Gender::");
            scanf("%s", gender);
            printf("\n\nEnter 0 to exit::");
            scanf("%d", &done);

            root_entity = populate(1, &first_name, &last_name, age, &gender);
            inorder(root_entity, fp);
            if(done == 0){
                return 0; 
            }    
        }
    }

    free(root_entity);

    return 0;
}
