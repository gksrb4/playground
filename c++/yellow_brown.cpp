#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // 10 + 2 = 12
    // 1, 2, 3, 4, 6, 12
    // 24 + 24 = 48
    // 1, 2, 3, 4, 6, 8, 12, 16, 24, 48
    
    vector<vector<int>> yellow_shape = vector<vector<int>>();
    for (int i=0;i<(yellow/2)+1;i++) {
        int n = (i+1);
        if (yellow%n == 0) {
            yellow_shape.push_back(vector<int>{yellow/n, n});
        }
    }
    for (auto y : yellow_shape) {
        cout << "y: " << y[0] << ", " << y[1] << endl;
    }
    for (int i=0;i<yellow_shape.size();i++) {
        auto shape = yellow_shape[i];
        int brown_cnt = shape[0]*2 + shape[1]*2 + 4;
        if (brown_cnt == brown) {
            answer.push_back(shape[0]+2);
            answer.push_back(shape[1]+2);
            break;
        }
    }
    
    
    return answer;
}

int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;

    auto ret = solution(24, 24);

    cout << "solution: " << ret[0] << ", " << ret[1] << endl;
    return 0;
}
