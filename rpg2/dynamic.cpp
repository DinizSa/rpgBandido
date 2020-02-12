#include "dynamic.h"

Dynamic::Dynamic():
	Entity(){
	this->solidVsSolid = false;
	this->solidVsDynamic = false;
	this->friendly = true;
	this->vx = 0;
	this->vy = 0;
	this->hasFriction = true;
	this->maxSpeed = 0;
}
Dynamic::~Dynamic() {
}
Dynamic::Dynamic(string name, float px, float py, float vx, float vy, float width, float height, bool solidVsSolid, bool solidVsDynamic, bool friendly, bool hasFriction, int maxSpeed) :
	Entity(name, px, py, width, height)	{
	this->solidVsSolid = solidVsSolid;
	this->solidVsDynamic = solidVsDynamic;
	this->friendly = friendly;
	this->vx = vx;
	this->vy = vy;
	this->hasFriction = hasFriction;
	this->maxSpeed = maxSpeed;
}
void Dynamic::move(Maps& map, int windowW, int windowH) {
	float widthLandscape = windowW / map.getNrHorizontal();
	float heightLandscape = windowH / map.getNrVertical();
	int blockXOrigin = (int)(px/ widthLandscape) % (int)widthLandscape;
	int blockXCenter = (int)((px+width/2)/ widthLandscape) % (int)widthLandscape;
	int blockXRight = (int)((px+width)/ widthLandscape) % (int)widthLandscape;
	int blockYOrigin= (int)(py/ heightLandscape) % (int)heightLandscape;
	int blockYCenter = (int)((py+height/2)/ heightLandscape) % (int)heightLandscape;
	int blockYDown = (int)((py+height)/ heightLandscape) % (int)heightLandscape;

	// Horizontal
	if ((vx > 0 && px < windowW - this->width && (this->solidVsSolid && !map.getSolid(blockXRight, blockYCenter))) || (vx < 0 && px > 0 && (this->solidVsSolid && !map.getSolid(blockXOrigin, blockYCenter)))) {
		px += vx;
	}
	// Vertical
	if ((vy > 0 && py < windowH - this->height && (this->solidVsSolid && !map.getSolid(blockXCenter, blockYDown ))) || (vy < 0 && py > 0 && (this->solidVsSolid && !map.getSolid(blockXCenter, blockYOrigin)))) {
		py += vy;
	}
	applyFriction();
	this->shape.setPosition(px, py);
}


// Return a pointer to the entity that is colliding or nullptr if not colliding
Entity* Dynamic::getCollidingEntity(vector<Entity>* entitys) {
	for (Entity entity : *entitys)
	{
		if (this->getPosX() + this->getWidth() > entity.getPosX() && this->getPosX() < entity.getPosX() + entity.getWidth()) {
			if (this->getPosY() + this->getWidth() > entity.getPosY() && this->getPosY() < entity.getPosY() + entity.getHeight()) {
				cout << this->getName() << " colliding with " << entity.getName() << endl;
				return &entity;
			}
		}
	}
	return nullptr;
}

// Return a pointer to the entity that is colliding or a nullptr if not colliding, in a chosen direction
// UP: 1, RIGHT: 2, DOWN:3, LEFT: 4
Entity* Dynamic::getCollidingEntity(vector<Entity>*, int direction) {
	
	return nullptr;
}

void Dynamic::applyFriction() {
	float friction = (float)maxSpeed/10.f;
	if (this->hasFriction) {
		// Horizontal
		if (abs(vx) < friction)
			vx = 0.f;
		if (vx > 0){
			vx -= friction;
			if (vx > this->maxSpeed)
				vx = this->maxSpeed;
		}else if (vx < 0) {
			vx += friction;
			if (vx < - this->maxSpeed)
				vx = -this->maxSpeed;
		}
		// Vertical
		if (abs(vy) < friction)
			vy = 0.f;
		if (vy > 0) {
			vy -= friction;
			if (vy > this->maxSpeed)
				vy = this->maxSpeed;
		}
		else if (vy < 0) {
			vy += friction;
			if (vy < -this->maxSpeed)
				vy = -this->maxSpeed;
		}
	}
}