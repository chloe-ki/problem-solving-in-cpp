//Main program
  
#include <iostream>
#include <string>
#include <iomanip>
#include "romanimp.cpp" 

using namespace std; 

//Top level functions prototype to be implemented
romanType add(romanType, romanType);
romanType add(romanType, int);
void printTimesTable(romanType, romanType);

int main()
{

    //test the constructors
    romanType roman1;  //default constructor
    romanType roman2 = romanType("XXIV"); //String Constructor
    romanType roman3 = romanType(33); //Integer Constructor

    //test the results from the constructors
    cout << endl << "Print the roman representation of the values" << endl;
    roman1.printRoman();
    cout << endl;
    roman2.printRoman();
    cout << endl;
    roman3.printRoman();
    cout << endl;
    
    //Add the rest of the tests to get the outputs as in the example output
    
    //Test the no parameter constructor
    cout << "Defualt romanType constructor with no parameter" << endl;
    cout << "Default romanType variable as Roman = " << roman1.getRoman() << endl;
    cout << "Default romanType variable as number = " << roman1.getValue() << endl;

    //Test change the romanType value and representation
    cout << "\nSetting the default romanType value to 44" << endl;
    roman1.setRoman(44);
    cout << "Default romanType variable as Roman = " << roman1.getRoman() << endl;
    cout << "Default romanType variable as number = " << roman1.getValue() << endl;
    
    //Check the string constructor for romanType
    cout << "\nGet roman and value from the string constructor" << endl;
    cout << "String constructor romanType variable as Roman = " << roman2.getRoman() << endl;
    cout << "String constructor romanType variable as number = " << roman2.getValue() << endl;
    
    //Check the value constructor for romanType
    cout << "\nGet roman and value from the integer constructor" << endl;
    cout << "Number constructor romanType variable as Roman = " << roman3.getRoman() << endl;
    cout << "Number constructor romanType variable as number = " << roman3.getValue() << endl;    

    //Check the increment and decrement operations
    cout << "\nIncrement and Decrement on romanTypes" << endl;
    cout << "Increment class method on a romanType before " << roman3.getRoman();
    roman3.inc();
    cout << " After call to class method inc " << roman3.getRoman();

    cout << "\nDecrement class method on a romanType before " << roman3.getRoman();
    roman3.dec();
    cout << " After call to class method dec " << roman3.getRoman() << endl;
                        
    //use the top level add function to add two romanTypes
    romanType roman4 = add(roman2, roman3);
    cout << "\nAdd two romanType using top level function " << roman2.getRoman() << " plus " << roman3.getRoman() << " = " << roman4.getRoman() << endl;
                            
    //use the overloaded add methods using an integer and a romanType as param
    cout << "\nAdd using overloaded function method on romanTyes and integer" << endl;
    romanType roman5 = add(roman2, 12);
    cout << "Add two romanType using top level function " << roman2.getRoman() << " plus 12 = " << roman5.getRoman() << endl;
    
    //check the class method for the add function with romanType
    cout << "\nUsing class method for addition of romanTypes " << roman2.getRoman() << " plus " << roman3.getRoman();
    roman2.add(roman3);

    cout << " Result = " << roman2.getRoman() << endl;

    //check add integer class method to a romanType
    cout << "\nUsing overloaded class method for addition of romanType and integer "<< roman2.getRoman() << " plus 12";
    roman2.add(12);

    cout << " Result = " << roman2.getRoman() << endl; 

    //check the times table using romanTypes
    romanType roman6 = romanType(6);
    romanType roman7 = romanType(12);
    cout << "\nRoman Times Table base " << roman6.getValue() << " " << roman7.getValue() << " times" << endl;
   

    printTimesTable(roman6, roman7);

    return 0;
}

// adds value of two romanTypes and returns romanType of new value
romanType add(romanType roman1, romanType roman2) {
    int value = roman1.getValue() + roman2.getValue();

    romanType roman3 = romanType(value);

    return roman3;
}

// adds int to romanType and returns romanType of new value
romanType add(romanType roman, int number) {
    int value = roman.getValue() + number;

    romanType roman2 = romanType(value);

    return roman2;
}

// mulitplies two romanTypes
void printTimesTable(romanType roman1, romanType roman2) {
    for (int i = 1; i <= roman2.getValue(); ++i) {
        romanType multiplier(i);
        romanType product(roman1.getValue() * i);

        cout << setw(5) << multiplier.getRoman()
             << "  *  " << setw(2) << roman1.getRoman()
             << "  =  " << setw(10) << product.getRoman() << endl;
    }
}
