/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "std_lib_facilities.h"
  


struct Person
{

public:
	Person(string f, string s, int a);
	Person():first_name{"Goofy"},second_name{"GOOFY"},age{63}{}
	string names() const { return first_name + " " + second_name; }
	int ages() const { return age; }
	void set_name(string f, string s);
	void set_age(int sz);
	
private:
	string second_name;
	string first_name;
	int age;



};


void Person::set_age(int a)
{
	age = a;
	
	 if (age < 0 || 150 < age)
	{

		error("ervenytelen kor");
	}
	

};

void Person::set_name(string f, string s)
{

	string n = f + s;
for (char c : n) 
	{
        switch(c)
        {
            case ';': case ':': case '"': case '[': case ']': case '*':
            case '&': case '^': case '%': case '$': case '#': case '@':
            case '!':
                error("ervenytelen nev");
                break;
            default:
            	first_name = f;
            	second_name = s;
                break;
        }
    }


}

Person::Person(string f, string s, int a)
{

	age = a;
	first_name = f;
	second_name = s;
	string n2 = first_name + second_name;
	 if (age < 0 || 150 < age)
	{

		error("ervenytelen kor");
	}
	
	for (char c : n2) 
	{
        switch(c)
        {
            case ';': case ':': case '"': case '[': case ']': case '*':
            case '&': case '^': case '%': case '$': case '#': case '@':
            case '!':
                error("ervenytelen nev");
                break;
            default:
            	
                break;
        }
    }
	

}

ostream& operator<<(ostream& os, Person& p)
{
	return os << p.names() << " " << p.ages();

}

istream& operator>>(istream& is, Person& p)
{
	string first="";
	string second="";
	int age = 0;

	is >> first >> second >> age;
	p.set_age(age);
	p.set_name(first,second);
	return is;
}
int main()
try{
	Person h1("szia","macsak",34);
	
	cout << h1 << endl;
	/*Human.name = "Goofy";
	Human.age = 63;*/
	
	vector<Person>Humans;

	for(int i = 0 ; i < 2; ++i)
	{
		Person p;
		cin >> p;
		Humans.push_back(p);


	}
	for(int i = 0; i < Humans.size(); ++i)
	{
		cout << Humans[i] << endl;

	}
	

	Person Human2("asda","nev",3);
	
	cout << Human2 << endl;
 	return 0;
}catch(...)
{

	cerr << "error" << endl;
}