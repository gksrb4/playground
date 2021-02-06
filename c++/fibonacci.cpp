#include <iostream>
#include <string>
#include <vector>

using namespace std;

int d[100];

int fibonacci(int n)
{
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 1;
    }
    if (d[n] != 0) return d[n];
    int n_1 = fibonacci(n-1);
    int n_2 = fibonacci(n-2);
    d[n] = n_1 + n_2;
    return d[n];
}


int main()
{
    cout << "TEST DEBUG " << __FILE__ << endl;


    int ret = fibonacci(10);

    return 0;
}
