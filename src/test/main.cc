#include <iostream>
#include "json/Value.hh"
#include "json/Object.hh"
#include "json/Array.hh"
#include <vector>
#include <unordered_map>
#include <map>
#include <list>

using namespace std;

int main()
{
    Value<int> v(2);
    v = 100;
    v = 1.2;
    
    Object<> o;
    
    o.set("fucked", 32);
    
    Array<> a;
    
    a.push_back(20);
    a.push_back(22);
//    a.push_back(true);
    a.push_back<string>("fuck you mate!");
    
    cout << a.get<int>(1) << " " << o.get<int>("fucked") << " " << a.get<string>(2) << endl;
    
    
    cout << v.get() << endl;
    
    return 0;
}
