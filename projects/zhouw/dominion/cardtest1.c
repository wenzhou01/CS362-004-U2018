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

   printf("  **  cardtest makeSmithy()  **  \n");
   makeSmithy(&G1, 0, 0);
   int result, result1;
   result=G.handCount[0]+3;
   result1=G1.handCount[0];
   
   /*int result2, result3;
   result2=G.handCount[1];
   result3=G1.handCount[1];
  
   printf("original player 1 hand count is %d\n", result);
    printf("original player 2 hand count is %d\n", result2);
    printf("new game player 1 hand count is %d\n", result1);
   printf("new game player 2 hand count is %d\n", result3);
  */

   
   if (result==result1){
     printf("Pass the test\n");
   }
   else{
     printf("Fail the test\n");
   }
   


return 0;
}
