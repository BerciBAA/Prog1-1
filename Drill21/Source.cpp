#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <algorithm>
#include <map>
#include <numeric>


struct Item {
    std::string name;
    int iid;
    double value;
};
//operátor overloading beolvasni consoleról vagy fileróbol
std::istream& operator>>(std::istream& is, Item& it)
{
    std::string ss;
    int ii;
    double dd;
    is >> ss >> ii >> dd;
    Item itt{ ss, ii, dd };
    it = itt;
    return is;
}
//operátor overloadning kiírja az item összes tagját
std::ostream& operator<<(std::ostream& os, Item& it)
{
   return os << it.iid << ' ' << it.name << ' ' << it.value ;
}
//beolvas item vectorba dolgokat
void read(std::vector<Item>& v)
{
    const std::string iname{ "input_items.txt" };

    std::ifstream ifs{ iname };
    if (!ifs)
    {
        std::cout << "error ";
    }


    for (Item ii; ifs >> ii; )
        v.push_back(ii);

}
//kírás vector
template<typename T>
void print(T& v)
{
    for (auto& a : v)
    {
        std::cout << a << std::endl;
    }
}
//kisebbes rendezõs cucc
struct smaller
{
    bool operator() (const Item& a, const Item& b) { return a.value > b.value; }
};
//id alapján való törlés
class iidf
{
    int iid;
public:
    iidf(int idf): iid(idf) {}
    bool operator()(Item& r) { return iid == r.iid; }
};
//név alapján való törlés
class name
{
    std::string names;
public:
    name(std::string nam) : names(nam) {}
    bool operator()(Item& r) { return names == r.name; }
};
//map kiírása
template<typename K,typename V>
void print2(std::map<K, V> m)
{
    for (const auto& a : m)
        std::cout << a.first << "\t" << a.second << std::endl;

}
//mapba való beolvasás
void read2(std::map<std::string, int>& m, int num)
{
    std::string s = "";
    int n = 0;
    for (int i = 0; i < num; i++)
    {
        std::cin >> s >> n;
        m.insert(std::make_pair(s,n));
    }

}
class Less_than {
    double v;
public:
    Less_than(double vv) : v{ vv } { }

    bool operator()(const double val) { return val < v; }
};
//Drill elsõ része
void first()
{
    int size = 10;
    std::vector<Item> vi;
    read(vi);
    std::sort(vi.begin(), vi.end(),
        [](const Item& a, const Item& b) { return a.name < b.name; });

    std::sort(vi.begin(), vi.end(),
        [](const Item& a, const Item& b) { return a.iid < b.iid; });

    std::sort(vi.begin(), vi.end(),
        [](const Item& a, const Item& b) { return a.value < b.value; });

    std::sort(vi.begin(), vi.end(), smaller());

    Item item{ "horse sohe",99,12.34 };
    vi.insert(vi.end(), item);
    Item item2{ "Canon S400",9988,499.95 };
    vi.insert(vi.end(), item2);

    vi.erase(std::find_if(vi.begin(), vi.end(), iidf(17)));
    vi.erase(std::find_if(vi.begin(), vi.end(), name("Canon S400")));
    print(vi);

    std::cout << "cucc" << std::endl;

    std::list<Item> li(vi.size());
    std::copy(vi.begin(), vi.end(), li.begin());
    li.insert(li.end(), item);
    li.insert(li.end(), item2);

    li.erase(std::find_if(li.begin(), li.end(), iidf(6)));
    li.erase(std::find_if(li.begin(), li.end(), name("Canon S400")));
    print(li);

}

//Drill második része
void second(int m)
{
    std::map<std::string, int>msi;
    msi["a"] = 0;
    msi["b"] = 1;
    msi["c"] = 2;
    msi["ab"] = 3;
    msi["ac"] = 4;
    msi["aa"] = 5;
    msi["bb"] = 6;
    msi["bc"] = 7;
    msi["ba"] = 8;
    msi["ca"] = 9;
    print2(msi);

    std::cout << "msi delete" << std::endl;
    msi.erase(msi.begin(), msi.end());
    print2(msi);
    read2(msi, m);
    int count = 0;
    for(auto &a : msi)
    {
        count += a.second;
    }
    std::cout << count << std::endl;
    print2(msi);
    std::cout << "mis" << std::endl;
    std::map<int, std::string> mis;

    for (auto& a : msi)
        mis[a.second] = a.first;

    print2(mis);
}
int main()
{
    //first();
    //second(2);
    std::string filename = "file2.txt";
    std::ifstream ifs{ filename };
    if (!ifs) { std::cout << "error" << std::endl; }
    std::vector<double> vd;
    for (double d; ifs >> d;)
    {
        vd.push_back(d);
    }

    print(vd);

    std::vector<int> vi(vd.size());
    std::cout << "copy vd" << std::endl;
    std::copy(vd.begin(), vd.end(), vi.begin());
    for (int i = 0; i < vd.size(); i++)
    {
        std::cout << vd[i] << '\t' << vi[i] << std::endl;
    }
    double sum = std::accumulate(vd.begin(),vd.end(),0.);
    std::cout << "vi sum: " << sum << std::endl;
    double sum2 = std::accumulate(vi.begin(), vi.end(), 0.);
    std::cout << "kulonbseg:" << sum - sum2 << std::endl;

    std::reverse(vd.begin(), vd.end());
    std::cout << "reverse:" << std::endl;
    print(vd);

    double avg = sum / vd.size();
    std::cout << "avg: " << avg << std::endl;

    std::vector<double> vd2(vd.size());
    std::copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(avg));
    std::cout << "vd2 copy " << std::endl;
    std:sort(vd2.begin(), vd2.end());
    print(vd2);

    return 1;
}