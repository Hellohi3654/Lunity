#include "pch.h"
#include "PacketLogger.h"

PacketLogger::PacketLogger() : Cheat::Cheat("PacketLogger", "Other")
{
}

void PacketLogger::onEnable()
{
	/*
	LunMem::getClientInstance()->LocalPlayer->displayLocalizableMessage(new TextHolder("Test!"));
	LunMem::getClientInstance()->LocalPlayer->setName(new TextHolder("Franklin"));
	LunMem::getClientInstance()->LocalPlayer->setNameTagVisible(true);
	*/
	//LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(new TextHolder(string("Hello!")));
	//enabled = false;
}

void PacketLogger::onTick() {
	
}

void PacketLogger::onGmTick(GameMode* gm) {

}

int packetId = 0;
void PacketLogger::onPacket(void* Packet, PacketType type) {
	if (enabled) {
		Logger::logHex("Packet sent", (ulong)Packet);
		if (type == Movement) {
			Logger::log("Packet was movement packet");
		}
		Logger::log("Saving packet to disk...");
		char logged[0x0110];
		memcpy(logged, Packet, 0x0110);
		string fileName = to_string(packetId) + string(".pkt");
		if (type != Unknown) {
			if (type == Movement) {
				fileName = string("Mvmt-") + fileName;
			}
			if (type == Text) {
				fileName = string("Text-") + fileName;
			}
		}
		string debugPath = string(getenv("APPDATA") + string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\Packets\\") + fileName);
		ofstream fout;
		fout.open(debugPath, ios::binary | ios::out);
		fout.write(logged, 0x0110);
		fout.close();
		Logger::log("Packet saved as "+ fileName);
		packetId++;
	}
}