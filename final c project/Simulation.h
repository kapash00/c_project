#pragma once
#include "Structs.h"
void run_simulation(char* file_name,int shift);
int** create_matrix_and_arry(FILE*file,int size, Analyst** ptrtoarr);
int find_analyst(Analyst* analysts, int num_analysts, double current_time);
Event create_closing_event(Event current_event,int analyst_id , Analyst * analysts,double current_time);