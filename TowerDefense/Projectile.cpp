#include "Projectile.h"
#include <glm/gtc/matrix_transform.inl>
#include "OBJLoader.h"

Projectile::Projectile()
{
	m_projectile = new GeometryNode();
}

Projectile::~Projectile()
{
	delete m_projectile;
}

void Projectile::SetPosition(glm::vec3 position)
{
	this->pos = position;
	m_transformation_matrix = glm::translate(glm::mat4(1), position*glm::vec3(4, 1, 4));
	m_transformation_matrix *= glm::scale(glm::mat4(1), glm::vec3(0.1));
	m_transformation_matrix_normal = glm::mat4(glm::transpose(glm::inverse(glm::mat3(m_transformation_matrix))));
}

void Projectile::Update(Game* game)
{
	//TODO FIND THE RELATIVE POSITIONS FOR THE PROJECTILE FROM THE TOWER
	/*pos.z += 0.001;
	pos.y -= 0.001;
	pos.x += 0.001;*/
	SetPosition(pos);
}

void Projectile::DrawGeometry(Renderer* renderer)
{
	renderer->DrawGeometryNode(m_projectile, m_transformation_matrix, m_transformation_matrix_normal);
}

void Projectile::DrawGeometryToShadowMap(Renderer* renderer)
{
	renderer->DrawGeometryNodeToShadowMap(m_projectile, m_transformation_matrix, m_transformation_matrix_normal);
}
