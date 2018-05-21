#pragma once
#ifndef OBJ_ELEMENT
#define OBJ_ELEMENT

#include "File_utils.hpp"

namespace Obj_version_control
{
	/// <summary>element type</summary>
	enum TYPE_ELEMENT { V, VT, VN, F, TEXT, NONE };

	/// <summary>class that represent a element of the 3d obj (paragraph)</summary>
	class Obj_element
	{

	private:

		TYPE_ELEMENT type;
		vector<string> content;

	public:

		/// <summary>Represent a element of the 3d obj (paragraph)</summary>
		/// <param name="_type">element type</param>  
		Obj_element(TYPE_ELEMENT _type) : type(_type){}

		inline TYPE_ELEMENT  Get_type() { return type; }
		inline void          Content_push_back(string line) { content.push_back(line); }
		inline string &      Get_content_line(size_t n_line) { return content[n_line]; }
		inline size_t        Get_content_size() { return content.size(); }

	};
}
#endif