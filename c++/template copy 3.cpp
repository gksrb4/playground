#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second <= b.second;
}

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    vector<pair<int, int>> workers;

    for (const auto& t : times) {
        workers.push_back(make_pair(t, 0));
    }
    int min_time = 0, i = 0, p = 0;
    printf("i=%d, t=%d, [[%d, %d] [%d, %d]]\n", 
            i, answer, workers[0].first, workers[0].second, workers[1].first, workers[1].second);
    while (i != n) {
        for (int j=0;j<workers.size();j++) {
            auto& w = workers[j];
            w.second -= min_time;
            if (w.second == 0) {
                if (min_time) i++;
                if (i != n) w.second = w.first;
                else break;
            }
        }
        sort(workers.begin(), workers.end(), cmp);
        printf("i=%d, t=%d, [[%d, %d] [%d, %d]]\n", 
            i, answer, workers[0].first, workers[0].second, workers[1].first, workers[1].second);
        min_time = workers.front().second;
        answer += min_time;
    }

    return answer;
}

int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;
    int ret = solution(
        6,
        {7,10}
    );
    return 0;
}
