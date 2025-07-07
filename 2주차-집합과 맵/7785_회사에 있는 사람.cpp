#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, string> input;
vector<string> arr;

void input_words();
void find_words();

int main()
{
	input_words();

	sort(arr.begin(), arr.end(), greater<>());

	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	find_words();
}

void input_words()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name, log;
		cin >> name >> log;
		if (log == "enter")
		{
			arr.push_back(name);
			input.insert(make_pair(name, name));
		}
		else if (log == "leave")
		{
			input.erase(name);
		}
	}
}

void find_words()
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (input.count(arr[i]) == 1)
		{
			cout << arr[i] << "\n";
		}
	}
}