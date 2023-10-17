#include <iostream>
#include <algorithm>
#include <stack>

#define LIMIT 10

using namespace::std;

typedef struct ToStack{
    int l;
    int c;
    int index[LIMIT];
    int until;
} ToStack;


class SubSet{
private:
    int target;
    int length;
    int numbers[LIMIT];
    int min;
    int max;
    stack<ToStack> steak;
    
    void flipSign(){
        int i;
        target = -target;
        for (i = 0; i < length; i++) {
            numbers[i] = -numbers[i];
        }
    }
    
    bool DP(){
        bool matrix[length][target-min+1];
        int i, j;
        for (i = 0; i < length; i++) {
            for (j = 0; j < target-min+1; j++) {
                matrix[i][j] = 0;
            }
        }
        for (j = 0; j < target-min+1; j++) {
            matrix[0][j] = (numbers[0] == min + j);
        }
        for (i = 1; i < length; i++) {
            for (j = 0; j < target-min+1; j++) {
                matrix[i][j] = matrix[i-1][j] || (numbers[i] == (min+j));
                if (!matrix[i][j]) {
                    int holder = j - numbers[i];
                    if (holder >= 0 && holder < target-min+1) {
                        matrix[i][j] = matrix[i-1][holder];
                    }
                }
            }
        }
        return matrix[length-1][target-min];
    }
    
public:
    SubSet(int n, int obj){
        target = obj;
        length = n;
        min = max = 0;
    }
    
    void insert(int val, int pos){
        numbers[pos] = val;
    }
    
    bool SubSetSolve(){
        if (target < 0) {flipSign();}
        sort(numbers, numbers+length);
        int i;
        for (i = 0; numbers[i] < 0 && i < length; i++) {
            min += numbers[i];
        }
        if (min > target) {return false;}
        
        for (i = length-1; numbers[i] > 0 && i >= 0; i--) {
            max += numbers[i];
        }
        if (max < target) {return false;}
        return DP();
    }
    
    void getSolutions(){
    }
};


int main(){
    int n, target, val;
    cin >> n >> target;
    SubSet sett(n, target);
    for (target = 0; target < n; target++) {
        cin >> val;
        sett.insert(val, target);
    }
    if (sett.SubSetSolve()) {
        sett.getSolutions();
    }
    else cout << "threres no solution :(\n" << endl;
}
