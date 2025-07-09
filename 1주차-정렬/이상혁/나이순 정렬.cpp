#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class People
{
public:
	string name;
	int age, num;

	bool operator<(People comp_pp)
	{
		if (age < comp_pp.age)
		{
			return true;
		}
		else if (age > comp_pp.age)
		{
			return false;
		}

		if (num < comp_pp.num)
		{
			return true;
		}

		return false;
	}
};

vector<People> arr;

void input_pp();
void print_pp();

bool compare_pp(People pp1, People pp2);

int main()
{
	input_pp();

	sort(arr.begin(), arr.end(), compare_pp);

	print_pp();
}

void input_pp()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		People temp;
		temp.num = i;
		cin >> temp.age >> temp.name;
		arr.push_back(temp);
	}
}

void print_pp()
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i].age << " " << arr[i].name << "\n";
	}
}

bool compare_pp(People pp1, People pp2)
{
	return pp1 < pp2;
}