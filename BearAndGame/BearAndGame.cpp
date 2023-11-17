#include <iostream>
#include<vector>
using namespace std;

int main()
{

    int n; cin >> n;
    vector<int> T(n);
    int watch(15);
    for (int i = 0; i < n; i++)
    {
        cin >> T[i];
    }
    for (int i = 0; i < n; i++)
    {
        if ((T[i] - watch) > 0)
        {
            break;
        }
        else
        {
            watch = T[i] + 15;
            if (T[i] >= 75)
            {
                watch = 90; break;
            }
        }
    }
    cout << watch << endl;
}
