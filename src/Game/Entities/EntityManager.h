#pragma once

#include "Entity.h"
#include "inspector.h"
//#include "Client.h"


class EntityManager {
public:
	int leftClients = 0;
	int servedClients = 0;
	Client* firstClient;
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeLeavingClients();
	std::vector<Entity*> entities;
	void reset();
	bool isInspector(Client* client);

};

