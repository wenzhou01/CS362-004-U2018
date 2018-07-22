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
        int numPlayer = 2;
        int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

        printf("   ***   test scoreFor()  ****   \n");

        struct gameState G;

        memset(&G, 23, sizeof(struct gameState));
        initializeGame(numPlayer, k, seed, &G);

        int i;
        int a=0;
        int b=0;
        int c=0;
        int d=0;
        int e=0;
        int f=0;
      
         int score=0;


        for (i=0; i<G.handCount[0];i++){
            if (G.hand[0][i]==curse){a++;}
            if (G.hand[0][i]==estate){b++;}
            if (G.hand[0][i]==duchy){c++;}
            if (G.hand[0][i]==province){d++;}
            if (G.hand[0][i]==great_hall){e++;}
            if(G.hand[0][i]==gardens){f++;}
            
           }

        score=score-a+b+3*c+6*d+e+f*(fullDeckCount(0,0,&G)/10);
        

  /*      printf(" a b c d e f is %d %d %d %d %d %d\n", a, b, c, d, e, f);
        printf("score is %d\n", score);
  */

       int result;
       result=scoreFor(0, &G);

       if (score==result){printf("Pass the test\n");}
       else {printf("Fial the test\n");}
return 0;
}
