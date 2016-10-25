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
			if(autoFill)
			{
				lookupValues();
				inferValues();
			}
		}

		element::element(int _protons, float _neutrons, bool autoFill)
		{
			setProtons(_protons);
			setNeutrons(_neutrons);
			if(autoFill)
			{
				lookupValues();
				inferValues();
			}
		}

		element::element(int _protons, float _neutrons, int _electrons, bool autoFill)
		{
			setProtons(_protons);
			setNeutrons(_neutrons);
			setElectrons(_electrons);
			if(autoFill)
			{
				lookupValues();
				inferValues();
			}
		}

		element::element(int _protons, float _neutrons, int _electrons, float _atomicMass, bool autoFill)
		{
			setProtons(_protons);
			setNeutrons(_neutrons);
			setElectrons(_electrons);
			setAtomicMass(_atomicMass);
			if(autoFill)
			{
				lookupValues();
				inferValues();
			}
		}

		element::element(string _symbol, bool autoFill)
		{
			setName(symbol);
			if(autoFill)
			{
				lookupValues();
				inferValues();
			}
		}

		element::element(string _symbol, string _name, bool autoFill)
		{
			setName(_name);
			setSymbol(_symbol);
			if(autoFill)
			{
				lookupValues();
				inferValues();
			}
		}

		element::element(string _symbol, string _name, int _protons, float _neutrons, int _electrons, float _atomicMass)
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
			if(_protons <= 0)
			{
				_DEBUG_ERROR("Bad '_protons': Value cannot <= 0.");
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
			if(_neutrons < 0)
			{
				_DEBUG_ERROR("Bad '_neutrons': Value cannot < 0.");
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
			if(_electrons < 0)
			{
				_DEBUG_ERROR("Bad '_electrons': Value cannot < 0.");
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
			if(_atomicMass <= 0)
			{
				_DEBUG_ERROR("Bad '_atomicMass': Value cannot <= 0.");
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
			if(_atomicNumber <= 0)
			{
				_DEBUG_ERROR("Bad '_atomicNumber': Value cannot <= 0.");
				return false;
			}
			else if(protonsSet == true && neutronsSet == true)
			{
				if(_atomicNumber != protons + neutrons)
				{
					_DEBUG_ERROR("Bad '_atomicNumber': Value is in conflict with existing 'protons' and 'neutrons' value.");
					return false;
				}
				else
				{
					atomicNumber = _atomicNumber;
					atomicNumberSet = true;
					return true;
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
			charge = _charge;
			chargeSet = true;
			return true;
		}

		bool element::setDensity(float _density)
		{
			if(_density > 0)
			{
				density = _density;
				densitySet = true;
			}
			else return false;
		}

		bool element::isProtonsSet()
		{
			return protonsSet;
		}

		bool element::isNeutronsSet()
		{
			return neutronsSet;
		}

		bool element::isElectronsSet()
		{
			return electronsSet;
		}

		bool element::isNameSet()
		{
			return nameSet;
		}

		bool element::isSymbolSet()
		{
			return symbolSet;
		}

		bool element::isAtomicMassSet()
		{
			return atomicMassSet;
		}

		bool element::isAtomicNumberSet()
		{
			return atomicNumberSet;
		}

		bool element::isChargeSet()
		{
			return chargeSet;
		}

		bool element::isDensitySet()
		{
			return densitySet;
		}

		int element::getProtons()
		{
			if(protonsSet == false)
			{
				_DEBUG_ERROR("'protons' has not yet been set.\n Returning '1' in the place of 'protons'.  This may result in calculation errors.");
				return 1;
			}
			return protons;
		}

		float element::getNeutrons()
		{
			if(neutronsSet == false)
			{
				_DEBUG_ERROR("'neutrons'has not yet been set.\nReurning '1' in the place of 'neutrons'.  This may result in calculation errors.");
				return 1;
			}
			else return neutrons;
		}

		int element::getElectrons()
		{
			if(electronsSet == false)
			{
				_DEBUG_ERROR("'electrons' has not yet been set?\nReturning '1' in the place of 'electrons'.  This may result in calculation errors.");
				return 1;
			}
			else return electrons;
		}

		string element::getName()
		{
			if(nameSet == false)
			{
				_DEBUG_ERROR("'name' has not yet been set?\nReturning 'Err' in the place of 'name'.  This may result in errors.");
				return "Err";
			}
			else return name;
		}

		string element::getSymbol()
		{
			if(symbolSet == false)
			{
				_DEBUG_ERROR("'symbol' has not yet been set?\nReturning 'Er' in the place off 'name'.  This may result in errors.");
				return "Er";
			}
			else return symbol;
		}

		float element::getAtomicMass()
		{
			if(atomicMassSet == false)
			{
				_DEBUG_ERROR("'atomicMass' has not yet been set?\nReturning 1 in the place of 'atomicMass'.  This may result in calculation errors.");
				return 1;
			}
			else return atomicMass;
		}

		float element::getAtomicNumber()
		{
			if(atomicNumberSet == false)
			{
				_DEBUG_ERROR("'atomicNumber' has not yet been set?\nReturning 1 in the place of 'atomicMass'.  This may result in calculation errors.");
				return 1;
			}
			else return atomicNumber;
		}

		int element::getCharge()
		{
			if(chargeSet == false)
			{
				_DEBUG_ERROR("'charge' has not yet been set?\nReturning 1 in the place of 'charge'.  THis may result in calculation errors.");
				return 1;
			}
			else return charge;
		}

		float element::getDensity()
		{
			if(isDensitySet()) return density;
			else
			{
				_DEBUG_ERROR("'desity' has not been set.\nReturning '1' in the place of 'mass'.  This may result in errors.");
				return 1;
			}
		}

		bool element::inferValues()
		{
			bool change = false;		//If the current cycle has calculated any values
			bool anyChanges = false;	//If there were any changes at all
			do
			{
				change = false;
				if(protonsSet == false)			//Calculating protons
				{
					if(electronsSet == true && chargeSet == true)
					{
						setProtons(charge + electrons);
						change = true;
					}
					else if(atomicNumberSet == true && neutronsSet == true && fmod(neutrons, 1) != 0)
					{
						setProtons(atomicNumber - neutrons);
						change = true;
					}
				}
				if(neutronsSet == false)		//Calculating neutrons
				{
					if(atomicNumberSet == true && protonsSet == true)
					{
						setNeutrons(atomicNumber - protons);
						change = true;
					}
				}
				if(electronsSet == false)		//Calculating electrons
				{
					if(protonsSet == true && chargeSet == true)
					{
						setElectrons(protons - charge);
						change = true;
					}
				}
				if(atomicNumberSet == false)	//Calculating atomicNumber
				{
					if(protonsSet == true && neutronsSet == true)
					{
						setAtomicNumber(protons + neutrons);
						change = true;
					}
				}
				if(chargeSet == false)			//Calculating charge
				{
					if(protonsSet == true && electronsSet == true)
					{
						setCharge(protons - electrons);
						change = true;
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

		string element::toString(bool multiLine)
		{
			string separator = " | ";
			if(multiLine) separator = "\n";
			string output = "";

			output.append("Name:");
			if(nameSet) output.append(name);
			else output.append("Not set");
			output.append(separator);

			output.append("Symbol:");
			if(symbolSet) output.append(symbol);
			else output.append("Not set");
			output.append(separator);

			output.append("Protons:");
			if(protonsSet) output.append(conv::toString(getProtons()));
			else output.append("Not set");
			output.append(separator);

			output.append("Neutrons:");
			if(neutronsSet)	output.append(conv::toString(getNeutrons()));
			else output.append("Not set");
			output.append(separator);

			output.append("Electrons:");
			if(electronsSet) output.append(conv::toString(getElectrons()));
			else output.append("Not set");
			output.append(separator);

			output.append("Charge:");
			if(chargeSet) output.append(conv::toString(getCharge()));
			else output.append("Not set");
			output.append(separator);

			output.append("Atomic Mass:");
			if(atomicMassSet) output.append(conv::toString(getAtomicMass()));
			else output.append("Not set");
			output.append(separator);

			output.append("Atomic Number:");
			if(atomicNumberSet) output.append(conv::toString(getAtomicNumber()));
			else output.append("Not set");

			return output;
		}

		compound::compound(bool _isElement)
		{
			isElement = _isElement;
			isSegment = !_isElement;
		}

		compound::compound(vector<element> _elements)
		{
			setElements(_elements);
			isElement = true;
			isSegment = false;
		}

		compound::compound(vector<element> _elements, vector<int> _subscripts)
		{
			setElements(_elements);
			setSubscripts(_subscripts);
			isElement = true;
			isSegment = false;
		}

		compound::compound(vector<element> _elements, vector<int> _subscripts, int _amount)
		{
			setElements(_elements);
			setSubscripts(_subscripts);
			setAmount(_amount);
			isElement = true;
			isSegment = false;
		}

		compound::compound(vector<compound> _segments)
		{
			setSegments(_segments);
			isSegment = true;
			isElement = false;
		}

		compound::compound(vector<compound> _segments, int _amount)
		{
			setSegments(_segments);
			setAmount(_amount);
		}

		bool compound::getIsElement()
		{
			return isElement;
		}

		bool compound::getIsSegment()
		{
			return isSegment;
		}

		bool compound::setSegments(vector<compound> _segments)
		{
			if(getIsSegment())
			{
				segments = _segments;
				return true;
			}
			else
			{
				_DEBUG_ERROR("Unable to set 'segments', segment is initialized as an element.");
				return false;
			}
		}

		bool compound::addSegment(compound _segment)
		{
			if(getIsSegment())
			{
				segments.push_back(_segment);
				return true;
			}
			else
			{
				_DEBUG_ERROR("Unable to set 'segments', segment is initialized as an element.");
				return false;
			}
		}

		bool compound::removeSegment(int _segmentID)
		{
			if(segments.size() < _segmentID)
			{
				return false;
			}
			else
			{
				segments.erase(segments.begin() + _segmentID);
				return true;
			}
		}

		bool compound::setElements(vector<element> _elements)
		{
			if(getIsElement())
			{
				elements = _elements;
				return true;
			}
			else
			{
				_DEBUG_ERROR("Unable to set 'element', segment is initialized as a sub-segment.");
				return false;
			}
		}

		bool compound::addElement(element _element)
		{
			elements.push_back(_element);
			return true;
		}

		bool compound::addElement(element _element, int _subscript)
		{
			elements.push_back(_element);
			return setSubscript(elements.size() - 1, _subscript);
			return false;
		}

		bool compound::removeElement(int _elementID)
		{
			if(elements.size() < _elementID)
			{
				return false;
			}
			else
			{
				elements.erase(elements.begin() + _elementID);
				return false;
			}
		}

		bool compound::setSubscripts(vector<int> _subscripts)
		{
			bool ret = true;
			for(int x = 0; x < _subscripts.size(); x++)
			{
				if(setSubscript(x, _subscripts[x]) == false) ret = false;
			}
			return ret;
		}

		bool compound::setSubscript(int _elemID, int _subscript)
		{
			if(getIsElement())
			{
				if(_subscript < 0)		//_subscript input validation
				{
					_DEBUG_ERROR("Bad '_subscript': Value cannot < 0.");
					return false;
				}
				else
				{
					if(_elemID < 0)		//_elemID input validation
					{
						_DEBUG_ERROR("Bad '_elemID': _elemID cannot < 0.");
						return false;
					}
					else if(elements.size() < _elemID)
					{
						_DEBUG_ERROR("Bad '_elemID': There is no corresponding element for subscript.");
						return false;
					}
					else
					{
						if(subscripts.size() < _elemID)
						{
							while(subscripts.size() < _elemID) subscripts.push_back(0);
						}
						subscripts[_elemID] = _subscript;
						return true;
					}
				}
			}
			else
			{
				_DEBUG_ERROR("Unable to set 'subscript', segment is initialized as a sub-segment.");
				return false;
			}
			_DEBUG_ERROR("Error: Unknown case.  Values escaped validation tree, caught at end-of-function.");
			return false;
		}

		bool compound::setAmount(int _amount)
		{
			if(_amount <= 0)
			{
				_DEBUG_ERROR("Bad '_amount': Value cannot be <= 0.");
				return false;
			}
			else
			{
				amount = _amount;
				amountSet = true;
				return true;
			}
		}

		bool compound::setName(string _name)
		{
			if(_name.length() == 0)
			{
				_DEBUG_ERROR("Bad '_name': cannot be \"\"");
				return false;
			}
			else
			{
				name = _name;
				return true;
			}
			return false;
		}

		bool compound::setAtomicMass(float _atomicMass)
		{
			if(_atomicMass <= 0) return false;
			else
			{
				atomicMass = _atomicMass;
				return true;
			}
		}

		bool compound::setCharge(int _charge)
		{
			charge = _charge;
			return false;
		}

		bool compound::setMass(float grams)
		{
			if(grams <= 0) return false;
			else
			{
				mass = grams;
				massSet = true;
			}
		}

		bool compound::setMols(float _mols)
		{
			if(_mols <= 0) return false;
			else
			{
				mols = _mols;
				molsSet = true;
			}
		}

		bool compound::isElementSet(int _elemID)
		{
			if(elements.size() > _elemID) return true;
			else return false;
		}

		bool compound::isSubscriptSet(int _elemID)
		{
			if(subscripts.size() > _elemID && subscripts[_elemID] > 0) return true;
			else return false;
		}

		bool compound::isAmountSet()
		{
			return amountSet;
		}

		bool compound::isNameSet()
		{
			return nameSet;
		}

		bool compound::isAtomicMassSet()
		{
			return atomicMassSet;
		}

		bool compound::isChargeSet()
		{
			return chargeSet;
		}

		bool compound::isMassSet()
		{
			return massSet;
		}

		bool compound::isMolsSet()
		{
			return molsSet;
		}

		vector<compound> compound::getSegments()
		{

			return segments;
		}

		vector<element> compound::getElements()
		{
			if(isElementSet() == false)
			{
				_DEBUG_ERROR("'elements' has not yet been set.\nReturning a vector with a blank element template in the place off 'elements'.  This may result in errors.");
				vector<element> t;
				t.push_back(element());
				return t;
			}
			else return elements;
		}

		element compound::getElement(int _elemID)
		{
			if(_elemID < 0)
			{
				_DEBUG_ERROR("Bad '_elemID': _elemID cannot be < 0.\nReturning a blank 'element' template in the place of 'element[_elemID]'.  This may result in errors.");
				return element();
			}
			else if(_elemID > elements.size())
			{
				_DEBUG_ERROR("Bad '_elemID': there is no element for that value.\nReturning a blank 'element' template in the place of 'element[_elemID]'.  This may result in erros.");
				return element();
			}
			else
			{
				return elements[_elemID];
			}
		}

		int compound::getSubscript(int _elemID)
		{
			if(isSubscriptSet(_elemID) == false)
			{
				_DEBUG_ERROR("'subscript' has not yet been set.\nReturning '1' in the place of 'subscript'.  This may result in errors.");
				return 1;
			}
			else return subscripts[_elemID];
		}

		vector<int> compound::getSubscripts()
		{
			return subscripts;
		}

		int compound::getAmount()
		{
			if(isAmountSet() == false)
			{
				_DEBUG_ERROR("'amount' has not been set.\nReturning '1' in the place of 'amount'.  This may result in errors.");
				return 1;
			}
			else return amount;
		}

		string compound::getName()
		{
			if(isNameSet() == false)
			{
				_DEBUG_ERROR("'amount' has not been set.\nReturning 'Err' in the place of 'name'.  This may result in errors.");
				return "Err";
			}
			else return name;
		}

		float compound::getAtomicMass()
		{
			if(isAtomicMassSet() == false)
			{
				_DEBUG_ERROR("'amount' has not been set.\nReturning '1' in the place of 'atomicMass'.  This may result in errors.");
				return 1;
			}
			else return atomicMass;
		}

		int compound::getCharge()
		{
			if(isChargeSet() == false)
			{
				_DEBUG_ERROR("'charge' has not been set.\nReturning '1' in the place of 'charge'.  This may result in errors.");
				return 1;
			}
			else return charge;
		}
		float compound::getMass()
		{
			if(isMassSet() == false)
			{
				_DEBUG_ERROR("'mass' has not been set.\nReturning '1' in the place of 'mass'.  This may result in errors.");
				return 1;
			}
			else return mass;
		}

		float compound::getMols()
		{
			if(isMolsSet() == false)
			{
				_DEBUG_ERROR("'mols' has not been set.\nReturning '1' in the place of 'mols'.  This may result in errors.");
				return 1;
			}
			else return mols;
		}

		bool compound::calculateValues()
		{
			bool totalChange = false;
			bool localChange = false;
			bool canSetAtomicMass = true;
			bool canSetCharge = true;
			int charge = 0;
			float atomicMass = 0;
			do
			{
				if(getIsElement())			//Calulating traits that can be found as a sum of element properties
				{
					canSetAtomicMass = true;
					canSetCharge = true;
					charge = 0;
					atomicMass = 0;
					for(int x = 0; x < elements.size(); x++)
					{
						if(elements[x].inferValues()) localChange = true;
						if(isAtomicMassSet() == false)
						{
							if(elements[x].isAtomicMassSet()) atomicMass += elements[x].getAtomicMass();
							else canSetAtomicMass = false;
						}
						if(isChargeSet() == false)
						{
							if(elements[x].isChargeSet()) charge += elements[x].getCharge();
							else canSetCharge = false;
						}
					}
					if(canSetAtomicMass)
					{
						setAtomicMass(atomicMass);
						localChange = true;
					}
					if(canSetCharge)
					{
						setCharge(charge);
						localChange = true;
					}
				}
				else if(getIsSegment())		//Calulating traits that can be found as a sum of segment properties
				{
					canSetAtomicMass = true;
					canSetCharge = true;
					charge = 0;
					atomicMass = 0;
					for(int x = 0; x < segments.size(); x++)
					{
						if(segments[x].calculateValues()) localChange = true;
						if(isAtomicMassSet() == false)
						{
							if(segments[x].isAtomicMassSet()) atomicMass += segments[x].getAtomicMass();
							else canSetAtomicMass = false;
						}
						if(isChargeSet() == false)
						{
							if(segments[x].isChargeSet()) charge += segments[x].getCharge();
							else canSetCharge = false;
						}
					}
					if(canSetAtomicMass)
					{
						setAtomicMass(atomicMass);
						localChange = true;
					}
					if(canSetCharge)
					{
						setCharge(charge);
						localChange = true;
					}
				}
				if(isAtomicMassSet() == false)		//Calculating atomic mass
				{
					if(isMolsSet() == true && isMassSet() == true)		//From mass and mols
					{
						if(getMass() / getMols() > 0)		//Verifys that the calculated value is valid
						{
							setAtomicMass(getMass() / getMols());
							localChange = true;
						}
						else _DEBUG_ERROR("Calculated atomic mass is <= 0!  Either the mass or mols is incorrect, if not both!");
					}
				}
				if(isMassSet() == false)		//Calculating mass
				{
					if(isMolsSet() == true && isAtomicMassSet() == true)	//From mols and atomic mass
					{
						if(getMols() * getAtomicMass() > 0)		//Verifys that the calculated value is valid
						{
							setMass(getMols() * getAtomicMass());
							localChange = true;
						}
						else _DEBUG_ERROR("Calculated mass is <= 0!  Either the mols or the atomic mass is incorrect, if not both!");
					}
				}
				if(isMolsSet() == false)		//Calculating mols
				{
					if(isAtomicMassSet() == true && isMassSet() == true)	//From atomicMass and mass
					{
						if(getMass() / getAtomicMass() > 0)		//Verifys that the calculated value is valid
						{
							setMols(getMass() / getAtomicMass());
							localChange == true;
						}
						else _DEBUG_ERROR("Calculated mols is <= 0!  Either the mass or atomic mass is incorrect, if not both!");
					}
				}
				if(localChange) totalChange = true;
			}
			while(localChange);
			return totalChange;
		}
	}
}