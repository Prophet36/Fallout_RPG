#pragma once

#include <string>
#include "const.h"

enum e_consumable
{
	STIMPAK,
	SUPER_STIMPAK,
	MEDKIT,
	FOOD_CLEAN,
	FOOD_RADIATED,
	WATER_CLEAN,
	WATER_RADIATED,
	JET,
	PSYCHO,
	BUFFOUT,
	CONSUMABLE_COUNT
};

struct st_consumable
{
	std::string name;
	std::string description;
	int attribute_type;
	int magnitude;
	int duration;
	int value;
	double weight;
};

const st_consumable consumable[CONSUMABLE_COUNT]
{
	/*	Name				Description													Attribute	Magnitude	Duration	Value	Weight	*/
	{	"Stimpak",			"Healing hypo. Heals up to 10 HP.",							HEALTH,		10,			0,			20,		0.1		},
	{	"Super Stimpak",	"Advanced healing hypo. Heals up to 25 HP.",				HEALTH,		20,			0,			50,		0.25	},
	{	"Medkit",			"Basic medkit. Heals broken limbs and up to 5 HP.",			HEALTH,		5,			0,			15,		0.5		},
	{	"Cooked food",		"Cooked and edible foodstuff. Heals up to 2 HP.",			HEALTH,		2,			0,			3,		1		},
	{	"Raw food",			"Raw, unprepared foodstuff. Adds 20 RADS.",					RADS,		20,			0,			1,		1		},
	{	"Purified water",	"Purified water. Heals up to 2 HP.",						HEALTH,		2,			0,			5,		2		},
	{	"Irradiated water",	"Unpurified, irradiated water. Adds 20 RADS.",				RADS,		20,			0,			2,		2		},
	{	"Jet",				"Chemical drug. Boosts Agility for 5 turns.",				AGILITY,	2,			5,			10,		0.1		},
	{	"Psycho",			"Military combat booster. Boosts Perception for 5 turns.",	PERCEPTION,	2,			5,			10,		0.1		},
	{	"Buffout",			"Muscle enhancing drug. Boosts Strength for 5 turns.",		STRENGTH,	2,			5,			10,		0.1		}
};
