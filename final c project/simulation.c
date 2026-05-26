#include "structs.h"
#include "Simulation.h"
void run_simulation(char* file_name, int shift)
{
	int num_analyst = 0;
	double curr_time = 0.0;
	Node* head = NULL;
	FILE* file = fopen(file_name, "r");
	if (file == NULL) 
	{
		system("cls");
		printf("ERROR! could not open file: %s\n", file_name);
		return;
	}	
	switch (shift) 
	{
	case 1:
		printf("======================================================\n");
		printf("    Starting the simulation - Routine Morning Shift\n");
		printf("======================================================\n");
		break;
	case 2: 
		printf("======================================================\n");
		printf("    Starting the simulation - Quiet Night Shift\n");
		printf("======================================================\n");
		break;
	case 3:
		printf("======================================================\n");
		printf("    Starting the simulation - Active Cyber Attack\n");
		printf("======================================================\n");
		break;
	}
	fscanf_s(file, "%d", &num_analyst);
	Attack** analysts = (Attack**)malloc(num_analyst * sizeof(Attack*));//amount of analysts
	int* attacks = (int*)malloc(6* sizeof(int));




	fclose(file);
}