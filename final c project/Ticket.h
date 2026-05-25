#pragma once
#define STATUS_OPEN 0
#define STATUS_IN_PROGRESS 1
#define STATUS_CLOSED 2
#define ATTACK_PHISHING 0
#define ATTACK_MALWARE 1
#define ATTACK_BRUTE_FORCE 2
typedef struct {
    int ticket_id;            
    double service_time;      
    int attack_type;           
    int status;               
    char description[100];   
    char resolution_text[150]; 
} Ticket;