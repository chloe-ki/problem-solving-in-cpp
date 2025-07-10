//Roman Number Header file
//DO NOT MODIFY
   
#include <string> 
using namespace std;

class romanType
{
public:
    void setRoman(string);//Set the romaType to a new value as string(no error checking)
    void setRoman(int);//Set the romanType to a new value with integer
    void romanToPositiveInteger(); //convert the roman string to a number value
    void printPositiveInteger() const;
    void printRoman() const;
    string getRoman();//Return the roman value as a string
    int getValue();//return the roman value as a number
    void inc();//increment the roman variable
    void dec();//dec the roma variable
    void add(romanType);//add two romanType values
    void add(int);//Add new integr value to exisitng romanType
    //constructors
    romanType();
    romanType(string);
    romanType(int);

private:
    string intToRoman(int); //convert an integer value into roman string represetnation
    string romanNum;
    int num;
};