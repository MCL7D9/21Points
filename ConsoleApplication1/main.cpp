#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
#define USI unsigned short int
USI* poker_set, poker_top = 51;
string name;

USI &shuffle() {
    USI poker[52] = { 0 }, temp, rann, & ref_poker = *poker;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            poker[i * 13 + j] = j + 1;
        }
    }
    for (int i = 0; i < 52; i++) {
        srand(time(nullptr));
        rann = rand() % (52 - i);
        temp = poker[i];
        poker[i] = poker[rann];
        poker[rann] = temp;
    }
    return ref_poker;
}

class player {
private:
    int cards[20] = { 0 }, top = 0,sum=0;

public:
    void give_card() {
        cards[top] = poker_set[poker_top];
        poker_top -= 1;
        top += 1;
    }

    void echo_card() {
        cout << "Player " << name << "\'s card set are:\n ";
        for (int i = 0; i < top; i++) {
            cout << "[" << cards[i] << "] ";
        }
        cout << "====================\n";
    }

};

int round_ctrl(player *Player,player *AI) {
    char p1_choice=0, p2_choice=0;
    while (p1_choice != 78){
        cout << "Do You Want To Add A Card?\n Yes[Y] No[N] Information[I]\n";
        cin.get(p1_choice);
        switch (p1_choice) {
        case 59:
            Player->give_card();
        case 78:
        case 73:
        default:
            break;
        }
    }
    return 0;
}

int main()
{ 
    cout << "Welcome To The Game 21 Points!\n";
    cout << "Please Enter Your Name\n";
    cin >> name;
    cout << "==========Game Start==========\n";
    poker_set = &shuffle();
    player P1, P2;
    for (int i = 0; i < 2; i++) {
        P1.give_card();
        P2.give_card();
    }
    P1.echo_card();
    round_ctrl(&P1,&P2);
    system("pause");
    return 0;
}
