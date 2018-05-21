
#include "Objs_utils.hpp"

namespace Obj_version_control
{
	vector<Obj_change> Obj_utils::Get_diffs(Obj_splitted & current_obj, Obj_splitted & prev_obj)
	{
		/*

		IMPORTANT:

		Some improvements could be made to the diff algorithm.
		This is diff algorithm that works but is not optimal.
		Is a prototype and all the code related is in a function until it is finished.

		*/

		unsigned num_line = 0;

		vector<Obj_change> changes;

		string * current_obj_line;
		string * prev_obj_line;

		size_t prev_elements_size = prev_obj.elements.size();
		size_t current_elements_size = current_obj.elements.size();

		for (size_t n_element = 0; n_element < current_elements_size; ++n_element)
		{
			size_t current_content_size = current_obj.elements[n_element].Get_content_size();

			if (n_element < prev_elements_size)
			{
				size_t prev_content_size = prev_obj.elements[n_element].Get_content_size();

				for (size_t n_line_in_elemt = 0; n_line_in_elemt < current_content_size; ++n_line_in_elemt)
				{
					current_obj_line = &current_obj.elements[n_element].Get_content_line(n_line_in_elemt);

					if (n_line_in_elemt < prev_content_size)
					{
						prev_obj_line = &prev_obj.elements[n_element].Get_content_line(n_line_in_elemt);

						if (*current_obj_line != *prev_obj_line)
						{
							cout << *current_obj_line;
							cout << *prev_obj_line;
							changes.push_back(Obj_change(TYPE_CHANGE::REPLACE, num_line, *current_obj_line));
						}
					}
					else //if the new obj has more lines the old one
					{
						changes.push_back(Obj_change(TYPE_CHANGE::ADD, num_line, *current_obj_line));
					}

					++num_line;
				}

				if (prev_content_size > current_content_size)//if the old obj has more lines the new one
				{
					for (size_t i = current_content_size; i < prev_content_size; ++i)
					{
						changes.push_back(Obj_change(TYPE_CHANGE::DELETE, num_line, ""));
					}
				}
			}
			///if the new obj has more modules the old one
			else
			{
				for (size_t n_line_in_elemt = 0; n_line_in_elemt < current_content_size; ++n_line_in_elemt)
				{
					changes.push_back(Obj_change(TYPE_CHANGE::ADD, num_line, current_obj.elements[n_element].Get_content_line(n_line_in_elemt)));
					++num_line;
				}
			}
		}
		///if the old obj has more modules the new one
		if (prev_elements_size > current_elements_size)
		{
			for (size_t i = current_elements_size; i < prev_elements_size; ++i)
			{
				for (size_t n_line_in_elemt = 0; n_line_in_elemt < prev_obj.elements[i].Get_content_size(); ++n_line_in_elemt)
				{
					changes.push_back(Obj_change(TYPE_CHANGE::DELETE, num_line, ""));
				}
			}
		}

		return changes;
	}

	vector<string> Obj_utils::Get_prev_version_obj(unsigned int num_prev_version, const char * original_file, string & file_name)
	{
		vector<string> sum;
		vector<string> hg;
		vector<string> obj_restored;

		obj_restored = File_utils::Get_file_content(original_file);

		for (unsigned int version = 0; version <= num_prev_version; ++version)
		{
			sum = File_utils::Get_file_content("../../sum/" + file_name + "_" + to_string(version) + "_sum.txt");
			hg = File_utils::Get_file_content ("../../hg/"  + file_name + "_" + to_string(version) + "_hg.txt");
			Restore_obj(obj_restored, sum, hg);
		}

		return obj_restored;
	}

	void Obj_utils::Restore_obj(vector<string> & obj_restored, vector<string> & sum, vector<string> & hg)
	{
		for (unsigned int i = 0; i < sum.size(); ++i)
		{
			Obj_change change(sum[i], hg[i]);

			if (change.Get_type() == TYPE_CHANGE::REPLACE)
			{
				obj_restored[change.Get_num_line()] = sum[i];
			}
			else if (change.Get_type() == TYPE_CHANGE::ADD)
			{
				obj_restored.insert(obj_restored.begin() + change.Get_num_line(), sum[i]);
			}
			else if (change.Get_type() == TYPE_CHANGE::DELETE)
			{
				obj_restored.erase(obj_restored.begin() + change.Get_num_line());
			}
		}
	}
}