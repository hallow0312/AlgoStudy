#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> arr;
stack<int> stk;
int target = 1;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
}

bool check()
{
	int index = 0;
	stk.push(arr[index++]);

	while (!stk.empty() || index < arr.size())
	{
		if (index < arr.size() && arr[index] == target)
		{
			index++;
			target++;
		}
		else if (!stk.empty() && stk.top() == target)
		{
			target++;
			stk.pop();
		}
		else
		{
			if (index >= arr.size())
			{
				return false;
			}

			stk.push(arr[index++]);
		}
	}

	return true;
}

int main()
{
	input();

	if (check())
	{
		cout << "Nice\n";
	}
	else
	{
		cout << "Sad\n";
	}
}