#include <iostream>
#include <cmath>
using namespace std;

int n;
string line;

void remove_line(int idx1, int idx2, int count)
{
	if (count > n)
	{
		return;
	}

	int remove_len = ((idx2 + 1) - (idx1 + 1) + 1) / 3;
	int remove_idx = idx1 + remove_len;

	for (int i = remove_idx; i < remove_idx + remove_len; i++)
	{
		line[i] = ' ';
	}

	remove_line(idx1, remove_idx, count + 1);
	remove_line(remove_idx + remove_len, idx2, count + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> n)
	{
		line = "";

		for (int i = 0; i < pow(3, n); i++)
		{
			line += '-';
		}

		remove_line(0, line.size() - 1, 1);

		cout << line << "\n";
	}
}