#pragma once
#ifndef OBJ_SPLITTED
#define OBJ_SPLITTED

#include "Obj_element.hpp"

namespace Obj_version_control
{
	//class that represent an obj splited in elements(paragraphs)
	class Obj_splitted
	{

	public:

		//elements(paragraphs) of the obj
		vector<Obj_element> elements;

		/// <summary>represent an obj splited in elements(paragraphs)</summary>
		/// <param name="obj_txt_lines">File splitted in lines</param>  
		Obj_splitted(vector<string> & obj_txt_lines);

	private:

		/// <summary>Get the type of a lines</summary>
		TYPE_ELEMENT Get_line_type(string & line);
	};
}
#endif