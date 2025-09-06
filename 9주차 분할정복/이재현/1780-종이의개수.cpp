#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 2188
int buffer[SIZE][SIZE];
int a, b, c, n;
void Debug(int num)
{
	switch (num)
	{
	case -1:a++;
		break;
	case 0: b++;
		break;
	case 1: c++;
		break;
	}
}
void Answer(int x, int y, int size)
{
	int tmp = buffer[x][y];
	if (size <= 1)
	{
		Debug(tmp);
		return;
	}
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
		int oneThird = size / 3;
		int twoThird = oneThird * 2;
		Answer(x, y, oneThird); 
		Answer(x, y + oneThird, oneThird);  
		Answer(x, y + twoThird, oneThird); 
		Answer(x + oneThird, y, oneThird);
		Answer(x + oneThird, y + oneThird, oneThird);
		Answer(x + oneThird, y + twoThird, oneThird); 
		Answer(x + twoThird, y, oneThird); 
		Answer(x + twoThird, y + oneThird, oneThird); 
		Answer(x + twoThird, y + twoThird, oneThird);
	}
		
}
void Init()
{
	a = 0; b = 0; c = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> buffer[i][j];
		}
	}
	Answer(0, 0, n);
	cout << a << '\n' << b << '\n' << c << '\n';
}
int main()
{
	IOS_BASE
		Init();
	return 0;
}