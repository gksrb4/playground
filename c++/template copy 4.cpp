#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<int> nt;

    for (int i=0;i<n;i++) {
        nt.push_back(i+1);
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i==j) continue;
            if (!computers[i][j]) continue;
            if (nt[j] >= nt[i]) nt[j] = nt[i];
            else {
                int tmp = nt[i];
                for (int ii=0;ii<n;ii++) {
                    if (nt[ii] == tmp) nt[ii] = nt[j];
                }
            }
        }
    }

    sort(nt.begin(), nt.end());

    int nn = 0;
    for (const auto& n : nt) {
        if (nn != n) {
            answer++;
            nn = n;
        }
    }
    return answer;
}

int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;
    int ret = solution(
        5,
        {{1, 1, 1, 0, 0}, {1, 1, 0, 0, 0}, {1, 0, 1, 1, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 1}}
    );
    return 0;
}
