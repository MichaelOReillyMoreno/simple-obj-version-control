
#include "Obj_splitted.hpp"

namespace Obj_version_control
{
	Obj_splitted::Obj_splitted(vector<string> & obj_txt_lines)
	{
		TYPE_ELEMENT current_line_type;
		TYPE_ELEMENT prev_line_type = TYPE_ELEMENT::NONE;

		unsigned int current_part = -1;

		for (size_t i = 0; i < obj_txt_lines.size(); ++i)
		{
			current_line_type = Get_line_type(obj_txt_lines[i]);

			//if the current line has an other type is an other element(paragraph) in the obj
			if (current_line_type != prev_line_type)
			{
				elements.push_back(Obj_element(current_line_type));
				++current_part;
			}

			elements[current_part].Content_push_back(obj_txt_lines[i]);

			prev_line_type = current_line_type;
		}
	}

	TYPE_ELEMENT Obj_splitted::Get_line_type(string & line)
	{
		string type_line = line.substr(0, 2);

		if (type_line == "v ")
		{
			return TYPE_ELEMENT::V;
		}
		else if (type_line == "vn")
		{
			return TYPE_ELEMENT::VN;
		}
		else if (type_line == "vt")
		{
			return TYPE_ELEMENT::VT;
		}
		else if (type_line == "f ")
		{
			return TYPE_ELEMENT::F;
		}
		else
		{
			return TYPE_ELEMENT::TEXT;
		}
	}
}
