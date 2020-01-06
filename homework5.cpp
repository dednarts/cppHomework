#include <iostream> 
#include <iomanip>
#include <string>
using namespace std;

//function prototypes/declarations
void welcome(); // welcome message
void getRaceTimes(string &,double &); // take user input for racers
void findWinner(string &,string &,string &,double &, double &,double &); //compare times for racers, tie = 2 wins, all tie = no winner
double raceAverage(double &,double &,double &); //return average for the racers time

int main(void){
    string RacerName1, RacerName2, RacerName3; // variables declared
    double RacerTime1 = 0, RacerTime2 = 0, RacerTime3 = 0;
    double averageTime;

    welcome();

    getRaceTimes(RacerName1,RacerTime1);
    getRaceTimes(RacerName2,RacerTime2);
    getRaceTimes(RacerName3,RacerTime3);

    findWinner(RacerName1, RacerName2, RacerName3, RacerTime1, RacerTime2, RacerTime3);
    averageTime = raceAverage(RacerTime1, RacerTime2, RacerTime3); //stores the returned value in here

    cout << "\nOverall Race Time Average:  " << averageTime << endl; // a variable for average time isnt really necessary since this is its only use 
    
    return 0;
}

void welcome(){ //purpose is to display welcome message
    cout << "*****************************************************************" << endl; //setting value at start of the program, i didnt see anything over 4 im just doing this to be safe
    cout << "Welcome to Race Results Program" << endl;
    cout << "You Asked to Enter the Three Racer's Names" << endl;
    cout << "and Their Associated Race Time.\n" << endl;
    cout << "Please enter a real number for Race Time <the Race Time Must be > 0).\n" << endl;
    cout << "Program Developed by: Nicholas Pellitteri" << endl;
    cout << "*****************************************************************";
}

void getRaceTimes(string &RacerName, double &RacerTime){ // function is taking input as desired
    cout << "\nPlease enter the racer's first name > ";
    cin >> RacerName;
    cout << "\nPlease enter the racer's time > ";
    cin >> RacerTime;
    while (RacerTime < 1){ //input validation
        cout << "Invalid time input...time must be greater than 0\nPlease enter the racer's time > ";
        cin >> RacerTime;
    }
}

void findWinner(string &RacerName1,string &RacerName2,string &RacerName3,double &RacerTime1,double &RacerTime2,double &RacerTime3){ 
    if (RacerTime1 == RacerTime2 && RacerTime2 == RacerTime3){ // triple tie checks first because the rest of this function wont work properly if theyre all the same
        cout << "\nWe have a 3 way TIE!!! No winner for this Race..." << endl;
        return;
    }

    if (RacerTime1 <= RacerTime2 && RacerTime1 <= RacerTime3){ //i feel like there is a much simpler way of doing this
        if (RacerTime1 == RacerTime2 || RacerTime1 == RacerTime3){ //case1
            cout << "\nWe have a TIE ";
                if( RacerTime1 == RacerTime2){
                    cout << RacerName1 << " and " << RacerName2 << " win!!" << endl;
                    cout <<"***** Your winning time is: " << RacerTime1 << " *****" << endl;
                }            
                if( RacerTime1 == RacerTime3){
                    cout << RacerName1 << " and " << RacerName3 << " win!!" << endl;
                    cout <<"***** Your winning time is: " << RacerTime1 << " *****" << endl;
                }
            } else {
                cout << "\nCongratulations " << RacerName1 << "!!! You are the winner!!" << endl;
                cout <<"***** Your winning time is: " << RacerTime1 << " *****" << endl;
            }
    } else if (RacerTime2 <= RacerTime1 && RacerTime2 <= RacerTime3){ //case2
        if (RacerTime2 == RacerTime1 || RacerTime2 == RacerTime3){
            cout << "\nWe have a TIE ";
                if (RacerTime2 == RacerTime1){
                    cout << RacerName2 << " and " << RacerName1 << " win!!" << endl;
                    cout <<"***** Your winning time is: " << RacerTime2 << " *****" << endl;
                }
                if (RacerTime2 == RacerTime3){
                    cout << RacerName2 << " and " << RacerName3 << " win!!" << endl;
                    cout <<"***** Your winning time is: " << RacerTime2 << " *****" << endl;
                }
            } else {
                cout << "\nCongratulations " << RacerName2 << "!!! You are the winner!!" << endl;
                cout <<"***** Your winning time is: " << RacerTime2 << " *****" << endl;
            }
    } else if (RacerTime3 <= RacerTime2 && RacerTime3 <= RacerTime1){ //case3
        if (RacerTime3 == RacerTime2 || RacerTime3 == RacerTime1){
            cout << "\nWe have a TIE ";
                if (RacerTime3 == RacerTime1){
                    cout << RacerName3 << " and " << RacerName1 << " win!!" << endl;
                    cout <<"***** Your winning time is: " << RacerTime3 << " *****" << endl;
                }
                if (RacerTime3 == RacerTime2){
                    cout << RacerName3 << " and " << RacerName2 << " win!!" << endl;
                    cout <<"***** Your winning time is: " << RacerTime3 << " *****" << endl;
                }
            }else{
                cout << "\nCongratulations " << RacerName3 << "!!! You are the winner!!" << endl;
                cout <<"***** Your winning time is: " << RacerTime3 << " *****" << endl;
            }
    }

}

double raceAverage(double &RacerTime1, double &RacerTime2, double &RacerTime3){
    double average;
    average = (RacerTime1 + RacerTime2 + RacerTime3 ) / 3;
    return average;
}