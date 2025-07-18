#include <iostream>
#include <deque>
using namespace std;

deque<int> deq;

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

		switch (temp)
		{
		case 1:
			cin >> temp;
			deq.push_front(temp);
			break;

		case 2:
			cin >> temp;
			deq.push_back(temp);
			break;

		case 3:
			if (!deq.empty())
			{
				cout << deq.front() << "\n";
				deq.pop_front();
			}
			else
			{
				cout << "-1\n";
			}
			break;

		case 4:
			if (!deq.empty())
			{
				cout << deq.back() << "\n";
				deq.pop_back();
			}
			else
			{
				cout << "-1\n";
			}
			break;

		case 5:
			cout << deq.size() << "\n";
			break;

		case 6:
			if (deq.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
			break;

		case 7:
			if (!deq.empty())
			{
				cout << deq.front() << "\n";
			}
			else
			{
				cout << "-1\n";
			}
			break;

		case 8:
			if (!deq.empty())
			{
				cout << deq.back() << "\n";
			}
			else
			{
				cout << "-1\n";
			}
			break;
		}
	}
}