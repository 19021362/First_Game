#include <iostream>
#include <cstdlib>
#include <ctime>
#include "matching_card.h"

using namespace std;

int main()
{
    char ans;
    int r1, c1, r2, c2, cards[4][4], moves;
    bool cardstatus[4][4];
    bool gameover = false;
    do
    {
        moves = 0;

        shuffle(cards);

        print_play_board(cardstatus);

        do
        {
            do
            {

                cout<<"Please insert the first card row and column.\n";
                cin>>r1>>c1;
                if(cardstatus[r1-1][c1-1] == true)
                {
                    cout << "This card is already flipped! Select another card.";
                }
            }while(cardstatus[r1-1][c1-1]!= false);
            do
            {
                cout<<"Please insert the second card row and column.\n";
                cin>>r2>>c2;
                if(cardstatus[r2-1][c2-1] == true)
                {
                    cout << "This card is already flipped! Select another card.";
                }
                if((r1==r2)&&(c1==c2))
                {
                    cout << "You can't select same card twice!" << endl;
                    continue;
                }
            }while(cardstatus[r2-1][c2-1]!= false);

            r1--;
            c1--;
            r2--;
            c2--;

            reveal(cards, cardstatus, r1, c1, r2, c2);

            if (cards[r1][c1]==cards[r2][c2] && r1 != r2 )
            {
                cout << "Cards Matched!"<<endl;

                cardstatus[r1][c1] = true;
                cardstatus[r2][c2] = true;
            }

            for (int b=0; b<=20; b++)
                cout<<endl;

            for (int r=0; r<4; r++)
            {
                cout<<r+1<<" | ";
                for (int c=0; c<4; c++)
                {
                    if (cardstatus[r][c] == true)
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

            gameover = gamestatus(cardstatus);
            moves++;

        }while(gameover != true);
        cout << "Congratulations, You won!!!"<<endl;
        cout << "It Required " << moves << " moves to finish it."<<endl<<endl;
        cout << "Would you like to play again? (y=Yes/n=No) : ";
        cin >> ans;
    }while(ans == 'y' || ans == 'Y');
    cin.get();
    return 0;
}
