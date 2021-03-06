/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"


int main()
{
	
	using namespace Graph_lib;
	Simple_window win(Point{100,100},800,1000,"Simple_window");
	Lines grid;
    for(int i = 0; i < 900; i+=100)
    {
    	grid.add(Point{i,0},Point{i,800});

    }
    for(int i = 0; i < 900; i+=100)
    {
    	grid.add(Point{0,i},Point{800,i});

    }
    Vector_ref<Rectangle> recs;
    for (int i = 0; i < 800; i += 100) 
    {
	
		recs.push_back(new Rectangle{Point{i,i},100,100});
		recs[recs.size()-1].set_color(Color::red);
        recs[recs.size()-1].set_fill_color(Color::red);
        win.attach(recs[recs.size()-1]);

		
    }
  	Image img{Point{200,0},"badge.jpg"};
  	img.set_mask(Point{200,100},200,200);
  	Image img1{Point{400,0},"badge.jpg"};
  	img1.set_mask(Point{200,100},200,200);
  	Image img2{Point{0,200},"badge.jpg"};
  	img2.set_mask(Point{200,100},200,200);
  	win.attach(img);
  	win.attach(img1);
  	win.attach(img2);

  	Image apple {Point{0,0}, "download.jpg"};

  	win.attach(grid);
    win.attach(apple);
    win.wait_for_button();
    int le =0;
    for (int i = 0; i < 7; ++i) {
    	for (int i = 0; i < 7; ++i)
    	{
    		apple.move(100, 0);
    		 win.wait_for_button();
    	}
    	  apple.move(-700, 100);
                 
        win.wait_for_button();
    }


	
	
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
