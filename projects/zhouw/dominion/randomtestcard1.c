// tst card smithy

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>



int main(){
  
   int seed = 1000;
   int numPlayers = 2;
   int player;
   int numAfter;
   
   int deckCount;
   int handCount;
   int p=0;


   int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

   struct gameState G;
   memset(&G, 23, sizeof(struct gameState));
  

   srand(time(NULL));
   int i;
   for (i=0; i<1000; i++){

   initializeGame(numPlayers, k, seed, &G);

   player=rand()%numPlayers;  // random player 0 or 1
   deckCount=rand()%(MAX_DECK+1); // random deckCount
   handCount=rand()%(deckCount+1);// rand handCount
 
   G.handCount[player]=handCount;

   makeSmithy(&G, player, 0); 

   numAfter=G.handCount[player];

           if (numAfter-3!= handCount){
                p++;}


    }
              int pass;
             pass=1000-p;
    printf("****\n");
    printf("%d times failed in 1000 test\n", p);
    printf("%d times passed in 1000 test\n", pass);
  
return 0;
}
