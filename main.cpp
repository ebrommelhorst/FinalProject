//
//  main.cpp
//  FinalProject
//
//  Created by Hareen Patel on 4/17/17.
//  Copyright © 2017 Hareen Patel. All rights reserved.
//


//Fixes and changes for next iteration

//Account class... add hand object
//Implement betting 
//Implement multiple players


#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iomanip>

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
		string checkname1;
		Hand plr;
		double balance;
		char namefile[];
		double bet;
	public:
		void Openinfo(string checkname);
		void UpdateInfo(string checkname1, float filebalance);
		int Operations(int pnum, int rnum);
		int Oph();
		void winCheck(int dealer, int player);
		void initBet();
   // Accounts();
   // ~Accounts();
};

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
        if(buffer1 == 1)
        {
            UpdateInfo(checkname, 0.00);
            cout<<"Account Has been Created!"<<endl;
          //  exit(0);
            //call deal here?
        }
        else
        {
            cout<<"Without an account you can not play, goodbye!"<<endl;
        }
    }
    else
    {
    fscanf(fp, "%s %lf", &*namefile, &balance);
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
	return 0;
}
void Accounts::UpdateInfo(string checkname1, float filebalance){
    char buffer[(checkname1.length()+4)];
    sprintf(buffer, "%s.txt",checkname1.c_str());
    FILE *fp = fopen(buffer, "w");
    
    if(fp == NULL)
    {
        cout<<"the file was not found!, would you like to open an account?"<<endl;
        exit(0);
    }
    
    fprintf(fp, "Name  Balance\n%s  %.2f\n",checkname1.c_str(),filebalance);
}
int Accounts:: Oph(){
	int h;
	cout << checkname1 << " Enter 0 to hit: ";
    cin >> h;
    while(h == 0){                                 // Player hit or stay
        plr.hit(0,checkname1);
		if(plr.check() > 21){
			h = 1;
		}else{
			cout << "Enter 0 to hit: ";
			cin >> h;
		}
    }
	return plr.check();
}
void Accounts::initBet(){
	bet = 0;
	do{
		cout << setprecision(3) << "Current Balance For " << checkname1 << " is " << balance << endl;
		cin >> bet;
		if(bet == 0){
			cout << "You must bet to play" << endl;
		}else if(bet > balance){
			cout << "You cannot bet more money than you have" << endl;
			bet = 0;
		}
	}while(bet == 0);
}

int main(int argc, const char * argv[]){
    int pnum = 1;
	int rnum = 1;
	int i = 0;
	int h;
	int run = 0;
    string checkname;
    cout<<"||||||||WELCOME TO THE CASINO!||||||||"<< endl <<"|||We hope you enjoy your time here|||"<<endl;
    cout << endl <<"Please enter your name: ";
    getline(cin,checkname);
    Accounts A1;
	int H1;
	Accounts A2;
	int H2;
	Accounts A3;
	int H3;
	Accounts A4;
	int H4;
	Accounts A5;
    int H5;
	int D;
	A1.Openinfo(checkname);
	do{
		cout << "Enter 1 to add another player, Else Continue: ";
		cin >> i;
		if(i == 1){
			pnum++;
			cout << "Enter player's name: ";
			cin.ignore();
			getline(cin,checkname);
			switch(pnum){
				case 2:
					A2.Openinfo(checkname);
					break;
				case 3:
					A3.Openinfo(checkname);
					break;
				case 4:
					A4.Openinfo(checkname);
					break;
				case 5:
					A5.Openinfo(checkname);
					break;
			}
		}
	}while(pnum < 5 && i == 1);
	
	while(run == 0){
	rnum = 1;
	/*while(rnum <= pnum){
		switch(rnum){
				case 1:
					A1.initBet();
					break;
				case 2:
					A2.initBet();
					break;
				case 3:
					A3.initBet();
					break;
				case 4:
					A4.initBet();
					break;
				case 5:
					A5.initBet();
					break;
		}
		rnum++;
	}*/
	rnum = 1;
	while(rnum <= pnum){
		switch(rnum){
				case 1:
					A1.Operations(pnum, rnum);
					break;
				case 2:
					A2.Operations(pnum, rnum);
					break;
				case 3:
					A3.Operations(pnum, rnum);
					break;
				case 4:
					A4.Operations(pnum, rnum);
					break;
				case 5:
					A5.Operations(pnum, rnum);
					break;
		}
		rnum++;
	}
	rnum = 1;
	while(rnum <= pnum){
		switch(rnum){
				case 1:
					H1 = A1.Oph();
					break;
				case 2:
					H2 = A2.Oph();
					break;
				case 3:
					H3 = A3.Oph();
					break;
				case 4:
					H4 = A4.Oph();
					break;
				case 5:
					H5 = A5.Oph();
					break;
		}
		rnum++;
	}
	D = A1.Operations(pnum,rnum);
	rnum = 1;
	while(rnum <= pnum){
		switch(rnum){
				case 1:
					A1.winCheck(D,H1);
					break;
				case 2:
					A2.winCheck(D,H2);
					break;
				case 3:
					A3.winCheck(D,H3);
					break;
				case 4:
					A4.winCheck(D,H4);
					break;
				case 5:
					A5.winCheck(D,H5);
					break;
		}
		rnum++;
	}
	cout << "Enter 0 to play again: ";
	cin >> run;
	}
    return 0;
}
