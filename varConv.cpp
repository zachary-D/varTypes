#pragma once

#include<iostream>
#include<sstream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<algorithm>
#include<windows.h>
#include<vector>
#include<new>

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Text.h"
#include "cinder/app/App.h"
#include "cinder/Font.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/TextureFont.h"
#include "cinder/ImageIo.h"
#include "cinder/app/window.h"

#include "varTypes.h"

using namespace std;

using namespace ci;
using namespace ci::app;

stringstream convert;
string strOut;
float floatOut;
bool boolOut;

string a;


namespace conv
{
	string toString(int inp)
	{	
		convert.clear();
		convert << inp;
		convert >> strOut;
		convert.clear();
		return strOut;
	}

	string toString(float inp)
	{
		convert.clear();
		convert << inp;
		convert >> strOut;
		convert.clear();
		return strOut;
	}

	string toString(double inp)
	{
		convert.clear();
		convert << inp;
		convert >> strOut;
		convert.clear();
		return strOut;
	}

	string toString(time_t inp)
	{
		convert.clear();
		convert << inp;
		strOut = "";
		convert >> strOut;
		convert.clear();
		return strOut;
	}

	string toString(var::coord2 inp, bool multiLine = true)
	{
		if(multiLine == false)
		{
			return inp.toString();
		}
		else
		{
			return "x:"	 + toString(inp.x) + "\ny:" + toString(inp.y);
		}
	}

	string toString(var::color_RGB inp, bool multiLine = true)
	{
		if(multiLine == false)
		{
			return "r:" + toString(inp.R) + ", g" + toString(inp.G) + ", b" + toString(inp.B);
		}
		else
		{
			return "r:" + toString(inp.R) + "\ng" + toString(inp.G) + "\nb" + toString(inp.B);
		}
	}

	string toString(bool inp)
	{
		if(inp == true) return "true";
		else if(inp == false) return "false";
	}

	string toLowercase(string & inp, bool changeArg = true)		//Coverts 'inp' to lowercase.  USES POINTERS TO CHANGE ARGUMENT VALUES
	{
		string ret;
		if(changeArg)
		{
			transform(inp.begin(), inp.end(), inp.begin(), tolower);
			ret = inp;
		}
		else
		{
			ret = inp;
			transform(ret.begin(), ret.end(), ret.begin(), tolower);
		}
		return ret;
	}

	string toUppercase(string & inp, bool changeArg = true)		//Coverts 'inp' to uppercase.  USES POINTERS TO CHANGE ARGUMENT VALUES
	{
		string ret;
		if(changeArg)
		{
			transform(inp.begin(), inp.end(), inp.begin(), toupper);
			ret = inp;
		}
		else
		{
			transform(inp.begin(), inp.end(), ret.begin(), toupper);
		}
		return ret;
	}

	bool isNum(string inp)
	{
		convert.clear();
		convert << inp;
		convert >> floatOut;
		if(convert.fail())
		{
			convert.clear();
			return false;
		}
		else
		{
			convert.clear();
			return true;
		}
	}
	
	float toNum(string inp)
	{
		convert.clear();
		convert << inp;
		convert >> floatOut;
		convert.clear();
		return floatOut;
	}

	bool isBool(string inp)
	{
		if(inp == "true" || inp == "false") return true;
		else return false;
	}

	bool toBool(string inp)
	{
		if(inp == "true") return true;
		else if(inp == "false") return false;
		else return false;
	}

	bool toBool(float inp)
	{
		if(inp == 1) return true;
		else if(inp == 0) return false;
		else return false;
	}
}

//Test