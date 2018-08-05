#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main() {
    struct gameState G;
    int seed = 3000;
    int tempHand=0;
    int numPlayers = 2;
    int t=0; // count the fail
    
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
sea_hag, tribute, smithy, council_room}; 




   memset(&G, 23, sizeof(struct gameState));


   srand(time(NULL));
   int ii;
   for (ii=0; ii<1000; ii++){

   initializeGame(numPlayers, k, seed, &G);
   int player, deckCount, handCount;
   player=rand()%numPlayers;  // random player 0 or 1
   deckCount=rand()%(MAX_DECK+1); // random deckCount
   handCount=rand()%(deckCount+1);// rand handCount

   G.handCount[player]=handCount;
 


    // random the copper gold and silver
    
    int s, randomNum, randi;
    for (s=0; s<G.deckCount[player]; s++){
          
                randomNum = rand() % (50 + 1);
                randi = rand() % (10);
                if(randomNum == 2){
                    G.deck[player][s] = copper;
                } else if(randomNum == 6){
                    G.deck[player][s] = silver;
                }else if(randomNum == 9){
                    G.deck[player][s] = gold;
                }else {
                    G.deck[player][s] = k[randi];
                }
        }
  

   int i;
   int coinCount1=0;
   for (i=0; i<G.handCount[player]; i++){
 if(G.hand[player][i] == copper || G.hand[player][i] == silver || G.hand[player][i] == gold){
         coinCount1++;
     }
}

   makeAdventurer(&G, player, &tempHand);
  


    int p;
   int coinCount2=0;
   for (p=0; p<G.handCount[player]; p++){
 if(G.hand[player][p] == copper || G.hand[player][p] == silver || G.hand[player][p] == gold){
         coinCount2++;
     }
  }
 



              if (coinCount1+2!= coinCount2){
                t++;}

   } 
              int pass;
             pass=1000-t;
    printf("****\n");
    printf("%d times failed in 1000 test\n", t);
    printf("%d times passed in 1000 test\n", pass);

return 0;
}

