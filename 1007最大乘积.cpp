
#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
 
int main()
{
	int K,N;
	char str[41]; //数字串
	int i,j,k;
	cout << "输入数字串的长度N:";
	cin >> N;
	cout << "输入乘号个数K:";
	cin >> K;
	cout << "输入数字串:";
	cin >> str;
	//dp[i][j]表示从角标0~i之间的数字串之间插入j个乘号得到的乘积
	int dp[41][7]; 
	//将dp的所有元素初始化为0
	memset(dp,0,sizeof(dp));
	//num[i][j]表示取角标i~j（包括i,j）之间的数字串
	int num[41][41];
	//将字符串转换为数字
	for(i=0;i<N;i++)
	{
		int temp = 0;
		for(j=i;j<N;j++)
		{
			temp = temp*10 + str[j] - '0';
			num[i][j] = temp;
		}
	}
	//当不插入乘号时，最大乘积为其本身
	for(i=0;i<N;i++)
		dp[i][0] = num[0][i];
	//动态转移方程，更新解
	for(i=0;i<N;i++)
		for(j=1;j<=K;j++)
			for(k=0;k<i;k++)
				dp[i][j] = max(dp[k][j-1]*num[k+1][i],dp[i][j]);
	//cout << "dp[i][j]:" << endl;
	//for(i=0;i<N;i++)
	//{
	//	for(j=0;j<=K;j++)
	//		cout << dp[i][j] << ' ';
	//	cout << endl;
	//}
	cout << "在插入" << K << "个乘号的情况下，数字串" << str << "的最大乘积为: " << dp[N-1][K] << endl;
	system("pause");
	return 0;
}
