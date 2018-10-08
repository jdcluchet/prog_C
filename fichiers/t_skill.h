#ifndef T_SKILL_H_
#define T_SKILL_H_
 
#include "t_individual.h"
 
// To make it easier we can use this method to set our candidate solution
// with string of 0s and 1s
t_individual * setSolution(char * newSolution);
 
// Compute skill by comparing it to our candidate solution
int getSkill(t_individual * individual, t_individual *solution);
// Get optimum skill
int getMaxSkill();
 
#endif /* HEADERS_T_SKILL_H_ */
