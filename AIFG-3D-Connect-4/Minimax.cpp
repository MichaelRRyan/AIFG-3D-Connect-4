#include "Minimax.h"

///////////////////////////////////////////////////////////////////////////////
Coordinate Minimax::getCoordinate(GameBoard & t_board, 
								  PieceType t_pieceType, 
								  size_t t_maxDepth)
{
	return minimax(t_board, t_pieceType, {}, 0, t_maxDepth).move.position;
}

///////////////////////////////////////////////////////////////////////////////
Minimax::Ply Minimax::minimax(GameBoard & t_board, PieceType t_pieceType,
							  Move t_move, size_t t_depth, size_t t_maxDepth)
{
	if (t_depth < t_maxDepth)
	{
		std::vector<Coordinate> * availableMoves = 
			getAllAvailableMoves(t_board);

		std::vector<Ply> plys;

		// If the depth is odd, we're min.
		bool min = t_depth % 2 == 1;

		for (Coordinate const& coord : *availableMoves)
		{
			Move move{ coord, t_pieceType };

			// Sets the piece type to the opposite if we're min.
			if (min)
				move.type = (PieceType::Red == t_pieceType) ?
					PieceType::Yellow : PieceType::Red;

			// Does the move.
			t_board.setPiece(coord, move.type);

			// Recursively calls minimax and saves the value.
			plys.push_back(minimax(t_board, t_pieceType, move, t_depth + 1, t_maxDepth));

			// Returns the piece to it's original empty state.
			t_board.setPiece(coord, PieceType::None);
		}

		// Cleans up.
		delete availableMoves;

		// Finds the highest/lowest scoring ply depending on whether min or max.
		auto const * bestPly = &plys.front();
		for (auto const & ply : plys)
		{
			if (min)
			{
				if (ply.score < bestPly->score)
					bestPly = &ply;
			}
			else if (ply.score > bestPly->score)
				bestPly = &ply;
		}

		return *bestPly; // Returns the best ply.
	}

	// If greater than or equal to the depth, return the best estimated coord.
	return Ply{ t_move, FourTechEvaluator::evaluateMove(t_board, t_move) };
}

///////////////////////////////////////////////////////////////////////////////
std::vector<Coordinate> * Minimax::getAllAvailableMoves(
	GameBoard const & t_board)
{
	// Move position and score.
	std::vector<Coordinate>* moves = new std::vector<Coordinate>;

	// Loops through each position on the board.
	Coordinate position;
	for (; position.x < GameBoard::SIZE; ++position.x)
	{
		for (position.y = 0; position.y < GameBoard::SIZE; ++position.y)
		{
			for (position.z = 0; position.z < GameBoard::SIZE; ++position.z)
			{
				// If the position has no piece on it.
				if (PieceType::None == t_board.getPiece(position))
				{
					// Stores the move position.
					moves->push_back(position);
				}
			}
		}
	}

	return moves;
}

///////////////////////////////////////////////////////////////////////////////