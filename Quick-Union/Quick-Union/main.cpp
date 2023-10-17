#include <iostream>
#include <set>
#include <list>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <vector>
#include <list>

#define UNVISITED 0
#define VISITED 1




using namespace::std;

class Subset {
private:
    int rank;
    int size;
    int* representative;
    int* parent;
public:
    Subset(int n){
        int i;
        size = n;
        representative = new int[n+1];
        for (i = 1; i <= n; i++) {
            representative[i] = -1;
        }
    }
    
    int find(int curr){
        if (representative[curr] == -1) {return curr;}
        representative[curr] = find(representative[curr]);
        return representative[curr];
    }
    
    void yunion(int a, int b){
        int root1 = find(a), root2 = find(b);
        if (root1 != root2) {
            representative[root2] = root1;
        }
    }

};


int main(){
    Subset sub(6);
    sub.yunion(1, 4); sub.yunion(4, 5); sub.yunion(1, 2); sub.yunion(3, 6);
    if (sub.find(1) == sub.find(5)) {
        cout << "true\n";
    }
    else cout << "false\n";
}
