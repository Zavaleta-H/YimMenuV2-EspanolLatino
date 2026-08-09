#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/gta/Natives.hpp"

namespace YimMenu::Features
{
	class AllowHatsInVehicles : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			PED::SET_PED_RESET_FLAG(Self::GetPed().GetHandle(), 337, true);
		}
	};

	static AllowHatsInVehicles _AllowHatsInVehicles{"allowhatsinvehicles", "Permitir sombreros en vehículos", "Te permite mantener tus gorras o cascos dentro de vehículos"};
};
