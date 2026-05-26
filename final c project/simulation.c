#include "structs.h"
#include "Simulation.h"
void run_simulation(char* file_name, int shift)
{
	int ticket_counter = 1;
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
	Attack** stats_matrix = (Attack**)malloc(num_analyst * sizeof(Attack*));//amount of analysts
	for (int i = 0; i < num_analyst; i++) 
	{
		stats_matrix[i] = (int*)calloc(6 , sizeof(int));
	}
	double time;
	Attack attack;
	while (fscanf_s(file, "%lf %d", &time, &attack) != EOF) 
	{
		Event new_log;
		new_log.start_time = time;
		new_log.attack_type = attack;
		new_log.ticket_id = ticket_counter++;
		new_log.status = Open;
		new_log.event_type = event_log_arrival;
		insert_event(&head, new_log);
	}
	fclose(file);
	double max_sim_time = 480.0;
	while (head != NULL && curr_time < max_sim_time) 
	{
		Event current_event = pop_event(&head);
		curr_time = current_event.start_time;
	
	}
}
