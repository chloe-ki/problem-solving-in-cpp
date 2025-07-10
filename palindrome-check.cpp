#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream numFile;
// using long long instead of int because .txt numbers exceed int limit
long long number;
int palindromic, nonPalindromic;

bool isPalindrome(long long num);

// reads numbers from file and checks if palindrome by calling isPalindrome function
main() {
    numFile.open("numbers.txt");
    // closes program if file numbers.txt can't be found
	if (!numFile) {
		cout << "Cannot open input file!" << " Terminating program..." << endl;
		return 1; 
	}

    // iterates and checks
    while(numFile >> number) {
        if(isPalindrome(number) == true) {
            cout << "Number: " << number << " is a palindromic number." << endl;
            palindromic++;
        }
        else {
            cout << "Number: " << number << " is not a palindromic number." << endl;
            nonPalindromic++;
        }
    }

    cout << "\nA total of " << palindromic << " palindromic numbers were found." << endl;
    cout << "A total of " << nonPalindromic << " non palindromic numbers were found." << endl;

    numFile.close();

    return 0;
}

// reverses int using division and modulo results and compares reversedInt to originalInt
bool isPalindrome(long long num){
    long long numReversed = 0;
    long long number = num;
    while(num > 0) {
        numReversed = numReversed * 10 + num % 10;
        num = num / 10;
    }

   if(number == numReversed) {
    return true;
   }
   else {
    return false;
   }
}