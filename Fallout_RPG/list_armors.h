#pragma once

#include <string>
#include "const.h"

enum e_armor
{
	CLOTHES,
	BUNKER,
	LEATHER,
	WASTELAND,
	METAL,
	COMBAT,
	ALLOY,
	CARBON,
	POWERED,
	ALIEN,
	QUICKSILVER,
	ARMOR_COUNT
};

struct st_armor
{
	std::string name;
	std::string description;
	int reduction;
	int evasion;
	int protection;
	int value;
	double weight;
};

const st_armor armor[ARMOR_COUNT]
{
	/*	Name					Description													Reduction	Evasion	Protection	Value	Weight	*/
	{	"Plain clothing",		"Plain clothes.",											0,			2,		0,			2,		1		},
	{	"Bunker outfit",		"Outfit from fallout bunker.",								0,			2,		20,			10,		3		},
	{	"Leather armor",		"Sturdy leather armor.",									1,			1,		0,			20,		5		},
	{	"Wasteland armor",		"Hand made wasteland armor, protects from elements.",		2,			0,		30,			30,		5		},
	{	"Metal armor",			"Metal armor, heavy and durable.",							5,			-3,		0,			50,		10		},
	{	"Combat armor",			"Military combat armor.",									4,			-1,		20,			100,	7		},
	{	"Alloy armor",			"Advanced military armor, made from durable alloys.",		6,			-2,		0,			150,	8		},
	{	"Carbon-fiber armor",	"Advanced special forces armor, very light, yet durable.",	6,			0,		0,			250,	4		},
	{	"Powered armor",		"High-tech powered metal armor.",							10,			-3,		50,			500,	10		},
	{	"Alien armor",			"Human adapted Entirian armor.",							15,			-5,		100,		1000,	18		},
	{	"Quicksilver armor",	"Advanced Entirian armor, covers whole body.",				12,			0,		100,		2000,	2		}
};
