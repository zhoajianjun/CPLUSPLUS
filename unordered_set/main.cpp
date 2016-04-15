#include <iostream>
#include <boost/unordered_set.hpp>
#include <algorithm>

using namespace std;
using namespace boost;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    unordered_set<int> s = {1,2,3,4,5,6};
    for (auto x:s)
    {
        cout<<x<<endl;
    }

    cout<<s.size()<<endl;
    s.insert(8);
    cout<<s.size()<<endl;
    cout<<*s.find(2)<< endl;

    s.erase(5);

    typedef complex<double> complex_t;

    unordered_set<complex_t> s1;
    s1.emplace(1.0,2.0);
    s1.emplace(3.0,4.0);
    for (auto &x : s1) {
        cout<<x<<endl;
     }
    s1.emplace_hint(s1.begin(),5.0,6.0);
    for (auto &y : s1) {
        cout<<y<<endl;
    }


    return 0;
}
