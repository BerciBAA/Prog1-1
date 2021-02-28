/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;
	Simple_window win(Point{100,100},900,600,"DRILL");

    Polygon pol;
    pol.add(Point(100,100));
    pol.add(Point(100,200));
    pol.add(Point(200,200));
    pol.add(Point(200,100));
    pol.set_color(Color::red);
    win.attach(pol);

    Rectangle rec1(Point(205,100),100,100);
    rec1.set_color(Color::blue);
    win.attach(rec1);
    
    Rectangle rec2(Point{200,200},100,30);
    win.attach(rec2);


    Text t(Point{228,220},"Howdy!");
    win.attach(t);

    Text B(Point{300,300},"B");
    B.set_font(Font::helvetica_bold_italic);
    B.set_font_size(150);
    B.set_color(Color::red);
    win.attach(B);

    Text A(Point{400,300},"A");
    A.set_font(Font::helvetica_bold_italic);
    A.set_font_size(150);
    A.set_color(Color::blue);
    win.attach(A);

    Text A2(Point{530,300},"A");
    A2.set_font(Font::helvetica_bold_italic);
    A2.set_font_size(150);
    A2.set_color(Color::green);
    win.attach(A2);
	
	Vector_ref<Rectangle> vr;
	int w = 10;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			vr.push_back(new Rectangle{Point{0+w*i,0+w*j},w,w});
			if(vr.size()%2==0)
			{
				vr[vr.size()-1].set_fill_color(Color::red);

			}
			else
			{
				vr[vr.size()-1].set_fill_color(Color::white);
			}
			
		}
	}
	for(int i = 0; i < vr.size(); i++)
	{
		win.attach(vr[i]);
	}


	Rectangle rec3 {Point{150, 150}, x_max() * 2 / 3, y_max() * 3 / 4};
	rec3.set_color(Color::red);
	win.attach(rec3);

	Rectangle rec4 {Point{50,50},x_max()+10,y_max()+10};
	win.attach(rec4);
	Rectangle rec5 {Point{600,600},200,200};
	win.attach(rec5);

	Rectangle wall{Point{400,400},100,100};
	win.attach(wall);

	Rectangle door{Point{437,450},25,50};
	win.attach(door);

	Rectangle win1{Point{410,425},25,25};
	win.attach(win1);

	Rectangle win2{Point{465,425},25,25};
	win.attach(win2);
	
	Closed_polyline roof;
	roof.add(Point(400,400));
	roof.add(Point(450,350));
	roof.add(Point(500,400));
	win.attach(roof);

	Line chimney1(Point{425,375},Point{425,350});
	win.attach(chimney1);
	Line chimney2(Point{410,350},Point{425,350});
	win.attach(chimney2);
	Line chimney3(Point{410,350},Point{410,390});
	win.attach(chimney3);


	Circle bl {Point{400, 500}, 75};
    bl.set_style(Line_style(Line_style::solid, 12));
    bl.set_color(Color::blue);
    win.attach(bl);

    Circle yl {Point{480, 575}, 75};
    yl.set_style(Line_style(Line_style::solid, 12));
    yl.set_color(Color::yellow);
    win.attach(yl);

    Circle bk {Point{560, 500}, 75};
    bk.set_style(Line_style(Line_style::solid, 12));
    bk.set_color(Color::black);
    win.attach(bk);

    Circle gn {Point{640, 575}, 75};
    gn.set_style(Line_style(Line_style::solid, 12));
    gn.set_color(Color::green);
    win.attach(gn);

    Circle rd {Point{720, 500}, 75};
    rd.set_style(Line_style(Line_style::solid, 12));
    rd.set_color(Color::red);
    win.attach(rd);
	
    win.wait_for_button();

}
