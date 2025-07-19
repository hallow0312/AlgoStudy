#include <iostream>
#include <stack>
using namespace std;

stack<int> stk;
int sum = 0;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			sum -= stk.top();
			stk.pop();
		}
		else
		{
			sum += temp;
			stk.push(temp);
		}
	}
}

int main()
{
	input();
	cout << sum << "\n";
}