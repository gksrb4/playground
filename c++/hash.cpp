#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    vector<string> keys;
    vector<vector<string>> wears;
    
    for (auto cloth : clothes) {
        string key = cloth[1];
        string wear = cloth[0];
        int i;
        for (i=0;i<keys.size();i++) {
            if (keys[i] == key) {
                wears[i].push_back(wear);
                break;
            }
        }
        if (i == keys.size()) {
            keys.push_back(key);
            wears.push_back(vector<string>{wear});
        }
    }

    for (auto wear : wears) {
        answer *= (wear.size() + 1);
    }

    answer -= 1;
    
    return answer;
}

int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;
    vector<vector<string>> clothes = vector<vector<string>>{{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    int sol = solution(clothes);
    return 0;
}
