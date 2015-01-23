/*
 *  tmpltown.h
 *  BoE
 *
 *  Created by Celtic Minstrel on 24/04/09.
 *
 */

#ifndef BOE_DATA_TMPLTOWN_H
#define BOE_DATA_TMPLTOWN_H

#include <iosfwd>

#include "location.h"
#include "monster.h"
#include "simpletypes.h"
#include "regtown.h"

class cTemplTown {
public:
	class cCityBlock { // formerly city_block_type
	public:
		short type;
		short destroy_time;
		short alignment;
		short key_time;
		location where;
	};
	class cTerRect { // formerly city_ter_rect_type
	public:
		rectangle rect;
		ter_num_t ter_type;
		unsigned char hollow;
	};
	cCityBlock blocks[15];
	cTerRect ter_rects[10];
};

class cBigTemplTown : public cBigTown, cTemplTown {
	unsigned char _lighting[8][64];
public:
	ter_num_t& terrain(size_t x, size_t y);
	unsigned char& lighting(size_t i, size_t r);
	size_t max_dim() const;
	void writeTerrainTo(std::ostream& file);
	void readTerrainFrom(std::istream& file);
	explicit cBigTemplTown(cScenario& scenario, bool init_strings = false);
};

class cMedTemplTown : public cMedTown, cTemplTown {
	unsigned char _lighting[6][48];
public:
	ter_num_t& terrain(size_t x, size_t y);
	unsigned char& lighting(size_t i, size_t r);
	size_t max_dim() const;
	void writeTerrainTo(std::ostream& file);
	void readTerrainFrom(std::istream& file);
	explicit cMedTemplTown(cScenario& scenario, bool init_strings = false);
};

class cTinyTemplTown : public cTinyTown, cTemplTown {
	unsigned char _lighting[4][32];
public:
	ter_num_t& terrain(size_t x, size_t y);
	unsigned char& lighting(size_t i, size_t r);
	size_t max_dim() const;
	void writeTerrainTo(std::ostream& file);
	void readTerrainFrom(std::istream& file);
	explicit cTinyTemplTown(cScenario& scenario, bool init_strings = false);
};

// City blocks - I want to figure out how to use these sometime.

//struct city_block_type {
//	short block_type;
//	short block_destroy_time;
//	char block_alignment;
//	char block_key_time;
//	location block_loc;
//};
//
//struct city_ter_rect_type {
//	Rect what_rect;
//	unsigned char ter_type;
//	unsigned char hollow;
//};
//
//struct template_town_type {
//	creature_start_type creatures[30];
//	city_block_type city_block[15];
//	city_ter_rect_type city_ter_rect[10];
//};

#endif
