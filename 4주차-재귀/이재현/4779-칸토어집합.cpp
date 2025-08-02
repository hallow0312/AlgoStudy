#include<bits/stdc++.h>

using namespace std;

#define IOS_BASE ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int n;

void Answer(int num)
{
    int a = pow(3, num-1);
    -if (num == 0)
    {
        cout << "-";
        return;
    }
    Answer(num - 1);
    for (int i = 0; i < a; i++)
    {
        cout << " ";
    }
    Answer(num - 1);
}
void Init()
{
    
    while(cin>>n)
    {
        Answer(n);
        cout << '\n';
    }

}
int main()
{
    IOS_BASE
     Init();

    return 0;
}
