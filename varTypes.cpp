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
		return coord2(x + other.x, y + other.y);
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

	square::square()
	{}

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
		element::element(bool autoFill)
		{
			if(autoFill)
			{
				protons = 1;
				lookupValues();
			}
		}

		element::element(int _protons, bool autoFill)
		{
			setProtons(_protons);
			if(autoFill) lookupValues();
		}

		element::element(int _protons, float _neutrons, bool autoFill)
		{
			setProtons(_protons);
			setNeutrons(_neutrons);
			if(autoFill) lookupValues();
		}

		element::element(int _protons, float _neutrons, int _electrons, bool autoFill)
		{
			setProtons(_protons);
			setNeutrons(_neutrons);
			setElectrons(_electrons);
			if(autoFill) lookupValues();
		}

		element::element(int _protons, float _neutrons, int _electrons, float _atomicMass, bool autoFill)
		{
			setProtons(_protons);
			setNeutrons(_neutrons);
			setElectrons(_electrons);
			setAtomicMass(_atomicMass);
			if(autoFill) lookupValues();
		}

		element::element(string _symbol, bool autoFill)
		{
			setName(symbol);
			if(autoFill) lookupValues();
		}

		element::element(string _symbol, string _name, bool autoFill)
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
			if(_protons == NULL || _protons <= 0)
			{
				_DEBUG_ERROR("Bad '_protons': Value cannot == NULL or <= 0.");
				return false;
			}
			else
			{
				protons = _protons;
				protonsSet = true;
				return true;
			}
		}

		bool element::setNeutrons(float _neutrons)
		{
			if(_neutrons == NULL || _neutrons < 0)
			{
				_DEBUG_ERROR("Bad '_neutrons': Value cannot == NULL or < 0.");
				return false;
			}
			else
			{
				neutrons = _neutrons;
				neutronsSet = true;
				return true;
			}
		}

		bool element::setElectrons(int _electrons)
		{
			if(_electrons == NULL || _electrons < 0)
			{
				_DEBUG_ERROR("Bad '_electrons': Value cannot == 0 or < 0.");
				return false;
			}
			else
			{
				electrons = _electrons;
				electronsSet = true;
				return true;
			}
		}

		bool element::setName(string _name)
		{
			if(_name.length() == 0)
			{
				_DEBUG_ERROR("Bad '_name': Value cannot be empty.");
				return false;
			}
			else
			{
				name = _name;
				nameSet = true;
				return true;
			}
		}

		bool element::setSymbol(string _symbol)
		{
			if(_symbol.length() <= 0 || _symbol.length() > 3)
			{
				_DEBUG_ERROR("Bad '_symbol': Value cannot <= 0 or > 3.");
				return false;
			}
			else
			{
				symbol = _symbol;
				symbolSet = true;
				return true;
			}
		}

		bool element::setAtomicMass(float _atomicMass)
		{
			if(_atomicMass == NULL || _atomicMass <= 0)
			{
				_DEBUG_ERROR("Bad '_atomicMass': Value cannot == NULL or <= 0.");
				return false;
			}
			else
			{
				atomicMass = _atomicMass;
				atomicMassSet = true;
				return true;
			}
		}

		bool element::setAtomicNumber(float _atomicNumber)
		{
			if(_atomicNumber == NULL || _atomicNumber <= 0)
			{
				_DEBUG_ERROR("Bad '_atomicNumber': Value cannot == NULL or <= 0.");
				return false;
			}
			else if(protons != NULL && neutrons != NULL)
			{
				if(_atomicNumber != protons + neutrons)
				{
					_DEBUG_ERROR("Bad '_atomicNumber': Value is in conflict with existing 'protons' and 'neutrons' value.");
					return false;
				}
			}
			else
			{
				atomicNumber = _atomicNumber;
				atomicNumberSet = true;
				return true;
			}
		}

		bool element::setCharge(int _charge)
		{
			if(_charge == NULL)
			{
				_DEBUG_ERROR("Bad '_charge': Value is not defined.");
				return false;
			}
			else
			{
				charge = _charge;
				chargeSet = true;
				return true;
			}
		}

		int element::getProtons()
		{
				if(protonsSet)
				{
					_DEBUG_ERROR("'protons' has not yet been set.\n Returning '1' in the place of 'protons'.  This may result in calculation errors.");
					return 1;
				}
			return protons;
		}

		float element::getNeutrons()
		{
				if(neutronsSet)
				{
					_DEBUG_ERROR("'neutrons'has not yet been set.\nReurning '1' in the place of 'neutrons'.  This may result in calculation errors.");
					return 1;
			}
			else return neutrons;
		}

		int element::getElectrons()
		{
				if(electrons == NULL)
				{
					_DEBUG_ERROR("'electrons' == NULL.  Has its value ont yet been set?\nReturning '1' in the place of 'electrons'.  This may result in calculation errors.");
					return 1;
			}
			else return electrons;
		}

		string element::getName()
		{
				if(name.length() == 0)
				{
					_DEBUG_ERROR("'name.length()' == 0.  Has its value not yet been set?\nReturning 'Err' in the place of 'name'.  This may result in errors.");
					return "Err";
			}
			else return name;
		}

		string element::getSymbol()
		{
				if(symbol.length() == 0)
				{
					_DEBUG_ERROR("'symbol.length()' == 0.  Has its value not yet been set?\nReturning 'Er' in the place off 'name'.  This may result in errors.");
					return "Er";
			}
			else return symbol;
		}

		float element::getAtomicMass()
		{
				if(atomicMass == NULL)
				{
					_DEBUG_ERROR("'atomicMass' == 0.  Has its value not yet been set?\nReturning 1 in the place of 'atomicMass'.  This may result in calculation errors.");
					return 1;
			}
			else return atomicMass;
		}

		float element::getAtomicNumber()
		{
				if(atomicNumber == NULL)
				{
					_DEBUG_ERROR("'atomicNumber' == NULL.  Has its value not yet been set?\nReturning 1 in the place of 'atomicMass'.  This may result in calculation errors.");
					return 1;
			}
			else return atomicNumber;
		}

		int element::getCharge()
		{
				if(charge == NULL)
				{
					_DEBUG_ERROR("'charge' == NULL.  Has its value not yet been set?\nReturning 1 in the place of 'charge'.  THis may result in calculation errors.");
					return 1;
			}
			else return charge;
		}

		bool element::inferValues()
		{
			bool change = false;		//If the current cycle has calculated any values
			bool anyChanges = false;	//If there were any changes at all
			do
			{
				if(protons == NULL)			//Calculating protons
				{
					if(electrons != NULL && charge != NULL)
					{
						setProtons(charge + electrons);
						change = true;
					}
					else if(atomicNumber != NULL && neutrons != NULL && fmod(neutrons, 1) != 0)
					{
						setProtons(atomicNumber - neutrons);
						change = true;
					}
				}
				if(neutrons == NULL)		//Calculating neutrons
				{
					if(atomicNumber != NULL && protons != NULL)
					{
						setNeutrons(atomicNumber - protons);
						change = true;
					}
				}
				if(electrons == NULL)		//Calculating electrons
				{
					if(protons != NULL && charge != NULL)
					{
						setElectrons(protons - charge);
						charge = true;
					}
				}
				if(atomicNumber == NULL)	//Calculating atomicNumber
				{
					if(protons != NULL && neutrons != NULL)
					{
						setAtomicNumber(protons + neutrons);
						charge = true;
					}
				}
				if(charge == NULL)			//Calculating charge
				{
					if(protons != NULL && electrons != NULL)
					{
						setCharge(protons - electrons);
						charge = true;
					}
				}
				if(change) anyChanges = true;
			}
			while(change);
			return anyChanges;
		}

		bool element::lookupValues()
		{
			_DEBUG_ERROR("We haven't made the periodic table yet sooooo...");
			return false;
		}

		string element::testOutput(bool multiLine)
		{
			string separator = " | ";
			if(multiLine) separator = "\n";
			string output = "";
			if(protons == NULL)
			{


			}
			return "N/A";
		}
	}
}