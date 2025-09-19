#include <iostream>
using namespace std;

// 흰색 킹이 이기려면 무조건 검은색 폰의 바로 아래 지점에 도달해야 함, 도달 불가 시 검은색 승

int n;

char arr[9][9] = {};

struct Pos
{
	int x, y; // x: 좌우, y: 상하
	char ground = '.'; // 현재 밟고 있는 땅의 종류
};

Pos pawn, king;

void move_king_handle();
void move_king(int move_x, int move_y);
bool can_move_king();
bool check_pawn_danger(int x, int y); // 폰의 움직이는 위험 구역인지 체크

void move_pawn_handle();
bool can_move_pawn();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int idx = 0; idx < n; idx++)
	{
		for (int i = 1; i <= 8; i++)
		{
			for (int j = 1; j <= 8; j++)
			{
				cin >> arr[i][j];
			}
		}

		cin >> king.x >> king.y;
		arr[8 - king.y + 1][king.x] = 'P';

		cin >> pawn.x >> pawn.y;
		pawn.ground = arr[8 - pawn.y + 1][pawn.x];
		arr[8 - pawn.y + 1][pawn.x] = 'K';

		move_king_handle();
	}
}

void move_king_handle()
{
	if (!can_move_king() || king.y - pawn.y >= 2) // 킹이 폰보다 2칸 이상 위에 있는 경우는 잡을 수 없음
	{
		cout << "Black\n";
		return;
	}

	// 맨 마지막 줄이 아니라면 이론상 대각선 아래 방향으로 움직이는 것이 무조건 좋을듯?

	int dis_x = pawn.x - king.x;
	int dis_y = pawn.y - king.y;

	if (king.y == 8) // 킹의 y위치가 맨 밑일 경우
	{
		if (dis_x < 0) // 킹이 폰보다 오른쪽인 경우
		{
			move_king(-1, 0);
		}
		else if (dis_x > 0) // 킹이 폰보다 왼쪽인 경우 (참고로 같은 라인일 경우 잡는 것이 확정이라서 움직일 필요 없음)
		{
			move_king(1, 0);
		}
	}
	else // 킹이 y위치가 맨 밑이 아닐 경우
	{
		if (dis_x < 0) // 킹이 폰보다 오른쪽인 경우
		{
			move_king(-1, -1);
		}
		else if (dis_x > 0) // 킹이 폰보다 왼쪽인 경우 (참고로 같은 라인일 경우 잡는 것이 확정이라서 움직일 필요 없음)
		{
			move_king(1, -1);
		}
	}

	move_pawn_handle();
}

void move_king(int move_x, int move_y)
{
	arr[king.y][king.x] = king.ground; // 복원
	king.ground = arr[king.y][king.x + move_x]; // 저장

	arr[king.y][king.x + move_x] = 'K'; // 이동
	king.x += move_x;
	king.y += move_y;
}

bool can_move_king()
{
	if (king.y > 1 && arr[king.y - 1][king.x] == '.') // 위
	{
		if (!check_pawn_danger(king.y - 1, king.x))
		{
			return true;
		}
	}

	if (king.y > 1 && king.x > 1 && arr[king.y - 1][king.x - 1] == '.') // 왼쪽 위
	{
		if (!check_pawn_danger(king.y - 1, king.x - 1))
		{
			return true;
		}
	}

	if (king.y > 1 && king.x < 8 && arr[king.y - 1][king.x + 1] == '.') // 오른쪽 위
	{
		if (!check_pawn_danger(king.y - 1, king.x + 1))
		{
			return true;
		}
	}

	if (king.x > 1 && arr[king.y][king.x - 1] == '.') // 왼쪽
	{
		if (!check_pawn_danger(king.y, king.x - 1))
		{
			return true;
		}
	}

	if (king.x < 8 && arr[king.y][king.x + 1] == '.') // 오른쪽
	{
		if (!check_pawn_danger(king.y, king.x + 1))
		{
			return true;
		}
	}

	if (king.y < 8 && arr[king.y + 1][king.x] == '.') // 아래
	{
		if (!check_pawn_danger(king.y + 1, king.x))
		{
			return true;
		}
	}

	if (king.y < 8 && king.x > 1 && arr[king.y + 1][king.x - 1] == '.') // 왼쪽 아래
	{
		if (!check_pawn_danger(king.y + 1, king.x - 1))
		{
			return true;
		}
	}

	if (king.y < 8 && king.x < 8 && arr[king.y + 1][king.x + 1] == '.') // 오른쪽 아래
	{
		if (!check_pawn_danger(king.y + 1, king.x + 1))
		{
			return true;
		}
	}

	return false;
}

bool check_pawn_danger(int x, int y)
{
	if (x == pawn.x - 1 && y == pawn.y - 1)
	{
		return true;
	}

	if (x == pawn.x + 1 && y == pawn.y - 1)
	{
		return true;
	}

	return false;
}

void move_pawn_handle()
{
	if (!can_move_pawn())
	{
		if (pawn.y == 8)
		{
			cout << "Black\n";
		}
		else
		{
			cout << "White\n";
		}

		return;
	}

	arr[pawn.y][pawn.x] = pawn.ground; // 복원
	pawn.ground = arr[pawn.y + 1][pawn.x]; // 저장

	arr[pawn.y + 1][pawn.x] = 'P'; // 이동
	pawn.y++; // 이동

	move_king_handle();
}

bool can_move_pawn()
{
	if (pawn.y < 8 && arr[pawn.y + 1][pawn.x] == '.')
	{
		return true;
	}

	if (pawn.y < 8 && arr[pawn.y + 1][pawn.x] == 'D')
	{
		return true;
	}

	return false;
}