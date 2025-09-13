#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE 129
int n, w, b;
int buffer[SIZE][SIZE];
bool complete;
void Add(int num)
{
	if (num == 1)b++;
	else w++;
}
void Answer(int x,int y ,int size)
{
	if (size <= 1)
	{
		Add(buffer[x][y]);
		return;
	}
	complete = true;
	int color = buffer[x][y];
	for (int i = x; i< x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (buffer[i][j] != color) 
			{
				complete = false;
				break;
			}
		}
		if (!complete) break; 
	}
	if (complete)Add(color);
	else
	{
		int half = size / 2;
		Answer(x, y, half);           
		Answer(x + half, y, half);    
		Answer(x, y + half, half);    
		Answer(x + half, y + half, half); 
	}

}
void Init()
{
	w = 0;
	b = 0;
	cin >> n;
	memset(buffer, 0, sizeof(buffer));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> buffer[i][j];
		}
	}
	Answer(0, 0, n);
	cout << w << '\n';
	cout << b << '\n';
}
int main()
{
	IOS_BASE
		Init();
	return 0;
}