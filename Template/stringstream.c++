#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> parseInts(string str)
{
    // Complete this function
    vector<int> v;
    stringstream ss(str);

    int temp;
    char c;
    while (ss)
    {
        if (ss.peek() != ',')
        {
            if (ss >> temp)
            {
                v.push_back(temp);
            }
        }
        else
        {
            ss >> c;
        }
    }

    return v;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }

    return 0;
}
