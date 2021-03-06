#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}


bool compare_si(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int, int>>> map;
    unordered_map<string, int> sum_map;
    
    for (int i=0;i<genres.size();i++) {
        string g = genres[i];
        int c = plays[i];
        map[g].push_back(make_pair(i, c));
        sum_map[g] += c;
    }

    vector<pair<string, int>> sum;

    for (auto& s : sum_map) {
        sum.push_back(make_pair(s.first, s.second));   
    }

    sort(sum.begin(), sum.end(), compare_si);

    for (auto& m : sum) {
        auto& p = map[m.first];
        sort(p.begin(), p.end(), compare);
        answer.push_back(p[0].first);
        if (p.size() > 1) {
            answer.push_back(p[1].first);
        }
    }
    
    return answer;
}

int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;
    auto ret = solution(
        vector<string>{"classic", "pop", "classic", "classic", "pop"},
        vector<int>{500, 600, 150, 800, 2500});
    return 0;
}
