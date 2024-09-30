#include "global.h"
#include "main.h"
#include "dns.h"
#include "palette.h"
#include "start_menu.h"
#include "overworld.h"
#include "battle_main.h"
#include "rtc.h"
#include "constants/map_types.h"
#include "constants/rgb.h"

  /*******************************************************/
 /*********    Day and Night Configuration     **********/
/********************************************************
 * You can customize the DNS by editing the following   *
 * timelapses and the filters used to change the        *
 * palette colours.                                     *
 * In addition to that, you can also configure which    *
 * palettes are affected by the system, as well as      *
 * establishing sprite palettes exceptions by its TAG.  *
 * 
 * It is highly recommended to read the following config*
 * options, to understand how the dns works.            *
 * ******************************************************/

/* Custom Time Filters */
#include <stdint.h>

// Define the structure for time and colour mapping
struct TimeToFilter {
    u16 time;       // Time represented as hhmm
    u16 colour;     // Colour
};

#define DNS_HOUR(t) (t*100)
/* Start and end hour of the lighting system.
 * This system is generally used for building's windows. */
#define LIGHTING_START_HOUR    EVENING_HOUR_BEGIN
#define LIGHTING_END_HOUR      MORNING_HOUR_BEGIN

// Example constant list of times and colours
const struct TimeToFilter timeToFilterList[] = {
    // Midnight
    { 0 , RGB2(16,16,10) }, 
    // Sunrise
    { DNS_HOUR(MORNING_HOUR_BEGIN), RGB2(16, 16, 10) }, 
    { DNS_HOUR(MORNING_HOUR_BEGIN)+100, RGB2(0, 0, 10) },
    { DNS_HOUR(DAY_HOUR_BEGIN), RGB2(0, 0, 0) },
    // Midday
    { 1200, RGB2(0, 0, 0) },
    // Sunset
    { DNS_HOUR(EVENING_HOUR_BEGIN), RGB2(0, 0, 0)},
    { DNS_HOUR(EVENING_HOUR_BEGIN)+30, RGB2(0, 7, 14)},
    { DNS_HOUR(EVENING_HOUR_BEGIN)+100, RGB2(0, 14, 14)},
    // Nightfall
    { DNS_HOUR(NIGHT_HOUR_BEGIN), RGB2(16, 16, 10)},
    { DNS_HOUR(HOURS_PER_DAY), RGB2(16,16,10)},
};

#define NUM_ENTRIES (sizeof(timeToFilterList) / sizeof(timeToFilterList[0]))

// Helper function to linearly interpolate between two colors
u16 lerpColour(u16 colour1, u16 colour2, float t) {
    u8 r1 = GET_R(colour1);
    u8 g1 = GET_G(colour1);
    u8 b1 = GET_B(colour1);
    
    u8 r2 = GET_R(colour2);
    u8 g2 = GET_G(colour2);
    u8 b2 = GET_B(colour2);
    
    u8 r = r1 + t * (r2 - r1);
    u8 g = g1 + t * (g2 - g1);
    u8 b = b1 + t * (b2 - b1);
    
    return RGB2(r,g,b);
}

// Function to find the interpolated colour based on the time
u16 getColourForTime(u16 currentTime) {
    DebugPrintf("Starting getColourForTime at %d\n{", currentTime);
    // Initialize pointers to store closest times
    const struct TimeToFilter* lowerTime = NULL;
    const struct TimeToFilter* upperTime = NULL;

    // Loop through the list to find the closest lower and upper times
    for (int i = 0; i < NUM_ENTRIES; i++) {
        DebugPrintf("%d: %x,   ", timeToFilterList[i].time, timeToFilterList[i].colour);
        if (timeToFilterList[i].time <= currentTime) {
            if (!lowerTime || timeToFilterList[i].time > lowerTime->time) {
                lowerTime = &timeToFilterList[i];
            }
        }
        if (timeToFilterList[i].time >= currentTime) {
            if (!upperTime || timeToFilterList[i].time < upperTime->time) {
                upperTime = &timeToFilterList[i];
            }
        }
    }
    DebugPrintf("}\nChose lowerTime {%d : %x} and upperTime {%d: %x}", lowerTime->time, lowerTime->colour, upperTime->time, upperTime->colour);

    // If no lower or upper bound is found, return black (default case)
    if (!lowerTime || !upperTime) {
        return RGB2(0,0,0);
    }

    // If current time matches an exact time in the list, return its colour
    if (lowerTime->time == upperTime->time) {
        return lowerTime->colour;
    }

    // Compute the interpolation factor between the lower and upper time
    float t = (float)(currentTime - lowerTime->time) / (upperTime->time - lowerTime->time);

    // Return the interpolated colour
    return lerpColour(lowerTime->colour, upperTime->colour, t);
}

/* Start and end hour of the lightning system.
 * This system is generally used for building's windows. */
#define LIGHTNING_START_HOUR    NIGHTFALL_END_HOUR
#define LIGHTNING_END_HOUR      MIDNIGHT_END_HOUR

/* This array contains the colours used for the windows or          *
 * other tiles that have to be illuminated at night.                *
 * You can add or remove light slots as you whish, each entry       *
 * requires the paletteNum and the colourNum of each colour slot,   *
 * as well as the RGB 15 bit colour that's gonna be used as         *
 * "light colour".                                                  */
const struct LightingColour gLightingColours[] =
{
    {
        .paletteNum = 1,
        .colourNum = 9,
        .lightColour = RGB2(30, 30, 5),
    },
    {
        .paletteNum = 1,
        .colourNum = 10,
        .lightColour = RGB2(29, 29, 5),
    },
    {
        .paletteNum = 5,
        .colourNum = 9,
        .lightColour = RGB2(30, 30, 5),
    },
    {
        .paletteNum = 5,
        .colourNum = 10,
        .lightColour = RGB2(29, 29, 5),
    },
    {
        .paletteNum = 5,
        .colourNum = 3,
        .lightColour = RGB2(30, 30, 5),
    },
    {
        .paletteNum = 5,
        .colourNum = 4,
        .lightColour = RGB2(29, 29, 5),
    },
    {
        .paletteNum = 6,
        .colourNum = 9,
        .lightColour = RGB2(30, 30, 5),
    },
    {
        .paletteNum = 6,
        .colourNum = 10,
        .lightColour = RGB2(29, 29, 5),
    },
    {
        .paletteNum = 8,
        .colourNum = 9,
        .lightColour = RGB2(30, 30, 5),
    },
    {
        .paletteNum = 8,
        .colourNum = 10,
        .lightColour = RGB2(29, 29, 5),
    },
};

/* Maptypes that are not affected by DNS */
const u8 gDnsMapExceptions[] =
{
    MAP_TYPE_NONE,
    MAP_TYPE_INDOOR,
    MAP_TYPE_UNDERGROUND,
    MAP_TYPE_SECRET_BASE,
};

/* Configure each palette slot to be affected or not by DNS *
 * while you are in the overworld.                          */
const struct DnsPalExceptions gOWPalExceptions = 
{
    .pal = {
        DNS_PAL_ACTIVE,     //0
        DNS_PAL_ACTIVE,     //1
        DNS_PAL_ACTIVE,     //2
        DNS_PAL_ACTIVE,     //3
        DNS_PAL_ACTIVE,     //4
        DNS_PAL_ACTIVE,     //5
        DNS_PAL_ACTIVE,     //6
        DNS_PAL_ACTIVE,     //7
        DNS_PAL_ACTIVE,     //8
        DNS_PAL_ACTIVE,     //9
        DNS_PAL_ACTIVE,     //10
        DNS_PAL_ACTIVE,     //11
        DNS_PAL_ACTIVE,     //12
        DNS_PAL_EXCEPTION,  //13
        DNS_PAL_EXCEPTION,  //14
        DNS_PAL_EXCEPTION,  //15
        DNS_PAL_ACTIVE,     //16
        DNS_PAL_ACTIVE,     //17
        DNS_PAL_ACTIVE,     //18
        DNS_PAL_ACTIVE,     //19
        DNS_PAL_ACTIVE,     //20
        DNS_PAL_ACTIVE,     //21
        DNS_PAL_ACTIVE,     //22
        DNS_PAL_ACTIVE,     //23
        DNS_PAL_ACTIVE,     //24
        DNS_PAL_ACTIVE,     //25
        DNS_PAL_ACTIVE,     //26
        DNS_PAL_ACTIVE,     //27
        DNS_PAL_ACTIVE,     //28
        DNS_PAL_ACTIVE,     //29
        DNS_PAL_ACTIVE,     //30
        DNS_PAL_ACTIVE,     //31
    }
};

/* Configure each palette slot to be affected or not by DNS *
 * while in combat.                                         */
const struct DnsPalExceptions gCombatPalExceptions =  
{
    .pal = {
        DNS_PAL_EXCEPTION,  //0
        DNS_PAL_EXCEPTION,  //1
        DNS_PAL_ACTIVE,     //2
        DNS_PAL_ACTIVE,     //3
        DNS_PAL_ACTIVE,     //4
        DNS_PAL_EXCEPTION,  //5
        DNS_PAL_ACTIVE,     //6
        DNS_PAL_ACTIVE,     //7
        DNS_PAL_ACTIVE,     //8
        DNS_PAL_ACTIVE,     //9
        DNS_PAL_ACTIVE,     //10
        DNS_PAL_ACTIVE,     //11
        DNS_PAL_ACTIVE,     //12
        DNS_PAL_ACTIVE,     //13
        DNS_PAL_ACTIVE,     //14
        DNS_PAL_ACTIVE,     //15
        DNS_PAL_EXCEPTION,  //16
        DNS_PAL_EXCEPTION,  //17
        DNS_PAL_EXCEPTION,  //18
        DNS_PAL_EXCEPTION,  //19
        DNS_PAL_EXCEPTION,  //20
        DNS_PAL_EXCEPTION,  //21
        DNS_PAL_EXCEPTION,  //22
        DNS_PAL_EXCEPTION,  //23
        DNS_PAL_EXCEPTION,  //24
        DNS_PAL_EXCEPTION,  //25
        DNS_PAL_EXCEPTION,  //26
        DNS_PAL_EXCEPTION,  //27
        DNS_PAL_EXCEPTION,  //28
        DNS_PAL_EXCEPTION,  //29
        DNS_PAL_EXCEPTION,  //30
        DNS_PAL_EXCEPTION,  //31
    }
};

/*************   SpritePalette Dns exceptions by TAG   **************
 * If you are using any dynamic sprite palette allocation system,   *
 * you will most likely want to use this system to avoid certain    *
 * palette tags to be "banned" from dns, as the palettes may get    *
 * loaded in different slots each time.                             */
const u16 gPaletteTagExceptions[] =
{
    0xD6FF, //TAG_HEALTHBOX_PAL
    0xD704, //TAG_HEALTHBAR_PAL
    0xD710, //TAG_STATUS_SUMMARY_BAR_PAL
    0xD712, //TAG_STATUS_SUMMARY_BALLS_PAL
};

/***********************************************
 * --------- DNS CONFIGURATION END ----------- *
 * ******************************************* */


//Functions
static u16 DnsApplyFilterToColour(u16 colour, u16 filter);
static u16 DnsApplyProportionalFilterToColour(u16 colour, u16 filter);
static void DoDnsLightning();
static u16 GetDNSFilter();
static bool8 IsMapDNSException();
static bool8 IsSpritePaletteTagDnsException(u8 palNum);
static bool8 IsOverworld();
static bool8 IsCombat();
static bool8 IsLightActive();

//Dns palette buffer in EWRAM
ALIGNED(4) EWRAM_DATA static u16 sDnsPaletteDmaBuffer[512] = {0};


/* **************************************************** *
 * **************** D&N for pokeemerald *************** *
 * **************************************************** *
 * Based on Prime Dialga DNS for Pokemon GBA Games.     *
 * Additional credits to Andrea & Eing                  *
 * Author: Xhyz/Samu                                    *
 ****************************************************** */

//Called from TransferPlttBuffer
void DnsTransferPlttBuffer(void *src, void *dest)
{
    if ((IsOverworld() || IsCombat()) && !IsMapDNSException()) 
    {
        DmaCopy16(3, sDnsPaletteDmaBuffer, dest, PLTT_SIZE);
    }
    else
    {
        DmaCopy16(3, src, dest, PLTT_SIZE);
    }
}

/* Applies filter to palette colours, stores new palettes in EWRAM buffer.   *
 * It must be called from CB2 if the DNS wants to be used (similar to        *
 * TransferPlttBuffer)  in VBlank callbacks                                  */
void DnsApplyFilters()
{
    u8 palNum, colNum;
    u16 rgbFilter;
    struct DnsPalExceptions palExceptionFlags;

    rgbFilter = GetDNSFilter();

    palExceptionFlags = gMain.inBattle ? gCombatPalExceptions : gOWPalExceptions;   //Init pal exception slots

    for (palNum = 0; palNum < 32; palNum++)
        if (palExceptionFlags.pal[palNum] && (palNum < 15 || !IsSpritePaletteTagDnsException(palNum - 16)))
            for (colNum = 0; colNum < 16; colNum++) //Transfer filtered palette to buffer
                sDnsPaletteDmaBuffer[palNum * 16 + colNum] = DnsApplyProportionalFilterToColour(gPlttBufferFaded[palNum * 16 + colNum], rgbFilter);
        else
            for (colNum = 0; colNum < 16; colNum++)  //Transfers palette to buffer without filtering
                sDnsPaletteDmaBuffer[palNum * 16 + colNum] = gPlttBufferFaded[palNum * 16 + colNum];      

    if (!IsMapDNSException() && IsLightActive() && !gMain.inBattle)
        DoDnsLightning();
}

//Applies filter to a colour. Filters RGB channels are substracted from colour RGB channels.
//Based on Andrea's DNS filtering system 
/*
static u16 DnsApplyFilterToColour(u16 colour, u16 filter)
{
    u16 red, green, blue;

    red = (colour & 0x1F) - (filter & 0x1F);
    green = ((colour & 0x3E0) - (filter & 0x3E0)) >> 5;
    blue = ((colour & 0x7C00) - (filter & 0x7C00)) >> 10;

    return RGB2(red <= 31 ? red : 0, green <= 31 ? green : 0, blue <= 31 ? blue : 0);
}
*/

/*Alternative way to apply filter. Works similar to the first one, but colours are substracted PROPORTIONALLY.
This system is great if you want to avoid colours with low rgb channels getting donw to 0 too fast.
That's something that can easily happen with above Andrea's filtering system.*/
static u16 DnsApplyProportionalFilterToColour(u16 colour, u16 filter)
{
    u32 red, green, blue;

    red = (colour & 0x1F) * (0x1F - (filter & 0x1F)) >> 5;
    green = ((colour & 0x3E0) >> 5) * ((0x3E0 - (filter & 0x3E0)) >> 5) >> 5;
    blue = ((colour & 0x7C00) >> 10) * ((0x7C00 - (filter & 0x7C00)) >> 10) >> 5;

    return RGB2(red <= 31 ? red : 0, green <= 31 ? green : 0, blue <= 31 ? blue : 0);  
}

//returns the filter to use depending on RTC time.
static u16 GetDNSFilter()
{
    u8 hour = gLocalTime.hours;    
    u8 minutes = gLocalTime.minutes;   
    u16 convertedTime = (100 * hour) + minutes;

    DebugPrintf("Current Time: %d : %d (%d)", hour, minutes, convertedTime);

    return getColourForTime(convertedTime);
}

static void DoDnsLightning()
{
    u8 i;

    for (i = 0; i < sizeof(gLightingColours)/sizeof(gLightingColours[0]); i++)
    {
        u16 colourSlot = gLightingColours[i].paletteNum * 16 + gLightingColours[i].colourNum;
        
        if (gPaletteFade.active || gPlttBufferUnfaded[colourSlot] != 0x0000)
        {
            sDnsPaletteDmaBuffer[colourSlot] = gPlttBufferFaded[colourSlot];
            gPlttBufferUnfaded[colourSlot] = gLightingColours[i].lightColour;
        }
        else
        {
            sDnsPaletteDmaBuffer[colourSlot] = gLightingColours[i].lightColour;
        }
    }
}

//Returns Dns time lapse
/*
u8 GetDnsTimeLapse(u8 hour)
{
    if (hour < MIDNIGHT_END_HOUR)
        return DNS_TIME_MIDNIGHT;
    else if (hour < DAWN_END_HOUR)
        return DNS_TIME_DAWN;
    else if (hour < DAY_END_HOUR)
        return DNS_TIME_DAY;
    else if (hour < SUNSET_END_HOUR)
        return DNS_TIME_SUNSET;
    else if (hour < NIGHTFALL_END_HOUR)
        return DNS_TIME_NIGHTFALL;
    else 
        return DNS_TIME_NIGHT;
}
*/
//Checks if current map is affected by dns
static bool8 IsMapDNSException()
{
    u8 i;
    for (i=0; i < sizeof(gDnsMapExceptions)/sizeof(gDnsMapExceptions[0]); i++)
        if (gMapHeader.mapType == gDnsMapExceptions[i])
            return TRUE;
    return FALSE;
}

//Returns true if the palette should not be affected by DNS filtering
static bool8 IsSpritePaletteTagDnsException(u8 palNum)
{
    u8 i;

    for (i = 0; i < sizeof(gPaletteTagExceptions)/sizeof(gPaletteTagExceptions[0]); i++)
        if (GetSpritePaletteTagByPaletteNum(palNum) == gPaletteTagExceptions[i])
            return TRUE;
    return FALSE;
}

//Returns true if overworld is running
static bool8 IsOverworld()
{
    if (gMain.callback2 == CB2_Overworld || gMain.callback2 ==CB2_OverworldBasic)
        return TRUE;
    else
        return FALSE;
}

//Returns true if combat is running
static bool8 IsCombat()
{
    if (gMain.callback2 == BattleMainCB2)
        return TRUE;
    else
        return FALSE;
}

static bool8 IsLightActive()
{
    if (gLocalTime.hours >= LIGHTING_START_HOUR || gLocalTime.hours < LIGHTING_END_HOUR)
        return TRUE;
    return FALSE;
}
