#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main(){
   int seed = 1000;
   int numPlayers = 2;

     int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

   struct gameState G, G1;
   memset(&G, 23, sizeof(struct gameState));
    memset(&G1, 23, sizeof(struct gameState));

   initializeGame(numPlayers, k, seed, &G);
   memcpy(&G1, &G, sizeof(struct gameState));

   printf("  **  cardtest makeVillage()  **  \n");
   makeVillage(&G1, 0, 0);
   int result, result1;
   result=G.numActions+2;
   result1=G1.numActions;

   /*
           printf("original num action  is  %d\n", result);
              printf("new game nnum action  is %d\n", result1);
              
                      */

  
   if (result==result1){
     printf("Pass the test\n");
   }
    else{
    printf("Fail the test\n");
     }

return 0;
}
