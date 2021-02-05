#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int p1[] = {1, 2, 3, 4, 5};
    int p2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int p3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int p1_sz = sizeof(p1)/sizeof(int);
    int p2_sz = sizeof(p2)/sizeof(int);
    int p3_sz = sizeof(p3)/sizeof(int);
    
    int score[3] = {0};
    for (int i=0;i<answers.size();i++) {
        int answ = answers[i];
        int _p1 = p1[i%p1_sz];
        int _p2 = p2[i%p2_sz];
        int _p3 = p3[i%p3_sz];
        if (_p1 == answ) {
            score[0]++;
        }
        if (_p2 == answ) {
            score[1]++;
        }
        if (_p3 == answ) {
            score[2]++;
        }
    }
    
    // int highest_score = max(max(score[0], score[1]), score[2]);
    int highest_score = *max_element(score, score + 2);
    for (int i = 0; i < 3; i++){
        if (score[i] == highest_score)
            answer.push_back(i + 1);
    }
    //int they_max = *max_element(they.begin(),they.end());
    // int highest_score = *max_element(score, score + 2);
    return answer;
}


int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;
    vector<int> test = vector<int>{1, 2, 5, 3, 2, 1, 1, 1, 1};

    vector<int> ret = solution(test);
    for (auto &num : ret) {
        cout << num << " ";
    }
    cout << endl;
    // cout << "solution: " << ret << endl;
    return 0;
}
