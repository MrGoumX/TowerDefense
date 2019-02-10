#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GeometryNode.h"
#include "Renderer.h"
#include "Game.h"

class Projectile : public GameObject
{
private:

protected:
	glm::mat4 m_transformation_matrix;
	glm::mat4 m_transformation_matrix_normal;
	class GeometryNode* m_projectile;
	glm::vec3 pos;
	bool hit = false;

public:
	Projectile();
	virtual ~Projectile();

	static bool InitializeMeshes();

	//void SetPosition(glm::vec3 position);
	void Update(Game* game) override;
	void DrawGeometry(class Renderer* renderer) override;
	void DrawGeometryToShadowMap(class Renderer* renderer) override;
	void SetHit(bool hit);

	glm::vec3 GetPos();
	bool GetHit();
};

#endif