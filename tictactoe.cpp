#include <iostream>
#include <ctype.h>
using namespace std;

struct Player //we created the player struct to store the number and user choice for x or y
{
    char letter;
    int num;
    bool player_won = 0; //we need to pull which player is the winner
};

void print_the_board(char print_board[][3]); //prints board
void take_input(Player player,int game_board[][3], char print_board[][3]);  //takes input, compares to game board and then changes and returns printboard
void create_board(int game_board[][3], char print_board[][3]); //creates the boards for the playetr to use
bool win_conditions(int game_board[][3],char print_board[][3], Player &player); //return t/f if win conditions are satisfied also set game up to be played multiple times.
void initialize_player(Player &,Player &); // takes in the players and asks them whether or not they want x or y 


int main(void)
{
    Player p_1, p_2;
    bool win_flag = 1;
    int turns = 0;
    char print_board[3][3]; //this board is whats going change based off game board input
    int game_board[3][3]; //user input will be compared to the board which will go to 1-9
    cout << "Welcome to Tic Tac Toe!\nThe game will now begin. " << endl;
    initialize_player(p_1,p_2);
    create_board(game_board,print_board);
    print_the_board(print_board);

    while(win_flag)
    {
        switch(turns % 2)
        {
            case 0:
                take_input(p_1, game_board, print_board);
                print_the_board(print_board);
                win_flag = win_conditions(game_board, print_board,p_1);
                break;
            case 1:
                take_input(p_2, game_board, print_board);
                print_the_board(print_board);
                win_flag = win_conditions(game_board, print_board,p_2);
                break;
        }

        if(p_1.player_won == 1)
        {
            cout << "Player " << p_1.num << " wins!" << endl;
        }
        else if(p_2.player_won == 1)
        {
            cout << "Player " << p_1.num << " wins!" << endl;
        }
        turns++;
    }
    
    return 0;
}

bool win_conditions(int game_board[][3],char print_board[][3], Player &player)
{
    int full_board_counter = 0;
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            if(print_board[i][j] != '~')
            {
                full_board_counter += 1;
            }
        }
    }
    if (full_board_counter == 9)
    {
        return 0;
    }
        //criss cross
        if(print_board[0][0] == print_board[1][1] && print_board[1][1] == print_board[2][2])
        {
            if(print_board[0][0] != '~')
            {  
                player.player_won = 1;
                return 0;
            }
            else
            {
                return 1;
            }   
        }
        if(print_board[0][2] == print_board[1][1] && print_board[1][1] == print_board[2][0])
        {
            if(print_board[0][2] != '~')
            {  
                player.player_won = 1;
                return 0;
            }
            else
            {
                return 1;
            }   
        }
        //going down the board
        if(print_board[0][0] == print_board[0][1] && print_board[0][1] == print_board[0][2])
        {
            if(print_board[0][0] != '~')
            {  
                player.player_won = 1;
                return 0;
            }
            else
            {
                return 1;
            }   
        }
        if(print_board[1][0] == print_board[1][1] && print_board[1][1] == print_board[1][2])
        {
            if(print_board[1][0] != '~')
            {  
                player.player_won = 1;
                return 0;
            }
            else
            {
                return 1;
            }   
        }
        if(print_board[2][0] == print_board[2][1] && print_board[2][1] == print_board[2][2])
        {
            if(print_board[2][0] != '~')
            {  
                player.player_won = 1;
                return 0;
            }
            else
            {
                return 1;
            }   
        }
        //going from across
        if(print_board[0][0] == print_board[1][0] && print_board[1][0] == print_board[2][0])
        {
            if(print_board[0][0] != '~')
            {  
                player.player_won = 1;
                return 0;
            }
            else
            {
                return 1;
            }   
        }
        if(print_board[0][1] == print_board[1][1] && print_board[1][1] == print_board[2][1])
        {
            if(print_board[0][1] != '~')
            {  
                player.player_won = 1;
                return 0;
            }
            else
            {
                return 1;
            }   
        }
        if(print_board[0][2] == print_board[1][2] && print_board[1][2] == print_board[2][2])
        {
            if(print_board[0][2] != '~')
            {  
                player.player_won = 1;
                return 0;
            }
            else
            {
                return 1;
            }   
        }

    return 1;
}

void take_input(Player player, int game_board[][3], char print_board[][3])
{
    int input;
    cout << "It's Player " << player.num <<"'s turn." << endl;
    cout << "Please input a number from 1-9 in correspondance to the game board. > ";
    cin >> input;
    while (input < 1 || input > 9)
    {
        cout << "Error: Invalid input.\nPlease enter a number within 1-9 > ";
        cin >> input;
    }
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            if(game_board[i][j] == input){
                print_board[i][j] = player.letter;
            }
        }
    }
}

void print_the_board(char print_board[][3]) 
/*The Game Board
---------------
 | 1 | 2 | 3 |
---------------
 | 4 | 5 | 6 |
---------------
 | 7 | 8 | 9 |
---------------*/
{
    cout << "The Game Board\n" <<"---------------" << endl;
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            cout << " | " << print_board[i][j];
            if(j == 2)
            {
                cout << " |\n" << "---------------" << endl;
            } 
        }
    }
    cout << '\n';
}

void create_board(int game_board[][3], char print_board[][3])
{
    int counter = 1; //this is the variable we're going to use to set game_board 1-9 we start off at one so it goes from 1-9
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            print_board[i][j] = '~';
            game_board[i][j] = counter;
            counter += 1;
        }
    }
}

void initialize_player(Player &player_1,Player &player_2) 
{
    //this function gives the values for player 1 and 2 to be called and gives the user option to input either x or o for their choice
    player_1.num = 1,
    player_2.num = 2;
 
    while(1)
    {
        cout << "Player " << player_1.num << ", do you want to be x or o?\nPlease enter a LOWERCASE letter > ";
        cin >> player_1.letter;
        player_1.letter = tolower(player_1.letter);

        if (player_1.letter == 'x')
        {
            cout << "Player " << player_1.num << " has selected x as their letter." << endl;
            cout << "Player " << player_2.num << " will be letter o." << endl;
            player_2.letter = 'o';
            break;
        }
        else if(player_1.letter == 'o')
        {
            cout << "Player " << player_1.num << " has selected x as their letter." << endl;
            cout << "Player " << player_2.num << " will be letter x." << endl;
            player_2.letter = 'x';
            break;
        }
        else
            cout << "Error: user input is invalid, please try again." << endl;
    }
}