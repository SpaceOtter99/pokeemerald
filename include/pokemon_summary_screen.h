#ifndef GUARD_POKEMON_SUMMARY_SCREEN_H
#define GUARD_POKEMON_SUMMARY_SCREEN_H

#include "main.h"

extern u8 gLastViewedMonIndex;

extern const u8 gNotDoneYetDescription[];
extern const struct SpriteTemplate gSpriteTemplate_MoveTypes;
extern const struct CompressedSpriteSheet gSpriteSheet_MoveTypes;
extern const struct CompressedSpriteSheet gSpriteSheet_CategoryIcons;
extern const struct SpritePalette gSpritePal_CategoryIcons;
extern const struct SpriteTemplate gSpriteTemplate_CategoryIcons;

void ShowPokemonSummaryScreen(u8 mode, void *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void));
void ShowSelectMovePokemonSummaryScreen(struct Pokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void), u16 newMove);
void ShowPokemonSummaryScreenHandleDeoxys(u8 mode, struct BoxPokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void));
u8 GetMoveSlotToReplace(void);
void SummaryScreen_SetAnimDelayTaskId(u8 taskId);

// The Pokémon Summary Screen can operate in different modes. Certain features,
// such as move re-ordering, are available in the different modes.
enum PokemonSummaryScreenMode
{
    SUMMARY_MODE_NORMAL,
    SUMMARY_MODE_LOCK_MOVES,
    SUMMARY_MODE_BOX,
    SUMMARY_MODE_SELECT_MOVE,
};

static const u8 sContestCategoryToOamPaletteNum[CONTEST_CATEGORIES_COUNT] =
{
    [CONTEST_CATEGORY_COOL] = 13,
    [CONTEST_CATEGORY_BEAUTY] = 14,
    [CONTEST_CATEGORY_CUTE] = 14,
    [CONTEST_CATEGORY_SMART] = 15,
    [CONTEST_CATEGORY_TOUGH] = 13,
};

#endif // GUARD_POKEMON_SUMMARY_SCREEN_H
