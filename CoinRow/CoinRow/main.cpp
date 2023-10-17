#include <iostream>

using namespace::std;


void backTrack(int* c, bool* arr, int n){
    if (n <= 0) {
        return;
    }
    if (arr[n]) {
        cout << c[n] << " ";
        backTrack(c, arr, n-2);
    }
    else backTrack(c, arr, n-1);
}


void coinRow(int* c, int n){
    bool* arr = new bool[n+1];
    int i, f[n+1];
    f[0] = 0;
    f[1] = c[1];
    arr[1] = true;
    for (i = 2; i <= n; i++) {
        arr[i] = false;
        f[i] = max(c[i] + f[i-2], f[i-1]);
        if ((c[i] + f[i-2]) > f[i-1]) {arr[i] = true;}
    }
    cout << f[n] << endl;
    backTrack(c, arr, n);
}

int main(){
    int cases, i, n, j;
    cin >> cases;
    for (i = 0; i < cases; i++) {
        cin >> n;
        int* coins = new int[n+1];
        for (j = 1; j <= n; j++) {
            cin >> coins[j];
        }
        coinRow(coins, n);
        cout << endl << endl;
    }
}

