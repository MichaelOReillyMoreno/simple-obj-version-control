#include "Obj_Record_manager.hpp"
#include <memory>

namespace Obj_version_control
{
	int Obj_record_manager::Get_num_prev_version(string & file_name)
	{
		int num_prev_version = 0;

		while (File_utils::Check_file_exist("../../sum/"+ file_name + "_" + to_string(num_prev_version) + "_sum.txt") == 1 &&
			   File_utils::Check_file_exist("../../hg/" + file_name + "_" + to_string(num_prev_version) + "_hg.txt") == 1)
		{
			++num_prev_version;
		}
		--num_prev_version;

		return num_prev_version;
	}


	Obj_record_manager::Obj_record_manager(){}

	void Obj_record_manager::Register_changes(const char * current_file, const char * original_file)
	{
		string file_name = lua_util.Get_name_file_from_route(original_file);

		num_prev_version = Get_num_prev_version(file_name);

		std::unique_ptr<Obj_splitted> prev_obj_version;

		if (num_prev_version != -1)//if there is any version of this obj, compare the new obj with the original obj
		{
			prev_obj_version = make_unique<Obj_splitted>(Obj_splitted(obj_utils.Get_prev_version_obj(num_prev_version, original_file, file_name)));
		}
		else
		{
			prev_obj_version = make_unique<Obj_splitted>(Obj_splitted(File_utils::Get_file_content(original_file)));
		}

		vector<string> current_content_obj_version = File_utils::Get_file_content(current_file);
		Obj_splitted current_obj(current_content_obj_version);

		vector<Obj_change> diff = obj_utils.Get_diffs(current_obj, *prev_obj_version);

		//if there are some diferences
		if (diff.size())
		{
			File_utils::Create_file_sum("../../sum/" + file_name + "_" + std::to_string(1 + num_prev_version) + "_sum.txt", diff);
			File_utils::Create_file_hg ("../../hg/"  + file_name + "_" + std::to_string(1 + num_prev_version) + "_hg.txt", diff);

			for each (Obj_change change in diff)
			{
				cout << change.To_string() + " \n";
			}
		}
		else
		{
			cout << "Changes not found \n";
		}
	}
	void Obj_record_manager::Restore_version(const char * original_file, int num_version)
	{
		string file_name = lua_util.Get_name_file_from_route(original_file);

		if (File_utils::Check_file_exist("../../sum/" + file_name + "_" + to_string(num_version) + "_sum.txt") == 1)
		{
			vector<string>  obj_restored = obj_utils.Get_prev_version_obj(num_version, original_file, file_name);
			File_utils::Create_file(obj_restored, "../../assets/" + file_name + "_restored.obj");
		}
	}

	void Obj_record_manager::Restore_last_version(const char * original_file)
	{
		string file_name = lua_util.Get_name_file_from_route(original_file);

		num_prev_version = Get_num_prev_version(file_name);

		if (num_prev_version != -1)
		{
			vector<string>  obj_restored = obj_utils.Get_prev_version_obj(num_prev_version, original_file, file_name);
			File_utils::Create_file(obj_restored,"../../assets/" + file_name + "_restored.obj");
		}
	}
}