#include "core/commands/BoolCommand.hpp"
#include "game/gta/Stats.hpp"

namespace YimMenu::Features
{
	class AllowGenderChange : public BoolCommand
	{
		using BoolCommand::BoolCommand;

		virtual void OnEnable() override
		{
			Stats::SetInt("MPX_ALLOW_GENDER_CHANGE", 52);
		}

		virtual void OnDisable() override
		{
			Stats::SetInt("MPX_ALLOW_GENDER_CHANGE", 0);
		}
	};

	static AllowGenderChange _AllowGenderChange{"allowgenderchange", "Permitir cambio de género", "Permite al jugador cambiar el género del personaje"};
}