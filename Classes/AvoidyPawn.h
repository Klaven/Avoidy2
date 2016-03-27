#ifndef __Avoidy_Pawn_H__
#define __Avoidy_Pawn_H__

#include "cocos2d.h"

class AvoidyPawn : public cocos2d::Node
{
public:
	CREATE_FUNC(AvoidyPawn);
	AvoidyPawn();
	~AvoidyPawn();

	bool init() override;

	void onEnter() override;

	void JumpLeft();
	void JumpRight();

	void PlaceOnScreen(float x, float y);

	void AddAsChild(cocos2d::Node* parent);

private:
	cocos2d::Sprite* _body;
};

#endif // __Avoidy_Pawn_H__
