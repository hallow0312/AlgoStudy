#include <iostream>
#include <vector>
using namespace std;

#define NO_CHECK -1

int t, n, k, w;
int dp[1000] = {};

struct Node
{
	int number = 0;
	int duration = 0;
	vector<int> needs;
};

vector<Node*> graph;

int find_path(Node* target)
{
	int number = target->number;

	if (dp[number] != NO_CHECK)
	{
		return dp[number];
	}

	if (target->needs.size() == 0)
	{
		dp[number] = target->duration;

		return dp[number];
	}

	int temp = INT32_MIN;
	
	for (int idx : target->needs)
	{
		temp = max(temp, find_path(graph[idx]));
	}

	dp[number] = temp + target->duration;

	return dp[number];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int idx = 0; idx < t; idx++)
	{
		fill(begin(dp), end(dp), NO_CHECK);

		cin >> n >> k;

		for (int i = 1; i <= n; i++)
		{
			Node* temp = new Node;
			temp->number = i - 1;
			cin >> temp->duration;
			graph.push_back(temp);
		}

		for (int i = 0; i < k; i++)
		{
			int start, end;
			cin >> start >> end;

			graph[end - 1]->needs.push_back(start - 1);
		}

		cin >> w;

		cout << find_path(graph[w - 1]) << "\n";

		graph.clear();
	}
}