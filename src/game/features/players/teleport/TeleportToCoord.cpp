#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "core/commands/Vector3Command.hpp"

namespace YimMenu::Features
{
	static Vector3Command _PlayerTeleportCoordinate{"playertpcoord", "Coordenadas de teletransporte del jugador", "Las coordenadas a donde teletransportar al jugador"};

	class TeleportToCoord : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			player.TeleportTo(_PlayerTeleportCoordinate.GetState());
		}
	};

	static TeleportToCoord _TeleportToCoord{"tpplayertocoord", "Teletransportar jugador a coordenadas", "Teletransporta al jugador a las coordenadas especificadas"};
}