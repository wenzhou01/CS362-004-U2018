
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


int main(){
   int seed = 1000;
   int numPlayers = 2;

     int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

   struct gameState G;
   memset(&G, 23, sizeof(struct gameState));
//    memset(&G1, 23, sizeof(struct gameState));

   initializeGame(numPlayers, k, seed, &G);
  // memcpy(&G1, &G, sizeof(struct gameState));

   printf("  **  cardtest buyCard()  **  \n");
   

   G.numBuys=0;
  
   int  result;
   result=buyCard(2, &G);

//   printf("result is %d\n", result);

   if (result==-1){printf("Pass the test\n");}
   else{printf("Fail the test\n");}

return 0;
}
