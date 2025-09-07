#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 65
int buffer[SIZE][SIZE]; int n;
void Debug(int num)
{
	if (num == 1)cout << '1';
	else cout << '0';

}
void Answer(int x, int y, int size)
{
	if (size <= 1)
	{
		Debug(buffer[x][y]);
		return;
	}

	int tmp = buffer[x][y];
	bool complete = true;
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (tmp != buffer[i][j])
			{
				complete = false;
				break;
			}
		}
		if (!complete)break;
	}
	if (complete)Debug(tmp);
	else
	{
		cout << "(";
		int half = size / 2;
		Answer(x, y, half);
		Answer(x + half, y, half);
		Answer(x, y + half, half);
		Answer(x + half, y + half, half);
		cout << ")";
	}
}
void Init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			buffer[i][j] = c - '0';
		}
	}
	Answer(0, 0, n);

}
int main()
{
	IOS_BASE
		Init();
	return 0;
}