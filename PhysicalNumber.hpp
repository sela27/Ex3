#pragma once

#include "Unit.hpp"

namespace ariel
{

	class PhysicalNumber
	{
	private:
		double _size;
		Unit _type;
		PhysicalNumber Convert(const PhysicalNumber& other);


	public:
		PhysicalNumber(double size, Unit type);
		PhysicalNumber();
		~PhysicalNumber();
		double getSize();
		Unit getType();
		PhysicalNumber operator+(const PhysicalNumber& other);
		PhysicalNumber operator+=(const PhysicalNumber& other);
		PhysicalNumber operator+();
		PhysicalNumber operator-(const PhysicalNumber& other);
		PhysicalNumber operator-=(const PhysicalNumber& other);
		PhysicalNumber operator-();
		bool operator<(const PhysicalNumber& other);
		bool operator>(const PhysicalNumber& other);
		bool operator<=(const PhysicalNumber& other);
		bool operator>=(const PhysicalNumber& other);
		bool operator==(const PhysicalNumber& other);
		bool operator!=(const PhysicalNumber& other);
		friend std::ostream& operator<<(ostream& os, const PhysicalNumber& other)
		{
			return (os << other._size << '[' << other._type << ']');
		}
		friend std::ostream& operator>>(ostream& os, const PhysicalNumber& other)
		{

		}
		PhysicalNumber operator++();
		PhysicalNumber operator--();
	};
}
