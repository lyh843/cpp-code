#include <iostream>

using namespace std;
// TODO: 补全此函数
int count(int m, int n) {
    // TODO
    if(n == 1 || m == 0)
    {
        return 1;
    }
    if(m < 0 || n < 1)
    {
        return 0;
    }
    return count(m, n - 1) + count(m - n, n);
}

int main() {
    int M, N;
    cin >> M >> N;
    cout << count(M, N);
    return 0;
}