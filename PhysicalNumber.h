#pragma once

#include "Unit.h"
#include <iostream>
#include <string>
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
		double getSize() const;
		Unit getType() const;
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
		friend std::ostream& operator<<(std::ostream& os, const PhysicalNumber& other);
		friend std::istream& operator>>(std::istream& input, PhysicalNumber& other);
		PhysicalNumber operator++(int);
		PhysicalNumber operator--(int);
		PhysicalNumber operator++();
		PhysicalNumber operator--();
	};

	std::string Unit_to_string(Unit t);
	Unit string_to_unit(std::string s);
}
