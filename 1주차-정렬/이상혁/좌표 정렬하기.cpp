#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Dot
{
public:
	int x, y;

	bool operator<(Dot comp_dot)
	{
		if (x < comp_dot.x)
		{
			return true;
		}
		else if (x > comp_dot.x)
		{
			return false;
		}

		if (y < comp_dot.y)
		{
			return true;
		}

		return false;
	}
};

vector<Dot> arr;

void input_dots();
void print_dots();

bool compare_dot(Dot dot1, Dot dot2);

int main()
{
	input_dots();

	sort(arr.begin(), arr.end(), compare_dot);

	print_dots();
}

void input_dots()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		Dot temp_dot;
		cin >> temp_dot.x >> temp_dot.y;
		arr.push_back(temp_dot);
	}
}

void print_dots()
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i].x << " " << arr[i].y << "\n";
	}
}

bool compare_dot(Dot dot1, Dot dot2)
{
	return dot1 < dot2;
}