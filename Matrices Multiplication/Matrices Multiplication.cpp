#include <iostream>
#include <vector>

using namespace std;

int randomNumber(int limit) {
    srand((unsigned int)time(NULL));
    int random = rand() % (limit);

    return random;
}

vector< vector<int> > fillMatrix(int row, int column) {
    vector<int> currentVector;
    vector< vector<int> > finalVector;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            currentVector.push_back(randomNumber(10));
        }
        finalVector.push_back(currentVector);
        currentVector.clear();
    }

    return finalVector;
}

vector< vector<int> > multiplyMatrices(vector< vector<int> > m1, vector< vector<int> > m2) {
    int result = 0;
    vector <int> currentVector;
    vector< vector<int> > finalVector;
    
    for (unsigned int i = 0; i < m1.size(); i++) {
        for (unsigned int j = 0; j < m2[0].size(); j++) {
            for (unsigned int k = 0; k < m1.size(); k++) {
                result += m1[i][k] * m2[k][j];
            }
            currentVector.push_back(result);
            result = 0;
        }
        finalVector.push_back(currentVector);
        currentVector.clear();
    }

    return finalVector;
}

void showMatrices(vector< vector<int> > m1, vector< vector<int> > m2, vector< vector<int> > mr) {

    cout << "First matrix" << endl << endl;

    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m1[0].size(); j++) {
            cout << m1[i][j] << "   ";
        }
        cout << endl;
    }

    cout << endl << "Second matrix" << endl << endl;

    for (int i = 0; i < m2.size(); i++) {
        for (int j = 0; j < m2[0].size(); j++) {
            cout << m2[i][j] << "   ";
        }
        cout << endl;
    }

    cout << endl << "Resulting Matrix" << endl << endl;

    for (int i = 0; i < mr.size(); i++) {
        for (int j = 0; j < mr[0].size(); j++) {
            cout << mr[i][j] << "   ";
        }
        cout << endl;
    }
}

int main() {
    int row, column = 0;
    int targetColumn, TargetRow = 0;
    vector< vector<int> > m1;
    vector< vector<int> > m2;
    vector< vector<int> > mr;



    cout << "Please enter the size of the first matrix (Separate the rows and columns with a space): ";
    cin >> row >> column;
    
    m1 = fillMatrix(row, column);
    targetColumn = column;

    cout << "Please enter the size of the second matrix (Separate the rows and columns with a space): ";
    cin >> row >> column;
    TargetRow = row;

    m2 = fillMatrix(row, column);

    if (targetColumn == TargetRow) {
        mr = multiplyMatrices(m1, m2);
        showMatrices(m1, m2, mr);
    }
    else {
        cout << "The matrices cannot be multiplied!";
    }

    return 0;
}