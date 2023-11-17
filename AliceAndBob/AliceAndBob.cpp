#include<vector>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    int left(0),right(n-1),timeA(0), timeB(0),eatA(0),eatB(0);
    while (left<=right)
    {
        if (timeA <= timeB)
        {
            timeA += t[left];
            left++;
            eatA++;
        }
        else
        {
            timeB += t[right];
            right--;
            eatB++;
        }
    }
    cout << eatA << " " << eatB;
}
