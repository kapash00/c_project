#include "Structs.h"
void insert_event(Node** head, Event new_event) 
{
	Node* n1 = (Node*)malloc(sizeof(Node));
	n1->data = new_event;
	n1->next = NULL;
	if (*head == NULL || (*head)->data.start_time > new_event.start_time) 
	{
		n1->next = *head;
		*head = n1;
		return;
	}
	Node* current = *head;
	while (current->next != NULL && current->next->data.start_time <= new_event.start_time) {
		current = current->next;
	}
	n1->next = current->next;
	current->next = n1;
}
Event pop_event(Node** head) {
	Node* temp = *head;
	Event extracted_event = temp->data;
	*head = (*head)->next;
	free(temp);

	return extracted_event;
}