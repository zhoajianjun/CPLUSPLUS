#include <iostream>
#include <boost/unordered_set.hpp>

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

    return 0;
}
