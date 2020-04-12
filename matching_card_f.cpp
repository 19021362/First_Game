#include<iostream>
#include<cstdlib>
#include<ctime>
#include "matching_card.h"

using namespace std;

void shuffle(int cards[4][4])
{
    int start[16]={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
        srand((unsigned)time(NULL));
        for (int x=0; x<16; x++)
        {
            int i=rand()%16;
            int temp=start[x];
            start[x]=start[i];
            start[i]=temp;
        }
        cout << endl;
    int i=0;
    for (int r=0; r<4; r++)
        {
            for (int c=0; c<4; c++)
            {
                cards[r][c]=start[i];
                cout<<cards[r][c];
                i=i+1;
            }
            cout<<endl;
        }
}

void print_play_board(bool cardstatus[4][4])
{
    cout<<"    1 2 3 4\n";
        cout<<"  ";
        for (int i=0; i<=8; i++)
        {
            cout<<"-";
        }
        cout<<endl;
        for (int r=0; r<4; r++)
        {
            cout<<r+1<<" | ";
            for (int c=0; c<4; c++)
            {
                cout<<"* ";
                cardstatus[r][c] = false;
            }
            cout<<endl;
        }
        cout<<endl;
}

void reveal(int cards[4][4], bool cardstatus[4][4], int r1, int c1, int r2, int c2)
{
    cout<<"    1 2 3 4\n";
            cout<<"  ";
            for (int i=0; i<=8; i++)
            {
                cout<<"-";
            }
            cout<<endl;
            for (int r=0; r<4; r++)
            {
                cout<<r+1<<" | ";
                for (int c=0; c<4; c++)
                {
                    if ((r==r1)&&(c==c1))
                    {
                        cout<<cards[r][c]<<" ";
                    }
                    else if((r==r2)&&(c==c2))
                    {
                        cout<<cards[r][c]<<" ";
                    }
                    else if (cardstatus[r][c] == true)
                    {
                        cout<<cards[r][c]<<" ";
                    }
                    else
                    {
                        cout<<"* ";
                    }
                }
                cout<<endl;
            }
}

bool gamestatus(bool cardstatus[4][4])
{
    bool gameover = true;
            for (int r=0; r<4; r++)
            {
                for (int c=0; c<4; c++)
                {
                    if(cardstatus[r][c]==false)
                    {
                      gameover = false;
                      break;
                    }
                }
                if(gameover == false)
                {
                    break;
                }
            }

        return gameover;
}
