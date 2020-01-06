#include <iostream> 
#include <iomanip>
#include <string>
using namespace std;


void displayTable(int table[10][3]); //function will be used to show 10 x 3 mult table use setw(3) to display
void createTables( int ansTable[10][3],int testTable[10][3], int usersChoice); //creates table based off user input
void testMe(int table[10][3]); //display each quesiton randomly until test is over
void gradeMe(int testTable[10][3], int ansTable[10][3]); //user after test me
void displayMenu(); //displays the menu


int main(void){
    int user_input, users_choice, completed_test;
    int answer_table[10][3], test_table[10][3]; // assuming test table holds NULL value, answer table is the same as my table
    

    cout << "What times table would you like to review?\nPlease enter a value from 1 to 12 > ";
    cin >> users_choice;
        while (users_choice < 1 || users_choice > 12){ //input validation
            cout << "Invalid Menu input. Please a valid number from 1 to 12 > ";
            cin >> users_choice;
        }
    createTables(answer_table, test_table, users_choice);

    do{
        displayMenu();
        cin >> user_input;
        while (user_input < 1 || user_input > 4){ //input validation
            cout << "Invalid Menu input. Please a valid number > ";
            cin >> user_input;
        }
        switch(user_input){
            case 1:
                displayTable(answer_table);
                break;
            case 2:               
                testMe(test_table);
                gradeMe(test_table, answer_table);
                break;
            case 3:
                    cout << "Please enter a value from 1 to 12 > ";
                    cin >> users_choice;
                        while (users_choice < 1 || users_choice > 12){ //input validation
                            cout << "Invalid Menu input. Please a valid number from 1 to 12 > ";
                            cin >> users_choice;
                        }
                    createTables(answer_table, test_table, users_choice);
                break;
        }

    }while(user_input != 4);

    return 0;
}

void gradeMe(int testTable[10][3], int ansTable[10][3]){
    int total_score = 0;
    for(int i = 0;i < 10;i++){
        if(testTable[i][2] == ansTable[i][2]){
            total_score += 10;
        }
    }
    if(total_score == 100){
        cout << "You did an excellent job!! PERFECT SCORE!!" << endl;
        return;
    }else if(total_score >= 70){
        cout << " You did a good job! ";
    } else if(total_score <= 60){
        cout << "I'm sorry you did not pass the exam...";
    }
        cout << "Your score was " << total_score << "%" << endl;
}

void testMe(int table[10][3]){
    for(int i=0;i<10;i++){
        cout << "what is " << table[i][0] << " x " << table[i][1] << " = ";
        cin >> table[i][2];
                while (table[i][2] < 1){ //input validation for test answers
                    cout << "Invalid Menu input. Please a valid greater than 0 > ";
                    cin >> table[i][2];
                }
        cout << endl;
    }
}

void displayTable(int table[10][3]){
    for(int i=0;i<10;i++){
        cout << setw(3) << table[i][0] << "  x ";
        cout << setw(3) << table[i][1] << "  = ";
        cout << setw(3) << table[i][2] << endl;
    }
}

void createTables( int ansTable[10][3],int testTable[10][3], int usersChoice){
    for(int i=0;i<10;i++){
        ansTable[i][0] = i + 1; //setting first column to 1-10
        testTable[i][0] = i + 1;
        ansTable[i][1] = usersChoice; // setting the second column to be the users choice
        testTable[i][1] = usersChoice;
        ansTable[i][2] = (i + 1) * usersChoice; //obviously this table is going to hold our answers
        testTable[i][2] = -1; // we set this to null(which is -1) to hold answers for later and obviously to reset it if used already
    }

}

void displayMenu(){
    cout << "\n*****************************************************************" << endl;
    cout << "\t\t\tMultiplication Tables" << endl;
    cout << "\t  Program Developed by: Nicholas Pellitteri" << endl;
    cout << "\n\t1.\tReview MyTable\n\t2.\tTest Me\n\t3.\tEnter a New Multiplcation Table (1-12)\n\t4.\tQuit" << endl;
    cout << "\tEnter a Menu item > " << endl;
}
