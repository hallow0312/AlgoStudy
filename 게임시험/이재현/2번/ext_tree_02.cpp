#include <iostream>
#include <stack>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

// 수식 트리 노드 구조체
struct BTreeNode {
    std::string data; // char → std::string
    BTreeNode* left;
    BTreeNode* right;
};

BTreeNode* MakeBTreeNode() {
    BTreeNode* node = new BTreeNode;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 노드에 연산자 데이터 저장
void SetData(BTreeNode* node, const std::string& data) {
    node->data = data;
}

std::string GetData(BTreeNode* node) {
    return node->data;
}

// 스택에서 왼쪽 자식 노드 꺼내 연결
void MakeLeftSubTree(BTreeNode* parent, BTreeNode* child) {
    parent->left = child;
}

// 스택에서 오른쪽 자식 노드 꺼내 연결
void MakeRightSubTree(BTreeNode* parent, BTreeNode* child) {
    parent->right = child;
}

BTreeNode* GetLeftSubTree(BTreeNode* node) {
    return node->left;
}

BTreeNode* GetRightSubTree(BTreeNode* node) {
    return node->right;
}

// 연산자 우선순위 함수, op는 연산자 문자('+', '-', '*', '/')
int GetPriority(char op) {
    //
    // ★ 문제 ( A )
    //
    // *, / : 5 (가장 높은 우선순위)
    // +, - : 3 (중간 우선순위)
    // 우선순위에 맞도록 연산자와 반환값을 수정하시오.
    if (op == '*' || op == '/') return 5;
    if (op == '+' || op == '-') return 3;
    //
    // ★ 문제 ( A )
    //
    // ( : 1 (괄호는 가장 낮은 우선순위로 처리)
    if (op == '(') return 1;
    // 나머지 문자(예: 공백 등) : -1 (우선순위 없음)
    return -1;
}

// 중위 표기법 -> 후위 표기법 변환 (토큰(숫자, 연산자 등) 단위, 숫자는 최대 10자리)
void InfixToPostfix(const char* inStr, std::vector<std::string>& outTokens) {
    stack<char> strStack;
    size_t len = strlen(inStr); // int → size_t로 변경
    for (size_t i = 0; i < len; ) {
        if (isdigit(inStr[i])) {
            std::string num;
            int cnt = 0;
            while (i < len && isdigit(inStr[i]) && cnt < 10) {
                num += inStr[i++];
                cnt++;
            }
            outTokens.push_back(num);
        }
        else {
            char token = inStr[i];
            switch (token) {
            case '(':
                strStack.push(token);
                break;
            case ')':
                while (!strStack.empty() && strStack.top() != '(') {
                    outTokens.push_back(std::string(1, strStack.top()));
                    strStack.pop();
                }
                strStack.pop(); // '(' 제거
                break;
                //
                // ★ 문제 ( B )
                //
                // 연산자를 만났을 때, 스택에 있는 연산자들과 우선순위를 비교하여
                // 현재 연산자(token)의 우선순위가 낮거나 같으면 스택의 연산자를 꺼내서(outTokens에 추가)
                // 후위 표기법으로 변환한다. 이후 현재 연산자를 스택에 push한다.
            case '+': case '-': case '*': case '/':
                // 1. 스택이 비어있지 않고, 현재 연산자(token)의 우선순위가
                //    스택의 top에 있는 연산자보다 낮거나 같을 때 반복
                while (!strStack.empty() && GetPriority(token) <= GetPriority(strStack.top())) {


                    // 2. 스택 top에 있는 연산자(문자 1개)를 후위표기법 결과에 추가
                    // 스택 top 연산자를 문자열로 변환하여 추가하도록 수정하시오.
                    outTokens.push_back(std::string(1, strStack.top()));
                    // 3. 스택에서 top 연산자를 제거(pop)하도록 아래 내용을 수정하시오.
                    strStack.pop();
                }
                // 4. 현재 연산자를 스택에 push
                strStack.push(token);
                break;
                //
                // ★ 문제 ( B )
                //
            }
            i++;
        }
    }
    while (!strStack.empty()) {
        outTokens.push_back(std::string(1, strStack.top()));
        strStack.pop();
    }
}

// 후위 표기법(예: "2 3 + 4 *") 토큰을 받아서, 이진 수식 트리를 생성
// tokens: 후위 표기법으로 변환된 토큰(숫자, 연산자 등) 리스트
// 반환값: 수식 트리의 루트 노드 포인터
BTreeNode* MakeExpTree(const std::vector<std::string>& tokens) {
    stack<BTreeNode*> stack; // 트리 노드 포인터를 저장할 스택
    for (const auto& tok : tokens) {
        BTreeNode* pnode = MakeBTreeNode(); // 새 노드 생성
        // 1. 숫자(피연산자)라면
        if (isdigit(tok[0]) && tok.find_first_not_of("0123456789") == std::string::npos) {
            SetData(pnode, tok); // 노드에 숫자 데이터 저장
        }
        else {
            //
            // ★문제( C )
            //
            // 2. 연산자라면
            // 스택에서 오른쪽 자식 노드 꺼내 연결
            MakeRightSubTree(pnode, stack.top());

            // 스택에서 제거하는 코드를 추가하세요.
            stack.pop();
            // 스택에서 왼쪽 자식 노드 꺼내 연결
            MakeLeftSubTree(pnode, stack.top());

            // 스택에서 제거하는 코드를 추가하세요.
            stack.pop();
            // 노드에 연산자 데이터 저장
            // 노드에 연산자 데이터 저장하는 함수를 추가하세요.
            SetData(pnode, tok);
            //
            // ★문제( C )
            //
        }
        // 3. 현재 노드를 스택에 push
        stack.push(pnode);
    }
    // 마지막에 남은 노드가 트리의 루트
    BTreeNode* pnode = stack.top();
    stack.pop();
    return pnode;
}

// 수식 트리 계산
int EvaluateExpTree(BTreeNode* bt) {
    if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
        return stoi(GetData(bt));

    int op1 = EvaluateExpTree(GetLeftSubTree(bt));
    int op2 = EvaluateExpTree(GetRightSubTree(bt));

    std::string op = GetData(bt);
    if (op == "+") return op1 + op2;
    if (op == "-") return op1 - op2;
    if (op == "*") return op1 * op2;
    if (op == "/") return op1 / op2;
    return 0;
}

// 트리 메모리 해제
void DeleteTreeNode(BTreeNode* node) {
    if (node == NULL) return;
    DeleteTreeNode(node->left);
    DeleteTreeNode(node->right);
    delete node;
}

// 트리 구조를 아스키로 시각화하는 함수 (왼쪽에서 오른쪽으로 전개)
void PrintAsciiTree(BTreeNode* node, int depth = 0, char branch = ' ') {
    if (node == NULL) return;
    PrintAsciiTree(node->right, depth + 1, '/');
    for (int i = 0; i < depth; i++) cout << "    ";
    // 숫자 또는 연산자 모두 '로 감싸서 출력
    cout << branch << "--'" << node->data << "'" << endl;
    PrintAsciiTree(node->left, depth + 1, '\\');
}

// 후위 표기법을 ''로 감싸서 출력
void PrintPostfix(const std::vector<std::string>& tokens) {
    cout << "후위표기법 수식 변환: ";
    for (const auto& tok : tokens) {
        cout << "'" << tok << "' ";
    }
    cout << endl;
}

// 메인함수
int main() {
    //
    // ★ 수험번호, 성명 작성 >> 반드시 수정 필수(수정 안하면 감점)
    //
    system("cls");
    // 아래의 수험번호와 성명을 본인 정보로 수정하세요.
    system("title KOCCA:[문제2](답안작성용), 수험번호:nnnnnnnn, 성명:홍길동");
    system("mode con:lines=12 cols=45");
    cout << "============================================\n";
    cout << " KOCCA:[문제2](답안작성용)\n";
    cout << " 수험번호: 202112296\n";
    cout << " 성명: 이재현\n";
    cout << "============================================\n\n";
    //
    // ★ 수험번호, 성명 작성(수정 안하면 감점)
    //

    char InputString[1000] = "235*25/(12+4*7)-81";
    std::vector<std::string> OutputTokens;

    // 중위표기법 → 후위표기법 변환
    InfixToPostfix(InputString, OutputTokens);
    cout << "중위표기법 수식 입력: " << InputString << endl;

    // 후위표기법으로 수식 트리 생성
    BTreeNode* eTree = MakeExpTree(OutputTokens);

    // 트리 구조 아스키 시각화 (왼쪽에서 오른쪽)
    cout << "\n[수식 트리 구조]\n";
    PrintAsciiTree(eTree);

    // 후위표기법 출력
    PrintPostfix(OutputTokens);

    // 수식트리로 결과 계산
    int res = EvaluateExpTree(eTree);
    cout << "\n연산의 결과: " << res << endl;

    // 수식트리 메모리 해제
    DeleteTreeNode(eTree);

    system("pause");
    return 0;
}