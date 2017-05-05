//
//  main.cpp
//  FinalProject
//
//  Created by Hareen Patel & Eric Brommelhorst on 4/17/17.
//  Copyright © 2017 Hareen Patel. All rights reserved.
//


//Fixes and changes for next iteration

//Account class... add hand object
//Implement betting
//Implement multiple players

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <climits>

using namespace std;
#define max 10

int winCheck(int dealer, int player, string name);
void printCards(int suit, int card);

class Deck{
public:
    int heart[52];
    int spade[52];
    int diamond[52];
    int club[52];
    Deck();
    ~Deck();
    void reset(void);
};
Deck hold;

class Hand{
private:
    vector <int> suit;
    vector <int> val;
public:
    Hand();
    ~Hand();
    void deal(int dealer, string name);
    void hit(int dealer, string name);
    int check(void);
};

class Accounts{
private:
    Hand plr;
    float balance;
    char namefile[100];
    double bet;
public:
	string checkname1;
    void Openinfo(string checkname);
    void UpdateInfo(float filebalance);
    int Operations(int pnum, int rnum);
    int Oph();
    void winCheck(int dealer, int player);
    void initBet();
    
    // Accounts();
    // ~Accounts();
};
void help();
Deck::Deck(){
    int i;
    for(i=0;i<52;i++){
        heart[i] = 0;
        spade[i] = 0;
        diamond[i] = 0;
        club[i] = 0;
    }
}
Deck::~Deck(){
}
void Deck::reset(void){
    int i;
    for(i=0;i<52;i++){
        heart[i] = 0;
        spade[i] = 0;
        diamond[i] = 0;
        club[i] = 0;
    }
}

Hand::Hand(){
}
Hand:: ~Hand(){
    val.clear();
    suit.clear();
}
void Hand::deal(int dealer, string name){
    int s;
    int v;
    int o = 0;
    srand(time(NULL));
    suit.resize(2);
    val.resize(2);
    cout << "\t" << name <<endl;
    do{
        s = rand() % 4;
        v = rand() % 52;
        
        switch (s){
            case 0:
                if(hold.heart[v] == 0){
                    hold.heart[v] = 1;
                    suit[o] = 1;
                    val[o] = (v % 13)+1;
                    o++;
                }
                break;
            case 1:
                if(hold.spade[v] == 0){
                    hold.spade[v] = 1;
                    suit[o] = 2;
                    val[o] = (v % 13)+1;
                    o++;
                }
                break;
            case 2:
                if(hold.diamond[v] == 0){
                    hold.diamond[v] = 1;
                    suit[o] = 3;
                    val[o] = (v % 13)+1;
                    o++;
                }
                break;
            case 3:
                if(hold.club[v] == 0){
                    hold.club[v] = 1;
                    suit[o] = 4;
                    val[o] = (v % 13)+1;
                    o++;
                }
                break;
        }
    }while(o < 2);
    printCards(suit[0],val[0]);
    if(dealer != 1){
        printCards(suit[1],val[1]);
    }
}
void Hand::hit(int dealer, string name){
    int o = val.size();
    int i;
    int s;
    int v;
    val.resize(o+1);
    suit.resize(o+1);
    if(dealer < 2){
        cout << "\t" <<  name <<endl;
    }
    if(dealer > 16){
        printCards(suit[1],val[1]);
        dealer = 0;
        return;
    }
    do{
        s = rand() % 4;
        v = rand() % 52;
        switch (s){
            case 0:
                if(hold.heart[v] == 0){
                    hold.heart[v] = 1;
                    suit[o] = 1;
                    val[o] = (v % 13)+1;
                    o++;
                    i++;
                }
                break;
            case 1:
                if(hold.spade[v] == 0){
                    hold.spade[v] = 1;
                    suit[o] = 2;
                    val[o] = (v % 13)+1;
                    o++;
                    i++;
                }
                break;
            case 2:
                if(hold.diamond[v] == 0){
                    hold.diamond[v] = 1;
                    suit[o] = 3;
                    val[o] = (v % 13)+1;
                    o++;
                    i++;
                }
                break;
            case 3:
                if(hold.club[v] == 0){
                    hold.club[v] = 1;
                    suit[o] = 4;
                    val[o] = (v % 13)+1;
                    o++;
                    i++;
                }
                break;
        }
    }while(i == 0);
    if(dealer == 1){
        printCards(suit[1],val[1]);
        dealer = 0;
    }
    printCards(suit[o-1],val[o-1]);
}
int Hand::check(void){
    int i;
    int hold;
    int a = 0;
    int total = 0;
    
    for(i=0;i<val.size();i++){
        switch(val[i]){
            case 1:
                a++;
                break;
            case 2:
                total += 2;
                break;
            case 3:
                total += 3;
                break;
            case 4:
                total += 4;
                break;
            case 5:
                total += 5;
                break;
            case 6:
                total += 6;
                break;
            case 7:
                total += 7;
                break;
            case 8:
                total += 8;
                break;
            case 9:
                total += 9;
                break;
            case 10:
                total += 10;
                break;
            case 11:
                total += 10;
                break;
            case 12:
                total += 10;
                break;
            case 13:
                total += 10;
                break;
        }
    }
    for(i = 0;i < a; i++){
        if((total+11) > 21){
            total += 1;
        }else{
            total +=11;
        }
    }
    
    return total;
}

void printCards(int suit, int card){
    cout << "\t\t";
    switch(suit){
        case 1:
            cout << "Heart ";
            break;
        case 2:
            cout << "Spade ";
            break;
        case 3:
            cout << "Diamond ";
            break;
        case 4:
            cout << "Club ";
            break;
    }
    switch(card){
        case 1:
            cout << " A" << endl;
            break;
        case 11:
            cout << " J" << endl;
            break;
        case 12:
            cout << " Q" << endl;
            break;
        case 13:
            cout << " K" << endl;
            break;
        default:
            cout << " " << card << endl;
            break;
            
    }
}
void Accounts :: winCheck(int dealer, int player){
    if(dealer > 21){										//Dealer bust conditions
        cout << "Dealer Busts with " << dealer << endl;
        if(player > 21){
            cout << checkname1 <<" Busts with " << player << endl;
            cout << "Dealer Wins Over " << checkname1 << endl;
            balance -= bet;
            return;
        }else{
            cout << checkname1 << " Wins" << endl;
            balance += bet;
			if(player == 21){
				balance +=(bet/2);
			}
            return;
        }
    }else if(dealer == 21){									//Dealer 21 conditions
        if(player > 21){
            cout << checkname1 << " Busts with " << player << endl;
            cout << "Dealer Wins Over " << checkname1 << endl;
            balance -= bet;
            return;
        }else if(player == 21){
            cout << "Push For " << checkname1 << endl;
            return;
        }else{
            cout << "Dealer Wins Over " << checkname1 << endl;
            balance -= bet;
            return;
        }
    }else{													//Dealer under 21 Conditions
        if(player > 21){
            cout << checkname1 << " Busts with " << player << endl;
            cout << "Dealer Wins Over " << checkname1 << endl;
            balance -= bet;
            return;
        }else if(player > dealer){
            cout << checkname1 << " Wins with " << player << endl;
            balance += bet;
			if(player == 21){
				balance +=(bet/2);
			}
            return;
        }else if(player == dealer){
            cout << "Push at " << player << " For " << checkname1 << endl;
            return;
        }else{
            cout << "Dealer Wins with " << dealer << " Over " << checkname1 << endl;
            balance -= bet;
            return;
        }
    }
    UpdateInfo(balance);
}

void Accounts::Openinfo(string checkname){
    checkname1 = checkname;
    int buffer1=0;
    char buffer[(checkname.length()+4)];
    
    sprintf(buffer, "%s.txt",checkname.c_str());
    FILE *fp = fopen(buffer, "r");
    
    if(fp == NULL)
    {
        cout<<"the file was not found!, would you like to open an account?"<<endl<<"1:Yes or 2:No?";
        cin>>buffer1;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
        if(buffer1 == 1)
        {
            UpdateInfo(100);
            sprintf(buffer, "%s.txt",checkname.c_str());
            FILE *fp = fopen(buffer, "r");
            fscanf(fp, "%s %f", &*namefile, &balance);
            cout<<"Account Has been Created!"<<endl;
            //  exit(0);
            //call deal here?
        }
        else
        {
            cout<<"Without an account you can not play, goodbye!"<<endl;
			throw 1;
        }
    }
    else
    {
        fscanf(fp, "%s %f", &*namefile, &balance);
        //format for file will be Name, Balance, possible threat level?
    }
    //cout<<"Name: " << checkname <<endl<< "Balance $" << filebalance<< endl;
}
int Accounts::Operations(int pnum, int rnum){
    /*Add in a betting system right here before the game starts*/
    //check to see if they have balance before dealing1
    static Hand dlr;
    int w;
    int x = 1;
    
    if(pnum < rnum){
        do{                                             //Run dealer operations
            dlr.hit(x,"Dealer");
            x++;
        }while(dlr.check() <= 16);
        return dlr.check();
    }
    
    if(rnum == 1){
        dlr.deal(1,"Dealer");
        if(dlr.check() == 21){                          //Check Blackjack conditions
            cout << "Dealer BlackJack" << endl;
        }
    }
    plr.deal(0,checkname1);
    if(plr.check() == 21){
        cout << checkname1 << " BlackJack" << endl;
        return 0;
    }
    
    UpdateInfo(balance);
    return 0;
}
void Accounts::UpdateInfo(float filebalance){
    char buffer[(checkname1.length()+4)];
    sprintf(buffer, "%s.txt",checkname1.c_str());
    //FILE *fp = fopen(buffer, "w");
    
    ofstream file;
    
    file.open(buffer);
	if(filebalance == 0){
		file << ""<<checkname1<<" "<<""<<balance;
    }else{
		file << ""<<checkname1<<" "<<""<<filebalance;
	}
	file.close();
    
    // if(fp == NULL)
    //{
    //  cout<<"the file was not found!, would you like to open an account?"<<endl;
    //    exit(0);
    // }
    //fprintf(fp, "%s %f",checkname1.c_str(),filebalance);
}
int Accounts:: Oph(){
    int h;
    cout << checkname1 << " Enter 1 to hit: Enter 0 to stay: ";
    cin >> h;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
    while(h == 1){                                 // Player hit or stay
        plr.hit(0,checkname1);
        if(plr.check() > 21){
            h = 0;
        }else{
            cout << "Enter 1 to hit: ";
            cin >> h;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
        }
    }
    return plr.check();
}
void Accounts::initBet(){
    bet = 0;
    if(balance == 0){
		cout << "You have no money in your account." << endl;
		cout << "Buying back in with $100" << endl;
		balance = 50;
	}
	
    do{
        cout << setprecision(3) << "Current Balance For " << checkname1 << " is " << balance << endl;
        cout<<"How much would you like to bet? Enter amount now: ";
        cin >> bet;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
        if(bet == 0){
            cout << "You must bet to play" << endl;
        }else if(bet > balance){
            cout << "You cannot bet more money than you have" << endl;
            bet = 0;
        }
    }while(bet == 0);
}

void help(){
    // got information from http://www.bicyclecards.com/how-to-play/blackjack/
    cout<<"So you don't know how to play, You will now"<<endl<<endl;
    
    cout<<"would you like to know the objective of the game?if so press 1, press 0 to skip: ";
    int c1;
    cin>> c1;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
    if (c1 == 1)
    {
        cout<<"Each participant attempts to beat the dealer by getting a count as close to 21 as possible, without going over 21!"<<endl;
    }
    cout<<endl;
    cout<<"Would you like to know card values?if so press 1, press 0 to skip: ";
    int c2;
    cin >> c2;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
    
    if (c2 == 1)
    {
        cout<<"It is up to each individual player if an ace is worth 1 or 11. Face cards are 10 and any other card is its value on the card."<<endl;
    }
    cout<<endl;
    cout<<"Do you want to know how the dealer deals the cards?if so press 1, press 0 skip: "<<endl;
    int c3;
    cin>>c3;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
    
    if(c3 == 1)
    {
        cout<<"When all the players have placed their bets, the dealer gives one card face up to each player in rotation clockwise, and then one card face up to himself. Another round of cards is then dealt face up to each player, but the dealer takes his second card face down. Thus, each player except the dealer receives two cards face up, and the dealer receives one card face up and one card face down."<<endl;
    }
    cout<<endl;
    cout<<"Would you like a basic strategy? if so press 1, press 0 to skip: ";
    int c4;
    cin>> c4;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
    if(c4 == 1)
    {
        cout<<"Winning tactics in Blackjack require that the player play each hand in the optimum way, and such strategy always takes into account what the dealer's upcard is. When the dealer's upcard is a good one, a 7, 8, 9, 10-card, or ace for example, the player should not stop drawing until a total of 17 or more is reached. When the dealer's upcard is a poor one, 4, 5, or 6, the player should stop drawing as soon as he gets a total of 12 or higher. The strategy here is never to take a card if there is any chance of going bust. The desire with this poor holding is to let the dealer hit and hopefully go over 21. Finally, when the dealer's up card is a fair one, 2 or 3, the player should stop with a total of 13 or higher."<<endl;
    }
    
    cout<<endl;
}

int main(int argc, const char * argv[]){
    int pnum = 1;
    int rnum = 0;
    int i = 0;
    int h;
    int j;
	int played;
    int run = 0;
	int D;
    string checkname;
    cout<<"||||||||WELCOME TO THE CASINO!||||||||"<< endl <<"|||We hope you enjoy your time here|||"<<endl;
    cout << endl <<"Please enter your name: ";
    getline(cin,checkname);
    fflush(stdout);
    
    cout<<"Have you ever played blackjack? 1:yes Else:no"<<endl;
    cin>>played;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	if (played != 1)
    {
        help();
    }
	vector <Accounts> acc;
	vector <int> H;
	acc.push_back(Accounts());
	H.push_back(0);
	acc[0].Openinfo(checkname);
	do{
        cout << "Enter 1 to add another player, Else Continue: ";
        cin >> i;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
        if(i == 1){
            pnum++;
            cout << "Enter player's name: ";
			getline(cin,checkname);
			acc.push_back(Accounts());
			H.push_back(0);
			try{
				acc[pnum-1].Openinfo(checkname);
			}catch(...){
				acc.erase(acc.begin()+pnum-1);
				H.erase(H.begin()+pnum-1);
				pnum--;
			}
		}
    }while(pnum < 5 && i == 1);
    do{
		for(rnum = 0;rnum < pnum; rnum++){
			acc[rnum].initBet();
		}
		for(rnum = 0;rnum < pnum; rnum++){
			acc[rnum].Operations(pnum, rnum+1 );
		}
		for(rnum = 0;rnum < pnum; rnum++){
			H[rnum] = acc[rnum].Oph();
		}
		D = acc[0].Operations(pnum,rnum+1);
		rnum = 1;
		for(rnum = 0;rnum < pnum; rnum++){
			acc[rnum].winCheck(D,H[rnum]);
			acc[rnum].UpdateInfo(0);
		}
		cout << "Enter 1 to remove players: ";
		cin >> i;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		while(i == 1){
			pnum--;
			if(pnum == 0){
				cout << "Last Player removed" << endl	
					 << "Thanks for Playing!!!" << endl;
					 return 0;
			}
			cout << "Choose Player to remove: " << endl;	
				for(rnum = 0;rnum < pnum+1; rnum++){
					cout << "\t" << rnum+1 << ". " << acc[rnum].checkname1 << endl;
				}
			cin >> j;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			if(0 < j <= (pnum+1)){
				acc.erase(acc.begin()+j-1);
			}else{
				cout << "Invalid Choice" << endl;
				pnum++;
			}
			cout << "Enter 1 to remove players: ";
			cin >> i;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		if(pnum < 5){
			do{
			cout << "Enter 1 to add another player, Else Continue: ";
			cin >> i;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			if(i == 1){
				pnum++;
				cout << "Enter player's name: ";
				cin.ignore();
				getline(cin,checkname);
				acc.push_back(Accounts());
				H.push_back(0);
				acc[pnum-1].Openinfo(checkname);
			}
			}while(pnum < 5 && i == 1);
		}
		h++;
		if(h == 10){
			hold.reset();
		}
	}while(run == 0);
    
    cout<<" Have a good day! Come back soon :)"<<endl;
    return 0;
}