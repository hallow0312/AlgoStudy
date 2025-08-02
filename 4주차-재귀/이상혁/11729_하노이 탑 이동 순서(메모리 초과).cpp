#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<pair<int, vector<int>>> tops;

bool check_top(pair<int, vector<int>>& check1, pair<int, vector<int>>& check2, pair<int, vector<int>>& check3)
{
	if (check1.first == 3)
	{
		return check1.second.size() == n;
	}
	else if (check2.first == 3)
	{
		return check2.second.size() == n;
	}
	else
	{
		return check3.second.size() == n;
	}
}

void move(pair<int, vector<int>> source, pair<int, vector<int>> target, pair<int, vector<int>> namuzi, int count, vector<pair<int, int>> result)
{
	if (count > pow(2, n) - 1)
	{
		return;
	}
	else if (source.second.empty())
	{
		return;
	}
	else if (!target.second.empty() && source.second.back() > target.second.back())
	{
		return;
	}

	target.second.push_back(source.second.back());
	source.second.pop_back();

	result.push_back({ source.first,target.first });

	if (check_top(source, target, namuzi))
	{
		cout << count << "\n";

		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i].first << " " << result[i].second << "\n";
		}

		exit(0);
	}

	// move(source, target, namuzi, count + 1, result); 불가능 -> 무조건 이번에 옮기는 것이 더 크기 때문에
	move(source, namuzi, target, count + 1, result);

	// move(target, source, target, count + 1, result); 의미 없는 반복
	// move(target, namuzi, source, count + 1, result); 동선 낭비 -> source에서 바로 namuzi로 가는게 있음

	move(namuzi, source, target, count + 1, result);
	move(namuzi, target, source, count + 1, result);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 3; i++)
	{
		vector<int> temp;
		tops.push_back({ i + 1,temp });
	}

	cin >> n;

	int temp = n;

	while (temp != 0)
	{
		tops[0].second.push_back(temp--);
	}

	vector<pair<int, int>> result;

	move(tops[0], tops[1], tops[2], 1, result);
	move(tops[0], tops[2], tops[1], 1, result);
}