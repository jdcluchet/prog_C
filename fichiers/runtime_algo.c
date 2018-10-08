#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "t_bool.h"
#include "t_individual.h"
#include "population.h"
 
/* GA parameters */
double uniformRate = 0.5;
double mutationRate = 0.00015;
int tournamentSize = 5;
t_bool elitism = true;
 
t_bool check(t_individual * solution) {
    int i = 0;
    if (solution == NULL) {
        printf(" ... NULL DETECTED ... ");
        return false;
    }
    for (; i < 64; i++) {
        if (solution->gene[i] != 1 && solution->gene[i] != 0) {
            printf("An individual is invalid (a gene not equals 1 or 0) : ");
            toString(solution);
            return false;
        }
    }
    return true;
}
 
// Select individuals for crossover
t_individual * tournamentSelection(t_population * pop, t_individual * solution) {
    // Create a tournament population
    t_population * tournament = malloc(sizeof(t_population)); // * sizeInd(pop));
    // For each place in the tournament get a random individual
    int i = 0;
    for (; i < tournamentSize; i++) {
        int randomId = (int) ((rand() % 50));
        tournament->element[i] = pop->element[randomId];
    }
    // Get the fittest
    t_individual * fittest = getMoreCompetentTournamant(tournament, solution);
    check(fittest);
    return fittest;
}
 
// Crossover individuals
t_individual * crossover(t_individual * indiv1, t_individual * indiv2) {
    t_individual * newSol = malloc(sizeof(t_individual));
    // Loop through genes
    int i = 0;
    for (; i < sizeIndividual(newSol); i++) {
        // Crossover
        if (rand() <= (RAND_MAX / 2)) {
            newSol->gene[i] = indiv1->gene[i];
        } else {
            newSol->gene[i] = indiv2->gene[i];
        }
    }
    return newSol;
}
 
// Mutate an individual
void mutate(t_individual * indiv) {
    int i = 0;
    // Loop through genes
    for (; i < sizeIndividual(indiv); i++) {
        int rvalue = rand();
        double value = rvalue * 0.0000001;
        if (value <= mutationRate) {
            if (indiv->gene[i] == 1) {
                indiv->gene[i] = 0;
            } else {
                indiv->gene[i] = 1;
            }
        }
    }
}
 
// Evolve a population
t_population * evolvePopulation(t_population * pop, t_individual * solution) {
    t_population * newPopulation = malloc(sizeof(t_population));
 
    // Keep our best individual
    if (elitism) {
        newPopulation->element[0] = getMoreCompetent(pop, solution);
        printf("Keep our best individual : ");
        toString(newPopulation->element[0]);
        printf("Searching a way for      : ");
        toString(solution);
    }
 
    // Crossover population
    int elitismOffset;
    if (elitism) {
        elitismOffset = 1;
    } else {
        elitismOffset = 0;
    }
    // Loop over the population size and create new individuals with
    // crossover
    int i = elitismOffset;
    for (; i < sizePopulation(pop); i++) {
        t_individual * indiv1 = tournamentSelection(pop, solution);
        t_individual * indiv2 = tournamentSelection(pop, solution);
        t_individual * newIndiv = crossover(indiv1, indiv2);
        newPopulation->element[i] = newIndiv;
    }
 
    i = elitismOffset;
    // Mutate population
    for (; i < sizePopulation(newPopulation); i++) {
        mutate(newPopulation->element[i]);
    }
 
    return newPopulation;
}
