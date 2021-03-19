#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


static int m_depth;


bool is_possible(string a, string b)
{
    int diff = 0;

    for (int i=0;i<a.size();i++) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) {
                return false;
            }
        }
    }
    return true;
}

void dfs(int depth, string begin, vector<string> words, string target)
{
    if (begin == target) {
        if (!m_depth) {
            m_depth = depth;
        } else {
            m_depth = min(m_depth, depth);
        }
        return;
    }
    bool possible = false;

    for (int i=0;i<words.size();i++) {
        auto& w = words[i];
        if (is_possible(begin, w)) {
            vector<string> _words;
            _words.resize(words.size());
            copy(words.begin(), words.end(), _words.begin());
            _words.erase(_words.begin()+i);
            dfs(depth+1, w, _words, target);
            possible = true;
        }
    }

    if (!possible) {
        return;
    }
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    dfs(0, begin, words, target);
    answer = m_depth;
    return answer;
}


int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;
    int ret = solution(
        "hit",
        "cog",
        {"hot", "dot", "dog", "lot", "log", "cog"}
    );
    return 0;
}
