#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <set>

#define UNVISITED 0
#define VISITED 1

using namespace::std;

typedef struct Tripla{
    int cost;
    int middleElement;
    int justBefore;
} Tripla;


struct comparator{
    bool operator()(Tripla a, Tripla b){
        return a.cost > b.cost;
    }
};

class Graph {
private:
    set<int> heavyEdges;
    int** matrix;
    int* Mark;
    int* Distance;
    int* Previous;
    int side;
    
    void setMark(int v, int val){
        Mark[v] = val;
    }

    int getMark(int v){
        return Mark[v];
    }
    
    int first(int v){
        for (int i = 0; i <= side; i++) {
            if (matrix[v][i] != -1) return i;
        }
        return side;
    }
    
    int next(int v, int w){
        for (int i = w+1; i <= side; i++) {
            if (matrix[v][i] != -1) return i;
        }
        return side;
    }
    
    int getMinV(int s){
        int min = INT_MAX, i, holder = -1;
        for (i = 0; i < side; i++) {
            if (getMark(i) == UNVISITED && Distance[i]< min) {
                min = Distance[i];
                holder = i;
            }
        }
        return holder;
    }
    
    void helpPrim(){
        int v, i;
        priority_queue<Tripla,vector<Tripla>, comparator> minHeap;
        Tripla heapIte; heapIte.cost = 0; heapIte.middleElement = 0; heapIte.justBefore = 0;
        minHeap.push(heapIte);
        Distance[0] = 0;
        for (i = 0; i < side; i++) {
            do {
                if (minHeap.empty()) {return;}
                heapIte = minHeap.top();
                minHeap.pop();
                v = heapIte.middleElement;
            } while (getMark(v) != UNVISITED);
            setMark(v, VISITED);
            Previous[v] = heapIte.justBefore;
            int w = first(v);
            while (w < side) {
                if (getMark(w) != VISITED && Distance[w] > matrix[v][w]) {
                    Distance[w] = matrix[v][w];
                    Tripla toPush; toPush.justBefore = v; toPush.middleElement = w; toPush.cost = Distance[w];
                    minHeap.push(toPush);
                }
                w = next(v, w);
            }
        }
    }
    
public:
    Graph(int n){
        side =  n;
        this->Mark = new int[n];
        this->Distance = new int[n];
        this->Previous = new int[n];
        this->matrix = new int*[n];
        for (int i = 0; i < n ; i++) {
            this->Distance[i] = INT_MAX;
            this->Previous[i] = -1;
            this->Mark[i] = UNVISITED;
            this->matrix[i] = new int[n];
            for (int j = 0; j < n; j++) {
                this->matrix[i][j] = -1;
            }
        }
    }
    
    
    void Prim(){
        int s;
        helpPrim();
        for (s = 0; s < side; s++) {
            if (Previous[s] == -1) {
                cout << "forest\n";
                return;
            }
            // cout << Previous[s];
            heavyEdges.erase(matrix[Previous[s]][s]);
        }
        if (heavyEdges.empty()) {
            cout << "forest\n";
            return;
        }
        set<int>::iterator ptr;
        for (ptr = heavyEdges.begin(); ptr != heavyEdges.end(); ptr++) {
            cout << *ptr;
            ptr++;
            if (ptr != heavyEdges.end()) {
                cout << " ";
            }
            ptr--;
        }
        cout << endl;
    }

    
    void setEdge(int i, int j, int wt){
        matrix[i][j] = wt;
        matrix[j][i] = wt;
        heavyEdges.insert(wt);
    }
};
    
    
int main (){
    int side, nEdges, i, from, to, val;
    do {
        cin >> side >> nEdges;
        if (side == 0 && nEdges == 0) {
            continue;
        }
        Graph graf(side);
        for (i = 0; i < nEdges; i++) {
            cin >> from >> to >> val;
            graf.setEdge(from, to, val);
        }
        graf.Prim();
    } while (nEdges != 0 || side != 0);
    
}
