#pragma once

#include <string>

using namespace std;

#ifdef USING_CINDER
#include "cinder\Color.h"
#include "cinder\app\AppNative.h"
#endif

namespace var
{
	class coord2
	{
	public:
		coord2();
		coord2(float X, float Y);

		coord2 operator+(const coord2 & other);
		coord2 operator-(const coord2 & other);
		coord2 operator*(const coord2 & other);
		coord2 operator*(const float & other);
		coord2 operator/(const coord2 & other);
		coord2 operator/(const float & other);
		coord2 operator+=(const coord2 & other);
		coord2 operator-=(const coord2 & other);
		coord2 operator*=(const coord2 & other);
		coord2 operator*=(const float & other);
		coord2 operator/=(const coord2 & other);
		coord2 operator/=(const float & other);
		bool operator==(const coord2 & other);
		bool operator!=(const coord2 & other);

		float x, y;

		coord2 negatedX();
		coord2 negatedY();
		coord2 negated();

	#ifdef USING_CINDER
		ci::Vec2f toVec2f();
	#endif
		string toString();
		int getQuadrant();
	};

	class coord3
	{
	public:
		coord3();
		coord3(float X, float Y, float Z);

		coord3 operator+(const coord3 & other);
		coord3 operator-(const coord3 & other);
		coord3 operator*(const coord3 & other);
		coord3 operator*(const float & other);
		coord3 operator/(const coord3 & other);
		coord3 operator/(const float & other);
		bool operator==(const coord3 & other);

		float x;
		float y;
		float z;

		//To be defined
		/*coord3 negatedX();
		coord3 negatedY();
		coord3 negatedZ();
		coord3 negatedXY();
		coord3 negatedXZ();
		coord3 negatedYZ();
		coord3 negated();*/
	#ifdef USING_CINDER
		ci::Vec3f toVec3f();
	#endif
		//coord3 toString();
	};

	class color_RGB
	{
	public:
		color_RGB();
		color_RGB(float r, float g, float b);

		float R;
		float G;
		float B;
	#ifdef USING_CINDER
		ci::Color toColor();	//BEING REMOVED.  use toCinderColor() istead
		ci::Color toCinderColor();	//Returns the color formatted in a way Cinder accepts
	#endif
	};

	class square
	{
	public:
		square();
		square(coord2 _upperRight, coord2 _lowerLeft);
		square(float _leftX, float _rightX, float _bottomY, float _topY);

		float leftX = 0;	//The X coordinate of every point along the left side of the square
		float rightX = 0;	//The X coordinate of every point along the right side of the square
		float bottomY = 0;	//The Y coordinate of every point along the bottom of the square
		float topY = 0;		//The Y coordinate of every point along the top of the square

		coord2 getTopLeft();
		coord2 getTopRight();
		coord2 getBottomLeft();
		coord2 getBottomRight();
	};

	namespace chem
	{
		class element
		{
		public:
			//For all of these functions, if autoFill == true data will attempt to be sourced from the periodic table.  If false, any values not explicitly stated will be left null
			element(bool autoFill = true);		//If autoFill == true, autofills with protons = 1
			element(int _protons, bool autoFill = true);	//Creates a instance with _protons
			element(int _protons, float _neutrons, bool autoFill = true);
			element(int _protons, float _neutrons, int _electrons, bool autoFill = true);
			element(int _protons, float _neutrons, int _electrons, float _atomicMass, bool autoFill = true);
			element(string _symbol, bool autoFill = true);
			element(string _symbol, string _name, bool autoFill = true);
			element(string _name, string _symbol, int _protons, float _neutrons, int _electrons, float _atomicMass);

		private:
			int protons;				//The number of protons in the element
			float neutrons;				//The number of neutrons in the element
			int electrons;				//The number of electron in (technically around) the element
			string name;				//The name of the element
			string symbol;				//The atomic symbol of the element
			float atomicMass;			//The atomic mass of the element
			float atomicNumber;			//The atomic number of the element (technically the average of the isotopes)
			int charge;					//The charge of the element

		public:
			//Setting traits
			bool setProtons(int _protons);		//Sets the number of protons in the element
			bool setNeutrons(float _neutrons);	//Sets the number of neutrons in the element
			bool setElectrons(int _electrons);	//Sets the number of electrons in the element
			bool setName(string _name);			//Sets the name of the element
			bool setSymbol(string _symbol);		//Sets the symbol of the element
			bool setAtomicMass(float _atomicMass);	//Sets the atomic mass of the element
			bool setAtomicNumber(float _atomicNumber);	//Sets the atomic number of the element
			bool setCharge(int _charge);		//Sets the charge of the element

			//Returning traits
			int getProtons();			//Returns the number of protons in the element
			float getNeutrons();		//Returns the number of neutrons in the element
			int getElectrons();			//Returns the number of electrons in the element
			string getName();			//Returns the name of the element
			string getSymbol();			//Returns the atomic symbol of the element
			float getAtomicMass();		//Returns the atomic mass of the element
			float getAtomicNumber();	//Returns the atomic number of the element
			int getCharge();			//The charge on the atom.  Not available for atoms with averaged neutrons (Will throw an error if this situation arises).

			//Other
			bool inferValues();			//Attempts to calculate all values possible from included information (i.e. protons from electrons and charge, etc.)
			bool lookupValues();		//Tries to autofill values from the periodic table, if it is loaded.
			string testOutput(bool multiLine = false);	//Converts all data from the element into a string.
		};
	};
};