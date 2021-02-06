#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<int> calculate(int n1, int n2)
{
    vector<int> cal = vector<int>();
    // if (n1 == n2) cal.push_back(n1*10+n2);
    cal.push_back(n1+n2);
    cal.push_back(n1-n2);
    // cal.push_back(n2-n1);
    cal.push_back(n1*n2);
    // if (n1 != 0) cal.push_back(n2/n1);
    if (n2 != 0) cal.push_back(n1/n2);
    return cal;
}

vector<int> get_n_vec(int N, int n, vector<vector<int>> prev_vector)
{
    if (prev_vector.size() >= n) {
        return prev_vector[n-1];
    }
    vector<int> vec = vector<int>();
    if (n == 0) return vec;
    if (n == 1) {
        vec.push_back(N);
        return vec;
    } else {
        string NN = "";
        for (int i=0;i<n;i++) {
            NN += to_string(N);
        }
        vec.push_back(stoi(NN));
        // 1 부터 시작 
        for (int i=1;i<n;i++) {
            // j 는 n (최근) - i
            int j = n - i;
            auto s1 = get_n_vec(N, i, prev_vector);
            auto s2 = get_n_vec(N, j, prev_vector);
            for (int n1 : s1) {
                for (int n2 : s2) {
                    auto cal = calculate(n1, n2);
                    vec.insert(vec.begin(), cal.begin(), cal.end());
                }
            }
        }
        sort(vec.begin(), vec.end());
        // 중복 제거
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        return vec;
    }
}

int solution(int N, int number) {
    int answer = 0;
    vector<vector<int>> prev_vector;
    for (int i=1;i<9;i++) {
        prev_vector.push_back(get_n_vec(N, i, prev_vector));
        for (auto ret : prev_vector[prev_vector.size()-1]) {
            if (ret == number) {
                return i;
            }
        }
    }
    
    return -1;
}

 
int answer = 9;
 
void dfs(int N, int number, int count, int currentNumber) {
    //일정횟수 이상갔다면 리턴
    if (count >= 9)        return;
    //현재수가 number와 같다면 작은횟수를 answer에 저장후 리턴
    if (currentNumber == number) {
        answer = min(answer, count);
        return;
    }
    int tempNumber = 0;
    //최대 N의 사용횟수는 9번까지이므로 이때까지 반복
    for (int i = 0; i + count< 9 ; i++) {
        //N부터 NN,NNN,NNNN .....
        tempNumber = tempNumber * 10 + N;
        //더하기 빼기 곱하기 나누기 dfs 사용
        dfs(N, number, count + 1 + i, currentNumber + tempNumber);
        dfs(N, number, count + 1 + i, currentNumber - tempNumber);
        dfs(N, number, count + 1 + i, currentNumber * tempNumber);
        dfs(N, number, count + 1 + i, currentNumber / tempNumber);
    }
}
 
int __solution(int N, int number) {
    dfs(N, number, 0, 0);
    //answer가 9라는 뜻은 number와 맞는 경우가 없었던 것이므로 -1 리턴
    if (answer == 9)    return -1;
    return answer;
}


int __solution2(int N, int number) {
    int answer = 0; 
    
    //"N"*(i+1)로 초기화
    vector<set<int>> arr(8);
    for(int i = 0; i < 8; i++){
        int n = 0;
        int digit = i+1;
        while(digit > 0){
            digit--;
            n += N*pow(10, digit);
        }
        arr[i].insert(n);
    }
    //[DP] 사칙연산으로 가능한 숫자 모두 확인
    for(int i = 1; i < 8; i++){
        for(int j = 0; j<i; j++){
            for(auto &x : arr[j]){
                for(auto &y : arr[i-j-1]){
                    arr[i].insert(x+y);
                    arr[i].insert(x*y);
                    arr[i].insert(x-y);
                    if(y!=0) arr[i].insert(x/y);
                }
            }
        }
        //number가 있는지 확인
        if(arr[i].find(number) != arr[i].end()){
            return i+1;
        }
    }
    //1부터 8까지 중에 return 없을시 -1 return
    return -1;
}

int main()
{
    srand(time(NULL));
    cout << "TEST DEBUG " << __FILE__ << endl;
    // auto ret = solution(12, 4);
    // auto ret = solution(5, 12);
    auto ret = solution(5, 133);
    auto ret0 = __solution2(5, 133);
    while (1) {
        int N = rand() % 9 + 1;
        int number = rand() % 32000 + 1;
        auto ret1 = __solution(N, number);
        auto ret2 = solution(N, number);
        if (ret1 != ret2) {
            cout << "ERROR" << endl;
        }
    }
    return 0;
}
