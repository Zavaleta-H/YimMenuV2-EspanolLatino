#include "core/commands/StringCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/Self.hpp"
#include "game/gta/Object.hpp"
#include "game/gta/Natives.hpp"

namespace YimMenu::Features
{
	static StringCommand _PedModelName{"pedmodelname", "Modelo del ped", "El nombre del modelo del ped que deseas generar."};
	static StringCommand _ObjectModelName{"objectmodelname", "Modelo del objeto", "El nombre del modelo del objeto que deseas generar."};


	class SpawnPed : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			auto model = _PedModelName.GetString();
			if (!model.length())
			{
				Notifications::Show("Generar ped", "No se proporcionó un nombre de modelo.", NotificationType::Error);
				return;
			}

			auto modelHash = Joaat(model);
			if (STREAMING::IS_MODEL_IN_CDIMAGE(modelHash))
			{
				Ped::Create(modelHash, Self::GetPed().GetPosition(), Self::GetPed().GetHeading());
			}
			else
			{
				Notifications::Show("Generar ped", "Nombre de modelo no válido.", NotificationType::Error);
			}
		}
	};

	class SpawnObject : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			auto model = _ObjectModelName.GetString();
			if (!model.length())
			{
				Notifications::Show("Generar objeto", "No se proporcionó un nombre de modelo.", NotificationType::Error);
				return;
			}

			auto modelHash = Joaat(model);
			if (STREAMING::IS_MODEL_IN_CDIMAGE(modelHash))
			{
				Object::Create(modelHash, Self::GetPed().GetPosition());
			}
			else
			{
				Notifications::Show("Generar objeto", "Nombre de modelo no válido.", NotificationType::Error);
			}
		}
	};

	static SpawnPed _SpawnPed{"spawnped", "Generar PNJ", "Genera un PNJ en tu ubicación actual"};
	static SpawnObject _SpawnObject{"spawnobject", "Generar objeto", "Genera un objeto en tu ubicación actual"};
}
