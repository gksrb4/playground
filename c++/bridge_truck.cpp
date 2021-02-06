#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    queue<int> running_q;
    vector<int> secs;
    
    for (int truck_weight : truck_weights) {
        q.push(truck_weight);
    }
    int answer = 0;
    int weight_on_the_bridge = 0;
    int truck_cnt = truck_weights.size();
    int truck_cnt_over_the_bridge = 0;
    while (!(q.empty() && running_q.empty())) {
        ;
        int start = truck_cnt_over_the_bridge;
        int end = truck_cnt_over_the_bridge + running_q.size();
        for (int i=start;i<end;i++) {
            int &sec = secs[i];
            if (sec++ == bridge_length) {
                truck_cnt_over_the_bridge++;
                weight_on_the_bridge -= running_q.front();
                running_q.pop();
            }
        }
        if (!q.empty() && ((weight_on_the_bridge + q.front()) <= weight)) {
            weight_on_the_bridge += q.front();
            running_q.push(q.front());
            q.pop();
            secs.push_back(1);
        }
        answer++;
    };
    
    return answer;
}
int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;
    // vector<int> test = vector<int>{10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    // auto ret = solution(100, 100, test);
    vector<int> test = vector<int>{7, 4, 5, 6};
    auto ret = solution(2, 10, test);
    return 0;
}
