

#include "AvoidyPawn.h"

using namespace cocos2d;

AvoidyPawn::AvoidyPawn()
{
	
	_body = Sprite::create("Guy2.png");
	auto playerPhysics = PhysicsBody::createCircle(_body->getContentSize().width / 2, PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO);
	_body->setPhysicsBody(playerPhysics);
}

AvoidyPawn::~AvoidyPawn()
{

}

void AvoidyPawn::AddAsChild(cocos2d::Node * parent)
{
    parent->addChild(this);
    parent->addChild(_body);
}

bool AvoidyPawn::init()
{
	if (!Node::init()) 
	{
		return false;
	}

	return true;
}

void AvoidyPawn::onEnter()
{
	Node::onEnter();
}

void AvoidyPawn::JumpLeft()
{
	_body->getPhysicsBody()->setVelocity(Vec2(-100, 300));
}

void AvoidyPawn::JumpRight()
{
	_body->getPhysicsBody()->setVelocity(Vec2(100, 300));
}

void AvoidyPawn::PlaceOnScreen(float x, float y)
{
	_body->setPosition(x, y);
}
