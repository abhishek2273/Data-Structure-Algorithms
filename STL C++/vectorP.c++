#include <bits/stdc++.h>
using namespace std;

void vectorFunction(vector<int> &v)
{
}

int main()
{
    vector<int> v{1, 2, 3, 4};
    // vector<int> v;
    // v.push_back(2);
    // v.emplace_back(45);

    // vector<pair<int, int>> vec;

    // v.push_back({1, 3});
    // v.emplace_back(8, 9);

    // vector<int> v(5, 100);

    // vector<int> v(5);

    // vector<int> v1(5, 20);
    // vector<int> v2(v1);

    // Accesing the element (long symtex)
    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *(it) << " ";
    // }

    // simple syntex
    for (auto it : v)
    {
        cout << it << " ";
    }

    return 0;
}