#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Killaura : public Cheat
{
public:
	Killaura();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};
