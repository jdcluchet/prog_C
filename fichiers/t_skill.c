#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "..\headers\t_skill.h"
#include "..\headers\t_individual.h"
 
// To make it easier we can use this method to set our candidate solution
// with string of 0s and 1s
t_individual * setSolution(char * newSolution) {
    // Loop through each character of our string and save it in our byte
    // array
    t_individual * result = malloc(sizeof(t_individual));
 
    char to[1];
    int i = 0;
    for (; i < strlen(newSolution); i++) {
        to[0] = newSolution[i];
        if (to[0] == 49) {
            result->gene[i] = 1;
        } else {
            result->gene[i] = 0;
        }
    }
    return result;
}
 
// Compute skill by comparing it to our candidate solution
int getSkill(t_individual * individual, t_individual * solution) {
    int skill = 0;
    int i = 0;
    // Loop through our individuals genes and compare them to our candidates
    for (; i < sizeIndividual(individual) ; i++) {
        if (individual->gene[i] == solution->gene[i]) {
            skill++;
        }
    }
    return skill;
}
 
// Get optimum skill
int getMaxSkill() {
    return 64;
}
