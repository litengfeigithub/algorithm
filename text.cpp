#include<bits/stdc++.h>
using namespace std;
int a[100];

void solution(int n)
{
    int dp[30] = {0};
	dp[0] = 1;
    for(int i = 1; i < n; ++i)
	{
        int maxL = 1;
        for(int j = 0; j < i; ++j)
		{
            if(a[i] <= a[j])
			{
                maxL = max(maxL, dp[j] + 1);
            }
        }
            dp[i] = maxL;
    }
    int ans = 1;
    for(int i = 0; i < n; ++i)
	{
        if(ans < dp[i]) ans = dp[i];
    }
    cout << ans << endl;
	
}

int main()
{
	int m;
	int n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		solution(n);
	}
	
	
}

