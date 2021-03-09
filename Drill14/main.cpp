/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "std_lib_facilities.h"

struct A1
{
	virtual void pvf() = 0;
};

struct B1:A1
{
	virtual void vf(){ cout << "B1::vf" << endl;}
	void f(){cout << "B1::f\n" << endl; }
};

struct D1:B1
{
	void vf() override { cout << "D1::vf" << endl;}
	void f(){cout << "D1::f\n" << endl; }
};
struct D2 : D1
{
	void pvf() override { cout << "D2::vf" << endl;}

};
struct B2
{
	virtual void pvf() = 0;

};
struct D21:B2
{
	string kacsa = "KACAS";
	void pvf() override { cout << kacsa << '\n'; }
};
struct D22:B2
{
	int num = 20;
    void pvf() override { cout << num << '\n'; }
};
void f(B2& b2)
{
	b2.pvf();

}
int main()
{

	/*B1 b;
	b.vf();
	b.f();

	D1 d;
	d.vf();
	d.f();

	B1& b1 = d;
	b1.vf();
	b1.f();*/

	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();
	D21 d21;
	D22 d22;
	f(d21);
	f(d22);
	return 0;
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
