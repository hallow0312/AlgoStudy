#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Dot
{
public:
	int value, index;

	bool operator<(Dot comp_dot)
	{
		if (value < comp_dot.value)
		{
			return true;
		}

		return false;
	}
};

void input_dot();
void print_dot();

void press_dots();
int find_last_index(int find_value, int index);

bool compare_index(Dot d1, Dot d2);

vector<Dot> arr;

int main()
{
	input_dot();

	sort(arr.begin(), arr.end());

	press_dots();

	sort(arr.begin(), arr.end(), compare_index);

	print_dot();
}

void input_dot()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Dot temp;
		cin >> temp.value;
		temp.index = i;
		arr.push_back(temp);
	}
}

void print_dot()
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i].value << " ";
	}
}

void press_dots()
{
	if (arr.size() == 1)
	{
		return;
	}

	int current_value = 0;

	for (int i = 0; i < arr.size();)
	{
		int last_index = find_last_index(arr[i].value, i);

		cout << "리턴 값: " << last_index << endl;

		for (int j = i; j < last_index; j++)
		{
			arr[j].value = current_value;
		}

		i = last_index;
		current_value++;
		//arr[arr.size() - 1].value = current_value;
	}
}

int find_last_index(int find_value, int index)
{
	if (index >= arr.size() - 1)
	{
		return index + 1;
	}

	if (find_value == arr[index].value)
	{
		return find_last_index(find_value, index + 1);
	}

	return index;
}

bool compare_index(Dot d1, Dot d2)
{
	if (d1.index < d2.index)
	{
		return true;
	}

	return false;
}