#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    sort(scoville.begin(), scoville.end());
    
    int first, second, sum;
    while (scoville[0] < K && scoville.size() > 1) {
        first = scoville[0];
        second = scoville[1];
        scoville.erase(scoville.begin());
        scoville.erase(scoville.begin());
        sum = first + second * 2;
        scoville.insert(scoville.begin(), sum);
        sort(scoville.begin(), scoville.end());
        answer++;
    }
    
    if (scoville.size() == 1 && scoville[0] < K) {
        return -1;
    }
    
    return answer;
}

int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;
    auto ret = solution(
        // vector<int>{1, 2, 3, 9, 10, 12},
        vector<int>{1, 1, 1, 1, 1, 1, 1, 1},
        7);
    return 0;
}
