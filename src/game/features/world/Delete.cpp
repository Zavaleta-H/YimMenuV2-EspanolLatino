#include "core/commands/Command.hpp"
#include "game/gta/Pools.hpp"
#include "game/gta/Object.hpp"

namespace YimMenu::Features
{
	class DeleteAllObjects : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (auto obj : Pools::GetObjects())
			{
				if (obj)
					obj.Delete();
			}
		}
	};

	class DeleteAllCameras : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (auto obj : Pools::GetObjects())
			{
				if (obj && obj.As<Object>().IsCamera())
					obj.Delete();
			}
		}
	};

	class DeleteAllPeds : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (auto ped : Pools::GetPeds())
			{
				if (!ped.IsPlayer())
					ped.Delete();
			}
		}
	};

	class DeleteAllVehs : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (auto veh : Pools::GetVehicles())
			{
				veh.Delete();
			}
		}
	};

	static DeleteAllCameras _DeleteAllCameras("delcams", "Delete All Cameras", "Deletes all cameras");
	static DeleteAllObjects _DeleteAllObjects{"delobjs", "Borrar todos los objetos", "Borra todos los objetos del mundo, incluyendo los críticos de misiones"};
	static DeleteAllPeds _DeleteAllPeds{"delpeds", "Borrar todos los PNJ", "Borra todos los PNJ del mundo, incluyendo los críticos de misiones"};
	static DeleteAllVehs _DeleteAllVehs{"delvehs", "Borrar todos los vehículos", "Borra todos los vehículos del mundo, incluyendo los críticos de misiones"};
}