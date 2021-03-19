#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> recur(bool plus, int i, vector<int> rets, const vector<int>& nums)
{
    if (i >= nums.size()) {
        return rets;
    }
    for (auto& ret : rets) {
        if (plus) {
            ret += nums.at(i);
        } else {
            ret -= nums.at(i);
        }
    }

    if (i+1 == nums.size()) return rets;

    auto sol1 = recur(true, i+1, rets, nums);
    auto sol2 = recur(false, i+1, rets, nums);
    sol1.insert(sol1.end(), sol2.begin(), sol2.end());
    return sol1;
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    auto sol1 = recur(true, 0, {0}, numbers);
    auto sol2 = recur(false, 0, {0}, numbers);
    sol1.insert(sol1.end(), sol2.begin(), sol2.end());
    for (const auto& ret : sol1) {
        if (ret == target) {
            answer++;
        }
    }
    numbers.
    return answer;
}


int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;
    

    auto ret = solution(
        {1,1,1,1,1},
        3
    );


    return 0;
}
