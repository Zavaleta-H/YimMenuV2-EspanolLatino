#include "game/commands/PlayerCommand.hpp"

namespace YimMenu::Features
{
	class DeleteVehicle : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			if (auto ped = player.GetPed())
				Entity::DeleteNetwork(ped.GetVehicleObjectId());
		}
	};

	static DeleteVehicle _DeleteVehicle{"deleteveh", "Eliminar vehículo", "Elimina el vehículo en el que está el jugador"};
}