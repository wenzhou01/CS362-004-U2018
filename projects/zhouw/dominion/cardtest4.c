#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main(){
   int seed = 3000;
   int numPlayers = 2;

     int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

   struct gameState G, G1;
   memset(&G, 23, sizeof(struct gameState));
    memset(&G1, 23, sizeof(struct gameState));

   initializeGame(numPlayers, k, seed, &G);
   memcpy(&G1, &G, sizeof(struct gameState));

   printf("  **  cardtest makeGreatHall()  **  \n");
   makeGreatHall(&G1, 0, 0);
   int result, result1;

   printf("test 1\n");
   result=G.handCount[0]+1;
   result1=G1.handCount[0];

   if (result==result1){
     printf("Pass the test\n");
   }
   else
    { printf("Fail the test\n");}
  
    printf("before handcount is %d\n",result);
        //  printf("After handcount is %d\n",result1);
  
           printf("test 2\n");
              result=G.numActions+1;
                 result1=G1.numActions;
  
                    if (result==result1){
                         printf("Pass the test\n");
                            }
                               else
                                   { printf("Fail the test\n");}
  
                                   //    printf("before numActions is %d\n",result);
                                     //   printf("After numActions  is %d\n",result1);
                                       return 0;}
