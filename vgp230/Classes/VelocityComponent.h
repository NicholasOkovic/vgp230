#pragma once

#include "cocos2d.h"
USING_NS_CC;

class VelocityComponent : public Component
{
public:
	static VelocityComponent* create(Vec2 s, float m)
	{
		auto rotating = new VelocityComponent(s, m);
		rotating->init();
		rotating->autorelease();
		return rotating;
	}
	virtual bool init() { _name = "VelocityComponent"; return true; }
	VelocityComponent(Vec2 s, float m) : _vel(s), _maxSpeed(m)
	{
	}
	virtual void update(float dt)
	{
		auto length = _vel.length();
		if (length > _maxSpeed)
		{
			_vel = Vec2((_vel.x / length) * _maxSpeed, (_vel.y / length) * _maxSpeed);
		}
		auto position = this->getOwner()->getPosition();
		this->getOwner()->setPosition(position + _vel * dt);
	}
	void operator+=(Vec2 const& v)
	{
		_vel += v;
	}
	Vec2 GetVelocity()
	{
		return _vel;
	}
private:
	Vec2 _vel;
	float _maxSpeed;
};
