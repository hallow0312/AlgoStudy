#include <iostream>
using namespace std;
#define LL long long
LL n, m;
struct Node
{
    LL x;
    LL y;
    Node(LL a, LL b) : x(max(a, b)), y(min(a, b)) {} 
};
bool Euclead(Node node, bool turn)
{
    if (node.y == 0)return !turn; 
    if (node.x % node.y == 0|| node.x / node.y >= 2)return turn;
  
    Node newNode(node.x % node.y, node.y);
    return Euclead(newNode, !turn);
}
void Init() 
{
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)break;
        Node node(n, m); 
        if (Euclead(node, true))cout << "A wins" << '\n';
        else cout << "B wins" << '\n';
    }
 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Init();
    return 0;
}
