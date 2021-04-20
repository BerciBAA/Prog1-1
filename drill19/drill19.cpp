#include "std_lib_facilities.h"

using namespace std;

template<typename T>
struct S
{
	S(T s):val(s){}
	T get();
	T get() const;
	S& operator=(const T);

private:
	T val;

};
template<typename T>
T S<T>::get()
{
    return val;
}
template<typename T>
T S<T>::get() const
{
    return val;
}

template<typename T>
S<T>& S<T>::operator=(const T s)
{
    val = s;
    return *this;
}

template<typename T>
ostream& operator<<(ostream& os, S<T>& t)
{
	return os << t.get();

}
template<typename T>
istream& operator>>(istream& os, S<T>& t)
{
	return os >> t;

}
template<typename T>
void read_val(T& v)
{
	cin >> v ;
}
int main()
{

    S<int> si {37};
    S<char> sc {'c'};
    S<double> sd {10.2};
    S<string> s {"Howdy"};
    S<vector<int>> svi { vector<int>{1, 1, 2, 3, 5, 8}};
    cout << si.get() << endl;
    cout << sc.get() << endl;
    cout << sd.get() << endl;
    for(int i = 0; i < svi.get().size(); ++i)
    {
    	cout << svi.get()[i] << endl;
    }
    si=30;
    cout << si.get() << endl;

    read_val(si);
    read_val(sc);
    read_val(sd);
	cout << "hello world " <<endl;

};