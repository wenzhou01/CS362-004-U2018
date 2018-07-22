#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// Unit test 1, test function isGameOver(struct gameState * state)



 int main (){


         int seed = 1000;
         int numPlayer = 2;
         int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
         printf("   ***   test gaincard()  ****   \n");

          struct gameState G;

          memset(&G, 23, sizeof(struct gameState));
          initializeGame(numPlayer, k, seed, &G);
          
          G.supplyCount[silver]=0;

          int result;
          result=gainCard(silver, &G, 0, 0);
                           if (result==-1){
         printf("pass the test 1\n");}
                            else
                       {  printf("fail the test 1");
                               }
  return 0;
}
