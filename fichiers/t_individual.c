#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
 
#include "..\headers\t_individual.h"
#include "..\headers\t_skill.h"
#include "..\headers\t_bool.h"
 
 
int defaultGeneLength = 64;
t_bool randomAlreadyDone = false;
int competence = 0;
 
// Create a random individual
t_individual * generateIndividual(int size, t_bool doRand) {
 
    if (doRand == true) {
        srand(time(NULL));
    }
 
    //generate the individual
    t_individual * new_arr = malloc(sizeof(t_individual));
    int i = 0;
    for (; i < size; i++) {
        new_arr->gene[i] = (int)rand() % 2;
    }
    new_arr->competence = 0;
    return new_arr;
}
 
/* Getters and setters */
// Use this if you want to create individuals with different gene lengths
void setDefaultGeneLength(int length) {
    defaultGeneLength = length;
}
 
int getGene(t_individual *individual, int index) {
    return individual->gene[index];
}
 
void setGene(t_individual *individual, int index, int value) {
    individual->gene[index] = value;
    individual->competence = 0;
}
 
int sizeIndividual(t_individual *individual) {
    //return sizeof(individual->gene) / sizeof (int);
    return 64;
}
 
int getCompetence(t_individual * individual, t_individual * solution) {
    //if (individual->competence == 0) {
        individual->competence = getSkill(individual, solution);
    //}
    return individual->competence;
}
 
void toString(t_individual *individual) {
    int i = 0;
    for (; i < (sizeof(individual->gene) / sizeof(int)); i++) {
        printf("%i", individual->gene[i]);
    }
    printf("\n");
}
