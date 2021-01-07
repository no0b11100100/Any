#include <iostream>
#include "any.h"
#include <vector>

using namespace ANY;
using std::cout;
using std::endl;

int main()
{
    any a;
    a = 12.43;

    std::cout << a.get<double>() << endl;

    a = 543;
    cout << a.get<int>() << endl;

    std::vector<int> vec = {1,2,3,445};
    a = vec;

    auto v = a.get<std::vector<int>>();

    for(auto vv : v)
    {
        cout << vv << endl;
    }

    return 0;
}
