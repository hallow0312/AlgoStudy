#include <iostream>
using namespace std;

int recursion(const string& s, int l, int r, int*& count)
{
	if (l >= r)
	{
		return 1;
	}
	else if (s[l] != s[r])
	{
		return 0;
	}

	(*count)++;

	return recursion(s, l + 1, r - 1, count);
}

int isPalindrome(const string& s, int*& count)
{
	return recursion(s, 0, s.size() - 1, count);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string temp;
	int* count = new int;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		*count = 1;
		int result = isPalindrome(temp, count);
		cout << result << " " << *count << "\n";
	}
}