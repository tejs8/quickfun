#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std; 

int main(){
    std::cout<<std::fixed<<std::setprecision(2);
    srand(int(time(0)));
    int playerIwins = 0;
    int playerIIwins = 0;
    int bothwins = 0;

    int simnum;
    cout<<"Number of sims to run: "; cin>>simnum;

    for(int i = 0; i < simnum; ++i){
    bool win = false;
    int playeroneprev = -1;
    int playertwoprev = -1;
    while(win==false){
        bool ponewin = false;
        bool ptwowin = false;
        int numone = rand() % 6 + 1;
        int numtwo = rand() % 6 + 1;
        if(numone== 6 && playeroneprev==6){
            ponewin = true;
            win = true;
        }
        if(numtwo == 6 && playertwoprev == 5){
            ptwowin = true;
            win = true;
        }

        if(ponewin && ptwowin){
            ++bothwins;
        }
        else if(ponewin) ++playerIwins;
        else if(ptwowin) ++playerIIwins;

        playeroneprev = numone;
        playertwoprev = numtwo;

        }
    }

    double poneprop = double(playerIwins) / double(simnum);
    double ptwoprop = double(playerIIwins) / double(simnum);
    double bothwinsprop = double(bothwins) / double(simnum);
    cout<<"Player 1 (6,6) win percentage: "<<poneprop*100<<"%"<<endl;
    cout<<"Player 2 (5,6) win percentage: "<<ptwoprop*100<<"%"<<endl;
    cout<<"Both win percentage: "<<bothwinsprop*100<<"%"<<endl;

}