#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SIZE 1001
int buffer[SIZE],Dynamic[SIZE],Reverse[SIZE] , n;

int Answer()
{
	for (int i = 0; i < n; i++)
	{
		Dynamic[i] = 1;
		for (int j = 0; j < n; j++)
		{
			if (buffer[i] > buffer[j])Dynamic[i] = max(Dynamic[i], Dynamic[j] + 1);
			
		}
	}
	for (int i = n-1; i >= 0; i--)
	{
		Reverse[i] = 1;
		for (int j = n-1; j > i; j--)
		{
			if (buffer[i] > buffer[j])Reverse[i] = max(Reverse[i], Reverse[j] + 1);
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		if (result < Dynamic[i] + Reverse[i] - 1)
		{
			result = Dynamic[i] + Reverse[i] - 1;
		}
	}
	return result;
		
}

void Init()
{
	cin >> n;
	memset(Dynamic, 0, sizeof(Dynamic));
	memset(Reverse, 0, sizeof(Reverse));
	for (int i = 0; i < n; i++)
	{
		cin >> buffer[i];
	}
	cout<<Answer()<<'\n';
}
int main()
{
	IOS_BASE
	Init();
}