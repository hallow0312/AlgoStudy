#include <iostream>
using namespace std;

int n, k;

int arr[500001];

void merge(int idx1, int idx2, int* count)
{
	int* temp = new int[idx2 - idx1 + 1];
	int mid = (idx1 + idx2) / 2;
	int i = idx1; int j = mid + 1; int t = 0;

	while (i <= mid && j <= idx2)
	{
		if (arr[i] <= arr[j])
		{
			temp[t++] = arr[i++];
		}
		else
		{
			temp[t++] = arr[j++];
		}
	}

	while (i <= mid)
	{
		temp[t++] = arr[i++];
	}

	while (j <= idx2)
	{
		temp[t++] = arr[j++];
	}

	i = idx1;
	t = 0;

	while (i <= idx2)
	{
		(*count)++;
		arr[i] = temp[t];

		if (*count == k)
		{
			cout << arr[i] << "\n";
			exit(0);
		}

		i++;
		t++;
	}
}

void merge_sort(int idx1, int idx2, int* count)
{
	if (idx1 < idx2)
	{
		int mid = (idx1 + idx2) / 2;

		merge_sort(idx1, mid, count);
		merge_sort(mid + 1, idx2, count);
		merge(idx1, idx2, count);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr[i] = temp;
	}

	int* temp = new int;
	*temp = 0;
	merge_sort(0, n - 1, temp);

	cout << "-1\n";
}