#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

#define UNVISITED 0
#define VISITED 1

using namespace::std;

class Graph {
private:
    int** matrix;
    int numEdge;
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
        for (int i = 0; i <= numEdge; i++) {
            if (matrix[v][i] != 0) return i;
        }
        return numEdge;
    }
    
    int next(int v, int w){
        for (int i = w+1; i <= numEdge; i++) {
            if (matrix[v][i] != 0) return i;
        }
        return numEdge;
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
        int v, i, j;
        Distance[0] = 0;
        for (i = 0; i < side; i++) {
            v = getMinV(i);
            setMark(v, VISITED);
            for (j = 0; j < side; j++) {
                if (matrix[v][j] > 0) {
                    if (getMark(j) == UNVISITED && matrix[v][j] != INT_MAX && matrix[v][j] < Distance[j]) {
                        Distance[j] = matrix[v][j];
                    }
                }
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
                this->matrix[i][j] = 0;
            }
        }
        numEdge = 0;
    }
    
    
    void Prim(){
        int somador = 0, s;
        helpPrim();
        for (s = 0; s < side; s++) {
            somador += Distance[s];
        }
        cout << somador << endl;
    }

    
    void setEdge(int i, int j, int wt){
        if (matrix[i][j] == 0) {
            numEdge++;
        }
        matrix[i][j] = wt;
        matrix[j][i] = wt;
    }
    
    void delEdge(int i, int j){
        if (matrix[i][j] != 0) {
            numEdge--;
        }
        matrix[i][j] = 0;
        matrix[j][i] = 0;
    }
    
    void print() {
        for (int i = 0; i < side; i++) {
          cout << i << " : ";
          for (int j = 0; j < side; j++)
            cout << matrix[i][j] << " ";
          cout << "\n";
        }
      }
};

int main (){
    int side, nEdges, i, from, to, val;
    cin >> side >> nEdges;

    Graph graf(side);
    for (i = 0; i < nEdges; i++) {
        cin >> from >> to >> val;
        graf.setEdge(from, to, val);
    }
    graf.Prim();
}
