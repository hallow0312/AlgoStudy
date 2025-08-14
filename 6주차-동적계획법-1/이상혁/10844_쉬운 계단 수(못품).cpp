#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;

int arr[101] = {};
queue<string> check;

void find()
{
	for (int i = 1; i <= n; i++)
	{
		int size = check.size();
		arr[i] = size;

		for (int j = 0; j < size; j++)
		{
			string temp_s = check.front();

			check.pop();

			int temp_i = stoi(temp_s) % 10;

			if (temp_i - 1 >= 0)
			{
				check.push(to_string(temp_i - 1));
			}

			if (temp_i + 1 <= 9)
			{
				check.push(to_string(temp_i + 1));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		arr[i] = 0;
	}

	for (int i = 1; i <= 9; i++)
	{
		check.push(to_string(i));
	}

	find();

	cout << arr[n] % 1000000000 << "\n";
}