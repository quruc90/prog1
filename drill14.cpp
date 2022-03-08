#include <iostream>
#include "std_lib_facilities.h"


class B1{
public:
	virtual void vf(){
		std::cout<<"vf in B1\n";}
	void f(){
		std::cout<<"f in B1\n";}
	virtual void pvf()=0;			//this makes B1 abstract ->
};						//cannot declare B1 type object.

class D1 : public B1 {
public:
	void vf(){
		std::cout<<"override vf in D1\n";}
	void f(){
		std::cout<<"f in D1\n";}
};

class D2 : public D1 {
public:
	void pvf(){
		std::cout<<"pvf in D2\n";}
};

class B2{
public:
	virtual void pvf()=0;
};

class D21 : public B2{
public:
	string dstr = "wow this works omg\n";
	void pvf(){
		std::cout<<dstr;}
	void f(){
		std::cout<<"f in D21\n";}
};

class D22 : public B2{
public:
	int dint = 7357;
	void pvf(){
		std::cout<<dint;}
	void f(B2& b2ref){
		b2ref.pvf();
	}
};

int main()
{
//	B1 b1;
//	b1.vf();
//	b1.f();
	
//	D1 d1;
//	d1.vf();
//	d1.f();
	
//	B1& b1ref=d1;
//	b1ref.vf();
//	b1ref.f();

	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();
	
	D21 d21;
	D22 d22;
	B2& b2ref=d21;
	
	d21.f();
	d22.f(b2ref);
	
	return 0;
}
