
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRIES 100

int testsPassed = 1;

void testAssert(int test, char* msg)
{
    if (!test) {
        printf("TEST FAILED: %s\n", msg);
        testsPassed = 0;
    } else {
#ifdef DEBUG_TEST
        printf("TEST PASSED: %s\n", msg);
#endif
    }
}

void adventureTest()
{
    srand(time(NULL));

    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
    struct gameState G, prevG;
    int p, i, j, coin_bonus = 0;

    memset(&G, 23, sizeof(struct gameState));

    for (j = 0; j < TRIES; j++) {
        int numPlayers = 2;
        int seed = rand();
        int adventurerPos, copperPos, silverPos, goldPos, expectedCoins = 0;

        initializeGame(numPlayers, k, seed, &G);

p = whoseTurn(&G);

 G.deckCount[p] = rand() % (MAX_DECK / 2 - 3) + 3;
        G.discardCount[p] = rand() % (MAX_DECK / 2 - 3) + 3;
        for (i = 0; i < G.deckCount[p]; G.deck[p][i++] = rand() % (treasure_map - gold + 1) + adventurer)
            ;
        for (i = 0; i < G.discardCount[p]; G.discard[p][i++] = rand() % (treasure_map - gold + 1) + adventurer)
;

 copperPos = rand() % (G.deckCount[p] + G.deckCount[p]);
        silverPos = rand() % (G.deckCount[p] + G.deckCount[p]);
        goldPos = rand() % (G.deckCount[p] + G.deckCount[p]);
        while (silverPos == copperPos)
            silverPos = rand() % (G.deckCount[p] + G.deckCount[p]);
        while (goldPos == copperPos || goldPos == silverPos)
            goldPos = rand() % (G.deckCount[p] + G.deckCount[p]);
        if (copperPos < G.deckCount[p]) {
            G.deck[p][copperPos] = copper;
        } else {
            G.discard[p][copperPos - G.deckCount[p]] = copper;
        }
        if (silverPos < G.deckCount[p]) {
            G.deck[p][silverPos] = silver;
        } else {
            G.discard[p][silverPos - G.deckCount[p]] = silver;
        }
        if (goldPos < G.deckCount[p]) {
            G.deck[p][goldPos] = gold;
        } else {
            G.discard[p][goldPos - G.deckCount[p]] = gold;
        }

 expectedCoins = copperPos > silverPos ? (copperPos > goldPos ? 5 : 3) : (silverPos > goldPos ? 4 : 3); 


 adventurerPos = rand() % G.handCount[p];
        G.hand[p][adventurerPos] = adventurer;

memcpy(&prevG, &G, sizeof(struct gameState));

cardEffect(adventurer, 0, 0, 0, &G, adventurerPos, &coin_bonus);

testAssert(coin_bonus == 0, "No bonus gained from play.");
        testAssert(G.numActions == prevG.numActions, "No actions gained from play");
        testAssert(G.handCount[p] == prevG.handCount[p] + 1, "Hand increased by 1 (+2 cards drawn -1 adventurer discarded)");
testAssert(G.deckCount[p] + G.discardCount[p] == prevG.deckCount[p] + prevG.discardCount[p] - 2, "Deck and discard decreased by 2");

updateCoins(p, &G, 0);
updateCoins(p, &prevG, 0);

testAssert(prevG.coins + expectedCoins == G.coins, "Value of the player's hand has increased the expected coin's values");
    }
}

int main()
{
    printf("Testing: adventurerEffect()\n");

    adventureTest();

    printf("%s\n", testsPassed ? "All tests passed" : "1 or more tests failed");
    return 0;
}
