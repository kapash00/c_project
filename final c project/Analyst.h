#pragma once
typedef struct Analyst 
{
	int analyst_id;
	int is_avaliable;
	int event_count;
	struct Ticket* current_ticket;
}Analyst;