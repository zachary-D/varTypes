#pragma once

#include <string>

using namespace std;

#include "cinder\Color.h"
#include "cinder\app\AppNative.h"

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

	ci::Vec2f coord2::toVec2f()
	{
		return ci::Vec2f(x, y);
	}

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

	ci::Vec3f coord3::toVec3f()
	{
		return ci::Vec3f(x, y, z);
	}

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

	ci::Color color_RGB::toColor()
	{
		return ci::Color(R, G, B);
	}

	ci::Color color_RGB::toCinderColor()
	{
		return ci::Color(R, G, B);
	}

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

	namespace math
	{
		line::line(coord2 _slope, coord2 _displacement)
		{
			setSlope(_slope);
			displacement = _displacement;
			xBounds = false;
			yBounds = false;
		}

		line::line(coord2 _slope, coord2 _displacement, float _lowxBound, float _highxBound)
		{
			setSlope(_slope);
			displacement = _displacement;
			setxBounds(_lowxBound, _highxBound);
			yBounds = false;
		}

		line::line(coord2 _slope, coord2 _displacement, float _lowxBound, float _highxBound, float _lowyBound, float _highyBound)
		{
			setSlope(_slope);
			displacement = _displacement;
			setxBounds(_lowxBound, _highxBound);
			setyBounds(_lowyBound, _highyBound);
		}

		line::line(coord2 _slope, float _xDisplacement, float _yDisplacement)
		{
			setSlope(_slope);
			displacement = var::coord2(_xDisplacement, _yDisplacement);
			xBounds = false;
			yBounds = false;
		}

		line::line(coord2 _slope, float _xDisplacement, float _yDisplacement, float _lowxBound, float _highxBound)
		{
			setSlope(_slope);
			displacement = var::coord2(_xDisplacement, _yDisplacement);
			setxBounds(_lowxBound, _highxBound);
			yBounds = false;
		}

		line::line(coord2 _slope, float _xDisplacement, float _yDisplacement, float _lowxBound, float _highxBound, float _lowyBound, float _highyBound)
		{
			setSlope(_slope);
			displacement = var::coord2(_xDisplacement, _yDisplacement);
			setxBounds(_lowxBound, _highxBound);
			setyBounds(_lowyBound, _highyBound);
		}

		line::line(float _slope, coord2 _displacement)
		{
			setSlope(coord2(1, _slope));
			displacement = _displacement;
			xBounds = false;
			yBounds = false;
		}

		line::line(float _slope, coord2 _displacement, float _lowxBound, float _highxBound)
		{
			setSlope(coord2(1, _slope));
			displacement = _displacement;
			setxBounds(_lowxBound, _highxBound);
			yBounds = false;
		}

		line::line(float _slope, coord2 _displacement, float _lowxBound, float _highxBound, float _lowyBound, float _highyBound)
		{
			setSlope(coord2(1, _slope));
			displacement = _displacement;
			setxBounds(_lowxBound, _highxBound);
			setyBounds(_lowyBound, _highyBound);
		}

		line::line(float _slope, float _xDisplacement, float _yDisplacement)
		{
			setSlope(coord2(1, _slope));
			displacement = var::coord2(_xDisplacement, _yDisplacement);
			xBounds = false;
			yBounds = false;
		}

		line::line(float _slope, float _xDisplacement, float _yDisplacement, float _lowxBound, float _highxBound)
		{
			setSlope(coord2(1, _slope));
			displacement = var::coord2(_xDisplacement, _yDisplacement);
			setxBounds(_lowxBound, _highxBound);
			yBounds = false;
		}

		line::line(float _slope, float _xDisplacement, float _yDisplacement, float _lowxBound, float _highxBound, float _lowyBound, float _highyBound)
		{
			setSlope(coord2(1, _slope));
			displacement = var::coord2(_xDisplacement, _yDisplacement);
			setxBounds(_lowxBound, _highxBound);
			setyBounds(_lowyBound, _highyBound);
		}

		int line::getSlopeSign()
		{
			if(slope.x == 0 && slope.y == 0) return 0;
			else if((slope.x >= 0 && slope.y >= 0) || (slope.x <= 0 && slope.y <= 0)) return 1;
			else if((slope.x > 0 && slope.y < 0) || (slope.x < 0 && slope.y > 0)) return -1;
			_DEBUG_ERROR("Unknown exception.  Returning 0.");
			return 0;
		}

		float line::getSlope()
		{
			if(slope.x != 0) return slope.y / slope.x;
			else
			{
				_DEBUG_ERROR("SLOPE = y / 0");
				return slope.y / (10 ^ -20);
			}
		}

		coord2 line::getSlopeCoord2()
		{
			return coord2();
		}

		bool line::setSlope(coord2 _slope)
		{
			if(_slope.x == 0 && _slope.y == 0)
			{
				_DEBUG_ERROR("Bad slope - slope cannot be 0 / 0.  Defaulting to 1.");
				slope = coord2(1, 1);
				return false;
			}
			else
			{
				slope = _slope;
				return true;
			}
		}

		bool line::setxBounds(float _lowxBound, float _highxBound)
		{
			if(_lowxBound < _highxBound)
			{
				lowxBound = _lowxBound;
				highxBound = _highxBound;
				xBounds = true;
			}
			else if(_lowxBound > _highxBound)
			{
				//_DEBUG_ERROR("Bad input, _lowxBound is greater than _highxBound.  Swapping low and high bounds.");
				lowxBound = _highxBound;
				highxBound = _lowxBound;
				xBounds = true;
			}
			else if(_lowxBound == _highxBound)
			{
				_DEBUG_ERROR("Bad input, _lowxBound is equal to _highxBound.  Setting xboudns to false.");
				xBounds = false;
			}
			else
			{
				_DEBUG_ERROR("Unspecified error.  Setting xBounds to false.");
				xBounds = false;
			}
			return xBounds;
		}

		bool line::setyBounds(float _lowyBound, float _highyBound)
		{
			if(_lowyBound < _highyBound)
			{
				lowyBound = _lowyBound;
				highyBound = _highyBound;
				yBounds = true;
			}
			else if(_lowyBound > _highyBound)
			{
				//_DEBUG_ERROR("Bad input, _lowyBound is greater than _highyBound.  Swapping low and high bounds.");
				lowyBound = _highyBound;
				highyBound = _lowyBound;
				yBounds = true;
			}
			else if(_lowyBound == _highyBound)
			{
				_DEBUG_ERROR("Bad input, _lowyBound is equal to _highyBound.  Setting yboudns to false.");
				yBounds = false;
			}
			else
			{
				_DEBUG_ERROR("Unspecified error.  Setting yBounds to false.");
				yBounds = false;
			}
			return yBounds;
		}

		float line::getY(float _x)
		{
			if(slope.x == 0) return _x;
			else return getSlope() * (_x - displacement.x) + displacement.y;
		}

		vector<float> line::getY(vector<float> _x)
		{
			vector<float> y;
			for(int x = 0; x < _x.size(); x++)
			{
				y.push_back(getY(_x[x]));
			}
			return y;
		}

		float line::getX(float _y)
		{
			if(slope.y == 0) return _y;
			else return (slope.x * (_y - displacement.y) / slope.y) + displacement.x;
		}

		vector<float> line::getX(vector<float> _y)
		{
			vector<float> x;
			for(int y = 0; y < _y.size(); y++)
			{
				x.push_back(getX(_y[y]));
			}
			return x;
		}

		vector<coord2> line::getValuesBetweenBounds(float _interval)
		{
			if(xBounds == true)
			{
				vector<coord2> ret;
				for(float x = lowxBound; x < highxBound; x += _interval)
				{
					float y = getY(x);
					if(yBounds == false || lowyBound <= y && y <= highyBound)
					{
						ret.push_back(var::coord2(x, y));
					}
				}
				if(highxBound != ret[ret.size() - 1].x)
				{
					float y = getY(highxBound);
					if(yBounds == false || lowyBound <= y && y <= highyBound)
					{
						ret.push_back(var::coord2(highxBound, y));
					}
				}
				return ret;
			}
			else _DEBUG_ERROR("Bounds not set!");
		}

		bool line::isCoordWithinBounds(coord2 _pos)
		{
			bool withinBounds = true;
			if(xBounds == true && (lowxBound > _pos.x || _pos.x > highxBound)) withinBounds = false;
			if(yBounds == true && (lowyBound > _pos.y || _pos.y > highyBound)) withinBounds = false;
			return withinBounds;
		}

		bool line::hasIntercept(line _line)
		{
			if(slope.x == 0 && _line.slope.x == 0 && displacement.x == _line.displacement.x) return true;
			else if(slope.y == 0 && _line.slope.y == 0 && displacement.y == _line.displacement.y) return true;
			else if((slope.x == 0 && _line.slope.x != 0) || (_line.slope.x == 0 && slope.x != 0)) return true;
			else if((slope.y == 0 && _line.slope.y != 0) || (_line.slope.y == 0 && slope.y != 0)) return true;
			else if(slope.x != 0 && slope.y != 0 && _line.slope.x != 0 && _line.slope.y != 0) return true;
			else if(slope == _line.slope)
			{
				if(displacement == _line.displacement) return true;
				if(displacement != _line.displacement)
				{
					//Checks if the displacement + the slope * a constant == the displacement of the argument, for x and y, and checks if the constant is the same for both x and y
					if((_line.displacement.x - displacement.x) / slope.x == (_line.displacement.y - displacement.y) / slope.y) return true;
				}
			}
			return false;
		}

		coord2 line::getIntercept(line _line)
		{
			if(hasIntercept(_line) == false)
			{
				_DEBUG_ERROR("No intercept!");
				return coord2(0, 0);
			}
			else
			{
				if(slope.x == 0 && _line.slope.x != 0)
				{
					return coord2(displacement.x, _line.getY(displacement.x));
				}
				else if(_line.slope.x == 0 && slope.x != 0)
				{
					return coord2(_line.displacement.x, getY(_line.displacement.x));
				}
				else if(slope.y == 0 && _line.slope.y != 0)
				{
					return coord2(displacement.y, displacement.y);
				}
				else if(_line.slope.y == 0 && slope.y != 0)
				{
					return coord2(_line.displacement.y, _line.displacement.y);
				}
				else
				{
					float x = (_line.displacement.y - displacement.y + (getSlope() * displacement.x) - (_line.getSlope() * _line.displacement.x)) / (getSlope() - _line.getSlope());
					return var::coord2(x, getY(x));
				}
			}
		}

		bool line::isInterceptWithinBounds(line _line)
		{
			if(hasIntercept(_line) == false) return false;
			else
			{
				coord2 intercept = getIntercept(_line);
				return isCoordWithinBounds(intercept) && _line.isCoordWithinBounds(intercept);
			}
		}

		float line::getLengthBetween(float _x1, float _x2)
		{
			return sqrt(pow((_x1 - _x2), 2) + pow(getY(_x1) - getY(_x2), 2));
		}

		float line::getLengthBetweenBounds()
		{
			if(yBounds == false && xBounds == false) return 0;		//The length would be infinite
			float x_lowy;			//The greater value of x_lowy and x_highy
			float x_highy;			//The lesser value of x_lowy and x_highy
			float lowx, highx;		//The best x and y values that represent the best bounds (basically the innermost boudnaries)
			if(yBounds)
			{
				if(getSlopeSign() > 0)
				{
					x_lowy = getX(lowxBound);
					x_highy = getX(highyBound);
				}
				else if(getSlopeSign() < 0)
				{
					x_lowy = getX(highyBound);
					x_highy = getX(lowyBound);
				}
			}
			if(xBounds == true && yBounds == true)
			{
				if(lowxBound >= x_lowy) lowx = lowxBound;
				else if(lowxBound < x_lowy) lowx = x_lowy;
				else lowx = lowxBound;
			}
			else if(xBounds == false && yBounds == true)
			{
				lowx = x_lowy;
				highx = x_highy;
			}
			else if(yBounds == false)
			{
				lowx = lowxBound;
				highx = highxBound;
			}
			return getLengthBetween(lowx, highx);
			return 0;		//An error value, incase something goes wrong
		}

		float line::getLengthToBounds(float _x, int _direction)
		{
			if(yBounds == false && xBounds == false) return 0;		//The length would be infinite
			float x_lowy;			//The greater value of x_lowy and x_highy
			float x_highy;			//The lesser value of x_lowy and x_highy
			float lowx, highx;		//The best x and y values that represent the best bounds (basically the innermost boudnaries)
			if(yBounds)
			{
				if(getSlopeSign() > 0)
				{
					x_lowy = getX(lowxBound);
					x_highy = getX(highyBound);
				}
				else if(getSlopeSign() < 0)
				{
					x_lowy = getX(highyBound);
					x_highy = getX(lowyBound);
				}
			}
			if(xBounds == true && yBounds == true)
			{
				if(lowxBound >= x_lowy) lowx = lowxBound;
				else if(lowxBound < x_lowy) lowx = x_lowy;
				else lowx = lowxBound;
			}
			else if(xBounds == false && yBounds == true)
			{
				lowx = x_lowy;
				highx = x_highy;
			}
			else if(yBounds == false)
			{
				lowx = lowxBound;
				highx = highxBound;
			}
			if(_direction >= 0) lowx = _x;
			else if(_direction < 0) highx = _x;
			return getLengthBetween(lowx, highx);
			return 0;		//An error value, incase something goes wrong
		}

		coord2 line::getCoordAtLength(coord2 _start, float _length)
		{
			return _start + (slope * (_length / sqrt(pow(slope.x, 2) + pow(slope.y, 2))));
		}
	};
};