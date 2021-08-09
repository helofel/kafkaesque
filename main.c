#include <stdio.h>
#include <stdlib.h>
#include "Entity.h"

int main(int argc, char** argv){


 /* char conchita_f[] = "Conchita";
    char conchita_l[] = "Bowling";
    char flem_f[] = "Flem";
    char flem_l[] = "Taree";
    char saxe_f[] = "Saxe";
    char saxe_l[] = "Greguol";
    char clement_f[] = "Clement";
    char clement_l[] = "Vennard";
    char merralee_f[] = "Merralee";
    char merralle_l[] = "Sleath";
    char alexis_f[] = "Alexis";
    char alexis_l[] = "Pharoah";
    char delmor_f[] = "Delmor"; 
    char delmor_l[] = "Stidston";
    char meris_f[] = "Meris";
    char meris_l[] = "Bracknall";
    char avrit_f[] = "Avrit"; 
    char avrit_l[] = "Braidford";*/
    char brocky_f[] = "Brocky";
    char brocky_l[] = "Brockton";
    char paulette_f[] = "Paulette";
    char paulette_l[] = "McCarney";
    char evelyn_f[] = "Evelyn";
    char evelyn_l[] = "Merit";
    char bil_f[] = "Bil";
    char bil_l[] = "Bassam";
    char linus_f[] = "Linus";
    char linus_l[] = "MacKettrick";
    char dionysus_f[] = "Dionysus";
    char dionysus_l[] = "Attwoul";

    char ruby_f[] = "Ruby";
    char ruby_l[] = "Caffery";
    char zita_f[] = "Zita";
    char zita_l[] = "Bremley";
    char sophey_f[] = "Sophey";
    char sophey_l[] = "Sacco";
    char nikolos_f[] = "Nikolos";
    char nikolos_l[] = "Vedyaev";
    char coretta_f[] = "Coretta";
    char coretta_l[] = "Stute";
    char leupold_f[] = "Leupold";
    char leupold_l[] = "Dodshun";

    struct node * root_entity = populate(
            12, &leupold_f, &leupold_l, 
            &coretta_f, &coretta_l, 
            &nikolos_f, &nikolos_l, 
            &sophey_f, &sophey_l, 
            &zita_f, &zita_l, 
            &ruby_f, &ruby_l,
            &dionysus_f, &dionysus_l,
            &linus_f, &linus_l,
            &bil_f, &bil_l,
            &evelyn_f, &evelyn_l,
            &paulette_f, &paulette_l,
            &brocky_f, &brocky_l);

    inorder(root_entity);

    free(root_entity);

    return 0;
}
