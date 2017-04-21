#include "BlockInfestedLeaves.h"

#include "mcpe/item/ItemInstance.h"
#include "mcpe/util/BlockPos.h"
#include "mcpe/level/BlockSource.h"
#include "mcpe/item/Item.h"
#include "mcpe/entity/player/Player.h"
#include "mcpe/level/Level.h"
#include "mcpe/block/Block.h"

BlockInfestedLeaves::BlockInfestedLeaves(int id) : EntityBlock("blockInfestedLeaves", id, Material::getMaterial(MaterialType::PLANT)) {
	leavesFancy = true;
	setSolid(false);
	setPushesOutItems(true);
	renderLayer = 8;
	unknown = 0.8F;
	properties |= 0x2000020;
	blockEntityType = BlockEntityType::None;
}

int BlockInfestedLeaves::getRenderLayer(BlockSource& region, const BlockPos& pos) const {
	return Block::mLeaves->getRenderLayer(region, pos);
}

void BlockInfestedLeaves::infestLeafBlock(BlockSource& world, const BlockPos& pos) {
	/*IBlockState block = world.getBlockState(pos);

	if (block.getBlock().isLeaves(block, world, pos) && !block.getBlock().equals(ENBlocks.infestedLeaves)) {
		world.setBlockState(pos, ENBlocks.infestedLeaves.getDefaultState());

		TileInfestedLeaves tile = (TileInfestedLeaves) world.getTileEntity(pos);

		if (tile != null) {
			tile.setLeafBlock(block);
		}
	}*/
}

int BlockInfestedLeaves::getVariant(int meta) const {
	return 0;
}

ItemInstance BlockInfestedLeaves::asItemInstance(BlockSource& region, const BlockPos& pos, int meta) const {
	return ItemInstance(this, 1, 0);
}

Color BlockInfestedLeaves::getMapColor(BlockSource& region, const BlockPos& pos) const {
	return Color::WHITE; // todo
}

int BlockInfestedLeaves::getColor(BlockSource& region, const BlockPos& pos, unsigned char meta) const {
	return 0xFFFFFF; // todo
}

bool BlockInfestedLeaves::isSeasonTinted(BlockSource& region, const BlockPos& pos) const {
	return Block::mLeaves->isSeasonTinted(region, pos);
}

bool BlockInfestedLeaves::shouldRenderFace(BlockSource& region, const BlockPos& pos, signed char side, const AABB& aabb) const {
	return !leavesFancy && region.getBlock(pos) == this ? false : Block::shouldRenderFace(region, pos, side, aabb);
}

Block* BlockInfestedLeaves::onGraphicsModeChanged(bool fancyGfx, bool idk_b, bool fancyLeaves) {
	leavesFancy = fancyLeaves;
	renderLayer = fancyLeaves ? 8 : 3;
	mLightBlock[blockId] = 1;
	return Block::onGraphicsModeChanged(fancyGfx, idk_b, fancyLeaves);
}

void BlockInfestedLeaves::playerDestroy(Player* harvester, const BlockPos& pos, int aux) const {
	if(!(harvester->getLevel().isClientSide())) {
		ItemInstance* selected = harvester->getSelectedItem();
		if(selected != NULL && Item::mShears != NULL && selected->item == Item::mShears)
			popResource(harvester->getRegion(), pos, ItemInstance(this, 1, 0));
		
		//block entity stuff here eventually
	}
}