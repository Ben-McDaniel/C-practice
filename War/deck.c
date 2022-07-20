/*
unfinished, still needs card logic for moving
cards from pile into winners hand and removing
the already used cards from both hands
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct Card* makeDeck();
void splitDeck(struct Card* deck, struct Card* p1, struct Card* p2);
void shuffle(struct Card* deck, int numTimesShuffle);

struct Card{
    char suit[9];
    char writtenValue[6];
    int value;
};


int main(int argc, char *argv[]){
    struct Card* deck = makeDeck();

    //void split which randomly splits deck in 2
    struct Card* player1 = malloc(sizeof(struct Card) * 52);
    struct Card* player2 = malloc(sizeof(struct Card) * 52);
    
    shuffle(deck, 3);
    splitDeck(deck, player1, player2);

    //game loop and logic
    int cardToFlip = 0;
    

    //copoy top 2 cards, then copy both haNDS INTO NEW LISTS THEN  recopy backj with pile on back of winners

    while(player1[cardToFlip].value != NULL && player2[cardToFlip].value != NULL){
        struct Card* pile = malloc(sizeof(struct Card) * 52);
        struct Card* tplayer1 = malloc(sizeof(struct Card) * 52);
        struct Card* tplayer2 = malloc(sizeof(struct Card) * 52);
        char nextMove;
        //enter to play next hand, will read all chars in buffer so might print multiple times if more chars are entered 
        nextMove = getchar();
        printf("Player 1 Card: %s of %s", player1[cardToFlip].writtenValue, player1[cardToFlip].suit);
        printf("Player 2 Card: %s of %s", player2[cardToFlip].writtenValue, player2[cardToFlip].suit);

        pile[cardToFlip] = player1[cardToFlip];
        pile[cardToFlip+1] = player2[cardToFlip];

        if(player1[cardToFlip].value == player2[cardToFlip].value){
            cardToFlip = cardToFlip + 1;
        }else if(player1[cardToFlip].value > player2[cardToFlip].value){
            printf("player1 wins\n");
            cardToFlip = 0;
        }else{
            printf("player2 wins\n");
            cardToFlip = 0;
        }

        free(pile);
        free(tplayer1);
        free(tplayer2);
    }




    //clear all memory 
    free(player1);
    free(player2);
    free(deck);

    return 0;
}

struct Card *makeDeck(){
    struct Card *deck = malloc(sizeof(struct Card) * 52);
    
    for(int i = 0; i < 52; i++){

        if(i < 13){
            strcpy(deck[i].suit, "Spades\0");
            deck[i].value = i;
            
        }else if(i < 26){
            strcpy(deck[i].suit, "Clubs\0");
            deck[i].value = i - 13;
            
        }else if(i < 39){
            strcpy(deck[i].suit, "Hearts\0");
            deck[i].value = i - 26;
            
        }else if(i < 52){
            strcpy(deck[i].suit, "Diamonds\0");
            deck[i].value = i - 39;
            
        }
        
        //card values go from 0-12
        //ik i messed up thats why ace is first and things are wack
        if(deck[i].value == 12){
            strcpy(deck[i].writtenValue, "ace\0");
        }else if(deck[i].value == 0){
            strcpy(deck[i].writtenValue, "two\0");
        }else if(deck[i].value == 1){
            strcpy(deck[i].writtenValue, "three\0");
        }else if(deck[i].value == 2){
            strcpy(deck[i].writtenValue, "four\0");
        }else if(deck[i].value == 3){
            strcpy(deck[i].writtenValue, "five\0");
        }else if(deck[i].value == 4){
            strcpy(deck[i].writtenValue, "six\0");
        }else if(deck[i].value == 5){
            strcpy(deck[i].writtenValue, "seven\0");
        }else if(deck[i].value == 6){
            strcpy(deck[i].writtenValue, "eight\0");
        }else if(deck[i].value == 7){
            strcpy(deck[i].writtenValue, "nine\0");
        }else if(deck[i].value == 8){
            strcpy(deck[i].writtenValue, "ten\0");
        }else if(deck[i].value == 9){
            strcpy(deck[i].writtenValue, "jack\0");
        }else if(deck[i].value == 10){
            strcpy(deck[i].writtenValue, "queen\0");
        }else if(deck[i].value == 11){
            strcpy(deck[i].writtenValue, "king\0");
        }

    }

    return deck;
}


void splitDeck(struct Card* deck, struct Card* p1, struct Card* p2){
    for(int i = 0; i < 26; i++){
        p1[i] = deck[2*i];
        p2[i] = deck[2*i+1];
    }
}

void shuffle(struct Card* deck, int numTimesShuffle){
    time_t t;
    srand((unsigned) time(&t));
    
    for(int j = 0; j < numTimesShuffle; j++){
        for(int i = 0; i < 52; i++){
            struct Card temp;
            int newIndex = rand() % 50;

            temp = deck[newIndex];
            deck[newIndex] = deck[i];
            deck[i] = temp;
        }
    }
}