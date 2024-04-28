#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

void progLogic();
void printHelp();
void initTable ();
void initSetters ();
static void gradeToRemarks(float grade);
void setGradeToUnits(float grade[], float gToUnits[], int size);
float calculateGWA(float gradeUnits[], float units[], int size);
int getOption();



#endif
