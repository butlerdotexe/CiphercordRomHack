#include "constants/spreads.h"

const struct TrainerMonSpread gSets[] = {
	// Trash trainers
	[SPREAD_0_IV_EV] =
	{
		.EVs = {},
		.IVs = {},
		.nature = NATURE_HARDY
	},

	[SPREAD_10_IV_0_EV] =
	{
		.EVs = {},
		.IVs = {10, 10, 10, 10, 10, 10},
		.nature = NATURE_HARDY
	},
	
	[SPREAD_15_IV_0_EV] =
	{
		.EVs = {},
		.IVs = {15, 15, 15, 15, 15, 15},
		.nature = NATURE_HARDY
	},
	
	[SPREAD_25_IV_0_EV] =
	{
		.EVs = {},
		.IVs = {25, 25, 25, 25, 25, 25},
		.nature = NATURE_HARDY
	},
	
	[SPREAD_31_IV_0_EV] =
	{
		.EVs = {},
		.IVs = {31, 31, 31, 31, 31, 31},
		.nature = NATURE_HARDY
	},
	
	[SPREAD_31_IV_20_EV] =
	{
		.EVs = {20, 20, 20, 20, 20, 20},
		.IVs = {31, 31, 31, 31, 31, 31},
		.nature = NATURE_HARDY
	},
	
	[SPREAD_31_IV_40_EV] =
	{
		.EVs = {40, 40, 40, 40, 40, 40},
		.IVs = {31, 31, 31, 31, 31, 31},
		.nature = NATURE_HARDY
	},
	
	[SPREAD_31_IV_60_EV] =
	{
		.EVs = {60, 60, 60, 60, 60, 60},
		.IVs = {31, 31, 31, 31, 31, 31},
		.nature = NATURE_HARDY
	},
	
	[SPREAD_31_IV_80_EV] =
	{
		.EVs = {80, 80, 80, 80, 80, 80},
		.IVs = {31, 31, 31, 31, 31, 31},
		.nature = NATURE_HARDY
	},
	// Generic spreads
	[SPREAD_31_IV_ATK_SPEED_JOLLY] =
	{
		.EVs = {
			  4,	// HP
			252,	// Attack
			  0,	// Defense
			252,	// Speed
			  0,	// Special Attack
			  0		// Special Defense	
		},
		.IVs = {31, 31, 31, 31, 31, 31},
		.nature = NATURE_JOLLY
	},
	
	[SPREAD_31_IV_ATK_SPEED_ADAMANT] =
	{
		.EVs = {
			  4,	// HP
			252,	// Attack
			  0,	// Defense
			252,	// Speed
			  0,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {31, 31, 31, 31, 31, 31},
		.nature = NATURE_ADAMANT
	},
	
	[SPREAD_31_IV_HP_ATK_ADAMANT] =
	{
		.EVs = {
			252,	// HP
			252,	// Attack
			  0,	// Defense
			  4,	// Speed
			  0,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {31, 31, 31, 31, 31, 31},
		.nature = NATURE_ADAMANT
	},

	[SPREAD_31_IV_HP_ATK_BRAVE] =
	{
		.EVs = {
			252,	// HP
			252,	// Attack
			  0,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			  4		// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			 0,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_BRAVE
	},
	
	[SPREAD_31_IV_SPATK_SPEED_TIMID] =
	{
		.EVs = {
			  0,	// HP
			  0,	// Attack
			  0,	// Defense
			252,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
			 0,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_TIMID
	},
	
	[SPREAD_31_IV_SPATK_SPEED_MODEST] =
	{
		.EVs = {
			  0,	// HP
			  0,	// Attack
			  0,	// Defense
			252,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
			 0,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_MODEST
	},
	
	[SPREAD_31_IV_HP_SPATK_MODEST] =
	{
		.EVs = {
			252,	// HP
			  0,	// Attack
			  0,	// Defense
			  4,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
			 0,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_MODEST
	},	
	
	[SPREAD_31_IV_HP_SPATK_QUIET] =
	{
		.EVs = {
			252,	// HP
			  0,	// Attack
			  4,	// Defense
			  0,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
			 0,		// Attack
			31,		// Defense
			 0,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_QUIET
	},
	
	[SPREAD_31_IV_HP_DEF_IMPISH] =
	{
		.EVs = {
			252,	// HP
			  0,	// Attack
			252,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			  4		// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_IMPISH
	},

	[SPREAD_31_IV_HP_DEF_BOLD] =
	{
		.EVs = {
			252,	// HP
			  0,	// Attack
			252,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			  4		// Special Defense
		},
		.IVs = {
			31,		// HP
			 0,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_BOLD
	},
	
	[SPREAD_31_IV_HP_SPDEF_CALM] =
	{
	.EVs = {
			252,	// HP
			  0,	// Attack
			  4,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			252		// Special Defense
		},
		.IVs = {
			31,		// HP
			 0,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_CALM
	},

	[SPREAD_31_IV_HP_SPDEF_CAREFUL] =
	{
	.EVs = {
			252,	// HP
			  0,	// Attack
			  4,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			252		// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_CAREFUL
	},
	// Hidden Power Spreads
	[SPREAD_HP_FIRE_TIMID] =
	{
		.EVs = {
			  4,	// HP
			  0,	// Attack
			  0,	// Defense
			252,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
			 0,		// Attack
			31,		// Defense
			30,		// Speed
			30,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_TIMID
	},
	
	[SPREAD_HP_FIRE_MODEST] =
	{
		.EVs = {
			  4,	// HP
			  0,	// Attack
			  0,	// Defense
			252,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
			 0,		// Attack
			31,		// Defense
			30,		// Speed
			30,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_MODEST
	},
	
	[SPREAD_HP_FIRE_QUIET] =
	{
		.EVs = {
			  4,	// HP
			  0,	// Attack
			  0,	// Defense
			252,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
			 0,		// Attack
			31,		// Defense
			 0,		// Speed
			30,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_QUIET
	},
	
	[SPREAD_HP_ICE_TIMID] =
	{
		.EVs = {
			  4,	// HP
			  0,	// Attack
			  0,	// Defense
			252,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
			 0,		// Attack
			30,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_TIMID
	},
	
	[SPREAD_HP_ICE_MODEST] =
	{
		.EVs = {
			  4,	// HP
			  0,	// Attack
			  0,	// Defense
			252,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
			 0,		// Attack
			30,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_MODEST
	},
	
	[SPREAD_HP_ICE_QUIET] =
	{
		.EVs = {
			252,	// HP
			  0,	// Attack
			  4,	// Defense
			  0,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
			 0,		// Attack
			30,		// Defense
			 1,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_QUIET
	},
	[SPREAD_HP_GRASS_TIMID] =
	{
		.EVs = {
			  4,	// HP
			  0,	// Attack
			  0,	// Defense
			252,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			30,		// HP
			 0,		// Attack
			31,		// Defense
			31,		// Speed
			30,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_TIMID
	},
	
	[SPREAD_HP_GRASS_MODEST] =
	{
		.EVs = {
			  4,	// HP
			  0,	// Attack
			  0,	// Defense
			252,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			30,		// HP
			 0,		// Attack
			31,		// Defense
			31,		// Speed
			30,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_MODEST
	},
	
	[SPREAD_HP_GRASS_QUIET] = {
		.EVs = {
			252,	// HP
			  0,	// Attack
			  4,	// Defense
			  0,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			30,		// HP
			 0,		// Attack
			31,		// Defense
			 1,		// Speed
			30,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_QUIET
	},

	[SPREAD_HP_FIGHTING_TIMID] = {
		.EVs = {
			  4,	// HP
			  0,	// Attack
			  0,	// Defense
			252,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			30,		// HP
			30,		// Attack
			30,		// Defense
			30,		// Speed
			30,		// Special Attack
			30		// Special Defense
		},
		.nature = NATURE_QUIET
	},
	
	// Specialised spreads

	[SPREAD_ROXANNE_ONE_MON] = {
		.EVs = {
			  0,	// HP
			  0,	// Attack
			  0,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			25,		// HP
			25,		// Attack
			25,		// Defense
			25,		// Speed
			25,		// Special Attack
			25		// Special Defense
		},
		.nature = NATURE_RELAXED
	},

	[SPREAD_ROXANNE_NOSEPASS] = {
		.EVs = {
			244,	// HP
			  0,	// Attack
			 92,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			168		// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_CAREFUL
	},
	[SPREAD_BRAWLY_ONE_MON] = {
		.EVs = {
			  0,	// HP
			  0,	// Attack
			  0,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_ADAMANT
	},
	[SPREAD_ARCHIE_ONE_MON] = {
		.EVs = {
			  20,	// HP
			  0,	// Attack
			  0,	// Defense
			  20,	// Speed
			  0,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_HARDY
	},
	[SPREAD_WATTSON_SPECIAL] = {
		.EVs = {
			  0,	// HP
			  0,	// Attack
			  0,	// Defense
			252,	// Speed
			  0,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	 0,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_MODEST
	},
	[SPREAD_FLANNERY_SPECIAL] = {
		.EVs = {
			  0,	// HP
			  0,	// Attack
			 80,	// Defense
			 80,	// Speed
			252,	// Special Attack
			 80		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	 0,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_MODEST
	},
	[SPREAD_FLANNERY_MIXED] = {
		.EVs = {
			  4,	// HP
			252,	// Attack
			  0,	// Defense
			  0,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_RASH
	},
	[SPREAD_CHANSEY] = {
		.EVs = {
			  4,	// HP
			  0,	// Attack
			252,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			252		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	 0,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_BOLD
	},
	[SPREAD_31_IV_ATK_SPEED_NAIVE]  = {
		.EVs = {
			  0,	// HP
			252,	// Attack
			  0,	// Defense
			252,	// Speed
			  4,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_NAIVE
	},
	[SPREAD_31_IV_HP_ATK_MIXED]  = {
		.EVs = {
			252,	// HP
			252,	// Attack
			  0,	// Defense
			  0,	// Speed
			  4,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_NAIVE
	},
	[SPREAD_31_IV_HP_SPEED_TIMID]  = {
		.EVs = {
			252,	// HP
			  0,	// Attack
			  0,	// Defense
			252,	// Speed
			  0,	// Special Attack
			  4		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	 0,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_TIMID
	},
	[SPREAD_31_IV_SPATK_SPEED_HASTY]  = {
		.EVs = {
			  0,	// HP
			  4,	// Attack
			  0,	// Defense
			252,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_HASTY
	},
	[SPREAD_31_IV_HP_DEF_SPDEF_SASSY]  = {
		.EVs = {
			252,	// HP
			  0,	// Attack
			104,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			152		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	 0,		// Attack
			31,		// Defense
			 0,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_SASSY
	},
	[SPREAD_31_IV_DEF_SPATK]  = {
		.EVs = {
			  0,	// HP
			  0,	// Attack
			252,	// Defense
			  0,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	 0,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_MODEST
	},
	[SPREAD_31_IV_ATK_SPDEF]  = {
		.EVs = {
			  4,	// HP
			252,	// Attack
			  0,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			252		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_ADAMANT
	},
	[SPREAD_31_IV_ATK_SPEED_NAUGHTY]  = {
		.EVs = {
			  0,	// HP
			252,	// Attack
			  0,	// Defense
			252,	// Speed
			  4,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_NAUGHTY
	},
	[SPREAD_31_IV_HP_SPEED_JOLLY]  = {
		.EVs = {
			252,	// HP
			  0,	// Attack
			  0,	// Defense
			252,	// Speed
			  0,	// Special Attack	
			  4		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_JOLLY
	},
	[SPREAD_HP_FIRE_MODEST_BULKY]  = {
		.EVs = {
			252,	// HP
			  0,	// Attack
			  0,	// Defense
			  0,	// Speed
			252,	// Special Attack	
			  4		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	 0,		// Attack
			31,		// Defense
			30,		// Speed
			30,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_MODEST
	},
	[SPREAD_LYCANROC_MIDDAY]  = {
		.EVs = {
			192,	// HP
			252,	// Attack
			  0,	// Defense
			 64,	// Speed
			  0,	// Special Attack	
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_JOLLY
	},
	[SPREAD_STAKATAKA]  = {
		.EVs = {
			252,	// HP
			252,	// Attack
			  0,	// Defense
			  0,	// Speed
			  0,	// Special Attack	
			  4		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	31,		// Attack
			15,		// Defense
			 0,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_LONELY
	},
	[SPREAD_31_IV_HP_SPATK_MIXED]  = {
		.EVs = {
			252,	// HP
			  4,	// Attack
			  0,	// Defense
			  0,	// Speed
			252,	// Special Attack
			  0		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_QUIET
	},
	[SPREAD_ROCK_POLISH_GROUDON]  = {
		.EVs = {
			128,	// HP
			  0,	// Attack
			 52,	// Defense
			128,	// Speed
			  0,	// Special Attack
			200		// Special Defense
		},
		.IVs = {
			31,		// HP
		  	31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_JOLLY
	},
	[SPREAD_31_IV_DEF_SDF_SPA_CALM] =
	{
	.EVs = {
			  0,	// HP
			  0,	// Attack
			128,	// Defense
			  0,	// Speed
			252,	// Special Attack
			128	// Special Defense
		},
		.IVs = {
			31,		// HP
			 0,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_CALM
	},
	[SPREAD_FALLEN_LINOONE] =
	{
	.EVs = {
			 60,	// HP
			252,	// Attack
			  0,	// Defense
			196,	// Speed
			  0,	// Special Attack
			  0	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_JOLLY
	},
	[SPREAD_31_IV_DEF_SPDEF_CALM] =
	{
	.EVs = {
			  4,	// HP
			  0,	// Attack
			252,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			252	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_CALM
	},
	[SPREAD_31_IV_DEF_SPDEF_BOLD] =
	{
	.EVs = {
			  4,	// HP
			  0,	// Attack
			252,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			252	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_BOLD
	},
	[SPREAD_SEMI_1] =
	{
	.EVs = {
			  0,	// HP
			  0,	// Attack
			  0,	// Defense
			128,	// Speed
			128,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_TIMID
	},
	[SPREAD_SEMI_2] =
	{
	.EVs = {
			  0,	// HP
			  0,	// Attack
			 64,	// Defense
			  0,	// Speed
			128,	// Special Attack
			 64  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_CALM
	},
	[SPREAD_SEMI_3] =
	{
	.EVs = {
			  0,	// HP
			128,	// Attack
			 64,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			 64  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_ADAMANT
	},
	[SPREAD_SEMI_4] =
	{
	.EVs = {
			 64,	// HP
			128,	// Attack
			  0,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			 64  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_JOLLY
	},
	[SPREAD_SEMI_5] =
	{
	.EVs = {
			  0,	// HP
			128,	// Attack
			  0,	// Defense
			128,	// Speed
			  0,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_JOLLY
	},
	[SPREAD_PENTA_1] =
	{
	.EVs = {
			  4,	// HP
			252,	// Attack
			252,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_IMPISH
	},
	[SPREAD_PENTA_2] =
	{
	.EVs = {
			  4,	// HP
			  0,	// Attack
			124,	// Defense
			  0,	// Speed
			252,	// Special Attack
			124  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_CALM
	},
	[SPREAD_PENTA_3] =
	{
	.EVs = {
			  4,	// HP
			252,	// Attack
			  0,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			252  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_JOLLY
	},
	[SPREAD_BRAIN_DRAG] =
	{
	.EVs = {
			132,	// HP
			  0,	// Attack
			  0,	// Defense
			124,	// Speed
			252,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_MODEST
	},
	[SPREAD_ATK_DEF_ADAMANT] =
	{
	.EVs = {
			  4,	// HP
			252,	// Attack
			252,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_ADAMANT
	},
	[SPREAD_CATMOON_POSTGAME1] =
	{
	.EVs = {
			 32,	// HP
			  0,	// Attack
			  0,	// Defense
			224,	// Speed
			252,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_JOLLY
	},
	[SPREAD_CATMOON_POSTGAME2] =
	{
	.EVs = {
			128,	// HP
			252,	// Attack
			  0,	// Defense
			128,	// Speed
			  0,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_ADAMANT
	},
	[SPREAD_CATMOON_POSTGAME3] =
	{
	.EVs = {
			  0,	// HP
			176,	// Attack
			  0,	// Defense
			192,	// Speed
			140,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_NAUGHTY
	},
	[SPREAD_CATMOON_POSTGAME4] =
	{
	.EVs = {
			128,	// HP
			  0,	// Attack
			  0,	// Defense
			128,	// Speed
			252,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_MODEST
	},
	[SPREAD_CATMOON_POSTGAME5] =
	{
	.EVs = {
			148,	// HP
			252,	// Attack
			  0,	// Defense
			 72,	// Speed
			  0,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_ADAMANT
	},
	[SPREAD_31_IV_HP_DEF_ADAMANT] =
	{
	.EVs = {
			252,	// HP
			  0,	// Attack
			252,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_ADAMANT
	},
	[SPREAD_EXALT_POSTGAME_1] =
	{
	.EVs = {
			128,	// HP
			  0,	// Attack
			  0,	// Defense
			252,	// Speed
			128,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_TIMID
	},
	[SPREAD_EXALT_POSTGAME_2] =
	{
	.EVs = {
			160,	// HP
			 92,	// Attack
			 84,	// Defense
			172,	// Speed
			  0,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_IMPISH
	},
	[SPREAD_EXALT_POSTGAME_3] =
	{
	.EVs = {
			168,	// HP
			124,	// Attack
			 56,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			160  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_BRAVE
	},
	[SPREAD_EXALT_POSTGAME_4] =
	{
	.EVs = {
			164,	// HP
			 92,	// Attack
			  0,	// Defense
			252,	// Speed
			  0,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			30,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_LONELY
	},
	[SPREAD_31_IV_HP_DEF_CALM] =
	{
	.EVs = {
			252,	// HP
			  0,	// Attack
			252,	// Defense
			  0,	// Speed
			  4,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_CALM
	},
	[SPREAD_31_IV_HP_SPA_BOLD] =
	{
	.EVs = {
			252,	// HP
			  0,	// Attack
			  4,	// Defense
			  0,	// Speed
			252,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_BOLD
	},
	[SPREAD_31_BASIL_POLITOED] =
	{
	.EVs = {
			252,	// HP
			  0,	// Attack
			  4,	// Defense
			  0,	// Speed
			252,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			 0,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_QUIET
	},
	[SPREAD_31_ATK_DEF_ADAMANT] =
	{
	.EVs = {
			  4,	// HP
			252,	// Attack
			252,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_ADAMANT
	},
	[SPREAD_31_SPA_SPDEF_BOLD] =
	{
	.EVs = {
			  0,	// HP
			  0,	// Attack
			  4,	// Defense
			  0,	// Speed
			252,	// Special Attack
			252  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_BOLD
	},
	[SPREAD_COLONEL_1] =
	{
	.EVs = {
			 80,	// HP
			252,	// Attack
			  0,	// Defense
			176,	// Speed
			  0,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_ADAMANT
	},
	[SPREAD_ROSA_1] =
	{
	.EVs = {
			252,	// HP
			  0,	// Attack
			 64,	// Defense
			  0,	// Speed
			  0,	// Special Attack
			192  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_CAREFUL
	},
	[SPREAD_ROSA_2] =
	{
	.EVs = {
			  0,	// HP
			252,	// Attack
			  0,	// Defense
			  0,	// Speed
			252,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_BRAVE
	},
	[SPREAD_Yurtz_1] =
	{
	.EVs = {
			252,	// HP
			  0,	// Attack
			  0,	// Defense
			  0,	// Speed
			 56,	// Special Attack
			200  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_QUIET
	},
	[SPREAD_Yurtz_2] =
	{
	.EVs = {
			248,	// HP
			  0,	// Attack
			112,	// Defense
			 44,	// Speed
			104,	// Special Attack
			  0  	// Special Defense
		},
		.IVs = {
			31,		// HP
			31,		// Attack
			31,		// Defense
			31,		// Speed
			31,		// Special Attack
			31		// Special Defense
		},
		.nature = NATURE_MODEST
	},
};
