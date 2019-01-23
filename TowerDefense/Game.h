#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SDL2/SDL.h>
#define TOTAL_GAME_TIMES = 29;

const glm::vec3 game_tiles[] = {
	glm::vec3(0, 0, 0),
	glm::vec3(0, 0, 1),
	glm::vec3(0, 0, 2),
	glm::vec3(0, 0, 3),
	glm::vec3(1, 0, 3),
	glm::vec3(1, 0, 4),
	glm::vec3(1, 0, 5),
	glm::vec3(1, 0, 6),
	glm::vec3(1, 0, 7),
	glm::vec3(2, 0, 7),
	glm::vec3(2, 0, 8),
	glm::vec3(3, 0, 8),
	glm::vec3(4, 0, 8),
	glm::vec3(5, 0, 8),
	glm::vec3(6, 0, 8),
	glm::vec3(6, 0, 7),
	glm::vec3(6, 0, 6),
	glm::vec3(7, 0, 6),
	glm::vec3(7, 0, 5),
	glm::vec3(7, 0, 4),
	glm::vec3(7, 0, 3),
	glm::vec3(8, 0, 3),
	glm::vec3(9, 0, 3),
	glm::vec3(9, 0, 2),
	glm::vec3(9, 0, 1),
	glm::vec3(8, 0, 1),
	glm::vec3(7, 0, 1),
	glm::vec3(6, 0, 1),
	glm::vec3(6, 0, 0)
};

const glm::vec3 treasure_locs[] = {
	glm::vec3(5, 0, -.5),
	glm::vec3(6, 0, -.5),
	glm::vec3(7, 0, -.5)
};

class Game: public Renderable
{
private:
	SDL_Event event;

	float m_time = 0.0f;
	class Renderer* m_renderer;
	class PlaneRG* plane_rg;
	class CannonBall* test_ball;
	class Terrain* m_terrain;

	std::vector<class Pirate*> m_pirates;
	std::vector<class Road*> m_roads;
	std::vector<class Treasure*> m_treasures;
	std::vector<class Tower*> m_towers;

public:
	Game();
	~Game();

	float time()
	{
		return m_time;
	}

	Renderer* renderer()
	{
		return m_renderer;
	}

	PlaneRG* getPlaneRG()
	{
		return plane_rg;
	}

	bool InitializeRenderer(int SCREEN_WIDTH, int SCREEN_HEIGHT);
	bool InitializeObjects();
	bool InitializeLogic();

	void Update(float elapsed);
	void Render();
	void SpawnPirate(float dt);
	void DeployTower(glm::vec3 pos);
	bool RemoveTower(glm::vec3 pos);
	void AddTower();

	void DrawGeometry(Renderer* renderer) override;
	void DrawGeometryToShadowMap(Renderer* renderer) override;

	std::vector<Tower*> GetTowers();
};

class GameObject : public Renderable
{
public:
	virtual void Update(Game* game) = 0;
};
#endif // GAME_H
