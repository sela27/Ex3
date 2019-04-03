// Ex3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include "PhysicalNumber.hpp"
#include "Unit.hpp"
using ariel::PhysicalNumber;
using ariel::Unit;
using namespace std;

int main()
{
	try 
	{
		PhysicalNumber a(2, Unit::KM);   // 2 kilometers
		PhysicalNumber b(300, Unit::M);  // 300 meters
		a + b;
		//cout << a << endl;   // Prints "2[km]"
		//cout << (a + b) << endl;
	}
	catch (...)
	{
		cout << "Exeption" << endl;
	}
}