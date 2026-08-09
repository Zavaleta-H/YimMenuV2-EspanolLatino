#include "core/commands/Command.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/PersonalVehicles.hpp"
#include "game/pointers/Pointers.hpp"

namespace YimMenu::Features
{
	class FixAllVehicles : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			if (!*Pointers.IsSessionStarted)
				return;

			int count = 0;
			for (const auto& it : PersonalVehicles::GetPersonalVehicles())
			{
				const auto& personalVeh = it.second;
				if (personalVeh->Repair())
					count++;
			}

			if (count > 0)
				Notifications::Show("Fix All Vehicles", std::format("{} vehículos reparados.", count), NotificationType::Success);
			else
				Notifications::Show("Reparar todos", "No hay vehículos que reparar.");
		}
	};

	static FixAllVehicles _FixAllVehicles{"fixallvehicles", "Arreglar todos los vehículos", "Arreglar todos tus vehículos personales destruidos"};
}
