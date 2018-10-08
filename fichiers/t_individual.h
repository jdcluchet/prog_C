#ifndef HEADERS_T_INDIVIDUAL_H_
#define HEADERS_T_INDIVIDUAL_H_
 
#include "t_bool.h"
 
 
typedef struct {
    int gene[64];
    int competence;
} t_individual;
 
t_individual * generateIndividual(int size, t_bool doRand);
void setDefaultGeneLength(int length);
int getGene(t_individual *individual, int index);
void setGene(t_individual *individual, int index, int value);
int sizeIndividual(t_individual *individual);
int getCompetence(t_individual *individual, t_individual *solution);
void toString(t_individual * individual);
 
 
 
#endif /* HEADERS_T_INDIVIDUAL_H_ */


