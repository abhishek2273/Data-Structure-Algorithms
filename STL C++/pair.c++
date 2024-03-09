#include <bits/stdc++.h>
using namespace std;

void Pair()
{

    pair<int, int> p1 = {1, 3};
    cout << p1.first << " " << p1.second << endl;

    pair<int, pair<int, int>> p = {5, {6, 0}};
    cout << p.first << " " << p.second.second << " " << p.second.first << endl;

    pair<int, int> arr[] = {{1, 2}, {3, 5}, {9, 6}};
    cout << arr[0].second;
}

int main()
{
    Pair();
    return 0;
}