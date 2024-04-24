#include <bits/stdc++.h>

using namespace std;


class Blackjack{
private:
    int dealerhand[5]; // max no of cards =5
    int playerhand[5];
    int dealerhandSize;
    int playerhandSize;
    int dealerhandSum;
    int playerhandSum;
    int playerhit;
    int playerstand;
    bool playerDone;
    bool dealerDone;
    void addPlayerCard();
    void addDealerCard();
    void printHand();
    void sumHands();

public:
    Blackjack();
    void playGame();
};


void Blackjack::addPlayerCard()
{
    if (playerhandSize <= 5)
    {
        playerhand[playerhandSize] = 1 + (rand() % 11);
        playerhandSize++;
    }
    else
    {
        cout << "SORRY. YOU HAVE REACHED THE MAXIMUM NUMBER OF CARDS (5)." << endl;
        playerDone = true;
    }
}

void Blackjack::addDealerCard()
{
    if (dealerhandSize <= 5)
    {
        dealerhand[dealerhandSize] = 1 + (rand() % 11);
        dealerhandSize++;
    }
    else
    {
        dealerDone = true;
    }
}

void Blackjack::printHand()
{
    cout << "YOUR CURRENT HAND IS..."<<endl;

    for (int i = 0; i < playerhandSize; i++)
    {
        cout << "    -" << playerhand[i] << "-    "<<endl<<endl;
    }

    cout << "DEALER'S CURRENT HAND IS..."<<endl;

    for (int j = 0; j < dealerhandSize; j++)
    {
        cout << "    -" << dealerhand[j] << "-    "<<endl<<endl;
    }
}

void Blackjack::sumHands()
{
    dealerhandSum = 0;
    playerhandSum = 0;
    for (int i = 0; i < dealerhandSize; i++)
    {
        dealerhandSum += dealerhand[i];
    }

    for (int j = 0; j < playerhandSize; j++)
    {
        playerhandSum += playerhand[j];
    }

    cout << "CURRENT PLAYER HAND SUM IS: " << playerhandSum << endl;
}






Blackjack::Blackjack()
{
    srand(time(0));
    dealerhandSize = 0;
    playerhandSize = 0;
    dealerhandSum = 0;
    playerhandSum = 0;
    playerDone = false;
    dealerDone = false;

}

void Blackjack::playGame()
{
    cout <<"********************WELCOME TO BLACKJACK********************"<<endl<<endl;

    // Start the player and dealer with two cards
    addPlayerCard();
    addPlayerCard();
    addDealerCard();
    addDealerCard();
    sumHands();
    printHand();

    if (dealerhandSum == 21)
    {
        cout << "DEALER HAS BLACKJACK. DEALER WINS."<<endl;
        return;
    }
    else if (playerhandSum == 21)
    {
        cout << "THE PLAYER HAS BLACKJACK. PLAYER WINS."<<endl;
        return;
    }

    while (dealerDone == false || playerDone == false)
    {
        if (playerDone == false)
        {
            cout << "WOULD YOU LIKE TO HIT?"<<endl;
            cout<<"1 for YES"<<endl<<"2 for NO"<<endl;
            cin >> playerhit;

            if (playerhit == 1)
            {
                addPlayerCard();
                printHand();
                sumHands();

                if (playerhandSum > 21)
                {
                    cout << "THE PLAYER'S HAND EXCEEDED 21. PLAYER LOSES."<<endl;
                    return;
                }
            }
        }

        if (playerDone == false)
        {
            cout << "WOULD YOU LIKE TO STAND?"<<endl;
            cout<<"1 for YES"<<endl<<"2 for NO"<<endl;
            cin >> playerstand;
        }

        if (playerstand == 1)
        {
            playerDone = true;
        }

        if (dealerhandSum < 17 && dealerDone != true)
        {
            addDealerCard();
            printHand();
            sumHands();

            if (dealerhandSum > 21)
            {
                cout << "DEALER HAND EXCEEDED 21. DEALER LOSES."<<endl;
                return;
            }
        }
        else if (dealerhandSum >= 17)
        {
            dealerDone = true;
        }

        if (playerhandSum == 21 && dealerhandSum == 21)
        {
            cout << "PUSH, PLAYER AND DEALER REACHED 21."<<endl;
            return;
        }
        else if (playerhandSum == 21)
        {
            cout << "THE PLAYER REACHED 21. PLAYER WINS."<<endl;
            return;
        }
        else if (dealerhandSum == 21)
        {
            cout << "DEALER REACHED 21. DEALER WINS."<<endl;
            return;
        }

        if ((playerDone == true && dealerDone == true) || (playerhandSize == 5 && playerhandSize == 5))
        {
            if (dealerhandSum < playerhandSum)
            {
                cout << "SUM OF YOUR HAND EXCEEDS THE DEALER'S SUM OF " << dealerhandSum << ". YOU WIN!";
                return;
            }
            else if (playerhandSum == dealerhandSum)
            {
                cout << "DEALER'S SUM OF " << dealerhandSum << " IS EQUAL TO THE SUM OF YOUR HAND. TIE GAME.";
                return;
            }
            else if (dealerhandSum > playerhandSum)
            {
                cout << "SUM OF YOUR HAND IS LOWER THAN THE DEALER'S SUM OF " << dealerhandSum << ". YOU LOSE!";
                return;
            }
        }
    }
}


