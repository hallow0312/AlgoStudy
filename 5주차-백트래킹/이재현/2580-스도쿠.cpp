#include<bits/stdc++.h>
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int n, cnt;
#define SIZE 9
int buffer[SIZE][SIZE];

void Print()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << buffer[i][j]<<' ';
        }
        cout << '\n';
    }
}
bool Check(int x, int y,int value)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (buffer[x][i] == value || buffer[i][y] == value)
            return  false;
    }
    int a = (x / 3) * 3;
    int b = (y / 3) * 3;
    for (int i = a; i < a+3; i++)
    {
        for (int j = b; j <b+ 3; j++)
        {
            if (buffer[i][j] == value) return false;
        }
    }
    return  true;
}
void Answer(int n)
{
    if (n == 81)
    {
        Print();
        exit(0);
    }
    int a = n / SIZE;
    int b = n % SIZE;
    if (buffer[a][b] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (Check(a, b, i))
            {
                buffer[a][b] = i;
                Answer(n + 1);
                buffer[a][b] = 0;
            }
        }
       
    }
    else
        Answer(n + 1);
}
void Init()
{
    memset(buffer, 0, sizeof(buffer));
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> buffer[i][j];
        }
    }
    Answer(0);
    
}

int main()
{
    IOS_BASE
    Init();

    return 0;
}
