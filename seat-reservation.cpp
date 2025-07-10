#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int ROW_NUMBERS = 13;
const int SEAT_NUMBERS = 6;

bool reserveSeat(string seat[ROW_NUMBERS][SEAT_NUMBERS], int row, int seatNum);
void printSeats(string seats[ROW_NUMBERS][SEAT_NUMBERS]);
void menu(string seats[ROW_NUMBERS][SEAT_NUMBERS]);

int main() {
    string seats[ROW_NUMBERS][SEAT_NUMBERS];
    
    // mark all seats as empty (*)
    for(int i = 0; i < ROW_NUMBERS; i++) {
        for(int j = 0; j < SEAT_NUMBERS; j++) {
            seats[i][j] = "*";
        }
    }

    // reserved seats, 1A, 1B, 2B, 2C, {3D, 3E, 3F}, 5A, 6A, 7A, row 13

    seats[0][0] = "X";
    seats[0][1] = "X";
    seats[1][1] = "X";
    seats[1][2] = "X";
    
    for(int i = 3; i < 6; i++) {
        seats[2][i] = "X";
    }

    seats[4][0] = "X";
    seats[5][0] = "X";
    seats[6][0] = "X";

    for(int i = 0; i < 6; i ++) {
        seats[12][i] = "X";
    }

    menu(seats);

    return 0;
}

// reserves seat as X
bool reserveSeat(string seat[ROW_NUMBERS][SEAT_NUMBERS], int row, int seatNum) {
    if(seat[row][seatNum] == "X") {
        return false;
    }

    return true;
}

// prints seating chart
void printSeats(string seats[ROW_NUMBERS][SEAT_NUMBERS]) {
    // column headings
    cout << setw(8) << " ";
    for (char col = 'A'; col < 'A' + SEAT_NUMBERS; col++) {
        cout << setw(4) << col;
    }
    cout << endl;

    // rows
    for (int i = 0; i < ROW_NUMBERS; i++) {
        cout << setw(8) << "Row " + to_string(i + 1);
        for (int j = 0; j < SEAT_NUMBERS; j++) {
            cout << setw(4) << seats[i][j];
        }
        cout << endl;
    }
}

void menu(string seats[ROW_NUMBERS][SEAT_NUMBERS]) {
    int row;
    int seat;

    do {
        cout << "\nThis program assigns seats for a commercial airplane. \nThe current seat assignments are as follows.\n" << endl;
        printSeats(seats);
        cout << "\n* -- available seat \nX -- occupied seat" << endl;
        cout << "Rows 1 and 2 are for first class passengers." << endl;
        cout << "Rows 3 through 7 are for business class passengers." << endl; 
        cout << "Rows 8 through 13 are for economy class passengers." << endl;

        char reserveChoice;
        cout << "To reserve a seat enter Y/y(Yes), N/n(No): ";
        cin >> reserveChoice;

        // lets user pick class
        if (tolower(reserveChoice) == 'y') {
            char classType;
            cout << "\nEnter ticket type: F/f (first class); B/b (business class); E/e (economy class): ";
            cin >> classType;
    
            int minRow = 0, maxRow = 0;
            switch (tolower(classType)) {
                case 'f':
                    minRow = 1; maxRow = 2;
                    break;
                case 'b':
                    minRow = 3; maxRow = 7;
                    break;
                case 'e':
                    minRow = 8; maxRow = 13;
                    break;
            }

            int row;
            cout << "\nEnter Row number " << minRow << " - " << maxRow << ": ";
            cin >> row;

            char c;
            cout << "\nEnter seat letter (A - F): ";
            cin >> c;

            // changes seat from letter to int
            int seat = 0;
            switch (toupper(c)) {
                case 'A': {
                    seat = 0;
                    break;
                }
                case 'B': {
                    seat = 1;
                    break;
                }
                case 'C': {
                    seat = 2;
                    break;
                }
                case 'D': {
                    seat = 3;
                    break;
                }
                case 'E': {
                    seat = 4;
                    break;
                }
                case 'F': {
                    seat = 5;
                    break;
                }
            } 

            row--;

            if(reserveSeat(seats, row, seat)) {
                seats[row][seat] = "X";
                printSeats(seats);
                menu(seats);
            }

            else {
                cout << "\n*#*#*# This seat is already occupied #*#*#*" << endl;
            }
        }
        
    } while (!reserveSeat(seats, row, seat));
}