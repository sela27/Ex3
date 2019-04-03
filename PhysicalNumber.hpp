#pragma once

#include "Unit.hpp"

namespace ariel
{
	class PhysicalNumber
	{
	public:
		PhysicalNumber(double size , Unit type);
		PhysicalNumber();
		~PhysicalNumber();
		PhysicalNumber operator+(const PhysicalNumber& other);

	private:
		double _size;
		Unit _type;
		PhysicalNumber Convert(const PhysicalNumber& other);
	};
}
