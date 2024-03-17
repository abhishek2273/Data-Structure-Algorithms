#include <bits/stdc++.h>
using namespace std;

void MinMax(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Max : " << *max_element(v.begin(), v.end()) << "\n";
    cout << "Min : " << *min_element(v.begin(), v.end()) << "\n";
}

int main()
{
    vector<int> v{4, 2, 5, 9, 1};
    MinMax(v);
    return 0;
}