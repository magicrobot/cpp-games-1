#define NUM_WORDS (9*4)
#define WORD_LEN 4

#include <cstdlib>
#include <iostream>
#include "conio.h"
#include "time.h"

using namespace std;

char dictionary[NUM_WORDS][WORD_LEN+1]= {
     "bake","burn","bark","born","bite","bike","boat","boot","best",
     "corn","crib","crop","city","coup","cast","card","cost","comb",
     "dawn","dart","dust","drag","drum","drop","dare","drip","dumb",
     "like","lake","laid","lair","liar","lump","loom","look","lame"};

void Rules()
{
  system("cls");
  cout<<"\t*****Cows'N'Bulls*****\n\n\n";
  cout<<"\t Rules\n\n";
  cout<<"\t You will be presented with an unknown 4 letter word.\n";
  cout<<"\t You need to type in a 4 letter word(your guess).\n";
  cout<<"\t For a correct letter at correct position you get 1 bull."; 
  cout<<"\n\t For a letter at incorrect position you get 1 cow.\n\n";
  cout<<"To Quit at any time during the game type 'quit' withoute quotes";
  cout<<"\n\n";
  system("PAUSE"); 
}
     
void PlayGame(void)
{
  int w=rand()%NUM_WORDS;
  int cows=0;
  int bulls=0;
  char theWord[WORD_LEN+1];
  
  strcpy(theWord,"abcd");
  while(true)
  {
    system("cls");
    cout<<"\t*****Cows'N'Bulls*****\n\n\n";
    //cout<<dictionary[w]<<"\n\n";
    cout<<"You have "<<cows<<" cows & "<<bulls<<" bulls\n\n";
    cout<<"Enter your guess (4 letter word) : ";
    cin>>theWord;
    if (strcmp(theWord,"quit")==0) break;
    if (strlen(theWord)!=WORD_LEN)
    {
      cout<<"The word should be 4 letters...\n";
      system("PAUSE");
      continue;
    }
    for (int i=0;i<WORD_LEN;i++)
    {
    if (dictionary[w][i]==theWord[i]) bulls++;
    else cows++;
    }//There was a problem without braces in for - if - else
    if (strcmp(theWord,dictionary[w])==0) break;
  }//while
  system("cls");
  cout<<"You have "<<cows<<" cows & "<<bulls<<" bulls\n\n";
  system("PAUSE");
}

int main(void)
{
    char m='1';
    srand((unsigned) time(NULL));
    while(m!='3')
    {
      system("cls");
      cout<<"\t*****Cows'N'Bulls*****\n\n\n";
      cout<<"\t Menu\n\n\n";
      cout<<"\t 1. Read Rules.\n\n";
      cout<<"\t 2. Play Game.\n\n";
      cout<<"\t 3. Quit.\n\n";
      cout<<"\t Press menu digit of your choice : ";
      if ((m<'1')||(m>'3'))
      {
        cout<<"\n Invalid choice, should press 1 or 2 or 3\n";
      }
      m=_getch();
      
      switch(m)
      {
       case '1': Rules(); break;
       case '2': PlayGame(); break;
       case '3': break;
       default: break;
      }
     }
    return EXIT_SUCCESS;
}
