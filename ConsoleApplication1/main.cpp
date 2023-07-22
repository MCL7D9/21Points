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
            if (j + 1 > 10) {
                poker[i * 13 + j] = 10;
            }
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
    USI cards[20] = { 0 }, top = 0,sum=0;

public:
    int give_card() {
        cards[top] = poker_set[poker_top];
        sum += poker_set[poker_top];
        poker_top -= 1;
        top += 1;
        return 0;
    }

    int echo_card() {
        cout << "Player " << name << "\'s card set are:\n ";
        for (int i = 0; i < top; i++) {
            cout << "[" << cards[i] << "] ";
        }
        cout << "====================\n";
        return 0;
    }
    
    int echo_info(USI i) {
        cout << "Sum Of Your Cards Is" << sum << endl;
        cout << "First Card Of Your Enemy's Cards Is" << i <<endl;
        return 0;
    }

    USI first_card() {
        return cards[1];
    }
    USI length() {
        return top + 1;
    }

    USI total() {
        return sum;
    }
};

char AI_decide(player *obj,player *self) {
    USI first = obj->first_card(),randNum=0,SUM=self->total(),LENGTH0=self->length(), LENGTH1=obj->length();
    srand(time(nullptr));
    randNum = rand() % 7;
    if ((SUM<11)||(randNum==0&&SUM<19)||(randNum>0&&randNum<5&&SUM<15)||(randNum>0&&randNum<6&&SUM<13)){

        return 59;

    }
    else {
        return 78;
    }


}

int round_ctrl(player *Player,player *AI) {
    char p1_choice=0, p2_choice=0;
    USI aiTotal=0,playerTotal=0;
    while (p1_choice != 78 || p2_choice != 78) {
        if (p1_choice != 78) {
            do {
                cout << "Do You Want To Add A Card?\n Yes[Y] No[N] Information[I]\n";
                cin >> p1_choice;
                if (p1_choice == 59) {
                    Player->give_card();
                }
                if (p1_choice==73) {
                    Player->echo_info(AI->first_card());
                }
            } while (p1_choice == 73);
        }
        if (p2_choice != 78) {
            p2_choice == AI_decide(Player, AI);
            if (p2_choice == 59) {
                AI->give_card();
            }
        }
    }
    aiTotal = AI->total();
    playerTotal = Player->total();
    if (aiTotal==playerTotal || (aiTotal>21 && playerTotal>21)) {
        cout << "Draw";
    }
    if (aiTotal > 21 || playerTotal > aiTotal) {
        cout << name << " Win!";
    }
    if (playerTotal > 21 || aiTotal > playerTotal) {
        cout<<"AI Win!";
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
