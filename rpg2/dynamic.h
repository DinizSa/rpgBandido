#pragma once
using namespace std;
#include "entity.h"
#include <string>
#include "maps.h"

class Dynamic: public Entity {
protected:
	float vx, vy;
	bool solidVsSolid;
	bool solidVsDynamic;
	bool friendly;
	bool hasFriction;
	int maxSpeed;

public:
	Dynamic();
	Dynamic(string name, float px, float py, float vx, float vy, float width, float height, bool solidVsSolid, bool solidVsDynamic, bool friendly, bool hasFriction, int maxSpeed);
	~Dynamic();
	inline void addVelocityX(float deltaVx) { this->vx += deltaVx; }
	inline void addVelocityY(float deltaVy) { this->vy += deltaVy; }
	inline void resetVelocity(float deltaVy) { this->vx = 0.f; this->vy = 0.f; }
	virtual void OnInteraction(Dynamic* secondDynamic) = 0;
	void move(Maps& map, int windowW, int windowH);
	Entity* getCollidingEntity(vector<Entity>* entitys);
	Entity* getCollidingEntity(vector<Entity>* entitys, int direction);

	// Getters
	inline float getSolidVsSolid() { return this->solidVsSolid; }
	inline float getSolidVsDynamic() { return this->solidVsDynamic; }
	inline float isFriendly() { return this->friendly; }
	inline int getMaxSpeed() { return this->maxSpeed; }

private:
	void applyFriction();

};