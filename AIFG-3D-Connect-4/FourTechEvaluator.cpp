#include "FourTechEvaluator.h"

int const FourTechEvaluator::m_WIN_POINTS = 5000;
int const FourTechEvaluator::m_BLOCK_WIN_POINTS = 1500;
int const FourTechEvaluator::m_BLOCK_THREE_IN_A_ROW_POINTS = 212; // Max 1,484 if blocking 3s along 7 axis.
int const FourTechEvaluator::m_THREE_IN_A_ROW_POINTS = 30; // Max 210 if involved in 3s along 7 axis.
int const FourTechEvaluator::m_TWO_IN_A_ROW_POINTS = 4; // Max 28 if involved in 2s along 7 axis.
int const FourTechEvaluator::m_CENTRE_POINTS = 1; // Max 3 (when centred along all axis).

size_t const FourTechEvaluator::m_LAST_CELL_INDEX = GameBoard::SIZE - 1; 

///////////////////////////////////////////////////////////////////////////////
bool FourTechEvaluator::isMoveAWin(GameBoard & t_board, Move const & t_move)
{
	PieceType prevType = t_board.getPiece(t_move.position);
	t_board.setPiece(t_move.position, t_move.type);
	bool success = false;

	// Checks the 3 straight axis.
	if (checkForStraightWin(t_board, t_move))
		success = true;

	// Checks both diagonals along each of the 3 axis.
	else if (checkForSingleAxisDiagonalWin(t_board, t_move))
		success = true;

	// Checks the diagonals along all axis.
	else if (checkForAllAxisDiagonalWin(t_board, t_move))
		success = true;

	t_board.setPiece(t_move.position, prevType);
	return success;
}

///////////////////////////////////////////////////////////////////////////////
int FourTechEvaluator::evaluateMove(GameBoard & t_board, Move const & t_move)
{
	int score = 0;

	// Checks for win.
	if (isMoveAWin(t_board, t_move))
		score += m_WIN_POINTS;

	// Checks for block opponent win.
	if (doesMoveBlockWin(t_board, t_move))
		score += m_BLOCK_WIN_POINTS;

	// Counts blocked opponent threes in a row.
	score += countBlockedThreeInARows(t_board, t_move) * 
		m_BLOCK_THREE_IN_A_ROW_POINTS;

	// Counts threes in a row.
	score += countThreeInARows(t_board, t_move) *
		m_THREE_IN_A_ROW_POINTS;

	// Counts twos in a row.
	score += countTwoInARows(t_board, t_move) *
		m_TWO_IN_A_ROW_POINTS;

	// Checks for centre.
	score += m_CENTRE_POINTS * countCentredAxis(t_board, t_move);

	return score;
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechEvaluator::checkForStraightWin(GameBoard& t_board, 
											Move const & t_move)
{
	Coordinate const & pos = t_move.position;

	// Checks the 3 straight axis.
	return countAlongAxis(t_board, t_move.type, 
			{ 0, pos.y, pos.z }, 1, 0, 0) == GameBoard::SIZE

		|| countAlongAxis(t_board, t_move.type, 
			{ pos.x, 0, pos.z }, 0, 1, 0) == GameBoard::SIZE

		|| countAlongAxis(t_board, t_move.type, 
			{ pos.x, pos.y, 0 }, 0, 0, 1) == GameBoard::SIZE;
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechEvaluator::checkForSingleAxisDiagonalWin(GameBoard& t_board, 
													  Move const & t_move)
{
	Coordinate const& pos = t_move.position;

		// Checks the diagonals along the x axis.
	return (pos.y == pos.z 
			&& countAlongAxis(t_board, t_move.type, 
			{ pos.x, 0, 0 }, 0, 1, 1) == GameBoard::SIZE)

		|| (pos.y == reversed(pos.z) 
			&& countAlongAxis(t_board, t_move.type, 
			{ pos.x, 0, m_LAST_CELL_INDEX }, 0, 1, -1) == GameBoard::SIZE)

		// Checks the diagonals along the y axis.
		|| (pos.x == pos.z 
			&& countAlongAxis(t_board, t_move.type,
			{ 0, pos.y, 0 }, 1, 0, 1) == GameBoard::SIZE)

		|| (pos.x == reversed(pos.z) 
			&& countAlongAxis(t_board, t_move.type,
			{ 0, pos.y, m_LAST_CELL_INDEX }, 1, 0, -1) == GameBoard::SIZE)

		// Checks the diagonals along the z axis.
		|| (pos.x == pos.y 
			&& countAlongAxis(t_board, t_move.type,
				{ 0, 0, pos.z }, 1, 1, 0) == GameBoard::SIZE)

		|| (pos.x == reversed(pos.y) 
			&& countAlongAxis(t_board, t_move.type,
				{ 0, m_LAST_CELL_INDEX, pos.z }, 1, -1, 0) == GameBoard::SIZE);
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechEvaluator::checkForAllAxisDiagonalWin(GameBoard& t_board,
												   Move const & t_move)
{
	Coordinate const& pos = t_move.position;

	// Counts the number of pieces of type t_type along the axis if the move
	//		sits along the axis.

		// From coordinates { 0, 0, 0 } to { 3, 3, 3 }
	return (pos.x == pos.y && pos.x == pos.z
			&& countAlongAxis(t_board, t_move.type, 
				{ 0, 0, 0 }, 1, 1, 1) == GameBoard::SIZE)

		// From coordinates { 3, 0, 0 } to { 0, 3, 3 }
		|| (reversed(pos.x) == pos.y && reversed(pos.x) == pos.z
			&& countAlongAxis(t_board, t_move.type, 
				{ m_LAST_CELL_INDEX, 0, 0 }, -1, 1, 1) == GameBoard::SIZE)

		// From coordinates { 0, 3, 0 } to { 3, 0, 3 }
		|| (pos.x == reversed(pos.y) && pos.x == pos.z
			&& countAlongAxis(t_board, t_move.type, 
				{ 0, m_LAST_CELL_INDEX, 0 }, 1, -1, 1) == GameBoard::SIZE)

		// From coordinates { 0, 0, 3 } to { 3, 3, 0 }
		|| (pos.x == reversed(pos.y) && pos.x == reversed(pos.z)
			&& countAlongAxis(t_board, t_move.type, 
				{ 0, 0, m_LAST_CELL_INDEX }, 1, 1, -1) == GameBoard::SIZE);
}

///////////////////////////////////////////////////////////////////////////////
int FourTechEvaluator::countAlongAxis(GameBoard& t_board, PieceType t_type,
									  Coordinate const& t_start,
									  int t_xInc, int t_yInc, int t_zInc)
{
	int count = 0;
	Coordinate cur = t_start;

	for (int i = 0; i < GameBoard::SIZE; ++i)
	{
		PieceType curPiece = t_board.getPiece(cur);
		if (t_type == curPiece)
			++count;

		// Invalidate the use of the row if there's an opposite colour on it.
		else if (t_type != curPiece && PieceType::None != curPiece)
			return 0;

		cur.x += t_xInc;
		cur.y += t_yInc;
		cur.z += t_zInc;
	}

	return count;
}

///////////////////////////////////////////////////////////////////////////////
int FourTechEvaluator::countRowsOfTypeAndSize(GameBoard & t_board, 
											  Coordinate const & t_position, 
											  PieceType t_type, int t_size)
{
	return countStraightRows(t_board, t_position, t_type, t_size)
		+ countSingleAxisDiagonalRows(t_board, t_position, t_type, t_size)
		+ countAllAxisDiagonalRows(t_board, t_position, t_type, t_size);
}

///////////////////////////////////////////////////////////////////////////////
int FourTechEvaluator::countStraightRows(GameBoard& t_board, 
										 Coordinate const& t_pos, 
										 PieceType t_type, int t_size)
{
	int count = 0;
	if (countAlongAxis(t_board, t_type, { 0, t_pos.y, t_pos.z }, 1, 0, 0) == t_size)
		++count; // +1 row along the X axis.
	if (countAlongAxis(t_board, t_type, { t_pos.x, 0, t_pos.z }, 0, 1, 0) == t_size)
		++count; // +1 row along the Y axis.
	if (countAlongAxis(t_board, t_type, { t_pos.x, t_pos.y, 0 }, 0, 0, 1) == t_size)
		++count; // +1 row along the Z axis.
	return count;
}

///////////////////////////////////////////////////////////////////////////////
int FourTechEvaluator::countSingleAxisDiagonalRows(GameBoard& t_board, 
												   Coordinate const& t_pos,
												   PieceType t_type, int t_size)
{
	// The last valid position along any axis.
	int count = 0;

	// Checks the diagonals along the x axis.
	if (t_pos.y == t_pos.z && countAlongAxis(t_board, t_type, 
		{ t_pos.x, 0, 0 }, 0, 1, 1) == t_size)
			++count;
	if (t_pos.y == reversed(t_pos.z) && countAlongAxis(t_board, t_type, 
		{ t_pos.x, 0, m_LAST_CELL_INDEX }, 0, 1, -1) == t_size)
			++count;

	// Checks the diagonals along the y axis.
	if (t_pos.x == t_pos.z && countAlongAxis(t_board, t_type, 
		{ 0, t_pos.y, 0 }, 1, 0, 1) == t_size)
			++count;
	if (t_pos.x == reversed(t_pos.z) && countAlongAxis(t_board, t_type, 
		{ 0, t_pos.y, m_LAST_CELL_INDEX }, 1, 0, -1) == t_size)
			++count;

	// Checks the diagonals along the z axis.
	if (t_pos.x == t_pos.y && countAlongAxis(t_board, t_type, 
		{ 0, 0, t_pos.z }, 1, 1, 0) == t_size)
			++count;
	if (t_pos.x == reversed(t_pos.y) && countAlongAxis(t_board, t_type, 
		{ 0, m_LAST_CELL_INDEX, t_pos.z }, 1, -1, 0) == t_size)
			++count;

	return count;
}

///////////////////////////////////////////////////////////////////////////////
int FourTechEvaluator::countAllAxisDiagonalRows(GameBoard& t_board, 
												Coordinate const& t_pos, 
												PieceType t_type, int t_size)
{
	int count = 0;

	// Counts the number of pieces of type t_type along the axis if the move
	//		sits along the axis.

	// From coordinates { 0, 0, 0 } to { 3, 3, 3 }
	if (t_pos.x == t_pos.y && t_pos.x == t_pos.z
		&& countAlongAxis(t_board, t_type, 
			{ 0, 0, 0 }, 1, 1, 1) == t_size)
				++count;

	// From coordinates { 3, 0, 0 } to { 0, 3, 3 }
	if (reversed(t_pos.x) == t_pos.y && reversed(t_pos.x) == t_pos.z
		&& countAlongAxis(t_board, t_type, 
			{ m_LAST_CELL_INDEX, 0, 0 }, -1, 1, 1) == t_size)
				++count;

	// From coordinates { 0, 3, 0 } to { 3, 0, 3 }
	if (t_pos.x == reversed(t_pos.y) && t_pos.x == t_pos.z
		&& countAlongAxis(t_board, t_type, 
			{ 0, m_LAST_CELL_INDEX, 0 }, 1, -1, 1) == t_size)
				++count;

	// From coordinates { 0, 0, 3 } to { 3, 3, 0 }
	if (t_pos.x == reversed(t_pos.y) && t_pos.x == reversed(t_pos.z)
		&& countAlongAxis(t_board, t_type, 
			{ 0, 0, m_LAST_CELL_INDEX }, 1, 1, -1) == t_size)
				++count;

	return count;
}

///////////////////////////////////////////////////////////////////////////////
bool FourTechEvaluator::doesMoveBlockWin(GameBoard& t_board, 
										 Move const& t_move)
{
	PieceType opponent = (t_move.type == PieceType::Red) ? 
		PieceType::Yellow : PieceType::Red;

	return isMoveAWin(t_board, { t_move.position, opponent });
}

///////////////////////////////////////////////////////////////////////////////
int FourTechEvaluator::countBlockedThreeInARows(GameBoard& t_board,
												Move const& t_move)
{
	PieceType opponent = (t_move.type == PieceType::Red) ?
		PieceType::Yellow : PieceType::Red;

	return countRowsOfTypeAndSize(t_board, t_move.position, opponent, 2);
}

///////////////////////////////////////////////////////////////////////////////
int FourTechEvaluator::countThreeInARows(GameBoard& t_board, 
										 Move const& t_move)
{
	// Gets the previous piece at the move position and replaces it with the move.
	PieceType prevType = t_board.getPiece(t_move.position);
	t_board.setPiece(t_move.position, t_move.type);

	int count = countRowsOfTypeAndSize(t_board, t_move.position, t_move.type, 3);

	// Replaces the piece to its original type and returns the count.
	t_board.setPiece(t_move.position, prevType);
	return count;
}

///////////////////////////////////////////////////////////////////////////////
int FourTechEvaluator::countTwoInARows(GameBoard& t_board, Move const& t_move)
{
	// Gets the previous piece at the move position and replaces it with the move.
	PieceType prevType = t_board.getPiece(t_move.position);
	t_board.setPiece(t_move.position, t_move.type);

	int count = countRowsOfTypeAndSize(t_board, t_move.position, t_move.type, 2);

	// Replaces the piece to its original type and returns the count.
	t_board.setPiece(t_move.position, prevType);
	return count;
}

///////////////////////////////////////////////////////////////////////////////
int FourTechEvaluator::countCentredAxis(GameBoard & t_board, 
										Move const & t_move)
{
	int score = 0;
	if (t_move.position.x == 1 || t_move.position.x == 2) ++score;
	if (t_move.position.y == 1 || t_move.position.y == 2) ++score;
	if (t_move.position.z == 1 || t_move.position.z == 2) ++score;
	return score;
}

///////////////////////////////////////////////////////////////////////////////
size_t FourTechEvaluator::reversed(size_t t_cell)
{
	return m_LAST_CELL_INDEX - t_cell;
}

///////////////////////////////////////////////////////////////////////////////