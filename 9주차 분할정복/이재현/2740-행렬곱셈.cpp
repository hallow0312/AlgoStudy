#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 101
int n, m,m1, k;
int A[SIZE][SIZE];
int B[SIZE][SIZE];
int result[SIZE][SIZE];
void Answer()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int x = 0; x < m1; x++)
			{
				result[i][j] += (A[i][x] * B[x][j]);
			}
		}
	}
}
void Init()
{
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	memset(result, 0, sizeof(result));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
	}
	cin >> m1>> k;
	assert(m1 == m);
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> B[i][j];
		}
	}
	Answer();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << result[i][j]<<' ';
		}
		cout << '\n';
	}
}
int main()
{
	IOS_BASE
	Init();
	return 0;
}