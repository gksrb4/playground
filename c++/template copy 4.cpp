#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;
    vector<int> test(26, 0);
    string s = "abASDansfjkANSasfJASDas";
    int h = 0;
    for (int i=0;i<s.size();i++) {
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z')
    }
    
    return 0;
}
