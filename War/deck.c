#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Card* makeDeck();

struct Card{
    char suit[9];
    char writtenValue[6];
    int value;
};


int main(int argc, char *argv[]){
    struct Card* deck = makeDeck();
    printf("%i",deck[17].value);


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
        
    }
    printf("%s", deck[17].suit);



    return deck;
}