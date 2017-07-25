#pragma once

#include "IHammer.h"

#include "mcpe/item/ToolItem.h"

class HammerBase : public ToolItem, public IHammer {
public:
	int miningLevel;
	
	HammerBase(const std::string&, int, int, Item::Tier);

	virtual int getMiningLevel(const ItemInstance&);
	virtual float getDestroySpeed(ItemInstance const&, Block const&) const;
	virtual bool canDestroySpecial(Block const&) const;
};