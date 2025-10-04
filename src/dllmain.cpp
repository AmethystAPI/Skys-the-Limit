#include "dllmain.hpp"
#include <mc/src/common/world/level/dimension/Dimension.hpp>
#include <mc/src/common/world/level/dimension/HeightRange.hpp>

SafetyHookInline _Dimension_$ctor;

Dimension* Dimension_$ctor(Dimension* self, void* a2, int dimensionID, HeightRange HeightRange, void* a5, std::string& dimName)
{
	// Set max height to 2048 blocks
	HeightRange.mMaxHeight = 2048;
	return _Dimension_$ctor.fastcall<Dimension*>(self, a2, dimensionID, HeightRange, a5, dimName);
}

// Ran when the mod is loaded into the game by AmethystRuntime
ModFunction void Initialize(AmethystContext& ctx, const Amethyst::Mod& mod)
{
	Amethyst::InitializeAmethystMod(ctx, mod);

	Amethyst::HookManager& hooks = Amethyst::GetHookManager();
	HOOK(Dimension, $ctor);
}
