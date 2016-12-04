#pragma once

#include <string>

using namespace std;

#include "cinder\Color.h"
#include "cinder\app\AppNative.h"

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
		ci::Vec2f toVec2f();
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

		/*coord3 negatedX();
		coord3 negatedY();
		coord3 negatedZ();
		coord3 negatedXY();
		coord3 negatedXZ();
		coord3 negatedYZ();
		coord3 negated();*/
		ci::Vec3f toVec3f();
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

		ci::Color toColor();	//BEING REMOVED.  use toCinderColor() istead
		ci::Color toCinderColor();	//Returns the color formatted in a way Cinder accepts
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

	namespace math
	{
		class line
		{
		public:
			line(coord2 _slope = var::coord2(1, 1), coord2 _displacement = var::coord2(0, 0));
			line(coord2 _slope = var::coord2(1, 1), float _xDisplacement = 0, float _yDisplacement = 0);
			line(float _slope = 1, coord2 _displacement = var::coord2(0, 0));
			line(float _slope = 1, float _xDisplacement = 0, float _yDisplacement = 0);

			coord2 slope;			//The slope of the line.  Duh.
			coord2 displacement;	//The displacement of the line from where it would be if it was calculated using only the slope
			//float lowBound;			//The lower boundary of the line segment
			//float highBound;		//The upper boundary of the line segment

			float getSlope();		//Returns the slope of the line, as a float (slope.y / slope.x)
			coord2 getSlopeCoord2();	//Returns the slope of the line, in x and y components

			float getY(float _x);
			vector<float> getY(vector<float> _x);
		};
	};
};