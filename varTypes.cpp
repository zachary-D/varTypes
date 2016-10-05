#pragma once

#include <string>

using namespace std;

#ifdef USING_CINDER
#include "cinder\Color.h"
#include "cinder\app\AppNative.h"
#endif

#ifdef USING_DEBUG
#include "debug.h"
#endif

#include "varConv.h"
#include "varTypes.h"

namespace var
{
	coord2::coord2()
	{
		x = 0;
		y = 0;
	}

	coord2::coord2(float X, float Y)
	{
		x = X;
		y = Y;
	}

	coord2 coord2::operator+(const coord2 & other)
	{
		//ci::app::console() << endl << "X :" + conv::toString(x + other.x) + " Y :"  + conv::toString(y + other.y) << endl << endl;
		//ci::app::console() << endl << "X_:" + conv::toString(coord2(x + other.x, y + other.y).x) + " Y_:" + conv::toString(coord2(x + other.x, y + other.y).y) << endl << endl;
		return coord2( x + other.x, y + other.y);
	}
	
	coord2 coord2::operator-(const coord2 & other)
	{
		return coord2(x - other.x, y - other.y);
	}

	coord2 coord2::operator*(const coord2 & other)
	{
		return coord2(x * other.x, y * other.y);
	}

	coord2 coord2::operator*(const float & other)
	{
		return coord2(x * other, y * other);
	}

	coord2 coord2::operator/(const coord2 & other)
	{
		return coord2(x / other.x, y / other.y);
	}

	coord2 coord2::operator/(const float & other)
	{
		return coord2(x / other, y / other);
	}

	coord2 coord2::operator+=(const coord2 & other)
	{
		x += other.x;
		y += other.y;
		return coord2(x, y);
	}

	coord2 coord2::operator-=(const coord2 & other)
	{
		x -= other.x;
		y -= other.y;
		return coord2(x, y);
	}

	coord2 coord2::operator*=(const coord2 & other)
	{
		x *= other.x;
		y *= other.y;
		return coord2(x, y);
	}

	coord2 coord2::operator*=(const float & other)
	{
		x *= other;
		y *= other;
		return coord2(x, y);
	}

	coord2 coord2::operator/=(const coord2 & other)
	{
		x /= other.x;
		y /= other.y;
		return coord2(x, y);
	}
	
	coord2 coord2::operator/=(const float & other)
	{
		x /= other;
		y /= other;
		return coord2(x, y);
	}

	bool coord2::operator==(const coord2 & other)
	{
		if(x == other.x && y == other.y) return true;
		else return false;
	}

	bool coord2::operator!=(const coord2 & other)
	{
		if(x != other.x || y != other.y) return true;
		else return false;
	}

	coord2 coord2::negatedX()
	{
		return coord2(x * -1, y);
	}

	coord2 coord2::negatedY()
	{
		return coord2(x, y * -1);
	}

	coord2 coord2::negated()
	{
		return coord2(x * -1, y * -1);
	}

#ifdef USING_CINDER
	ci::Vec2f coord2::toVec2f()
	{
		return ci::Vec2f(x, y);
	}
#endif

	string coord2::toString()
	{
		return("x: " + conv::toString(x) + ", y: " + conv::toString(y));
	}

	int coord2::getQuadrant()
	{
		//$$
		if(x >= 0 && y >= 0) return 1; 
		else if(x < 0 && y >= 0) return 2;
		else if(x < 0 && y < 0) return 3;
		else if(x >= 0 && y < 0) return 4;
		else _DEBUG_ERROR("Error determining quadrant.  Coordinates may be improperly defined.");
	}

	coord3::coord3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	coord3::coord3(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = Z;
	}

	coord3 coord3::operator+(const coord3& other)
	{
		return coord3(x + other.x, y + other.y, z + other.z);
	}

	coord3 coord3::operator-(const coord3& other)
	{
		return coord3(x - other.x, y - other.y, z - other.z);
	}

	coord3 coord3::operator*(const coord3& other)
	{
		return coord3(x * other.x, y * other.y, z * other.z);
	}

	coord3 coord3::operator*(const float& other)
	{
		return coord3(x * other, y * other, z * other);
	}

	coord3 coord3::operator/(const coord3& other)
	{
		return coord3(x / other.x, y / other.y, z / other.z);
	}

	coord3 coord3::operator/(const float& other)
	{
		return coord3(x / other, y / other, z / other);
	}

	bool coord3::operator==(const coord3& other)
	{
		if(x == other.x && y == other.y && z == other.z) return true;
		else return false;
	}

#ifdef USING_CINDER
	ci::Vec3f coord3::toVec3f()
	{
		return ci::Vec3f(x, y, z);
	}
#endif

	color_RGB::color_RGB()
	{
		R = 1;
		G = 0;
		B = 0;
	}

	color_RGB::color_RGB(float r, float g, float b)
	{
		R = r;
		G = g;
		B = b;
	}

#ifdef USING_CINDER
	ci::Color color_RGB::toColor()
	{
		return ci::Color(R, G, B);
	}

	ci::Color color_RGB::toCinderColor()
	{
		return ci::Color(R, G, B);
	}

#endif

	square::square() {}
	
	square::square(coord2 _upperRight, coord2 _lowerLeft)
	{
		topY = _upperRight.y;
		rightX = _upperRight.x;
		bottomY = _lowerLeft.y;
		leftX = _lowerLeft.x;
	}
	
	square::square(float _leftX, float _rightX, float _bottomY, float _topY)
	{
		leftX = _leftX;
		rightX = _rightX;
		bottomY = _bottomY;
		topY = _topY;
	}

	coord2 square::getTopLeft()
	{
		return coord2(leftX, topY);
	}

	coord2 square::getTopRight()
	{
		return coord2(rightX, topY);
	}

	coord2 square::getBottomLeft()
	{ 
		return coord2(leftX, bottomY);
	}

	coord2 square::getBottomRight()
	{
		return coord2(rightX, bottomY);
	}

	namespace chem
	{
		element::element(bool autoFill = true)
		{
			if(autoFill)
			{
				protons = 1;
				lookupValues();
			}
		}

		element::element(int _protons, bool autoFill = true)
		{
			setProtons(_protons);
			if(autoFill) lookupValues();
		}

		element::element(int _protons, float _neutrons, bool autoFill = true)
		{
			setProtons(_protons);
			setNeutrons(_neutrons);
			if(autoFill) lookupValues();
		}

		element::element(int _protons, float _neutrons, int _electrons, bool autoFill = true)
		{
			setProtons(_protons);
			setNeutrons(_neutrons);
			setElectrons(_electrons);
			if(autoFill) lookupValues();
		}

		element::element(int _protons, float _neutrons, int _electrons, float _atomicMass, bool autoFill = true)
		{
			setProtons(_protons);
			setNeutrons(_neutrons);
			setElectrons(_electrons);
			setAtomicMass(_atomicMass);
			if(autoFill) lookupValues();
		}

		element::element(string _symbol, bool autoFill = true)
		{
			setName(symbol);
			if(autoFill) lookupValues();
		}

		element::element(string _symbol, string _name, bool autoFill = true)
		{
			setName(_name);
			setSymbol(_symbol);
			if(autoFill) lookupValues();
		}

		element::element(string _name, string _symbol, int _protons, float _neutrons, int _electrons, float _atomicMass)
		{
			setName(_name);
			setSymbol(_symbol);
			setProtons(_protons);
			setNeutrons(_neutrons);
			setElectrons(_electrons);
			setAtomicMass(_atomicMass);
		}

		bool element::setProtons(int _protons)
		{
			if(_protons <= 0) throw "protons<=0";
			protons = _protons;
		}

		bool element::setNeutrons(float _neutrons)
		{
			if(_neutrons <= 0) throw "neutrons<=0";
			neutrons = _neutrons;
		}

		bool element::setElectrons(int _electrons)
		{
			if(_electrons <= 0) throw "electrons<=0";
			electrons = _electrons;
		}

		bool element::setName(string _name)
		{
			if(_name.length() == 0) throw "badname";
			name = _name;
		}

		bool element::setSymbol(string _symbol)
		{
			if(_symbol.length() == 0) throw "badsymbol";
			symbol = _symbol;
		}

		bool element::setAtomicMass(float _atomicMass)
		{
			bool ret = true;
			if(_atomicMass <= 0)
			{
				throw "atomicMass<=0";
				ret = false;
			}
			atomicMass = _atomicMass;
			return ret;
		}

		int element::getProtons()
		{
			return protons;
		}

		float element::getNeutrons()
		{
			return neutrons;
		}

		int element::getElectrons()
		{
			return electrons;
		}

		string element::getName()
		{
			return name;
		}

		string element::getSymbol()
		{
			return symbol;
		}

		float element::getAtomicMass()
		{
			return atomicMass;
		}

		int element::getCharge()
		{
			if(std::fmod(neutrons, 1) == 0)
			{
				
			}
		}
		
		bool element::lookupValues()
		{
			_DEBUG_ERROR("We haven't made the periodic table yet sooooo...");
		}
	}
}