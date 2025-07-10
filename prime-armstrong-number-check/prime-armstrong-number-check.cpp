#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool isPrime(int);
bool isArmstrong(int);

int main() {
    int primeNumbers, armstrongNumbers;
    int both = 0;

    cout << "+----------+----------+----------+" << endl;
    cout << left << setw(11) << "|Number"
         << left << setw(11) << "|Prime"
         << left << setw(11) << "|Armstrong" << "|" << endl;
    cout << "+----------+----------+----------+" << endl;

    // loops through each number, checks prime or armstrong by calling relevant functions, prints formatted table
    for(int i = 100; i <= 500; i++) {
        if(isPrime(i)) {
            cout << "|" << right << setw(10) << i
                 << "|" << left << setw(5) << " " << setw(5) << 'X'
                 << "|" << right << setw(11) << "|" << endl;
            cout << "+----------+----------+----------+" << endl;
            primeNumbers++;
        }
        else if(isArmstrong(i)) {
            cout << "|" << right << setw(10) << i
                 << "|" << right << setw(11) << "|"
                 << left << setw(5) << " " << setw(5) << 'X' << "|" << endl;;
            cout << "+----------+----------+----------+" << endl;
            armstrongNumbers++;
        }
        else if(isArmstrong(i) && isPrime(i)) {
            cout << "|" << right << setw(10) << i
                 << "|" << left << setw(4) << " " << setw(5) << 'X' << "|"
                 << left << setw(5) << " " << setw(5) << 'X' << "|" << endl;
            cout << "+----------+----------+----------+" << endl;
            both++;
        }
        else {
            cout << "|" << right << setw(10) << i 
                 << left << setw(11) << "|"
                 << left << setw(11) << "|" << "|" << endl;
            cout << "+----------+----------+----------+" << endl;
        }
    }
    cout << "\nBetween 100 and 500 range a total of " << primeNumbers << " prime numbers were found." << endl;
    cout << "Between 100 and 500 range a total of " << armstrongNumbers << " Armstrong numbers were found." << endl;
    cout << "Between 100 and 500 range a total of " << both << " numbers were found that meet both prime number and Armstrong number conditions." << endl;
    
    return 0;
}

bool isPrime(int value) {
    // check divisibility up to half of the original value, returns false if divisible
    for (int i = 2; i <= value/2; i++) {
        if (value % i == 0) {
          return false;
        }
    }    
    return true;
}


bool isArmstrong(int value) {
    int compare = 0;
    int original = value;

    // loops through each digit in original, cubes, and adds together
    for(int i = 0; i < 3; i++) {
        int digit = value % 10;
        compare = compare + pow(digit, 3);
        value = value / 10;
    }

    // checks the added sum to the orignal, returns true if they're the same
    if(compare == original) {
        return true;
    }

    return false;
}