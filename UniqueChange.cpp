#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, unsigned long long> table;

unsigned long long count( int s[], int m, int n)
{

    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    if (table[n] != -1)
        return table[n];

    unsigned long long sum = 0;
    for (int i = 0; i < m; i++)
        sum += count(s, m, n-s[i]);
    return table[n] = sum;
}

int main() {
    int num_coins, queries;
    cin >> num_coins;
    int coins[num_coins];
    for (int i = 0; i < num_coins; i++) {
        cin >> coins[i];
    }
    cin >> queries;
    while (queries--) {
        int change;
        cin >> change;

        for (int i = 0; i <= change; i++) {
            table[i] = -1;
        }
        cout << count(coins, num_coins, change) % 100000000 <<endl;
    }
    return 0;
}
