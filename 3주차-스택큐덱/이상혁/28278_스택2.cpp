#include <iostream>
using namespace std;

struct Node
{
	int value;

	Node* next = nullptr;
};

struct Stack
{
	Node* head = nullptr;

	int node_count = 0;

	void push(int value)
	{
		node_count++;

		Node* temp = new Node;
		temp->value = value;

		if (!head)
		{
			head = temp;
			return;
		}

		temp->next = head;
		head = temp;
	}

	void pop()
	{
		if (empty())
		{
			return;
		}

		Node* temp = head;
		head = head->next;

		delete temp;

		node_count--;
	}

	int top()
	{
		if (empty())
		{
			return 0;
		}

		return head->value;
	}

	int count()
	{
		return node_count;
	}

	bool empty()
	{
		return node_count == 0 ? true : false;
	}
};

Stack stack;

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int select;
		cin >> select;

		switch (select)
		{
		case 1:
			int temp;
			cin >> temp;
			stack.push(temp);
			break;

		case 2:
			if (!stack.empty())
			{
				cout << stack.top() << "\n";
			}
			else
			{
				cout << "-1\n";
			}
			stack.pop();
			break;

		case 3:
			cout << stack.count() << "\n";
			break;

		case 4:
			if (stack.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
			break;

		case 5:
			if (!stack.empty())
			{
				cout << stack.top() << "\n";
			}
			else
			{
				cout << "-1\n";
			}
			break;
		}
	}
}

int main()
{
	input();
}