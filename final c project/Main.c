#include <stdio.h>
#include <stdlib.h>
int main() 
{
	int choice;
	puts(" === Enter 1 start the simulation===\n         ===0 to exit===\n");
	scanf_s("%d",&choice);
	while (choice) 
	{
		system("cls");
		puts(" === Enter 1 start the simulation===\n         ===0 to exit===\n");
		scanf_s("%d", &choice);
	}
}