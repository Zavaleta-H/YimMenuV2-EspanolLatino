#include "core/commands/Command.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "core/commands/IntCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/gta/Natives.hpp"

namespace YimMenu::Features
{
	static IntCommand _WantedSlider{"wantedslider", "Wanted Slider", "Wanted level to set/freeze", 0, 5, 0};

	class ClearWanted : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			Self::GetPlayer().SetWantedLevel(0);
		}
	};

	class SetWanted : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			Self::GetPlayer().SetWantedLevel(_WantedSlider.GetState());
		}
	};

	class NeverWanted : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			Self::GetPlayer().SetWantedLevel(0);
			PLAYER::SET_MAX_WANTED_LEVEL(0);
		}

		virtual void OnDisable() override
		{
			PLAYER::SET_MAX_WANTED_LEVEL(6);
		}
	};

	class FreezeWanted : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (Self::GetPlayer().GetWantedLevel() != _WantedSlider.GetState())
				Self::GetPlayer().SetWantedLevel(_WantedSlider.GetState());
			PLAYER::SET_MAX_WANTED_LEVEL(_WantedSlider.GetState());
		}
	};

	static ClearWanted _ClearWanted{"clearwanted", "Quitar nivel de búsqueda", "Limpia tu nivel de búsqueda"};
	static SetWanted _SetWanted{"setwanted", "Establecer nivel de búsqueda", "Pone tu nivel de búsqueda al nivel que quieras"};
	static NeverWanted _NeverWanted{"neverwanted", "Nunca buscado", "Nunca te ponga un nivel de búsqueda"};
	static FreezeWanted _FreezeWanted{"freezewanted", "Congelar búsqueda", "Congela tu nivel de búsqueda en el nivel que quieras"};
}