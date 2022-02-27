#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Point cross {100,100};
	Simple_window win1 {cross,800,1000,"Canvas"};
	
	int x_size = win1.x_max(); // get the size of our window
	int y_size = win1.y_max();
	int x_grid = 100;
	int y_grid = 100;
	
	Lines grid;
	for (int x=x_grid; x<x_size; x+=x_grid)
	grid.add(Point{x,0},Point{x,800}); // vertical line
	for (int y = y_grid; y<900; y+=y_grid)
	grid.add(Point{0,y},Point{x_size,y}); // horizontal line
	
	Vector_ref<Rectangle> rect;
	
	Rectangle r {Point{100,200},Point{200,300}};
	rect.push_back(r);
	
	rect.push_back(new Rectangle{Point{50,60},Point{80,90}});
	
	for (int i=0; i<rect.size(); ++i)
		rect[i].move(100,100);
	
	Vector_ref<Rectangle> vr;
	for (int i = 0; i<8; ++i){
		for (int j = 0; j<8; ++j) {
			if(i==j){
				vr.push_back(new Rectangle{Point{i*100,j*100},100,100});
				vr[vr.size()-1].set_fill_color(Color::red);
				win1.attach(vr[vr.size()-1]);
				}
		}
	}
	
	Image car1{Point{200,0},"car.jpg"};
	Image car2{Point{400,0},"car.jpg"};
	Image car3{Point{600,0},"car.jpg"};
	
	Image logo{Point{0,0},"logo.jpg"};
	
	win1.attach(car1);
	win1.attach(car2);
	win1.attach(car3);
	win1.attach(grid);
	win1.attach(logo);
	
	int j=0;
	for (int i=0; i<8; ++i){
		j=0;
		for (j=0; j<8; ++j){
			win1.wait_for_button();
			win1.set_label("moving logo");
			if(j<7){
				logo.move(100,0);
			}
			else{
				logo.move(-700,100);
			}
		}
	}
}

