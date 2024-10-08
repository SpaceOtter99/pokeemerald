#ifndef GUARD_CONFIG_DEXNAV_H
#define GUARD_CONFIG_DEXNAV_H


#define USE_DEXNAV_SEARCH_LEVELS      TRUE   /* WARNING: EXCEEDS SAVEBLOCK SPACE! YOU WILL NEED TO FREE UP SPACE */

// search parameters
#define DEXNAV_TIMEOUT                  900  //15 seconds is the time out. Max of 1092 seconds allowed
#define SNEAKING_PROXIMITY              5   //Tile amount
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

#endif // GUARD_CONFIG_DEXNAV_H
