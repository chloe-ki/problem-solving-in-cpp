
//Roman Number Implementation file

#include <iostream> 
#include <string>
#include "roman.h"
 
using namespace std;

// constructors
romanType::romanType() {
    setRoman("I");
}

romanType::romanType(string romanNumeral) {
    setRoman(romanNumeral);
}

romanType::romanType(int number) {
    setRoman(number);
}

// getters and setters
void romanType::setRoman(string romanNumeral) {
    romanNum = romanNumeral;
    romanToPositiveInteger();
}

void romanType::setRoman(int value) {
    num = value;
    intToRoman(value);
}

string romanType::getRoman() {
    return romanNum;
}

int romanType::getValue() {
    return num;
}

// converts roman numerals to int
void romanType::romanToPositiveInteger() {
    int romanLength = romanNum.length();

    string numerals[7][2] = {
        {"M", "1000"},
        {"D", "500"},
        {"C", "100"},
        {"L", "50"},
        {"X", "10"},
        {"V", "5"}, 
        {"I", "1"}
    };

    int previousValue = 0, value = 0, number = 0;

    // gets next character in string
    for (int i = 0; i < romanLength; i++) {
        char c = romanNum.at(i);
        string numeral(1, c);

        // compares char to array to get value
        for (int j = 0; j < 7; j++) {
            if (numeral == numerals[j][0]) {
                value = stoi(numerals[j][1]);
                break;
            }
        }

        // increments/decrements by value depending on order
        if (value > previousValue) {
            number += value - 2 * previousValue; // avoiding duplicates if numeral is more than one character e.g. IV
        } else {
            number += value;
        }

        previousValue = value;
    }

    num = number;
}

// converts int to roman numerals
string romanType::intToRoman(int value) {
    string romanNumeral = "";

    // parallel arrays to account for various grouping of roman numerals (e.g. IV instead of IIII)
    string roman[] = {
        "M", "CM", "D", "CD", "C", "XC",
        "L", "XL", "X", "IX", "V", "IV", "I"
    };

    int values[] = {
        1000, 900, 500, 400, 100, 90,
        50, 40, 10, 9, 5, 4, 1
    };

    for (int i = 0; i < 13; i++) {
        while (value >= values[i]) {
            romanNumeral += roman[i];
            value -= values[i];
        }
    }

    romanNum = romanNumeral;
    return romanNumeral;
}
    

// prints value of current romanType
void romanType::printPositiveInteger() const {
    cout << "Integer: " << num << endl;
}

// prints the current romanType
void romanType::printRoman() const {
    cout << "Roman numeral: " << romanNum << endl;
}

// increments the current romanType
void romanType::inc() {
    int value = getValue();

    value++;

    setRoman(value);
}

// decrements the current romanType
void romanType::dec() {
    int value = getValue();

    value--;

    setRoman(value);
}

// adds value of another romanType to current romanType
void romanType::add(romanType roman) {
    int value = getValue();
    value += roman.getValue();

    setRoman(value);
}

// adds value to current romanType
void romanType::add(int add) {
    int value = getValue();

    value += add;

    setRoman(value);
}


