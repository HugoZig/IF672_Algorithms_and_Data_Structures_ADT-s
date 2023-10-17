#include<iostream>
#include<set>
#include<list>
#include<algorithm>
#include <limits.h>
#include <queue>
#include <vector>

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

typedef struct node {
   int to;
   int length;
}node;

class Graph {
private:
    int* Mark;
    int* Distance;
    int* Previous;
    int side;
    list<node> *adjList;

public:
      Graph(int n) {
          side = n;
          Mark = new int[n];
          Distance = new int[n];
          Previous = new int[n];
         adjList = new list<node>[side];
          for (int i = 0; i < n ; i++) {
              Distance[i] = INT_MAX;
              Previous[i] = -1;
              Mark[i] = UNVISITED;
          }
      }

    
      void createEdge(int source, int to, int length) {
          node holder1, holder2;
          holder1.to = to;
          holder1.length = length;
          holder2.to = source;
          holder2.length = length;
          adjList[source].push_back(holder1);
          adjList[to].push_back(holder2);
      }

    void helpDijkstra(int s){
        int v, i;
        priority_queue<Tripla,vector<Tripla>, comparator> minHeap;
        Tripla heapIte; heapIte.cost = 0; heapIte.middleElement = s; heapIte.justBefore = s;
        minHeap.push(heapIte);
        Distance[s] = 0;
        for (i = 0; i < side; i++) {
            do {
                if (minHeap.empty()) {return;}
                heapIte = minHeap.top();
                minHeap.pop();
                v = heapIte.middleElement;
            } while (Mark[v] != UNVISITED);
            Mark[v] = VISITED;
            list<node> :: iterator ptr;

            for(ptr = adjList[v].begin(); ptr != adjList[v].end(); ptr++) {
                if (Mark[ptr->to] != VISITED && Distance[ptr->to] > Distance[v] + ptr->length) {
                    Distance[ptr->to] = Distance[v] + ptr->length;
                    Tripla toPush; toPush.justBefore = v; toPush.middleElement = ptr->to; toPush.cost = Distance[ptr->to];
                    minHeap.push(toPush);
                }
            }
        }
    }
    
    void dijkstra(int s, int t, int caso){
            helpDijkstra(s);
            printf("Case #%d: ", caso);
            if (Distance[t] == INT_MAX) {
                printf("unreachable");
            }
            else printf("%d", Distance[t]);
            printf("\n");
    }
};

int main (){
    int cases, counter = 0;
    scanf("%d", &cases);
    while (cases--) {
        counter++;
        int v, t, side, nEdges, i, from, to, val;
        scanf("%d %d %d %d", &side, &nEdges, &v, &t);
        Graph graf(side);
        for (i = 0; i < nEdges; i++) {
            scanf("%d %d %d", &from, &to, &val);
            graf.createEdge(from, to, val);
        }
        graf.dijkstra(v, t, counter);
    }

}
