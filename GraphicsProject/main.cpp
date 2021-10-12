#include "Engine.h"
#include "RabbitWorld.h"

int main() {
	Engine* engine = new Engine(1280, 720, "Rabbit World");

	RabbitWorld* world = new RabbitWorld();

	engine->setActiveWorld(world);

	int exitCode = engine->run();

	delete world;
	delete engine;

	return exitCode;
}