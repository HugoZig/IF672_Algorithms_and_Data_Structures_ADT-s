#include <iostream>

using namespace::std;


int knapsack(int qnt, int capacity, int* weight, int* values, int** matrix){
    int i, j;
    for (i = 0; i <= qnt; i++) {
        for (j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {matrix[i][j] = 0;}
            else if (weight[i] <= j){matrix[i][j] = max(matrix[i-1][j], values[i] + matrix[i-1][j-weight[i]]);}
            else matrix[i][j] = matrix[i-1][j];
        }
    }
    return matrix[qnt][capacity];
}

int main(){
    int capacity, i, elements, val;
    cout << "How many objects can fit the knapsack?" << endl;
    cin >> capacity;
    cout << "How many items do you have?" << endl;
    cin >> elements;
    elements++;
    capacity++;
    int** matrix;
    int* values, *weight;
    values = new int[elements];
    weight = new int[elements];
    matrix = new int*[elements];
    matrix[0] = new int[capacity];
    for (i = 1; i < elements; i++) {
        matrix[i] = new int[capacity];
        cin >> weight[i] >> values[i];
    }
    val = knapsack(elements-1, capacity-1, weight, values, matrix);
    cout << val << endl;
}
