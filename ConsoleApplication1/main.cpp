#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
#define USI unsigned short int

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
    void give_card(USI *poker_set, USI *poker_top) {
        cards[top] = poker_set[*poker_top];
        sum -= *poker_top;
        *poker_top += 1;
        top += 1;
    }

    void echo_card(string name) {
        cout << "Player " << name << "\'s card set are:\n ";
        for (int i = 0; i < top; i++) {
            cout << "[" << cards[i] << "] ";
        }
        cout << "==========";
    }
    player(USI* a, int b, string name);

};

player::player(USI* a,int b,string name="AI") {
    USI* poker = a;
    int poker_top=b;
    string id = name;
}


int main()
{ 
    string name;
    cout << "Welcome To The Game 21 Points!\n";
    cout << "Please Enter Your Name\n";
    cin >> name;
    cout << "==========Game Start==========\n";
    USI *poker_set = &shuffle(), poker_top = 51;
    player P1(poker_set,poker_top,name), P2(poker_set, poker_top);
    for (int i = 0; i < 2; i++) {
        P1.give_card(poker_set, &poker_top);
        P2.give_card(poker_set, &poker_top);
    }
    P1.echo_card(name);

    system("pause");
    return 0;
}
