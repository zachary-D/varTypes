#pragma once
#define _USE_MATH_DEFINES

#include <string>
#include <vector>

using namespace std;

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
		const double pi = 4 * atan(1);

		class line
		{
		public:
			line(coord2 _slope = var::coord2(1, 1), coord2 _displacement = var::coord2(0, 0));
			line(coord2 _slope, coord2 _displacement, float _lowxBound, float _highxBound);
			line(coord2 _slope, coord2 _displacement, float _lowxBound, float _highxBound, float _lowyBound, float _highyBound);

			line(coord2 _slope, float _xDisplacement, float _yDisplacement);
			line(coord2 _slope, float _xDisplacement, float _yDisplacement, float _lowxBound, float _highxBound);
			line(coord2 _slope, float _xDisplacement, float _yDisplacement, float _lowxBound, float _highxBound, float _lowyBound, float _highyBound);

			line(float _slope, coord2 _displacement = var::coord2(0, 0));
			line(float _slope, coord2 _displacement, float _lowxBound, float _highxBound);
			line(float _slope, coord2 _displacement, float _lowxBound, float _highxBound, float _lowyBound, float _highyBound);
			
			line(float _slope, float _xDisplacement, float _yDisplacement);
			line(float _slope, float _xDisplacement, float _yDisplacement, float _lowxBound, float _highxBound);
			line(float _slope, float _xDisplacement, float _yDisplacement, float _lowxBound, float _highxBound, float _lowyBound, float _highyBound);

			coord2 slope;			//The slope of the line.  Duh.
			coord2 displacement;	//The displacement of the line from where it would be if it was calculated using only the slope
			bool xBounds;		//If the line has x boundaries
			float lowxBound;	//The lower x boundary of the line segment
			float highxBound;	//The upper x boundary of the line segment
			bool yBounds;		//If the line has y boundaries
			float lowyBound;	//The lower y boundary of the line segment
			float highyBound;	//The upper y boundary of the line segment

			int getSlopeSign();			//Returns 1 or -1, based on the sign of the slope (positive slope = 1, negative slope = -1).  Returns 0 if slope hasn't been set, or is 0, 0.  Horizontal or vertical lines are also considered positive.
			float getSlope();	//Returns the slope of the line, as a float (slope.y / slope.x)
			coord2 getSlopeCoord2();	//Returns the slope of the line, in x and y components

			bool setSlope(coord2 _slope);	//Sets the slope and preforms basic input validation
			bool setxBounds(float _lowxBound, float _highxBound);
			bool setyBounds(float _lowyBound, float _highyBound);

			float getY(float _x);		//Returns the y coordinate associated with _x (ignoring the bounds)
			vector<float> getY(vector<float> _x);		//Returns the y coordinates associated with the set of values in _x (ignoring the bounds)

			float getX(float _y);		//Returns the x coordinate associated with _y (ignoring the bounds)
			vector<float> getX(vector<float> _y);		//Returns the x coordinates associated with the set of values in _y (ignoring the bounds)

			vector<coord2> getValuesBetweenBounds(float _interval = 1);		//Returns a set of y values associated with x values, starting at 'lowBound' and increasing by '_interval', up until (and including) 'highBound'

			bool isCoordWithinBounds(coord2 _pos);		//Returns whether or not '_pos' is within the bounds of a segment. If no bounds are set, the point is within those bounds.

			bool hasIntercept(line _line);
			coord2 getIntercept(line _line);
			bool isInterceptWithinBounds(line _line);

			float getLengthBetween(float _x1, float _x2);		//Returns the length of the segment between _x1 and _x2, ignoring the bounds.
			float getLengthBetweenBounds();						//Returns the distance (length) of the line segment between the set bounds.  If the lines are infinite (no bounds are set, no y bounds and a vertical line, etc.), 0 is returned. 
			float getLengthToBounds(float _x, int _direction = 0);		//Returns the length of the line segment from _x to the boundary in _direction (only the sign of the argument is used.  1 would evalute the same as 10000).  If _direction is 0 (or not set) 1 is assumed.
			
			coord2 getCoordAtLength(coord2 _start, float _length);	//Returns the coordinate _length along the line from _start.  If _length is positive the coord to the right will be returned, if negative the coord to the left will be returned.

		};

		class circle
		{
		public:
			circle(coord2 _center, float _radius = 1);

			coord2 center;
			float radius;

			bool setCenter(coord2 _center);
			bool setRadius(float _radius);

			coord2 getCenter();
			float getRadius();

			float getCircumference();
			float getArea();

			int getNumIntercepts(line _line);				//returns the number of intercept points the circle and the line passed to the function have.  (returns 0 if none, duh)
			vector<coord2> getIntercept(line _line);	//Returns the intercept point(s) of the circle and the line passed to the function, if any
		};
	};
};