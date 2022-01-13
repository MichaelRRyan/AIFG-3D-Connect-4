#include "Scene.h"

Scene::Scene(GameState t_nextGameState) : 
    m_isEnded{ false },
    m_nextGameState{ t_nextGameState }
{
}

const bool & Scene::isEnded() const
{
    return m_isEnded;
}

const GameState & Scene::getNewGameState() const
{
    return m_nextGameState;
}
