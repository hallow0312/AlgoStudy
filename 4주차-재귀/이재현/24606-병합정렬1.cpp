#include <iostream>
using namespace std;

#define IOS_BASE ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SIZE 500001

int A[SIZE];
int tmp[SIZE];
int N, K;
int saveCount = 0;
int answer = -1;

void merge(int* A, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int t = left;

    while (i <= mid && j <= right) {
        if (A[i] <= A[j]) tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
    }

    while (i <= mid) tmp[t++] = A[i++];
    while (j <= right) tmp[t++] = A[j++];

 
    for (int l = left; l <= right; l++) {
        A[l] = tmp[l];
        saveCount++;
        if (saveCount == K) {
            answer = A[l];
        }
    }
}

void merge_sort(int* A, int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}
void Init()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    merge_sort(A, 0, N - 1);

    cout << answer << '\n';
}
int main()
{
    IOS_BASE
        Init();

    return 0;
}
