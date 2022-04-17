#include <iostream>
#include "std_lib_facilities.h"

template<typename T>	//Task 1.

class S {
public:		//Task 7. (val priváttá tétele - amit a feladat kér - hibát okoz.)
	T val;		//Task 2.
	
	const auto getvalconst() {return val;}	//Task 5.
	auto getval() {return val;}		//Task 11.
	
	//void setval(auto p) {val=p;}
//	
	
};

//Task 6. (dunno how)
//Task 12. (dunno how) -> Task13,14

int main()
{
	S<int> pint = {90};		//Task 3.
	S<char> pch = {'q'};
	S<double> pdbl = {3.141};
	S<string> pstr = {"cdl"};
	S<vector<int>> pvecint = {{4,16}};
	
	cout << "int: " << pint.getval() << endl	//Tasks 4 & 8.
	<< "char: " << pch.getval() << endl
	<< "double: " << pdbl.getval() << endl
	<< "string: " << pstr.getval() << endl;
	
	pint = {66};
	cout << "\nint: " << pint.getval() << endl;
	
	pch = {'f'};
	cout << "char: " << pch.getval() << endl;
	
	pdbl = {30.13};
	cout << "double: " << pdbl.getval() << endl;
	
	pstr = {"dvd"};
	cout << "string: " << pstr.getval() << endl;
	return 0;
}
