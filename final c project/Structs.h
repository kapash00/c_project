#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>
//analyst
typedef struct Analyst
{
	int analyst_id;
	char name[50];
	int is_avaliable;
	int event_count;
	struct Ticket* current_ticket;
}Analyst;
//event
typedef struct Event
{
	double start_time;
	int ticket_id;
	int status;
	int attack_type;
}Event; 
//node
typedef struct Node
{
	Event data;
	struct node* next;
}Node;
//ticket
typedef enum  { Open , In_progress, Closed }Status;//אפשר להשתמש בהנחיות קדם מעבד במקום
typedef enum  { Phishing, Malware, BruteForce, Ransomware, DDoS, FalsePostive}Attack;//אפשר להשתמש בהנחיות קדם מעבד במקום
typedef struct Ticket {
	int ticket_id;
	double service_time;
	Attack attack_type;
	Status status;
	char description[100];
} Ticket;