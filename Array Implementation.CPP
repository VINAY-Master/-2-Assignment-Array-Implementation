#include <iostream>
#include <vector>

using namespace std;

// Define the structure for storing non-zero elements
struct Element {
    int row;
    int col;
    int value;
};

// Define the class for the sparse matrix
class SparseMatrix {
private:
    int rows, cols;
    vector<Element> elements;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void addElement(int r, int c, int val) {
        if (val != 0) {
            elements.push_back({r, c, val});
        }
    }

    void display() {
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (k < elements.size() && elements[k].row == i && elements[k].col == j) {
                    cout << elements[k].value << " ";
                    k++;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    SparseMatrix sm(4, 4);
    sm.addElement(0, 1, 3);
    sm.addElement(1, 2, 5);
    sm.addElement(3, 0, 7);

    cout << "Sparse Matrix (Array Implementation):" << endl;
    sm.display();

    return 0;
}
