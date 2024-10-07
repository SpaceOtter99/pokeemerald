#ifndef GUARD_CONFIG_DEXNAV_H
#define GUARD_CONFIG_DEXNAV_H


#define USE_DEXNAV_SEARCH_LEVELS      TRUE   /* WARNING: EXCEEDS SAVEBLOCK SPACE! YOU WILL NEED TO FREE UP SPACE */

// search parameters
#define DEXNAV_TIMEOUT                  900  //15 seconds is the time out. Max of 1092 seconds allowed
#define SNEAKING_PROXIMITY              0   //Tile amount
#define CREEPING_PROXIMITY              0
#define MAX_PROXIMITY                   20

#define DEXNAV_CHAIN_MAX                100 // maximum chain value

//hidden pokemon options - no info so I just guessed at values
#define HIDDEN_MON_STEP_COUNT       100  //look for hidden pokemon every x steps
#define HIDDEN_MON_SEARCH_RATE      25  //x% chance of finding hidden pokemon every x steps
#define HIDDEN_MON_PROBABILTY       15  //x% chance of finding hidden mon compared to regular encounter data

//// SEARCH PROBABILITIES
// see https://m.bulbapedia.bulbagarden.net/wiki/DexNav#Benefits
//Chance of encountering egg move at search levels
#define SEARCHLEVEL0_MOVECHANCE         0
#define SEARCHLEVEL5_MOVECHANCE         20
#define SEARCHLEVEL10_MOVECHANCE        40
#define SEARCHLEVEL25_MOVECHANCE        50
#define SEARCHLEVEL50_MOVECHANCE        60
#define SEARCHLEVEL100_MOVECHANCE       70
#define searchLevel_Move {0, 20, 40, 50, 60, 70, 80, 90, 95}
//Chance of encountering Hidden Abilities at search levels
#define SEARCHLEVEL0_ABILITYCHANCE      0
#define SEARCHLEVEL5_ABILITYCHANCE      0
#define SEARCHLEVEL10_ABILITYCHANCE     5
#define SEARCHLEVEL25_ABILITYCHANCE     15
#define SEARCHLEVEL50_ABILITYCHANCE     20
#define SEARCHLEVEL100_ABILITYCHANCE    25
#define SEARCH_LEVEL_ABILITY {0, 0, 5, 15, 20, 25, 35, 45, 50}
//Chance of encountering held item
#define SEARCHLEVEL0_ITEM               0
#define SEARCHLEVEL5_ITEM               0
#define SEARCHLEVEL10_ITEM              1
#define SEARCHLEVEL25_ITEM              7
#define SEARCHLEVEL50_ITEM              6
#define SEARCHLEVEL100_ITEM             12
#define SEARCH_LEVEL_ITEM {0, 0, 1, 5, 10, 10, 15, 20, 25}

u8 searchLevels[] = {00, 05, 10, 25, 50, 100, 150, 200, 250};
#define NUM_SEARCH_LEVELS 9
#define NUM_DEXNAV_STARS 5
//Chance of encountering X star potential
u8 encounterChances[NUM_SEARCH_LEVELS][NUM_DEXNAV_STARS] = {
    {01, 00, 00, 00, 00},   //0
    {05, 01, 00, 00, 00},   //5
    {10, 05, 01, 00, 00},   //10
    {15, 10, 05, 01, 00},   //25
    {25, 15, 10, 05, 01},   //50
    {15, 25, 15, 10, 05},   //100
    {10, 15, 25, 15, 10},   //150
    {10, 10, 15, 25, 15},   //200
    {10, 10, 10, 15, 25},   //250

}

#define SUMARR(arr, index) ({         \
    int _sum = 0;                  \
    for (int _i = 0; _i <= (index); _i++) { \
        _sum += (arr)[_i];         \
    }                              \
    _sum;                          \
})


#endif // GUARD_CONFIG_DEXNAV_H
