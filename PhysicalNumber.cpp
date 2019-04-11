#include "PhysicalNumber.h"
#include "Unit.h"
#include <string>
#include <iostream>
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

	double ariel::PhysicalNumber::getSize() const
	{
		return _size;
	}

	Unit ariel::PhysicalNumber::getType() const
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
		return PhysicalNumber(_size - convert._size, _type);

	}

	PhysicalNumber ariel::PhysicalNumber::operator-=(const PhysicalNumber & other)
	{
		PhysicalNumber convert = Convert(other);
		_size -= convert._size;
		return *this;
	}

	PhysicalNumber ariel::PhysicalNumber::operator-()
	{
		return PhysicalNumber((-1 * _size) , _type);
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
	PhysicalNumber ariel::PhysicalNumber::operator++(int)
	{
		PhysicalNumber temp = *this;
		++_size;
		return temp;
	}

	PhysicalNumber ariel::PhysicalNumber::operator--(int)
	{
		PhysicalNumber temp = *this;
		--_size;
		return temp;
	}


	std::ostream & ariel::operator<<(std::ostream & os, const PhysicalNumber & other)
	{
		return (os << other.getSize() << '[' << Unit_to_string(other.getType()) << ']');
	}

	std::istream & ariel::operator>>(istream& input, PhysicalNumber & other)
	{
		std::string s(std::istreambuf_iterator<char>(input), {});
		try
		{
			string Ssize = s.substr(0 , s.find('['));
			double size = stod(Ssize);
			string Sunit = s.substr(s.find('[') + 1 , s.find(']') - s.find('[') - 1);
			Unit type = string_to_unit(Sunit);
			other._size = size;
			other._type = type;
			return input;
		}
		catch(...)
		{
			input.clear(input.rdstate());
			return input;
			//throw std::invalid_argument{"worng string to convert"};
		}
			
	}

	PhysicalNumber PhysicalNumber::Convert(const PhysicalNumber& other)
	{
		if (_type == other._type)
		{
			return other;
		}
		else if ((_type < 3 && other._type > 2) || ((_type > 2 && _type < 6) && (other._type < 3 || other._type > 5)) || (_type > 5 && other._type < 6))
		{

			throw std::invalid_argument{ "Units do not match - [" + Unit_to_string(other._type) + "] cannot be converted to [" + Unit_to_string(_type) + "]" };
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
		throw string("You Cant get here!");
	}

	string ariel::Unit_to_string(Unit t)
	{
		switch (t)
		{
		case ariel::M:
			return "m";
			break;
		case ariel::KM:
			return "km";
			break;
		case ariel::CM:
			return "cm";
			break;
		case ariel::SEC:
			return "sec";
			break;
		case ariel::MIN:
			return "min";
			break;
		case ariel::HOUR:
			return "hour";
			break;
		case ariel::G:
			return "g";
			break;
		case ariel::KG:
			return "kg";
			break;
		case ariel::TON:
			return "ton";
			break;
		default:
			return "Problem!";
			break;
		}
	}
	
	Unit ariel::string_to_unit(string s)
	{
		if(s.compare("m") == 0)
			return Unit::M;
		else if(s.compare("km") == 0)
			return Unit::KM;
		else if(s.compare("cm") == 0)
			return Unit::CM;
		else if(s.compare("sec") == 0)
			return Unit::SEC;
		else if(s.compare("min") == 0)
			return Unit::MIN;
		else if(s.compare("hour") == 0)
			return Unit::HOUR;
		else if(s.compare("g") == 0)
			return Unit::G;
		else if(s.compare("kg") == 0)
			return Unit::KG;
		else if(s.compare("ton") == 0)
			return Unit::TON;
		else
			throw std::invalid_argument{"worng string to convert"};
	}

