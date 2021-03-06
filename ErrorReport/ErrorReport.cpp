// ErrorReport.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "frozen/string.h"
#include "frozen/unordered_map.h"
#include <algorithm>

using namespace std;
static constexpr pair<frozen::string, int> inner1pair[]
{
	{ "name",{ 0 } },
{ "dummy1",{ 1 } },
{ "dummy2",{ 2 } }
};
static constexpr frozen::unordered_map<frozen::string, int, 3> inner1map = frozen::make_unordered_map(inner1pair);

static constexpr pair<frozen::string, int> inner2pair[]
{
	{ "lua_id",{ 0 } },
	{ "game_id",{ 1 } },
	{ "level",{ 2 } }
};
static constexpr frozen::unordered_map<frozen::string, int, 3> inner2map = frozen::make_unordered_map(inner2pair);

static constexpr pair<frozen::string, int> inner3pair[]
{
	{ "x",{ 0 } },
	{ "y",{ 1 } },
	{ "entity",{ 2 } }
};
static constexpr frozen::unordered_map<frozen::string, int, 3> inner3map = frozen::make_unordered_map(inner3pair);



static constexpr pair<frozen::string, frozen::unordered_map<frozen::string, int, 3>> outerpair[]
{
	{ "levels",{ inner1map } },
	{ "entities",{ inner2map } },
	{ "position_components",{ inner3map } },
};
static constexpr frozen::unordered_map<frozen::string, frozen::unordered_map<frozen::string, int, 3>, 3> outermap = frozen::make_unordered_map(outerpair);

int main()
{
	constexpr int this_causes_the_error = outermap.at("levels").at("name");
    return 0;
}

