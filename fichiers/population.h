#ifndef HEADERS_POPULATION_H_
#define HEADERS_POPULATION_H_
 
#include "t_individual.h"
#include "population.h"
 
 
typedef struct {
    t_individual * element[50];
} t_population;
 
t_population * createPopulation(int populationSize, t_bool initialise);
t_individual * getIndividual(t_population * population, int index);
t_individual * getMoreCompetent(t_population *population, t_individual *solution);
int sizePopulation(t_population *population);
void saveIndividual(int index, t_individual individual);
t_individual * getMoreCompetentTournamant(t_population * population, t_individual * solution);
 
 
#endif /* HEADERS_POPULATION_H_ */
