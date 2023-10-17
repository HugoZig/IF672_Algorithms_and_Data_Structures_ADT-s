#include <iostream>
#include <queue>

using namespace::std;

typedef struct Mata{
    int banana[21][21];
} Mata;

class n_Queens{
private:
    int side;
    int** matrix;
    queue<Mata> kiwi;
bool valid(int r, int c){
    int i, j;
    for (i = 0; i < r; i++) {
        if (matrix[i][c]) {
            return false;
        }
    }
    
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (matrix[i][j]) {
            return false;
        }
    }
    
    for (i = r, j = c; j < side && i >= 0; i--, j++) {
        if (matrix[i][j]) {
            return false;
        }
    }
    return true;
}
    
    void print(){
        int i, j;
        for (i = 0; i < side; i++) {
            for (j = 0; j < side; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    
public:
n_Queens(int n){
    side = n;
    matrix = new int*[n];
    int i, j;
    for (i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

bool qns(int l){
    if (l == side) {
        Mata holder;
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++) {
                holder.banana[i][j] = matrix[i][j];
            }
        }
        kiwi.push(holder);
        return true;
    }
    else{
        bool yn = false;
        int i;
        for (i = 0; i < side; i++) {
            if (valid(l, i)) {
                matrix[l][i] = 1;
                yn = (qns(l+1) || yn);
                matrix[l][i] = 0;
            }
        }
        return yn;
    }
}
    void output(){
        int i = 1;
        cout << kiwi.size() << endl;
        while (!kiwi.empty()) {
            Mata holder = kiwi.front();
            cout << "Sol. " << i++ << ":" << endl;
            kiwi.pop();
            for (int j = 0; j < side; j++) {
                for (int k = 0; k < side; k++) {
                    cout << holder.banana[j][k] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
};

int main(){
    int n;
    cin >> n;
    n_Queens queen(n);
    if (!queen.qns(0)) {
        cout << "no solution" << endl;
    }
    else queen.output();
}
