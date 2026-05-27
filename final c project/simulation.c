#include "structs.h"
#include "Simulation.h"
void run_simulation(char* file_name, int shift)
{
	double max_sim_time = 480.0;
	int ticket_counter = 1;
	int num_analyst = 0;
	double current_time = 0.0;
	Node* head = NULL;
	FILE* file = fopen(file_name, "r");
	if (file == NULL) 
	{
		system("cls");
		printf("ERROR! could not open file: %s\n", file_name);
		return;
	}	
	system("cls");
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
	//Log file
	FILE* log_file = fopen("Simulation_Log.txt", "w+");
	if (log_file == NULL) 
	{
		printf("Error creating log file!\n");
		return;
	}

	fscanf_s(file, "%d", &num_analyst);
	//build matrix
	Analyst* analysts=NULL;
	int** stats_matrix = create_matrix_and_arry(file, num_analyst, &analysts);
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
	Event current_event;
	while (head != NULL && current_time <= max_sim_time) 
	{
		current_event = pop_event(&head);
		current_time = current_event.start_time;
		if (current_event.event_type == event_log_arrival) 
		{
			int analyst_id = find_analyst(analysts, num_analyst, current_time);
			Event completion_event = create_closing_event(current_event, analyst_id, analysts, current_time);
			insert_event(&head, completion_event);
			printf("[Time: %06.2f] ALARM: Ticket %d (Type: %d) assigned to Analyst %s.\n",
				current_time, current_event.ticket_id, current_event.attack_type, analysts[analyst_id].name);

			fprintf(log_file, "[Time: %06.2f] ALARM: Ticket %d (Type: %d) assigned to Analyst %s.\n",
				current_time, current_event.ticket_id, current_event.attack_type, analysts[analyst_id].name);
		}
		else if (current_event.event_type == event_closed) 
		{
			int curr_attack = current_event.attack_type;
			stats_matrix[current_event.assigned_analyst_id][curr_attack]++;
			printf("[Time: %06.2f] RESOLVED: Ticket %d was closed by Analyst %s.\n",
				current_time, current_event.ticket_id, analysts[current_event.assigned_analyst_id].name);

			fprintf(log_file, "[Time: %06.2f] RESOLVED: Ticket %d was closed by Analyst %s.\n",
				current_time, current_event.ticket_id, analysts[current_event.assigned_analyst_id].name);
		}
	}
}


int** create_matrix_and_arry(FILE* file, int size, Analyst** ptrtoarr)
{
	Analyst* analysts = (Analyst*)malloc(size * sizeof(Analyst));
	for (int i = 0; i < size; i++)
	{
		fscanf_s(file, "%s", analysts[i].name, (unsigned)sizeof(analysts[i].name));
		analysts[i].analyst_id = i;
		analysts[i].available_at = 0.0;
	}
	*ptrtoarr = analysts;
	int** stats_matrix = (int**)malloc(size * sizeof(int*));//amount of analysts
	for (int i = 0; i < size; i++)
	{
		stats_matrix[i] = (int*)calloc(7, sizeof(int));
	}
	return stats_matrix;
}
//find the best analst - the one whos not busy soon
int find_analyst(Analyst* analysts, int num_analysts, double current_time)
{
	int best_id = 0;
	double min_time = analysts[0].available_at;

	for (int i = 1; i < num_analysts; i++)
	{
		if (analysts[i].available_at < min_time)
		{
			min_time = analysts[i].available_at;
			best_id = i;
		}
	}

	return best_id;
}
//creating closing ticket
Event create_closing_event(Event current_event, int analyst_id, Analyst* analysts, double current_time)
{
	double start_service_time;
	double service_time = (rand() % 16) + 5.0;
	if (current_time >= analysts[analyst_id].available_at) 
		start_service_time = current_time;
	else
		start_service_time = analysts[analyst_id].available_at;//when the first analyst is not busy
	analysts[analyst_id].available_at = start_service_time + service_time;
	Event completion_event;
	completion_event.ticket_id = current_event.ticket_id;
	completion_event.attack_type = current_event.attack_type;
	completion_event.event_type = event_closed;
	completion_event.start_time = analysts[analyst_id].available_at;
	completion_event.assigned_analyst_id = analyst_id;
	return completion_event;
}