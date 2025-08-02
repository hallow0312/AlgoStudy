#include<bits/stdc++.h>
using namespace std;
#define IOS_BASE ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int n, m;
#define SIZE 9

vector<int>vec;
void  Print()
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << "\n";
}
void Answer(int start, int  cnt,  int  num)
{
    if (vec.size() == num)
    {
        Print();
        return;
    }
    for (int i = start; i <= cnt; i++)
    {  
       
        vec.push_back(i);
        Answer(i, cnt, num);
        vec.pop_back();
    
    }
}
void Init()
{
    cin >> n >> m;
    Answer(1, n, m);
}

int main()
{
    IOS_BASE
        Init();

    return 0;
}
