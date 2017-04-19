#pragma once

//Written by and copyright Zachary Damato
//varConv.h is part of the varTypes submodule

#include<string>
#include<time.h>

#include "varTypes/varTypes.h"

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

	string toLowercase(string & inp, bool changeArg = true);
	char toLowercase(char & inp, bool changeArg = false);

	string toUppercase(string & inp, bool changeArg = true);
	char toUppercase(char & inp, bool changeArg = false);

	bool isNum(string inp);
	float toNum(string inp);

	bool isBool(string inp);
	bool toBool(string inp);
	bool toBool(float inp);

#ifdef USING_CINDER
	var::coord2 toCoord2(ci::Vec2f coordinate);
#endif
}