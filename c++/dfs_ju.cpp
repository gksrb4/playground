#include <iostream>

using namespace std;

int N, arr[11];

void DFS(int depth)
{
    int i;
    if (depth > N) {
        for (i=1;i<=N;i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (i=1;i<=6;i++) {
        arr[depth] = i;
        DFS(depth+1);
    }
}


int main(void)
{
    N = 2;
    string a;
    copy()
    a.size
    DFS(1);
    return 0;
}