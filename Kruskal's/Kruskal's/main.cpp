#include <iostream>
#include <set>
#include <list>
#include <queue>
#include <vector>

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
            representative = new int[n];
            for (i = 0; i < n; i++) {
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
                representative[root2] = root1;
        }
};


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

typedef struct node {
   int to;
   int length;
}node;

class Graph {
private:
    int side;
    set<int> heavyEdges;
    list<node> *adjList;
    priority_queue<Tripla,vector<Tripla>, comparator> minHeap;
public:
    
    Graph(int n) {
        side = n;
        adjList = new list<node>[side];
        heavyEdges.clear();
    }
    
     
    void createEdge(int from, int to, int length) {
        node holder1 = {to, length}, holder2 = {from, length};
        adjList[from].push_back(holder1);
        adjList[to].push_back(holder2);
        heavyEdges.insert(length);
      }

   void Kruskal(){
        int i;
        for (i = 0; i < side; i++) {
            list<node>::iterator ptr;
            for(ptr = adjList[i].begin(); ptr != adjList[i].end(); ptr++) {
                Tripla temp = {ptr->length, ptr->to, i};
                minHeap.push(temp);
            }
        }
        Subset ds(side);
        int numMST = side;
        while (numMST > 1 && !minHeap.empty()) {
            Tripla holder = minHeap.top();
            minHeap.pop();
            if (ds.find(holder.justBefore) != ds.find(holder.middleElement)) {
                ds.yunion(holder.justBefore, holder.middleElement);
                heavyEdges.erase(holder.cost);
                numMST--;
            }
        }
        if (heavyEdges.empty()) {
            //printf("forest");
            cout << "forest";
            return;
        }
        else{
            set<int>::iterator ptr;
            for (ptr = heavyEdges.begin(); ptr != heavyEdges.end(); ptr++) {
                //printf("%d ", *ptr);
                cout << *ptr;
                ptr++;
                if (ptr != heavyEdges.end()) {
                    cout << " ";
                }
                ptr--;
            }
        }
    }
};

int main (){
    int side, nEdges, i, from, to, val;
    do {
        cin >> side >> nEdges;
        //scanf("%d %d", &side, &edges);
        if (side == 0 && nEdges == 0) {
            continue;
        }
        Graph graf(side);
        for (i = 0; i < nEdges; i++) {
            cin >> from >> to >> val;
            //scanf("%d %d %d", &from, &to, &val);
            graf.createEdge(from, to, val);
        }
        graf.Kruskal();
        cout << endl;
        //printf("\n");
    } while (nEdges != 0 || side != 0);
    
}
