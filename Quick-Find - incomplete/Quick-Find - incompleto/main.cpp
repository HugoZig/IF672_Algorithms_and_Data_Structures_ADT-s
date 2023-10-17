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
    list<int> *sSet;
    int size;
    int* representative;

public:
    Subset(int n){
        int i;
        size = n;
        sSet = new list<int>[n+1];
        representative = new int[n+1];
        for (i = 0; i < n; i++) {
            representative[i] = i;
        }
    }
    
    int find(int curr){
        return representative[curr];
    }
    
    void yunion(int a, int b){
        int root1 = find(a), root2 = find(b);
        if (root1 != root2) {
            list<int> l1 = sSet[root1], l2 = sSet[root2];
            if (l1.size() < l2.size()) {swap(l1, l2);}
            list<int> :: iterator ptr;
            for (ptr = l2.begin(); ptr != l2.end(); ptr++) {
                representative[*ptr] = l1.front();
            }
            representative[*ptr] = l1.front();
            l1.splice(l1.end(), l2);
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
