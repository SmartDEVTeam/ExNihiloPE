#include "ExNihiloPERecipes.h"

#include "blocks/ENBlocks.h"
#include "items/ENItems.h"
#include "items/ItemResource.h"
#include "items/ItemCookedSilkworm.h"
#include "items/tools/HammerBase.h"
#include "items/tools/CrookBase.h"

#include "mcpe/block/Block.h"
#include "mcpe/item/Item.h"

Recipes* ExNihiloPERecipes::_Instance;
std::vector<Recipes::Type> ExNihiloPERecipes::_ingredients;

void ExNihiloPERecipes::initRecipes(Recipes *recipes) {	
	_Instance = recipes;
	
	pushIngredient(Block::mWoodPlanks, 'x');
	pushIngredient(Item::mStick, 'y');
	addRecipe(ENItems::hammerWood->itemId, 1, 0, { " x ", " yx", "y  "});

	pushIngredient(Block::mCobblestone, 'x');
	pushIngredient(Item::mStick, 'y');
	addRecipe(ENItems::hammerStone->itemId, 1, 0, { " x ", " yx", "y  "});

	pushIngredient(Item::mIronIngot, 'x');
	pushIngredient(Item::mStick, 'y');
	addRecipe(ENItems::hammerIron->itemId, 1, 0, { " x ", " yx", "y  "});

	pushIngredient(Item::mGoldIngot, 'x');
	pushIngredient(Item::mStick, 'y');
	addRecipe(ENItems::hammerGold->itemId, 1, 0, { " x ", " yx", "y  "});

	pushIngredient(Item::mDiamond, 'x');
	pushIngredient(Item::mStick, 'y');
	addRecipe(ENItems::hammerDiamond->itemId, 1, 0, { " x ", " yx", "y  "});

	// Crook
	pushIngredient(Item::mStick, 'n');
	addRecipe(ENItems::crookWood->itemId, 1, 0, {"nn", " n", " n"});

	pushIngredient(Item::mBone, 'n');
	addRecipe(ENItems::crookBone->itemId, 1, 0, {"nn", " n", " n"});
	
	/* BLOCKS */
	// Barrel
	pushIngredient(Block::mWoodPlanks, 'n');
	pushIngredient(Block::mWoodenSlab, 'm');
	addRecipe(ENBlocks::barrelWood->blockId, 1, 0, {"n n", "n n", "nmn"});

}

void ExNihiloPERecipes::initFurnaceRecipes(FurnaceRecipes *recipes) {
	recipes->addFurnaceRecipeAuxData(ENItems::resources->itemId, 2, ItemInstance(ENItems::cookedSilkworm->itemId, 1, 0));
}

void ExNihiloPERecipes::pushIngredient(Item *item, char letter) {
	pushIngredient(item->itemId, 0, letter);
}

void ExNihiloPERecipes::pushIngredient(Block *block, char letter) {
	Recipes::Type type {NULL, block, ItemInstance(*block, 1, 0), letter};
	_ingredients.push_back(type);
}

void ExNihiloPERecipes::pushIngredient(short id, short data, char letter) {
	Recipes::Type type {Item::mItems[id], NULL, ItemInstance(id, 1, data), letter};
	_ingredients.push_back(type);
} 

void ExNihiloPERecipes::addRecipe(short outputId, short outputCount, short outputData, const std::vector<std::string> &shape) {
	_Instance->addShapedRecipe(ItemInstance(outputId, outputCount, outputData), shape, _ingredients);	
	_ingredients.clear();
}

