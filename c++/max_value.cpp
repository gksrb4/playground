#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 최대값 문제


int srt_cnt = 0;

// vector<int> test = vector<int>{99, 95, 91, 90, 9, 900, 988};
vector<int> test = vector<int>{3, 30, 34, 5, 9};

bool comp(const string &s1, const string &s2)
{
    cout << "s1: " << s1 << ", s2: " << s2 << endl;
    cout << s1 << s2 << endl;
    cout << s2 << s1 << endl;
    cout << "ret[" << srt_cnt << "]: " << (s1 + s2 > s2 + s1) << endl;
    srt_cnt++;
    // for (auto t : test) {
    //     cout << t << " ";
    // }
    // cout << endl;
    return s1 + s2 > s2 + s1;
}

// 1 2 3 4 5 6 7 8 9 // 오름차순
// 9 8 7 6 5 4 3 2 1 // 내림차순
bool comp2(const int &a, const int &b)
{
    cout << "a: " << a << ", b: " << b << ", ret: " << (a < b) << endl;
    // 오름차순
    return a < b;
    // 내림차순
    // return a > b;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> s_numbers;
    for (auto &num : numbers) {
        s_numbers.push_back(to_string(num));
    }
    sort(s_numbers.begin(), s_numbers.end(), comp);

    for (auto &num : s_numbers) {
        answer += num;
    }

    return answer;
}



int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;
    for (auto t : test) {
        cout << t << " ";
    }
    cout << endl;
    int _arr[] = {12,54,7,1,2,3,654,78,1,2,35,7};

    sort(_arr, _arr + sizeof(_arr)/sizeof(int), comp2);

    for (auto t : _arr) {
        cout << t << " ";
    }
    cout << endl;

    string ret = solution(test);
    cout << "solution: " << ret << endl;
    return 0;
}
