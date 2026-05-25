#pragma once
#include "Event.h"
typedef struct Node 
{
	Event data;
	struct node* next;
}Node;