#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	static BoolCommand _LocallyVisible{"localvis", "Visible localmente", "Sé visible localmente mientras sigues invisible para los demás"};

	class Invis : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (Self::GetPed())
			{
				Self::GetPed().SetVisible(false);
				if (_LocallyVisible.GetState())
					Self::GetPlayer().SetVisibleLocally(true);
				else
					Self::GetPlayer().SetVisibleLocally(false);
			}
		}

		virtual void OnDisable() override
		{
			if (Self::GetPed())
			{
				Self::GetPed().SetVisible(true);
				Self::GetPlayer().SetVisibleLocally(false);
			}
		}
	};

	static Invis _Invis{"invis", "Invisibilidad", "Sé invisible"};
}