/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"
#include <iostream>


double slope(double x){return x/2;}
double one(double x){return 1;}
double sloping_cos(double x) {return cos(x)+slope(x);}
int main()
{

	Simple_window win{Point{100,100},600,600,"Function graphs"};

	Axis x(Axis::x,Point{50,300},400,20,"1 == 20 pixels");

	Axis y(Axis::y, Point{250,500},400,20,"1 == 20 pixels");


	x.set_color(Color::red);
	y.set_color(Color::red);

	Point orig{250,300};

	Function o{one,-10,10,orig,400,20,20};
	Function slp(slope,-10,10,orig,400,20,20);
	Text t{Point{50,400},"x/2"};



	Function squ([] (double x){return x*x;},-10,10,orig,400,20,20);


	Function f4(cos,-10,10,orig,400,20,20);
	  f4.set_color(Color::blue);

	Function slopcos(sloping_cos,-10,10,orig,400,20,20);

	win.attach(slopcos);
	win.attach(f4);
	win.attach(squ);
	win.attach(t);
	win.attach(slp);
	win.attach(o);
	win.attach(x);
	win.attach(y);

	win.wait_for_button();

}

/*
iint main()
try {
	Simple_window win{Point{100,100},600,400,"My window"};
	//12.7.4
	Axis xa(Axis::x,Point{20,320},450,10,"X");

	Axis ya(Axis::y,Point(20,320),300,10,"Y");
	ya.set_color(Color::blue);
	ya.label.set_color(Color::red);
	//12.7.4
	Function sine(sin,0,10,Point(25,100),1000,100,50);
	//12.7.5
	Polygon polo;
	polo.add(Point{322,123});
	polo.add(Point{100,100});
	polo.add(Point{200,200});
	polo.set_color(Color::red);
	polo.set_style(Line_style::dash);
	//12.7.6
	Rectangle koco(Point{300,300},100,40);
	Closed_polyline polo_nem;
	polo_nem.add(Point{100,100});
	polo_nem.add(Point{200,200});
	polo_nem.add(Point{300,300});
	polo_nem.add(Point{340,403});
	//12.7.7
	koco.set_fill_color(Color::red);
	polo.set_style(Line_style(Line_style::dash,4)); 
	polo_nem.set_style(Line_style(Line_style::dash,2));
	//12.7.8
	Text t(Point{140,200},"SZOVEG");
	t.set_font(Font::courier);
	t.set_font_size(20);
	//12.7.9
	Image kep(Point{100,200},"badge.jpg");
	//12.7.10
	Circle c(Point(100,200),40);
	c.set_color(Color::red);
	Mark m(Point(100,200),'X');
	ostringstream oss;
	oss << "screen size:" << x_max() << "*" << y_max() << ";" << "Window size:" << win.x_max() << "*" << win.y_max();
	Text si(Point(500,500),oss.str());



	win.attach(si);
	win.attach(c);
	win.attach(kep);
	win.attach(t);
	win.attach(polo_nem);
	win.attach(koco);
	win.attach(polo);
	win.attach(sine);
	win.attach(ya);
	win.attach(xa);
	win.set_label("changed");
	win.attach(m);
	win.wait_for_button();

	
}
catch(exception& e)
{

	return 1;
}
catch(...)
{

	return 2;
}*/
