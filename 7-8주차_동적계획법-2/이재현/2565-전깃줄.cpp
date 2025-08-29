#include"bits/stdc++.h"
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SIZE 101
int n, Dynamic[101];

struct Bag
{
	int w, v;
};
vector<Bag>vec;

int Answer()
{
	sort(
		vec.begin(), vec.end(), 
		[](const Bag& a, const Bag& b)
		{
		return a.w < b.w; 
		}
	);
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vec[i].v > vec[j].v)
			{
				Dynamic[i] = std::max(Dynamic[i], Dynamic[j] + 1);
			}
		}
		result = std::max(result, Dynamic[i]);
	}
	
	return n-result;
}

void Init()
{
	cin >> n;
	fill(Dynamic, Dynamic + n, 1);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
	
	}
	cout << Answer() << '\n';
		
}
int main()
{
	IOS_BASE
	Init();
}