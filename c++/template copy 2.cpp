#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> c;
    for (int i=0;i<n;i++) {
        c.push_back(1);
    }
    
    for (auto& l : lost) {
        c.at(l-1) = c.at(l-1) - 1;
    }
    
    for (auto& r : reserve) {
        c.at(r-1) = c.at(r-1) + 1;
    }
    
    for (int i=0;i<n;i++) {
        switch (c.at(i)) {
            case 1:
            case 2:
                answer++;
                break;
            case 0:
                if (i != 0 && c.at(i-1) == 2) {
                    answer++;
                    break;
                }
                if (i != n-1 && c.at(i+1) == 2) {
                    answer++;
                    c.at(i+1) = 1;
                }
                break;
        }
    }
    
    return answer;
}

int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;
    int ret = solution(
        5,
        {2,4},
        {1,3,5}
    );
    return 0;
}
