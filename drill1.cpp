#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Point tl{100,100};
	Simple_window win {tl,800,600,"Canvas"};
	Axis xa {Axis::x, Point{20,400}, 280, 10, "x axis"};
	
	Axis ya {Axis::y, Point{20,400}, 280,10,"y axis"};
	ya.set_color(Color::red);
	ya.label.set_color(Color::dark_blue);
	
	Function sine {sin,0,100,Point{20,250},1000,50,50};
	sine.set_color(Color::blue);
	
	Polygon poly;
	poly.add(Point{300,300});
	poly.add(Point{350,200});
	poly.add(Point{400,300});
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	
	Rectangle r {Point{200,300},100,50};
	
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,150});
	poly_rect.add(Point{200,150});
	poly_rect.add(Point{200,200});
	poly_rect.add(Point{100,200});
	poly_rect.add(Point{50,175});
	poly_rect.set_color(Color::yellow);
	
	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dot,6));
	poly_rect.set_style(Line_style(Line_style::dash,3));
	poly_rect.set_fill_color(Color::black);
	
	Text t {Point{150,250},"Hello, graphical world!"};
//	t.set_font(Font::times_italic);
	t.set_font_size(20);
	
	Image ii{Point{200,350},"badge.jpg"};
	
	Circle c {Point{100,300},50};
	
	Ellipse e {Point{100,300},75,25};
	c.set_color(Color::yellow);
	e.set_color(Color::white);
	Mark m {Point{100,310},'x'};
	
	win.attach(m);
	win.attach(c);
	win.attach(e);
	win.attach(ii);
	win.attach(t);
	win.attach(poly_rect);
	win.attach(r);
	win.attach(sine);
	win.attach(ya);
	win.attach(xa);
	win.wait_for_button();
}
