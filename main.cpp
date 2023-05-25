/*
 * Name: Ekaterina (Katy) Kuznetsova
 * Date: May 25th, 2023
 * Assignment: 5031Homework6
 * C++ Version: C++17
 *
 * Program description:
 *
 *
 */

#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

void clientProgram(string &inputFileName, string &outputFileName);

void readFile(string &fName, vector<vector<int>> &matrixA);

void printMatrix(vector<vector<int>> &matrixA);

void translate(vector<vector<int>> &matrix, string &outputFileName);

bool isDirectional(vector<vector<int>> &matrix);

int main() {

    string inputFileName;
    string outputFileName;
    vector<vector<int>> matrixA;

    //client program gets name of file
    clientProgram(inputFileName, outputFileName);

    readFile(inputFileName, matrixA);

    printMatrix(matrixA);

    translate(matrixA, outputFileName);

}

void clientProgram(string &inputFileName, string &outputFileName){

    cout << "Please update the filename strings in the clientProgram method\n"
            "with the absolute path of txt file.\n";

    //getline(cin, inputFileName);

    inputFileName = "C:\\Users\\Ekerterina "
            "Kuznetsov\\CLionProjects\\5031Homework6\\matrixTest.txt";

    outputFileName = "C:\\Users\\Ekerterina "
            "Kuznetsov\\CLionProjects\\5031Homework6\\matrixTest1.dot";

}

void readFile(string &fName, vector<vector<int>> &matrixA){

    ifstream fin;
    string line;
    string indexContent;
    int row = 0;

    fin.open(fName);

    //if the file can open
    if (fin) {

        while (fin.peek() != '\n' && !fin.eof()) {

            //get a line of the file
            getline(fin, line);

            //create istringstream object copying the contents of line
            istringstream ss(line);

            //push a vector into a vector to make a row
            matrixA.push_back(vector<int>());

            //read sections of line string separated by spaces
            while (getline(ss, indexContent, ' ')) {

                int num = stoi(indexContent);
                matrixA[row].push_back(num);
            }
            //count rows
            row++;
        }
    }
}

void printMatrix(vector<vector<int>> &matrix){

    for (int i = 0; i < matrix.size(); i++){

        for (int j = 0; j < matrix[i].size(); j++) {

            cout << matrix[i].at(j) << " ";

        }

        cout << endl;

    }
}


/*
 * If there's a 1 at A-B and B-A, then that edge is 'nondirectional'
 * If there are any directional edges, then the graph is considered directional.
 */

void translate(vector<vector<int>> &matrixA, string &outputFileName){

    vector<vector<int>> matrix = matrixA;

    bool directionality = isDirectional(matrix);

    // open a file in write mode.
    ofstream outfile;
    outfile.open(outputFileName);

    //traverse each row
    for (int i = 0; i < matrix.size(); i++){
        //traverse each column
        for (int j = 0; j < matrix[i].size(); j++){

            //if a 1 is found
            if (matrix[i].at(j) == 1){

                    //print first character
                    outfile << char(i + 65) << " ";

                    if (directionality){

                        outfile << "-> ";

                    } else {

                        outfile << "-- ";
                        matrix[j].at(i) = 0;
                    }

                outfile << char(j + 65) << endl;
            }
        }
    }
}

bool isDirectional(vector<vector<int>> &matrix){

    bool directional = false;

    //traverse each row
    for (int i = 0; i < matrix.size(); i++){
        //traverse each column
        for (int j = 0; j < matrix[i].size(); j++){

            //if a 1 is found
            if (matrix[i].at(j) == 1){

                if (matrix[j].at(i) != 1) {

                    directional = true;

                }
            }
        }
    }

    return directional;

}