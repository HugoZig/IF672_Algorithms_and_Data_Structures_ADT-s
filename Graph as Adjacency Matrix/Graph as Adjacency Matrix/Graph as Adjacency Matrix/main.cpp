#include <iostream>
using namespace::std;

class Graph {
private:
    int** matrix;
    int numEdge;
    int* Mark;
    int side;
public:
    Graph(int n){
        side =  n;
        this->Mark = new int[n];
        this->matrix = new int*[n];
        for (int i = 0; i < n ; i++) {
            this->matrix[i] = new int[n];
            for (int j = 0; j < n; j++) {
                this->matrix[i][j] = 0;
            }
        }
        numEdge = 0;
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
    
    void setEdge(int i, int j, int wt){
        if (wt == 0) {
            cout << "Error at setEdge function";
            exit(1);
        }
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
    int side;
    int vertice, after, line, insert, option = 0;
    cout << "what will be the side of the matrix?\n";
    cin >> side;
    Graph graph(side);
    do {
        cout <<"WELCOME TO THE GRAPH AS ADJACENCY MATRIX\n"
        << "what would you like to do?" << endl
        <<"1.....Next\n"
        <<"2.....Set edge" << endl
        <<"3.....Print graph" << "\n"
        <<"4.....Delete Edge\n"
        <<"5.....First\n"
        <<"7.....Leave" << endl;
        cin >> option;
        switch (option) {
            case 1:
                cout << "what vertice and after what would you like to chose" << endl;
                cin >> vertice >> after;
                graph.next(vertice, after);
                break;
                
            case 2:
                cout << "where? (i,j) " << endl;
                cin >> vertice >> line;
                cout << "value: ";
                cin >> insert;
                graph.setEdge(vertice, line, insert);
                break;
                
            case 3:
                graph.print();
                break;
                
            case 4:
                cout << "where? (i, j)" << endl;
                cin >> vertice >> line;
                graph.delEdge(vertice, line);
                break;
                
            case 5:
                cout << "what vertice would you like to chose(<" << side << " && > 0" << endl;
                cin >> vertice;
                graph.first(vertice);
                break;
            default:
                cout << "please try again dumbass" << endl;
                break;
                
            case 7:
                option = -1;
                break;
        }
        
    } while (option != -1);
    
}
