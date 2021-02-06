#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cstdlib>
// #include <format.h>

using namespace std;


int get_secs(string time)
{
    int h,m,s;
    sscanf(time.c_str(), "%02d:%02d:%02d", &h, &m, &s);
    return h*3600 + m*60 + s;
}

string get_time(int start_timestamp, int delta)
{
    char buffer[11] = {0};
    int timestamp = start_timestamp + delta;
    int h,m,s;
    h = timestamp/3600;
    m = (timestamp%3600)/60;
    s = (timestamp%3600)%60;
    sprintf(buffer, "%02d:%02d:%02d", h, m, s);
    return string(buffer);
}


int main()
{
    string time = "10:11:03 2300";
    string sub1 = time.substr(0, 9);
    string sub2 = time.substr(9);
    int test = get_secs(time);
    string test2 = get_time(test, 70);
    cout << "TEST DEBUG " << __FILE__ << endl;
    return 0;
}
