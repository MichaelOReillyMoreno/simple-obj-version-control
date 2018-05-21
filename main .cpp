
#include "Obj_record_manager.hpp"

using namespace Obj_version_control;

//solo compruebo  diferencias de tipos iguales

int main()
{
	Obj_record_manager obj_record_manager;
	obj_record_manager.Register_changes("../../assets/current_bridge.obj", "../../assets/init_bridge.obj");
	obj_record_manager.Restore_last_version("../../assets/init_bridge.obj");
	do 
	{
		cout << '\n' << "Press the Enter key to continue.";
	}
	while (cin.get() != '\n');

	return 0;
}