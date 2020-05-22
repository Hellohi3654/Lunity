#include "pch.h"
#include "Speed.h"
#include "../Hooks/KeyHook.h"

#define PI 3.14159
float speedValue = 0.4f;

Speed::Speed() :Cheat::Cheat("Speed", "Movement")
{
}

void Speed::onLoop()
{
	Cheat::onLoop();
}

void Speed::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
			float calcYaw = Player->LookingVec.y;

			bool pressedWKey = KeyHook::KeyState(0x57);
			bool pressedSKey = KeyHook::KeyState(0x53);
			bool pressedAKey = KeyHook::KeyState(0x41);
			bool pressedDKey = KeyHook::KeyState(0x44);

			if (pressedWKey) {
				if (!pressedAKey && !pressedDKey) {
					calcYaw += 90.0f;
				}
				else if (pressedAKey) {
					calcYaw += 45.0f;
				}
				else if (pressedDKey) {
					calcYaw += 135.0f;
				}
			}
			else if (pressedSKey) {
				if (!pressedAKey && !pressedDKey) {
					calcYaw -= 90.0f;
				}
				else if (pressedAKey) {
					calcYaw -= 45.0f;
				}
				else if (pressedDKey) {
					calcYaw -= 135.0f;
				}
			}
			else if (!pressedWKey && !pressedSKey) {
				if (pressedDKey) {
					calcYaw += 180.0f;
				}
			}

			if (pressedWKey | pressedSKey | pressedAKey | pressedDKey) {
				Player->VelocityXYZ.x = cos((calcYaw) * (PI / 180.0f)) * speedValue;
				Player->VelocityXYZ.z = sin((calcYaw) * (PI / 180.0f)) * speedValue;
			}
		}
	}
}

void Speed::onEnable()
{
	Cheat::onEnable();
}

void Speed::onDisable()
{
	Cheat::onDisable();
}

void Speed::onKey(ulong key) {

}