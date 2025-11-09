#include <iostream>
using namespace std;

int total = -1; // 처음 부분을 제외 (꺾인 것이 아니기 때문)
int wall_up = 0, wall_down, wall_left = -1, wall_right; // 처음 left는 벽을 만들지 않음

enum Dir
{
	up, down, left, right
};

struct Pos
{
	int x, y;
	Pos() {}
	Pos(int x, int y) :x(x), y(y) {}
};

Pos BangBangE(Dir dir, Pos pos)
{
	Dir next_dir;
	Pos next_pos;

	switch (dir)
	{
	case Dir::up:
	{
		if (pos.y - 1 <= wall_up)
		{
			return pos;
		}

		next_dir = Dir::right;
		next_pos = Pos(pos.x, wall_up + 1);
		wall_down--;
		break;
	}
	case Dir::down:
	{
		if (pos.y + 1 >= wall_down)
		{
			return pos;
		}

		next_dir = Dir::left;
		next_pos = Pos(pos.x, wall_down - 1);
		wall_up++;
		break;
	}
	case Dir::left:
	{
		if (pos.x - 1 <= wall_left)
		{
			return pos;
		}

		next_dir = Dir::up;
		next_pos = Pos(wall_left + 1, pos.y);
		wall_right--;
		break;
	}
	case Dir::right:
	{
		if (pos.x + 1 >= wall_right)
		{
			return pos;
		}

		next_dir = Dir::down;
		next_pos = Pos(wall_right - 1, pos.y);
		wall_left++;
		break;
	}
	}

	total++;

	return BangBangE(next_dir, next_pos);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> wall_down >> wall_right;

	wall_down++; // 벽 제외
	wall_right++; // 벽 제외

	Pos result = BangBangE(Dir::right, Pos(1, 1));

	cout << total << "\n" << result.y << " " << result.x;
}