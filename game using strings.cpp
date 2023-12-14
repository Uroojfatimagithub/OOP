//Exercise 3
//You need to create a game using strings. First generate a random letter from A to Z, this is your
//key and is hidden from the players. Ask player1 and player 2 to enter two strings of length 10.
//The player whose strings contains the key alphabet will win. If both the players have key
//alphabets, then the player for which it occurs earlier in the string will win. Example Run:
//Key: S (Not visible to user)
//Player1: ABDXSCJMNK; Player2: CSTUZWKMIJ
//Player 2 wins.
//HINT:
//string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//Generate a random number ‘k’ in range 0 to 25 inclusive. Use s[k] as your random letter
Program:
#include <iostream>
#include <string>

using namespace std;

class Game {
private:
    string alphabet;
    char key;
    string player1;
    string player2;

public:
    Game() : alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), key('S') {}

    void getinput() {
        cout << "Player 1, enter a string of length 10: ";
        getline(cin, player1);

        cout << "Player 2, enter a string of length 10: ";
        getline(cin, player2);
    }

    void determine_winner() {
        bool keyFoundPlayer1 = player1.find(key) != string::npos;
        bool keyFoundPlayer2 = player2.find(key) != string::npos;

        if (keyFoundPlayer1 && keyFoundPlayer2) {
            int keyPosPlayer1 = player1.find(key);
            int keyPosPlayer2 = player2.find(key);

            cout << "Player " << (keyPosPlayer1 < keyPosPlayer2 ? 1 : 2) << " wins!" << endl;
        } else if (keyFoundPlayer1) {
            cout << "Player 1 wins!" << endl;
        } else if (keyFoundPlayer2) {
            cout << "Player 2 wins!" << endl;
        } else {
            cout << "No player found the key. It was: " << key << endl;
        }
    }
};

int main() {
    Game game;

    game.getinput();
    game.determine_winner();

    return 0;
}
