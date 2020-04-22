#include<iostream>


void shuffle(int cards[4][4]);

void print_play_board(bool cardstatus[4][4]);

void reveal(int cards[4][4], bool cardstatus[4][4], int r1, int c1, int r2, int c2);

bool gamestatus(bool cardstatus[4][4]);
