#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

string uniqueChars(string);
void printResults(ifstream&);

int main() {
    // opens input file and creates output file;
    ifstream inFile;
    ifstream results;
    inFile.open("input.txt");
    ofstream outFile("output.txt");

    if (!inFile) {
		cout << "Cannot open input file!" << " Terminating program..." << endl;
		return 1; 
	}

    string inputString;

    // retrieves input string, runs uniqueChars function, prints to output file
    while(getline(inFile, inputString))
    {
        string outputString = uniqueChars(inputString);

        outFile << inputString << ", " << outputString <<endl;
    }

    // closes input.txt, opens output.txt and calls print method, closes output.txt
    inFile.close();
    
    results.open("output.txt");

    printResults(results);

    results.close();

    return 0;
}

// ensures all characters in string are unique, returns result as string
string uniqueChars(string in) {
    // iterates through each character in the string        
    for(int i = 0; i < in.length(); i++) {
        char character = in.at(i);
        // removes all spaces
        if(character == ' ') {
            in.erase(i, 1);
            i--;
        }
        // compares all characters in string and removes duplicates
        for(int j = i + 1; j < in.length(); j++) {
            char compare = in.at(j);
            if(character == compare) {
                in.erase(j,1);
                j--;
            }
        }

    }
    return in;
}

// displays results in formatted print
void printResults(ifstream& results) {
    string original, unique;

    // reads line up until comma
    while(getline(results, original, ',')) {
        // reads rest of line ignoring prior whitespace
        getline(results >> ws, unique);
        
        cout << left << setw(34) << setfill(' ') 
             << original << ":"
             << right << setw(20) << setfill('*')
             << unique << endl;    
    }
}