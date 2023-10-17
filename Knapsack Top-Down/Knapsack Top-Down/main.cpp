#include <iostream>

using namespace::std;

void printMatriz(int** matrix, int first, int second){
    int i, j;
    for (i = 0; i < first; i++) {
        for (j = 0; j < second; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

void setMatrix(int** matrix, int first, int second){
    int i, j;
    for (i = 0; i < first; i++) {
        for (j = 0; j < second; j++) {
            if (j == 0 || i == 0) {
                matrix[i][j] = 0;
            }
            else matrix[i][j] = -1;
        }
    }
}


int MFKnapsack(int i, int j, int* weight, int* values, int** matrix){
    int value;
    if (matrix[i][j] < 0) {
        if (j < weight[i]) {
            value = MFKnapsack(i-1, j, weight, values, matrix);
        }
        else value = max(MFKnapsack(i-1, j, weight, values, matrix), values[i] + MFKnapsack(i-1, j - weight[i], weight, values, matrix));
        matrix[i][j] = value;
    }
    return matrix[i][j];
}

int main(){
    int capacity, i, elements;
    cin >> elements;
    cin >> capacity;
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
    setMatrix(matrix, elements, capacity);
    MFKnapsack(elements-1, capacity-1, weight, values, matrix);
    printMatriz(matrix, elements, capacity);
}
