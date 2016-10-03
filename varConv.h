#pragma once

#include<string>
#include<time.h>

#include "varTypes.h"

using namespace std;

namespace conv
{
	string toString(int inp);
	string toString(float inp);
	string toString(double inp);
	string toString(time_t inp);
	string toString(var::coord2 inp, bool multiLine = true);
	string toString(var::color_RGB inp, bool multiLine = true);
	string toString(bool inp);
	string toLowercase(string& inp, bool changeArg = true);
	string toUppercase(string& inp, bool changeArg = true);
	bool isNum(string inp);
	float toNum(string inp);
	bool isBool(string inp);
	bool toBool(string inp);
	bool toBool(float inp);
}