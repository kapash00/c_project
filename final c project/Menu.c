#include <stdio.h>
#include <stdlib.h>
int start_menu(int* shift_type) 
{
	int start_sim;
	printf("======================================================\n");
	printf("               SOC SIMULATION SYSTEM                 \n");
	printf("         To start a simulation enter any number \n                  To Exit press 0\n");
	printf("======================================================\n>>");	
	scanf_s("%d", &start_sim);
	if (start_sim == 0)
		return 0;
	do
	{
		system("cls");
		printf("======================================================\n");
		printf("    Please select a shift scenario to simulate:\n");
		printf("======================================================\n");
		printf("||        [1] Routine Morning Shift                  ||\n");
		printf("||          (3 Analysts - Normal Load)               ||\n");
		printf("||                                                   ||\n");
		printf("||        [2] Quiet Night Shift                      ||\n");
		printf("||          (1 Analyst - Low Load)                   ||\n");
		printf("||                                                   ||\n");
		printf("||        [3] Active Cyber Attack                    ||\n");
		printf("||          (2 Analysts - Extreme Load)              ||\n");
		printf("======================================================\n\n>>");
		scanf_s("%d", shift_type);
	}
	while (*shift_type < 1 || *shift_type > 3);
	return 1;

}