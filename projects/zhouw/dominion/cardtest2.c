#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"



int main(){
   int seed = 3000;
   int numPlayers = 2;
   int tempHand=0;
   int card;
     int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

   struct gameState G, G1;
    memset(&G, 23, sizeof(struct gameState));
    memset(&G1, 23, sizeof(struct gameState));

   initializeGame(numPlayers, k, seed, &G);
   memcpy(&G1, &G, sizeof(struct gameState));
  
  
   makeAdventurer(&G1, 0, &tempHand);

   int result=0;
   int  result1=0;
   int i;

   for (i = 0; i < G1.handCount[0]; i++) {
        card = G1.hand[0][i];
        if (card == copper || card == silver || card == gold) {
            result1++;
        }
     }  
  
   for (i = 0; i < G.handCount[0]; i++) {
        card = G.hand[0][i];
        if (card == copper || card == silver || card == gold) {
            result++;
        }
     }

      result=result+2;
/*
    printf("original reslut is %d\n", result);
    printf("new result is %d\n", result1);

*/
     if (result==result1){
    printf("Pass the test\n");
       }
       else{
        printf("Fail the test\n");
       }



return 0;
}
