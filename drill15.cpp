#include <iostream>
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

double one(double) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x)+slope(x);}

void error()
{
	throw runtime_error("error()");
}

class Person{
private:
	string first_name;
	string last_name;
	int age;
public:
	string get_fname() {return first_name;}
	string get_lname() {return last_name;}
	int get_age() {return age;}
	
	void set_name(string fn, string ln)
		{first_name = fn;
		last_name = ln;}
	void set_age(int ae)
		{age = ae;}
	
	Person(string fn, string ln, int ag) : first_name{fn}, last_name{ln}, age{ag}
	{
		for (int i=0; i<(fn.length()+ln.length()); i++){
			if (ag>=150 || fn[i] == '$' || fn[i] == '^'
				   || fn[i] == '!' || fn[i] == ';' || fn[i] == ':'
				   || fn[i] == '#' || fn[i] == '@' || fn[i] == '&'
				   || fn[i] == '\'' || fn[i] == '[' || fn[i] == ']'
				   || fn[i] == '"' || fn[i] == '*' || fn[i] == '%'
				   || ln[i] == '$' || ln[i] == '^'
				   || ln[i] == '!' || ln[i] == ';' || ln[i] == ':'
				   || ln[i] == '#' || ln[i] == '@' || ln[i] == '&'
				   || ln[i] == '\'' || ln[i] == '[' || ln[i] == ']'
				   || ln[i] == '"' || ln[i] == '*' || ln[i] == '%')
			error();
		}
	}
	Person() : first_name{"Noname"},last_name{"Person"},age{0} {}
};

istream& operator>>(istream& is, Person& p)
{
	string fn;
	string ln;
	int ae;
	is >> fn >> ln >> ae;
	p.set_name(fn,ln);
	p.set_age(ae);
	return is;
}

ostream& operator<<(ostream& os, Person p)
{
	return os << p.get_fname() << " " << p.get_lname() << ", " << p.get_age();
}

int main()
{
/*	constexpr int r_min = -10;
	constexpr int r_max = 11;
	
	constexpr int n_points = 400;
	
	constexpr int x_scale = 20;
	constexpr int y_scale = 20;
	Point centre {300,300};
	Simple_window win {centre,600,600,"Function graphs"};
	
	Axis xa {Axis::x, Point{100,300}, 400, 20, "1 == 20 pixels"};
	Axis ya {Axis::y, Point{300,500}, 400, 20, "1 == 20 pixels"};
	xa.set_color(Color::red);
	ya.set_color(Color::red);
	xa.label.set_color(Color::black);
	ya.label.set_color(Color::black);
	
	Function s {one,r_min,r_max,centre,n_points,x_scale,y_scale};
	Function s2 {slope,r_min,r_max,centre,n_points,x_scale,y_scale};
	Function s3 {square,r_min,r_max,centre,n_points,x_scale,y_scale};
	Function s4 {cos,r_min,r_max,centre,n_points,x_scale,y_scale};
	Function s5 {sloping_cos,r_min,r_max,centre,n_points,x_scale,y_scale};
	
	s4.set_color(Color::blue);
	
	Text s2_label {Point{100,390},"x/2"};
	
	win.attach(xa);
	win.attach(ya);
	
	win.attach(s);
	win.attach(s2);
	win.attach(s2_label);
	win.attach(s3);
	win.attach(s4);
	win.attach(s5);
	
	win.wait_for_button();*/
	
	Person prs{"Goofy","Boy",63};
	cout<<prs<<endl;
	Person prs2{};
	cout<<prs2<<"\n\n";
	
	vector<Person> people {};
	
	Person pp1,pp2,pp3,pp4;
	cin >> pp1 >> pp2 >> pp3 >> pp4;
	
	people.push_back(pp1);
	people.push_back(pp2);
	people.push_back(pp3);
	people.push_back(pp4);
	
	for (int i=0; i<people.size(); i++){
		cout<<people[i]<<"\n";
	}
	return 0;
}
