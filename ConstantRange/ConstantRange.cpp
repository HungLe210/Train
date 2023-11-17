#include<vector>
#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	vector<int> Fre(100001);

	for (int i = 0; i < n; i++)
		cin >> A[i];

	int right(0), count(0), Max(0);

	for (int i = 0; i < n; i++)
	{
		while ((right < n) && (count <= 2))
		{
			if ((count == 2) && (Fre[A[right]] == 0))
				break;
			if (Fre[A[right]] == 0)
				count++;
			Fre[A[right]]++;
			right++;
		}
		Max = max(Max, right - i );
		if (Fre[A[i]] == 1)
			count--;
		Fre[A[i]]--;
	}
	cout << Max;
}
