#ifndef MINMAX_ALGORITHM_HPP_INCLUDED
#define MINMAX_ALGORITHM_HPP_INCLUDED

#include "board.hpp"
void minimax(board state, int depth, char sign, int &val);
int best_move(board state);

#endif // MINMAX_ALGORITHM_HPP_INCLUDED
