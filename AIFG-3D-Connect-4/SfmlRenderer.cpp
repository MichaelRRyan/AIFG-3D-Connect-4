#include "SfmlRenderer.h"

SfmlRenderer::SfmlRenderer() :
	m_gameBoard(nullptr)
{
}

SfmlRenderer::~SfmlRenderer()
{
}

void SfmlRenderer::render()
{

}

void SfmlRenderer::setGameBoard(GameBoard* t_gameBoard)
{
	m_gameBoard = t_gameBoard;
}