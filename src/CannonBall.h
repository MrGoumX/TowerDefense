#ifndef CANNONBALL_H
#define CANNONBALL_H

#include "Projectile.h"

class CannonBall : public Projectile
{
public:
	CannonBall();

	static bool InitializeMeshes();
};

#endif
