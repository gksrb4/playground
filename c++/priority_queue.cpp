#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <queue>

using namespace std;
 
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second >= b.second;
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    sort(jobs.begin(), jobs.end());

    int time=0, i=0, waiting_time=0;
    while(!(i==jobs.size() && pq.empty())) {
        if (i < jobs.size() && jobs[i][0] <= time) {
            pq.push(make_pair(jobs[i][0], jobs[i][1]));
            i++;
        } else {
            if (!pq.empty()) {
                waiting_time += (time - pq.top().first) + (pq.top().second);
                time += pq.top().second;
                pq.pop();
            } else {
                time = jobs[i][0];
            }
        }
    }
    if (i)  answer = waiting_time / i;
    return answer;
}
 
int main(){
    int ret = solution(
        {{0, 3}, {1, 9}, {2, 6}}
    );
    return 0;
}