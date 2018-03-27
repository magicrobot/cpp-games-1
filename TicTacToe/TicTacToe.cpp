//Author - Mandeep Singh Bhatia
//Program - Cross'N'Naughts

#include <cstdlib>
#include <iostream>

char matrix[3][3];

using namespace std;

const char NAUGHT='O';
const char CROSS='X';

void DrawGrid(void);
void PlayGame(bool player);
int WhoWon(void);

int main(void)
{
    char q='c';
    int x=0;
    int o=0;
    int turn=false;
    
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
        matrix[i][j]=' ';
    
    while((q!='q')&&(q!='Q'))
    {
      system("cls");
      cout<<"\t*****Cross'N'Naughts*****\n";
      DrawGrid();
      cout<<"\n\n Previous Game Winner : ";
      switch(WhoWon())
      {
        case 0: cout<<"Draw"; break;
        case 1: cout<<CROSS; x++; break;
        case 2: cout<<NAUGHT; o++; break;
      }
      cout<<"\n\nScores Player X : "<<x<<"    Player O : "<<o<<"\n\n";
      cout<<"Enter P to play, Q to quit :-";
      cin>>q;
      if ((q!='q')&&(q!='Q')) PlayGame(turn);
      turn=!turn;
    }
    
    return EXIT_SUCCESS;
}

void DrawGrid(void)
{
     cout<<endl;
     cout<<"\tRC "<<"1"<<" "<<"2"<<" "<<"3";
     cout<<endl<<endl;
     cout<<"\t1  "<<matrix[0][0]<<"|"<<matrix[0][1]<<"|"<<matrix[0][2];
     cout<<endl;
     cout<<"\t   "<<"-"<<"|"<<"-"<<"|"<<"-";
     cout<<endl;
     cout<<"\t2  "<<matrix[1][0]<<"|"<<matrix[1][1]<<"|"<<matrix[1][2];
     cout<<endl;
     cout<<"\t   "<<"-"<<"|"<<"-"<<"|"<<"-";
     cout<<endl;
     cout<<"\t3  "<<matrix[2][0]<<"|"<<matrix[2][1]<<"|"<<matrix[2][2];
     cout<<endl;     
}

int WhoWon(void)// returns 0 if no one wins, 1 - player X, 2 - player O 
{
    char winner=' ';
    bool found;
    
    found=(matrix[1][1]==matrix[0][0]) && (matrix[2][2]==matrix[0][0]);
    if (found) winner=matrix[0][0];

    if ((!found) || (winner==' ')) 
    {
      found=(matrix[1][1]==matrix[0][2]) && (matrix[2][0]==matrix[0][2]);
      if (found) winner=matrix[0][2];
    }

    if ((!found) || (winner==' '))
      for (int i=0;i<3;i++)
        if ((!found) || (winner==' '))
        {
          found=(matrix[i][1]==matrix[i][0])&&(matrix[i][2]==matrix[i][0]);
          if (found) winner=matrix[i][0];
        }

    if ((!found) || (winner==' '))
      for (int j=0;j<3;j++)
        if ((!found) || (winner==' '))
        {
          found=(matrix[1][j]==matrix[0][j])&&(matrix[2][j]==matrix[0][j]);
          if (found) winner=matrix[0][j];
        }
        
    switch(winner)
    {
      case ' ': return 0;
      case CROSS: return 1;
      case NAUGHT: return 2;
    }
}

void PlayGame(bool player)
{
  bool gameOver=false;
  bool turn=player;
  char t;
  int numTurns=0;
  int row,col;
  
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      matrix[i][j]=' ';
      
  while(!gameOver)
  {
    if (turn)
      t=NAUGHT;
    else
      t=CROSS;
    system("cls");
    cout<<"\t*****Cross'N'Naughts*****\n";
    DrawGrid();
    cout<<"\n\n Turn of Player : "<<t;      
    cout<<"\n\n Enter Row (1/2/3) : ";
    cin>>row;
    cout<<"\n Enter Column (1/2/3) : ";
    cin>>col;
    
    //check if valid input
    if ((row<1)||(row>3)||(col<1)||(col>3))
    {
      cout<<"\n Invalid row or column value (only 1 or 2 or 3 accepted)\n";
      system("PAUSE");
      continue;
    }
    if (matrix[row-1][col-1]!=' ')
    {
      cout<<"\n The cell is already occupied. choose another row & column.\n";
      system("PAUSE");
      continue;
    }
    
    matrix[row-1][col-1]=t;
    numTurns++;  
    gameOver=WhoWon()||(numTurns==9);  
    if(!gameOver) turn=!turn;
  }//while
}
