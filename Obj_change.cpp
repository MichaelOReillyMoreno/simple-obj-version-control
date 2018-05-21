#include "Obj_change.hpp"

string Obj_version_control::Obj_change::Parse_type()
{
	switch (type)
	{
	case REPLACE:
		return "R-";

	case DELETE:
		return "D-";

	default:
		return "A-";
	}
}

const vector<string> Obj_version_control::Obj_change::explode(const string & s, const char & c)
{
	string buff{ "" };
	vector<string> v;

	for (auto n : s)
	{
		if (n != c) buff += n; else
			if (n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if (buff != "") v.push_back(buff);

	return v;
}

void Obj_version_control::Obj_change::Deserialize_hg(string & hg)
{
	vector<string> content_hg{ explode(hg, '-') };

	if (content_hg[0] == "R")
		type = TYPE_CHANGE::REPLACE;
	else if (content_hg[0] == "D")
		type = TYPE_CHANGE::DELETE;
	else if (content_hg[0] == "A")
		type = TYPE_CHANGE::ADD;

	num_line = stoi(content_hg[1]);
}
