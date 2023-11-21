#pragma once

#include "cocos2d.h"




USING_NS_CC;
using namespace std;

template<typename T, typename T2> 
inline auto operator+(std::pair<T, T2> const& p1, std::pair<T, T2> const& p2) 
{
	auto [x1, y1] = p1;
	auto [x2, y2] = p2;

	return std::pair(x1 + x2, y1 + y2);
}

template<typename P>
inline decltype(auto) operator+=(Vec2& v, P const& p)
{
	auto& [x1, y1] = v;
	auto& [x2, y2] = p;

	return v;
}

class Ratman : public Scene
{
public:
	static Scene* createScene();

	virtual bool init();
	virtual void update(float dt);

	void initialize(Sprite* spr, TMXLayer* layer, std::pair<int, int>& position, bool draw);

	void setPosition(Sprite* spr, std::pair<int, int> playerPosition, std::pair<int, int>& oldPosition, bool draw);

	bool canSetPosition(std::pair<int, int> playerPosition);

	void changeActiveSprite(Sprite* newActive);

	void setCheese(TMXLayer* layer, TMXTiledMap* map);

	const Size* mapSize;
	const Size* tileSize;

	pair<int, int> playerPosition;
	pair<int, int> enemyPosition;
	pair<int, int> victoryPosition;

	TMXLayer* walkable = NULL;
	DrawNode* drawNode = NULL;

	CREATE_FUNC(Ratman);

private:
	std::pair<float, float> toScreenSpace(std::pair<int, int>const& position)
	{
		return toScreenSpaceT<std::pair<float, float>>(position);
	}
	template<typename T>
	T toScreenSpaceT(std::pair<int, int>const& position)
	{
		return
		{
		  tileSize->width * (float)position.first,
		  tileSize->height * (float)((int)mapSize->height - position.second - 1)
		};
	}

	//dfs
	int dfs(std::pair<int, int> current, std::pair<int, int>const& target, int depth);

	Vec2 size;

	std::vector<std::vector<bool>> dfsVisited;
	std::vector<std::pair<int, int>> dfsPath;


	template<typename T>
	void reset(std::vector<std::vector<T>>& v, std::vector<std::pair<int, int>>& p, T defaultT)
	{
		Vec2 v2;
		std::pair<float, float>p2;

		p.clear();

		for (int i = 0; i < mapSize->width; ++i)
		{
			for (int j = 0; j < mapSize->height; ++j)
			{
				v[i][j] = defaultT;
			}
		}
	}
	void drawPath(std::vector<std::pair<int, int>>const& p, std::pair<float, float> offset, Color4F const& color)
	{
		if (p.size() > 0)
		{
			drawNode->setLineWidth(5.0f);

			auto tileCenter = std::pair(tileSize->width / 2.0f, tileSize->height / 2.0f);
			auto previous = toScreenSpace(p[0]) + tileCenter + offset;

			for (size_t i = 1; i < p.size(); ++i)
			{
				auto current = toScreenSpace(p[i]) + tileCenter + offset;

				drawNode->drawLine({ previous.first, previous.second }, { current.first, current.second }, color);

				std::swap(previous, current);
			}
		}
	}

	template<typename T, typename S>
	void drawVisited(std::vector<std::vector<T>> const& v, Color4F const& c, std::pair<float, float> offset, S const& size, T defaultT)
	{
		for (int i = 0; i < mapSize->width; ++i)
		{
			for (int j = 0; j < mapSize->height; ++j)
			{
				if (v[i][j] != defaultT)
				{
					auto origin = toScreenSpaceT<S>({ i, j });

					origin += offset;                   
					auto dest = size + origin;          

					drawNode->drawSolidRect(origin, dest, c);
				}
			}
		}
	}

	enum GameState
	{
		Start,
		Running,
		Defeat,
		Victory
	} gameState = Start;

	TMXLayer* collision;			

	Sprite* active = NULL;
	Sprite* ratDown = NULL;
	Sprite* ratLeft = NULL;
	Sprite* ratUp = NULL;
	Sprite* ratRight = NULL;
	Sprite* hummer1 = NULL;
	Sprite* mushroom = NULL;


	Label* victoryTxt;
	Label* defeatTxt;

	int EnemyTimer = 100;

	void ResetInput();

	bool down = false;
	bool left = false;
	bool up = false;
	bool right = false;
	bool debug = false;
};


