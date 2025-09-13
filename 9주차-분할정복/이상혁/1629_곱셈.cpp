#include <iostream>
#include <unordered_map>
using namespace std;

int a, b, c;
unordered_map<int, long long> arr;

long long multi(int target)
{
	if (target <= 1)
	{
		return a % c;
	}

	if (arr.find(target) != arr.end())
	{
		return arr[target];
	}

	int temp1 = target / 2;
	int temp2 = target - temp1;

	long long value = multi(temp1) * multi(temp2) % c;
	arr[target] = value;

	return value;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;

	cout << multi(b) << "\n";
}