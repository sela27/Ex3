#include "PhysicalNumber.hpp"
#include "Unit.hpp"
#include <string>
//#include "pch.h"
using ariel::PhysicalNumber;
using ariel::Unit;
//using namespace ariel;
using namespace std;


	PhysicalNumber::PhysicalNumber(double size, Unit type)
	{
		_size = size;
		_type = type;
	}

	PhysicalNumber::PhysicalNumber()
	{
		_size = 0;
		_type = Unit::KM;
	}

	PhysicalNumber::~PhysicalNumber()
	{
	}

	double ariel::PhysicalNumber::getSize()
	{
		return _size;
	}

	Unit ariel::PhysicalNumber::getType()
	{
		return _type;
	}



	PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& other)
	{
		PhysicalNumber convert = Convert(other);
		return PhysicalNumber(convert._size + _size, _type);

	}

	PhysicalNumber PhysicalNumber::operator+=(const PhysicalNumber& other)
	{
		PhysicalNumber convert = Convert(other);
		_size += convert._size;
		return *this;
	}

	PhysicalNumber ariel::PhysicalNumber::operator+()
	{
		return *this;
	}

	PhysicalNumber ariel::PhysicalNumber::operator-(const PhysicalNumber & other)
	{
		PhysicalNumber convert = Convert(other);
		return PhysicalNumber(convert._size - _size, _type);

	}

	PhysicalNumber ariel::PhysicalNumber::operator-=(const PhysicalNumber & other)
	{
		PhysicalNumber convert = Convert(other);
		_size -= convert._size;
		return *this;
	}

	PhysicalNumber ariel::PhysicalNumber::operator-()
	{
		_size = -1 * _size;
		return *this;
	}

	bool ariel::PhysicalNumber::operator<(const PhysicalNumber & other)
	{
		PhysicalNumber convert = Convert(other);
		return _size < convert._size;
	}

	bool ariel::PhysicalNumber::operator>(const PhysicalNumber & other)
	{
		PhysicalNumber convert = Convert(other);
		return _size > convert._size;
	}

	bool ariel::PhysicalNumber::operator<=(const PhysicalNumber & other)
	{
		PhysicalNumber convert = Convert(other);
		return _size <= convert._size;
	}

	bool ariel::PhysicalNumber::operator>=(const PhysicalNumber & other)
	{
		PhysicalNumber convert = Convert(other);
		return _size >= convert._size;
	}

	bool ariel::PhysicalNumber::operator==(const PhysicalNumber & other)
	{
		PhysicalNumber convert = Convert(other);
		return _size == convert._size;
	}

	bool ariel::PhysicalNumber::operator!=(const PhysicalNumber & other)
	{
		PhysicalNumber convert = Convert(other);
		return _size != convert._size;
	}

	PhysicalNumber ariel::PhysicalNumber::operator++()
	{
		_size++;
		return *this;
	}

	PhysicalNumber ariel::PhysicalNumber::operator--()
	{
		_size--;
		return *this;
	}

	/*std::ostream& operator<<(ostream& os, PhysicalNumber& other)
	{
		return (os << other.getSize() << '[' << other.getType() << ']');
	}*/

	PhysicalNumber PhysicalNumber::Convert(const PhysicalNumber& other)
	{
		if (_type == other._type)
		{
			return other;
		}
		else if ((_type < 3 && other._type > 3) || ((_type > 3 && _type < 7) && (other._type < 3 || other._type > 7)) || (_type > 7 && other._type < 7))
		{

			throw string("Cannot convert " + to_string(_type) + "to " + to_string(other._type));
		}
		else
		{
			switch (_type)
			{
			case 0:
			{
				switch (other._type)
				{
				case 1: return PhysicalNumber(other._size * 1000, _type);
					break;
				case 2: return PhysicalNumber(other._size / 100, _type);
				default:
					break;
				}
			}
			break;
			case 1:
			{
				switch (other._type)
				{
				case 0: return PhysicalNumber(other._size / 1000, _type);
					break;
				case 2: return PhysicalNumber(other._size / 100000, _type);
				default:
					break;
				}
			}
			break;
			case 2:
			{
				switch (other._type)
				{
				case 0: return PhysicalNumber(other._size * 100, _type);
					break;
				case 1: return PhysicalNumber(other._size * 100000, _type);
				default:
					break;
				}
			}
			break;
			case 3:
			{
				switch (other._type)
				{
				case 4: return PhysicalNumber(other._size * 60, _type);
					break;
				case 5: return PhysicalNumber(other._size * 3600, _type);
				default:
					break;
				}
			}
			break;
			case 4:
			{
				switch (other._type)
				{
				case 3: return PhysicalNumber(other._size / 60, _type);
					break;
				case 5: return PhysicalNumber(other._size * 60, _type);
				default:
					break;
				}
			}
			break;
			case 5:
			{
				switch (other._type)
				{
				case 3: return PhysicalNumber(other._size / 3600, _type);
					break;
				case 4: return PhysicalNumber(other._size / 60, _type);
				default:
					break;
				}
			}
			break;
			case 6:
			{
				switch (other._type)
				{
				case 7: return PhysicalNumber(other._size * 1000, _type);
					break;
				case 8: return PhysicalNumber(other._size * 1000000, _type);
				default:
					break;
				}
			}
			break;
			case 7:
			{
				switch (other._type)
				{
				case 6: return PhysicalNumber(other._size / 1000, _type);
					break;
				case 8: return PhysicalNumber(other._size * 1000, _type);
				default:
					break;
				}
			}
			break;
			case 8:
			{
				switch (other._type)
				{
				case 6: return PhysicalNumber(other._size / 1000000, _type);
					break;
				case 7: return PhysicalNumber(other._size / 1000, _type);
				default:
					break;
				}
			}
			break;
			default:
				break;
			}
		}
	}

