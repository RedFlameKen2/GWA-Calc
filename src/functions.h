#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "class.h"


void deleteSubject(vector<Subject> &subjects);
void calculateGWA(vector<Subject> &subjects);
void calculateAveGrade(vector<Subject> &subjects);
void progLogic(vector<Subject> &subjects);
void printHelp();
void initTable (vector<Subject> &subjects);
int getOption();




#endif
