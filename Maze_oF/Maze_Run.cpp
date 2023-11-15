#include "Maze_Run.h"

void Setup_Maze(Maze_Algos type) {
	
	MazeSolver* m_solver;

	switch (type) {
	case Maze_Algos::Binary_Tree:
		bt.Generate(0, 0);
		delete m_solver;  // consider changing for unique_ptr
		m_solver->Get_Flat_DS();
		break;
	case Maze_Algos::Sidewinder:
		sw.Generate(maze.GetNumRows() - 1, 0);
		delete m_solver; // consider changing for unique_ptr
		m_solver->Get_Flat_DS();
		break;
	case Maze_Algos::Prims:
		w_maze.init_Weights(); /// integrate inside each weighted maze generating algo.
		w_maze.set_Rnd_Edges(); /// integrate inside each weighted maze generating algo.
		int rnd_row, rnd_col;
		prim.Gen_Rnd_Cell(rnd_row, rnd_col);
		prim.Generate(rnd_row, rnd_col);
		delete m_solver;   // consider changing for unique_ptr
		m_solver->Get_Flat_DS();
		break;
	}
}