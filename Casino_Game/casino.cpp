#include <bits/stdc++.h>  
#include <cstdlib>     // for random generating number
#include <ctime>
#include <unistd.h>   // for time pause using sleep
#include "blackjack.h"


using namespace std;

int amount;
int main();

void Exit(){
    cout<<"***********************************************************"<<endl;
    cout<<"ARE YOU SURE YOU WANT TO EXIT?"<<endl;
    cout<<"1 for YES "<<endl<<"2 for NO "<<endl;
    int e;
    cin>>e;
    if(e==1){
        cout<<"EXITING.........."<<endl;
        
    }
    else if(e==2){
        cout<<main()<<endl;
    }
    else{
        cout<<"INVALID INPUT"<<endl;
        Exit();
    }

}


void PlayAgain(){
    cout<<endl<<"***********************************************************"<<endl<<endl;
    cout << "DO YOU WANT TO PLAY AGAIN!" << endl;
    cout<<"1 for YES"<<endl<<"2 for NO"<<endl;
    int ch;
    cin >> ch;
    cout<<endl;
    if (ch == 1){
        cout<<main()<< endl;
    }
    else if (ch == 2){
        Exit();
        
    }
    else{
        cout<<"INVALID INPUT"<<endl;
        PlayAgain();
         
    }
}


void Betting(){
    cout<<"DO YOU WANT TO ADD AN AMOUNT FOR BETTING?"<<endl;
    cout<<"1 for YES"<<endl<<"2 for NO"<<endl;
    int ans;
    cin>>ans;
    if (ans==1 ){
        cout<<"ENTER AMOUNT: ";
        cin>>amount;
    }
    else if(ans==2){
        cout<<"YOU WILL BE PLAYING WITHOUT ANY BETS."<<endl;
        amount=0;
    }else{
        cout<<"INVALID INPUT"<<endl;
        Betting();
    }
    

}

void Rule(){
    cout<<"DO YOU WANT TO SEE THE RULES?"<<endl;
    cout<<"1 for YES"<<endl<<"2 for NO"<<endl;
    int rule;
    cin>>rule;
    cout<<endl;
    if(rule==1){
        cout<<"1. GET 21 POINTS ON THE PLAYER'S FIRST TWO CARDS (CALLED A 'BLACKJACK' OR 'NATURAL'), WITHOUT A DEALER BLACKJACK."<<endl;
        cout<<"2. REACH A FINAL SCORE HIGHER THAN THE DEALER WITHOUT EXCEEDING 21."<<endl;
        cout<<"3. LET THE DEALER DRAW ADDITIONAL CARDS UNTIL HIS OR HER HAND EXCEEDS 21."<<endl;
        cout<<"4. HIT: TAKE ANOTHER CARD FROM THE DEALER."<<endl;
        cout<<"5. STAND: TAKE NO MORE CARDS, ALSO KNOWN AS 'STAND PAT', 'STICK', OR 'STAY'"<<endl;
        cout<<"6. PUSH: BOTH DEALER AND PLAYER REACHED 21. TIE"<<endl;
        cout<<endl;
        sleep(10);  // pause program for 10 seconds.
    }
    else if(rule==2){
        return;
    }
    else{
        cout<<"INVALID INPUT"<<endl;
        Rule();
    }
}



void CardGuesser(){
      
    cout<<"********************WELCOME TO CARD GUESSER********************"<<endl;
    cout<<"ENTER CARD NUMBER FROM 1 TO 13"<<endl;
    int number;
    cin>>number;
    cout<<"ENTER SUIT : HEART,SPADE,CLUB,DIAMOND"<<endl;
    string suit;
    cin>>suit;
    cout<<"YOUR CARD IS: "<<number<<" "<<suit<<endl;
    
    srand(time(NULL));
    int randNum=(rand()%13)+1;

    string arr[4]={"HEART","SPADE","CLUB","DIAMOND"};
    srand(time(NULL));
    int randS=(rand()%4);
    string randSuit=arr[randS];

    cout<<"RANDOM CARD GENERATED IS: "<<randNum<<" "<<randSuit<<endl;

    if(number==randNum && suit==randSuit){
        cout<<"CONGO! YOU GUEESED CORRECTLY"<<endl;
        amount*=3;
    }
    else if(number==randNum ){
        cout<<"WRONG SUIT GUESSED!"<<endl;
        amount*=2;
    }
    else if(suit==randSuit ){
        cout<<"WRONG NUMBER GUESSED!"<<endl;
        amount*=2;
    }
    else{
        cout<<"WRONG GUESS!"<<endl;
        amount*=0.5;
    }
    if(amount!=0){
        cout<<"NOW YOU HAVE RUPEES Rs. "<<amount<<" LEFT"<<endl<<endl;        
    }
    

}

void Streak(){
    
    cout<<"********************WELCOME TO 7STREAK********************"<<endl;
    cout<<endl;
    cout<<"RANDOM NUMBER BETWEEN 1 AND 999 GENERATING....... "<<endl;
    srand(time(NULL));
    int randNum=(rand()%999)+1;
    cout<<"RANDOM NUMBER GENERATED IS: "<<randNum<<endl;
    if(randNum==777){
        cout<<"YOU WON THE BIG JACKPOT!"<<endl;
        amount*=10;
    }
    else if(randNum!=777 &&(randNum>=770 && randNum<=779)){
        cout<<"YOU WON THE MEDIUM JACKPOT!"<<endl;
        amount*=5;
    }
    else if(randNum==77){
        cout<<"OU WON THE SMALL JACKPOT!"<<endl;
        amount*=3;
    }
    else if(randNum!=77 &&(randNum>=70 && randNum<=79)){
        cout<<"OU WON THE MINI JACKPOT!"<<endl;
        amount*=2;
    }
    else{
        cout<<"PROBABLE MATCHES : 70-79 & 770-779"<<endl<<"NO MATCHES....YOU LOSE"<<endl<<endl;
        amount*=0.5;
    }
    if(amount!=0){
        cout<<"NOW YOU HAVE RUPEES Rs. "<<amount<<" LEFT"<<endl<<endl;        
    }

}

void GameMenu(){
    cout<<"****************** WELCOME TO GAME MENU ******************"<<endl;
    cout<<endl;
    cout<<"ENTER 1 FOR CARD GUESSER"<<endl<<"ENTER 2 for 7STREAK"<<endl<<"ENTER 3 for BLACKJACK"<<endl;
    int game;
    cin >> game;
    cout<<endl<<"***********************************************************"<<endl;
    cout<<endl;
    if (game == 1){
        CardGuesser();
        PlayAgain();
    }
    else if(game==2){
        Streak();
        PlayAgain();

    }
    else if(game==3){
            Rule();
            cout<<endl<<"NO BETS ALLOWED IN BLACKJACK!"<<endl<<endl;
            sleep(2);
            Blackjack casino_royale;
            casino_royale.playGame();
            PlayAgain();
        
    }
    else{
        cout<<"INVALID INPUT"<<endl;
        GameMenu();
    }
        
}

int main(){
    cout<<"******************** WELCOME TO CASINO ********************"<<endl;
    cout<<endl;
    Betting();
    cout<<"BETTING OVER"<<endl;
    cout<<"***********************************************************"<<endl;
    cout<<endl;
    
    cout<<"ENTER 1 for GAME MENU"<<endl<<"ENTER 2 to EXIT"<<endl;
    int choice;
    cin>>choice;
    cout<<endl;
    switch(choice){
        case 1:
            GameMenu();
            break;                
                     
        case 2:
            Exit();
            break;
        
        default:
            cout<<"INVALID INPUT"<<endl<<endl;
            main();
            break;

    }
    return 0;
}