// Nicholas Pellitteri, 12/03/19
// Class: COP2000-20201-1V-M-002, Fall 2019
// Purpose: to create a program that checks the given inventory of the given toys
#include <iostream> 
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

bool readFile(string inventory[10][3], int inventory2[10][2]); // true is 1 false is 0
void showMenu(string inventory[10][3]); //printing out the toys
void sortInput(string inventory[10][3], int inventory2[10][2]); //where the sort algorithm needs to go use bubble
void ckInventory(string inventory[10][3], int inventory2[10][2],int toyType); //toytype is menu input for check inven
void welcome(); // menu stuff
void menu();

int main(void){
    int menuInput, inventory2[10][2]; //sort by ascii value of typecasting
    string inventory[10][3], toyInput; //1 is plastic 2 is stuffed


    if (!readFile(inventory,inventory2)){
        cout << "Error file not able to be read. The program will now close.";
        return 0;
    }

    sortInput(inventory,inventory2);

    do{
        welcome();
        showMenu(inventory);
        menu(); 
        
        cin >> menuInput; 
        while(menuInput > 3 || menuInput < 1){
            cout << "\nPlease enter your menu item again, not a valid option...\n> ";
            cin >> menuInput;
        }
        switch(menuInput){
            case 1:
                ckInventory(inventory,inventory2,menuInput);
                break;
            case 2:                
                ckInventory(inventory,inventory2,menuInput);
                break;
        }

    } while(menuInput != 3);

    return 0;
}

void sortInput(string inventory[10][3], int inventory2[10][2]){
    string tempString;
    int tempInv[10][3],maxElement,index;
    ofstream newinventory("newinventory.txt"),
        newinventory2("newinventory2.txt");
    maxElement = 10 - 1;

    for(;maxElement > 0;maxElement--){
        for(index = 0;index < maxElement;index++){
            if(inventory[index][0] > inventory[index + 1][0]){ //it works
                swap(inventory[index][0],inventory[index+1][0]);
                swap(inventory[index][1],inventory[index+1][1]);
                swap(inventory[index][2],inventory[index+1][2]);
                swap(inventory2[index][0],inventory2[index+1][0]);
                swap(inventory2[index][1],inventory2[index+1][1]);

            }
        }
    }


        for(int i=0;i<10;i++){
            for(int j=0;j<3;j++){
                newinventory << inventory[i][j];
                newinventory << " ";
            }
            newinventory << "\n";
        }
        for(int i=0;i<10;i++){
            for(int j=0;j<2;j++){
                newinventory2 << inventory2[i][j];
                newinventory2 << " ";
            }
            newinventory2 << "\n";
        }
    newinventory.close();
    newinventory2.close();
}

void showMenu(string inventory[10][3]){ // i wish i could take a separate class learning how to efficiently use cout
    cout << "\nWe have the following toys:" << endl;
    for(int i=0;i<10;i++){
        cout << inventory[i][0];
        if (i != 9){
            cout << ", ";
        }
    }
    cout << endl;
}

void ckInventory(string inventory[10][3], int inventory2[10][2],int toyType){//1 is plastic 2 is stuffed
    bool success = 0;
    string toyName,toyCategory;
    int count;

    if(toyType == 1){
        toyCategory = "plastic";
    } else if (toyType == 2){
        toyCategory = "stuffed";
    }

    cout << "\nWhich toy would you like to check the quantity?" << endl;
    cout << "Please enter the name of the toy in all lowercase letters > ";
    cin >> toyName;

    for(count=0;count<10;count++){
        if(toyName == inventory[count][0]){
            success = 1;
            break;
        }
    }
    if(success == 0){
        cout << "\nWe are sorry the toy name you entered is not in our inventory please try again..." << endl;
        return;
    }
    cout << "\nThe toy you seek is a " << toyCategory << " " << toyName << "..." << endl;
    toyType = toyType - 1;
    if(inventory2[count][toyType] != 0){
        cout << "We have " << inventory2[count][toyType] << " In-Stock" << endl;
    } else if(toyType + 1 == 2){
        cout <<"We are sorry we do not have any toys that are stuffed." << endl;
    }else { 
        cout <<"We are sorry we do not have any In-Stock" << endl;
    }

}

bool readFile(string inventory[10][3], int inventory2[10][2]){
        ifstream inventoryData("inventoryData.txt"),
        inventoryData2("inventoryData2.txt");

        if(inventoryData.is_open()){
            for(int i=0;i<10;i++){
                for(int j=0;j<3;j++){
                inventoryData >> inventory[i][j];         
                }
            }
        } else {
            return 0;
        }
        if(inventoryData2.is_open()){
            for(int i=0;i<10;i++){
                for(int j=0;j<2;j++){
                inventoryData2 >> inventory2[i][j];         
                }
            }
        } else {
            return 0;
        }
        inventoryData.close();
        inventoryData2.close();
    return 1;
}

void welcome(){
    cout << "\n*****************************************" << endl;
    cout << "*          Welcome to Tekka Toys        *" << endl;
    cout << "*          Please follow the menu       *" << endl;
    cout << "*          Below to check our           *" << endl;
    cout << "*                  Inventory…           *" << endl;
    cout << "*****************************************" << endl;
}

void menu(){
    cout << "\nPlease check our inventory if you are interested..." << endl;
    cout <<"\n1.  Plastic Toy\n2.  Stuffed Toy\n3.  Exit\n> ";
}