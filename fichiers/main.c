#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "t_skill.h"
#include "t_individual.h"
#include "population.h"
 
int main(void) {
     
    printf("Generation population and mutation :\n");
    printf("1 - Generate optimal solution :\n");
    t_individual * solution = setSolution(
            "0101111011101011011011010000000001111110000000000111111111100000");
    toString(solution);
 
    // Create an initial population
    int nbIndividualInPopulation = 50;
    t_population * population = createPopulation(nbIndividualInPopulation,
            true);
 
    printf("Create population :\n");
    int i = 0;
    for (; i < nbIndividualInPopulation; i++) {
        getCompetence(population->element[i], solution);
    }
 
    int generationCount = 0;
    t_individual * entity = getMoreCompetent(population, solution);
 
    // Evolve our population until we reach an optimum solution
    while (entity->competence < getMaxSkill()) {
        generationCount++;
        printf("generation : %i competence %i\n", generationCount,
                entity->competence);
        population = evolvePopulation(population, solution);
        //printf("Computation entity done\n");
        entity = getMoreCompetent(population, solution);
    }
    printf("Solution found ! \n");
    printf("The number of generation is %i\n", generationCount);
    entity = getMoreCompetent(population, solution);
    printf("Our solution : ");
    toString(entity);
    printf("The solution : ");
    toString(solution);
 
    return 0;
}
