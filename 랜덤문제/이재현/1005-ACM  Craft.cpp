#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, k, w, t, x, y;
#define SIZE 1001

int Hour[SIZE];
int Degree[SIZE];
int Dynamic[SIZE];
vector<int> vec[SIZE];


void  Init()
{
    cin >> t;

    while (t--)
    {

        cin >> n >> k;

        for (int i = 0; i <= n; i++)
        {
            vec[i].clear();
            Degree[i] = 0;
            Dynamic[i] = 0;
        }

        for (int i = 1; i <= n; i++)
            cin >> Hour[i];

        for (int i = 0; i < k; i++)
        {

            cin >> x >> y;
            vec[x].push_back(y);
            Degree[y]++;
        }

        cin >> w;
        queue<int> q;

        for (int i = 1; i <= n; i++)
        {
            if (Degree[i] == 0)
            {
                q.push(i);
                Dynamic[i] = Hour[i];
            }
        }

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int nxt : vec[cur]) {
                Degree[nxt]--;
                Dynamic[nxt] = max(Dynamic[nxt], Dynamic[cur] + Hour[nxt]);

                if (Degree[nxt] == 0)
                    q.push(nxt);
            }
        }

        cout << Dynamic[w] << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Init();

    return 0;
}
