#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <string>
#include <algorithm>

template<typename C>
void read(C& I)
{
	for(auto& a : I)
	{
		std::cout << a ;
	}
	std::cout << " " << std::endl;

}
template<typename C>
void plus(C& I, int n)
{
	for(auto& a : I)
	{
		a = a + n;
	}


} 

template<typename iter1, typename iter2, typename>
iter2 copy(iter1 f1, iter1 e1, iter2 f2)
{
	while(f1!=e1)
	{
		*f1=*f2;
		f1++;
		f2++;
	}
	return f2;
}
int main()
{
	

	std::array<int,10> array{1,2,3,4,5,6,7,8,9,10};
	read(array);
	std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
	read(vec);
	std::list<int> lis {1,2,3,4,5,6,7,8,9,10};
	read(lis);

	std::array<int,10> array2;
	std::vector<int> vec2 = vec;
	std::list<int> lis2 = lis;
	std::cout << "coppy" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		array2[i] = array[i];
	}

	read(array2);

	read(vec2);
	read(lis2);

	std::cout << "plus" << std::endl;
	plus(array2, 2);
	plus(vec2, 3);
	plus(lis2,5);

	read(array2);
	read(vec2);
	read(lis2);

	copy(array2.begin(), array2.end(),vec2.begin());
	copy(lis2.begin(), lis2.end(),array2.begin());

	std::cout << "copy fuggveny" << std::endl;
	read(array2);
	read(vec2);
	read(lis2);

	const int w = 3;
	auto a = find(vec2.begin(), vec2.end(),w);

	auto e = distance(a,vec2.begin());
	if(e == vec2.size())
	{

		std::cout << "NICNS BEBBENEN" << std::endl;
	}else
	{
		std::cout << e;
	}
	return 1;
}