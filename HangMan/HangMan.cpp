//Author - Mandeep Singh Bhatia
//Program - HangMan

#define NUM_WORDS 5
#define MAX_LEN 15
#define LETTERS_LEN ('z'-'a'+1)

#include <cstdlib>
#include <iostream>
#include "time.h"
//#include <conio.h>

using namespace std;

char dictionary[NUM_WORDS][MAX_LEN+1]={"hello","picture",
"potential","computer","multimedia"};

const int max_chances=8;

void PlayGame(void);

int main(void)
{
    char q='c';
    //_getch();
    srand( (unsigned) time(NULL) );
    while ((q!='q') && (q!='Q'))
    {
      system("cls");
      cout<<"\t*****HangMan*****\n\n";
      cout<<"This is a word guessing game."<<endl;
      cout<<"You will have "<<max_chances<<" chances."<<endl;
      cout<<"You can guess a single letter or the complete word.\n\n";
      cout<<"Enter P to Play, or Q to quit :-";
      cin>>q;
      if ((q!='q') && (q!='Q')) PlayGame();
    }
    return EXIT_SUCCESS;
}

/*
void CheckWord(char s[],int w,char en[])
{
  int l=strlen(s);
  
  if (strlen(en)==1)
  {  
    for(int i=0;i<l;i++)
    if (dictionary[w][i]==en[0]) s[i]=dictionary[w][i];
  }
  else
  {
    if (strcmp(dictionary[w],en)==0) strcpy(s,dictionary[w]);
  }
}
*/

void PlayGame(void)
{
     char st[MAX_LEN+1];
     char entr[MAX_LEN+1];
     bool done[LETTERS_LEN];
     bool already=false;
     bool found;
     int w=rand()%NUM_WORDS;
     int l=strlen(dictionary[w]);
     int chances=max_chances;
     bool guessed=false;
          
     for (int i=0;i<l;i++)
       st[i]='*';
     
     st[l]='\0';
     
     for (int i=0;i<LETTERS_LEN;i++)
       done[i]=false;
     
     while((!guessed) && (chances>0))
     {
       system("cls");
       cout<<"\t*****HangMan*****\n\n";
       
       if (already) cout<<"You already entered : "<<entr<<"\n\n";
       
       cout<<st<<"\n\n\n";
       cout<<"You have "<<chances<<" chances.\n\n";
       cout<<"Enter a letter or a word (guess) : ";
       cin>>entr;
       found=false;
       if (strlen(entr)==1) 
       {
         already=done[(entr[0]-'a')];
         done[(entr[0]-'a')]=true;
         
         for(int i=0;i<l;i++)
           if (dictionary[w][i]==entr[0])
           {
             st[i]=dictionary[w][i];
             found=true;
           }
       }
       else
       {
         already=false;
         if (strcmp(dictionary[w],entr)==0) 
         {
           strcpy(st,dictionary[w]);
           found=true;
         }
       }
       
       //CheckWord(st,w,entr);
       guessed=( strcmp(st,dictionary[w])==0 );
       if (!already && !found) chances--;
     }
     
     system("cls");
     if (guessed)
       cout<<"Congratulations, You Guessed The Word.\n\n";
     else
       cout<< "Sorry, You Missed.\n\n";
       
     cout<< "The word was : "<<dictionary[w]<<"\n\n";
     cout<<"You Had "<<chances<<" chances remaining.\n\n";
     system("PAUSE");
}//PlayGame
