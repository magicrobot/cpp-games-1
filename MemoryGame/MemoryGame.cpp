//Author - Mandeep Singh Bhatia
//Program - Memory Game


//for system,rand function, 
//same as stdlib.h but safer
#include <cstdlib>
//in operating system other than windows
//replace system command if not supported

//for cout, cin
#include <iostream>

#include "time.h"
//#include "gl\gl.h"

//important statement, just accept for now
using namespace std;

const int max_range=100;
const int max_chances=5;

int PlayGame(void);

int main(void)
{
    //rand, srand for random numbers
    //The rand function returns a pseudorandom integer -
    //in the range 0 to RAND_MAX (32767). 
    char q='c';
    int games=0;
    int wins=0;
    int score=0;
    int totalScore=0;
    
    srand( (unsigned)time( NULL ) );
    //should include time.h for time function
    while((q!='q') && (q!='Q'))
    {
      //may replace with cout<<"\n\n\n";
      system("cls");//- to clear screen
      cout<<"\n*****Memory Game*****\n\n";
      cout<<"About Game...\n";
      cout<<"Try to guess a number in range 0 to "<<max_range;
      cout<<endl<<"in "<<max_chances<<" chances,";
      cout<<endl<<"Lower the chances used means more the score...\n";
      cout<<endl<<"Games Played = "<<games;
      cout<<endl<<"No. of Wins  = "<<wins;
      cout<<endl<<"Total Score  = "<<totalScore;
      cout<<endl<<"Percent Score= ";
      if (games)
      cout<<( (totalScore*100) / (games*max_chances) );
      else
      cout<<"0";
      
      cout<<endl<<endl<<"To play game enter P, To quit enter Q:-";
      cin>>q;
      if ((q!='q') && (q!='Q')) score+=PlayGame();
      games++;
      totalScore+=score;
      if (score) wins++;
    }
    return EXIT_SUCCESS;
}

int PlayGame(void)
{
     int toGuess=rand() % max_range;
     int chances=max_chances;
     bool guessed=false;
     int guess;
     char st[5];
     
     while ((chances>0) && (!guessed))
     {
       system("cls");
       cout<<"\n*****Memory Game*****\n\n";
       
       if (chances<max_chances)
       cout<<"Your previous guess was "<<st<<endl;
        
       cout<<"\n You have "<<chances<<" chances...\n";
       cout<<"\n Enter Your Guess?";
       cin>>guess;
       if (guess==toGuess)
       guessed=true;
       else
       {
         chances--;
         if (guess>toGuess)
         strcpy(st,"High");
         else
         strcpy(st,"Low");
       }    
     }//while
     
     system("cls");
     
     if (guessed)
     {
       cout<<"\n\n Congratulations! You Guessed It...\n";
     }
     else
     {
         cout<<"\n You Missed It This Time...\n";
     }

     cout<<"\n Your score is - "<<chances;
     cout<<endl<<endl;
     //may replace with _getch(); included in conio.h
     system("PAUSE"); //to pause
     return chances;
}//playgame
