#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.first > p2.first;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;

    vector<pair<int, int>> unique_priorities = vector<pair<int, int>>();
    
    deque<pair<int, int>> dq;
    
    for (int i=0;i<priorities.size();i++) {
        dq.push_back(make_pair(priorities[i], i));
        bool existed = false;
        for (int j=0;j<unique_priorities.size();j++) {
            if (unique_priorities[j].first == priorities[i]) {
                existed = true;
                unique_priorities[j].second++;
                break;
            }
        }
        if (!existed) {
            unique_priorities.push_back(make_pair(priorities[i], 1));
        }
    }
    sort(unique_priorities.begin(), unique_priorities.end(), comp);

    while (!dq.empty()) {
        int current_highest_priority = unique_priorities[0].first;
        pair<int, int> p = dq.front();
        dq.pop_front();    
        if (current_highest_priority != p.first) {
            dq.push_back(p);
        } else {
            answer++;
            unique_priorities[0].second--;
            if (unique_priorities[0].second == 0) {
                unique_priorities.erase(unique_priorities.begin());
            }
            if (p.second == location) {
                break;
            }
        }
    }
    return answer;
}


int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;
    // vector<int> test = vector<int>{2,1,3,2};
    // ret = 1
    vector<int> test = vector<int>{1, 1, 9, 1, 1, 1};
    auto ret = solution(test, 0);
    return 0;
}
