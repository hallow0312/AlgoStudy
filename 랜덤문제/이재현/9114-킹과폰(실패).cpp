#include <bits/stdc++.h>
using namespace std;

#define SIZE 8
#define FORBIDDEN 'F'
#define SAFE '.'
#define DANGER 'D'

struct Node {
    int x, y;
    bool operator==(const Node& other) const {
        return x == other.x && y == other.y;
    }
};

struct State { Node white; Node black; };

inline bool InBounds(const Node& p) {
    return p.x >= 0 && p.x < SIZE && p.y >= 0 && p.y < SIZE;
}

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

char chess[SIZE][SIZE];

bool Test(Node white, Node black) {
    if (!InBounds(white) || !InBounds(black)) return false;
    if (chess[white.x][white.y] == FORBIDDEN || chess[white.x][white.y] == DANGER) return false;
    if (white == black) return true;

    bool visited[SIZE][SIZE][SIZE][SIZE] = {};
    queue<State> q;
    q.push({ white, black });
    visited[white.x][white.y][black.x][black.y] = true;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        Node w = cur.white;
        Node b = cur.black;

        for (int k = 0; k < 8; ++k) {
            Node nw = { w.x + dx[k], w.y + dy[k] };
            if (!InBounds(nw)) continue;
            if (chess[nw.x][nw.y] == FORBIDDEN || chess[nw.x][nw.y] == DANGER) continue;
            if (nw == b) return true;

            Node atk1 = { b.x - 1, b.y - 1 };
            Node atk2 = { b.x - 1, b.y + 1 };
            if (InBounds(atk1) && chess[atk1.x][atk1.y] != FORBIDDEN && nw == atk1) continue;
            if (InBounds(atk2) && chess[atk2.x][atk2.y] != FORBIDDEN && nw == atk2) continue;

            Node nb = { b.x - 1, b.y };
            if (!InBounds(nb)) continue;

            if (chess[nb.x][nb.y] == FORBIDDEN)
            {
                if (!visited[nw.x][nw.y][b.x][b.y]) {
                    visited[nw.x][nw.y][b.x][b.y] = true;
                    q.push({ nw, b });
                }
            }
            else {
                if (!visited[nw.x][nw.y][nb.x][nb.y]) {
                    visited[nw.x][nw.y][nb.x][nb.y] = true;
                    q.push({ nw, nb });
                }
            }
        }
    }
    return false;
}

void Init() {
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cin >> chess[i][j];

        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a >= 1 && a <= SIZE && b >= 1 && b <= SIZE &&
            c >= 1 && c <= SIZE && d >= 1 && d <= SIZE) {
            a--; b--; c--; d--;
        }

        cout << (Test({ a,b }, { c,d }) ? "White" : "Black") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Init();
    return 0;
}
