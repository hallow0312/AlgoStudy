#include <iostream>
#include <vector>
using namespace std;

int n;
int add, mns, mul, dvs;

int min_v = INT32_MAX, max_v = INT32_MIN;

vector<int> arr;
vector<int> susik;

void calc();
void susik_select(int& ss, int num);
void select();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	cin >> add >> mns >> mul >> dvs;

	select();

	cout << max_v << "\n" << min_v << "\n";
}


void calc()
{
	int result = arr[0];

	for (int i = 0; i < susik.size(); i++)
	{
		switch (susik[i])
		{
		case 1:
			result += arr[i + 1];
			break;
		case 2:
			result -= arr[i + 1];
			break;
		case 3:
			result *= arr[i + 1];
			break;
		case 4:
			result /= arr[i + 1];
			break;
		}
	}

	if (result > max_v)
	{
		max_v = result;
	}
	if (result < min_v)
	{
		min_v = result;
	}
}

void susik_select(int& ss, int num)
{
	if (ss > 0)
	{
		ss--;
		susik.push_back(num);
		select();
		susik.pop_back();
		ss++;
	}
}

void select()
{
	if (susik.size() == n - 1)
	{
		calc();
		return;
	}

	susik_select(add, 1);
	susik_select(mns, 2);
	susik_select(mul, 3);
	susik_select(dvs, 4);
}