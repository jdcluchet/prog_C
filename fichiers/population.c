#include <stdlib.h>
#include "..\headers\t_individual.h"
#include "..\headers\population.h"
 
/*
 * Constructor
 */
// Create a population
t_population * createPopulation(int populationSize, t_bool initialise) {
 
    t_population * population = malloc(sizeof(t_individual) * populationSize);
 
    // Initialise population
    if (initialise == true) {
        // Loop and create individuals
        int i = 0;
        t_bool doRand = true;
        for (; i < populationSize; i++) {
            t_individual * newIndividual = generateIndividual(64, doRand);
            doRand = false;
            population->element[i] = newIndividual;
        }
    }
    return population;
}
 
// Get population size
int sizePopulation(t_population * population) {
    return 50;
}
 
t_individual * getIndividual(t_population * population, int index) {
    return population->element[index];
}
 
t_individual * getMoreCompetent(t_population * population, t_individual * solution) {
    t_individual * moreCompetent = population->element[0];
    int i = 1;
    // Loop through individuals to find more competent
    for (; i < sizePopulation(population); i++) {
        if (getCompetence(moreCompetent,solution)  <= getCompetence(getIndividual(population, i), solution)) {
            moreCompetent = getIndividual(population, i);
        }
    }
    return moreCompetent;
}
 
t_individual * getMoreCompetentTournamant(t_population * population, t_individual * solution) {
    t_individual * moreCompetent = population->element[0];
    int i = 1;
    // Loop through individuals to find more competent
    for (; i < 5; i++) {
        if (getCompetence(moreCompetent,solution)  <= getCompetence(getIndividual(population, i), solution)) {
            moreCompetent = getIndividual(population, i);
        }
    }
    return moreCompetent;
}
