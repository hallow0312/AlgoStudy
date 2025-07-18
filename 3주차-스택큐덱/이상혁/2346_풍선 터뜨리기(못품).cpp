#include <iostream>
#include <deque>
using namespace std;

deque<pair<int, int>> deq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		deq.push_back({ i + 1,temp });
	}

	int target = 1;

	for (int i = 0; i < n; i++)
	{
		if (target < 0)
		{
			target *= -1;

			for (int i = 0; i < target;)
			{
				if (deq.front().second != 0)
				{
					i++;
				}

				deq.push_front(deq.back());
				deq.pop_back();
			}
		}
		else
		{
			for (int i = 0; i < target;)
			{
				if (deq.front().second != 0)
				{
					i++;
				}

				deq.push_back(deq.front());
				deq.pop_front();
			}
		}

		cout << deq.front().first << " ";

		target = deq.front().second;

		deq.front().second = 0;
	}
}