#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_set<string> word_set;

string word;
int sum = 0;

void input_word();
void check_word();

int main()
{
	input_word();
	check_word();
	cout << sum;
}

void input_word()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> word;
}

void check_word()
{
	for (int i = 0; i < word.size(); i++)
	{
		for (int j = 1; j <= word.size() - i; j++)
		{
			string temp = word.substr(i, j);
			if (word_set.find(temp) == word_set.end())
			{
				word_set.insert(temp);
				sum++;
			}
		}
	}
}