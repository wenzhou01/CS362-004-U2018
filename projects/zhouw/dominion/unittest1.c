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
	
	printf("   ***   test isGameOver()  ****   \n");

        struct gameState G;

        memset(&G, 23, sizeof(struct gameState));
        initializeGame(numPlayer, k, seed, &G);
   
        printf("test 1\n");

        G.supplyCount[province]=0;   // expected result, the game is over

        int result;

        result=isGameOver(&G);

     		if (result==1){
         		printf("pass the test 1\n");
                          }
    		     else
       		{  printf("fail the test 1");
          		}

         printf("test 2\n"); 
         G.supplyCount[province]=1;
         int i;
         for (i=0; i<23; i++){
          G.supplyCount[i]=1;
           }                           // expected result, the game is not over.

    
          result=isGameOver(&G);

                if (result==0){
                        printf("pass the test 2\n");
                          }
                     else
                {  printf("fail the test 2");
                        }
 





return 0;
}

