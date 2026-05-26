#include "Menu.h"
#include "Simulation.h"
int main()
{
	int shift_type;
	int choice = start_menu(&shift_type);
	while (choice) 
	{
		if (shift_type == 1) 
		{
			run_simulation("Normal_Morning_Shift.txt",1);
		}
		if (shift_type == 2) 
		{
			run_simulation("Quiet_Night_Shift.txt",2);
		}
		if (shift_type == 3) 
		{
			run_simulation("Active_Cyber_Attack.txt",3);
		}
		choice = start_menu(&shift_type);

	}
}