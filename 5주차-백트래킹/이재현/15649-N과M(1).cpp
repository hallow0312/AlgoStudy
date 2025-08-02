#include<bits/stdc++.h>
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int n, m;
#define SIZE 8
bool visited[SIZE];
vector<int>vec;
void  Print()
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << "\n";
}
void Answer(int start, int  cnt, int  num)
{
    if (start == num)
    {
        Print();
        return;
    }
    for (int i = 1; i <= cnt; i++)
    {
        if (visited[i] == true)  continue;
        visited[i] = true;
        vec.push_back(i);
        Answer(start + 1, cnt, num);
        vec.pop_back();
        visited[i] = false;
    }
}
void Init()
{
    cin >> n >> m;
    Answer(0, n, m);
}

int main()
{
    IOS_BASE
        Init();

    return 0;
}
