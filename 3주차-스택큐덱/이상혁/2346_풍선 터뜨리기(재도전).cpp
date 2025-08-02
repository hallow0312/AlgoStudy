#include <iostream>
#include <deque>
using namespace std;

int n;

deque<pair<int, int>> dq;

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
		dq.push_back({ i + 1,temp });
	}

	int target = 0;

	for (int i = 0; i < n; i++)
	{
		while (target != 0)
		{
			if (target > 0)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				if (dq.front().second != 0)
				{
					target--;
				}

			}
			else
			{
				dq.push_front(dq.back());
				dq.pop_back();
				if (dq.front().second != 0)
				{
					target++;
				}
			}
		}

		cout << dq.front().first << " ";
		target = dq.front().second;
		dq.front().second = 0;
	}
}