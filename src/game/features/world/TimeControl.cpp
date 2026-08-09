#include "core/commands/Command.hpp"
#include "core/commands/IntCommand.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/gta/Natives.hpp"

namespace YimMenu::Features
{
	static IntCommand _NetworkTimeHour{"networktimehour", "Hour", "Set hour (0-23)", 0, 23, 12};
	static IntCommand _NetworkTimeMinute{"networktimeminute", "Minute", "Set minute (0-59)", 0, 59, 0};
	static IntCommand _NetworkTimeSecond{"networktimesecond", "Second", "Set second (0-59)", 0, 59, 0};


	class SetNetworkTime : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(_NetworkTimeHour.GetState(),
			    _NetworkTimeMinute.GetState(),
			    _NetworkTimeSecond.GetState());
		}
	};

	class FreezeNetworkTime : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(_NetworkTimeHour.GetState(),
			    _NetworkTimeMinute.GetState(),
			    _NetworkTimeSecond.GetState());
		}

		virtual void OnDisable() override
		{
			NETWORK::NETWORK_CLEAR_CLOCK_TIME_OVERRIDE();
		}
	};

	static SetNetworkTime _SetTime{"setnetworktime", "Establecer hora", "Establece la hora de en línea a la hora actual del juego"};
	static FreezeNetworkTime _FreezeTime{"freezenetworktime", "Congelar hora", "Congela el reloj de línea a la hora seleccionada"};
}
