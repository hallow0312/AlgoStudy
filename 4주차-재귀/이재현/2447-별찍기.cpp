#include<bits/stdc++.h>
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int num;

bool BlankTarget(int a ,int b,int size)
{
    return ((a / size) % 3 == 1) && ((b / size) % 3 == 1);
}
void Answer(int x, int y, int size)
{
   
    if (BlankTarget(x,y,size))
        cout << ' ';
    else {
        if (size == 1)  cout << '*';
        else  Answer(x, y, size / 3);
    }
}
void Init()
{

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            Answer(i, j,num);
        cout << '\n';
    }

}
int main()
{
    IOS_BASE
        Init();

    return 0;
}
