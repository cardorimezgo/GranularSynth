#include "Maze_Run.h"

bool Maze_Run::Select_Maze(int key) {
    bool chose = false;

    switch (key) {
    case 'b':
        maze_algo = Maze_Algos::Binary_Tree;
        std::cout << "binary_tree" << std::endl;
        break;
    case 's':
        maze_algo = Maze_Algos::Sidewinder;
        std::cout << "sidewinder" << std::endl;
        break;
    case 'a':
        maze_algo = Maze_Algos::Aldous_Broder;
        std::cout << "aldous_broder" << std::endl;
        break;
    case 'w':
        maze_algo = Maze_Algos::Wilsons;
        std::cout << "wilsons" << std::endl;
        break;
    case 'h':
        maze_algo = Maze_Algos::Hunt_and_Kill;
        break;
    case 'r':
        maze_algo = Maze_Algos::Recursive_Backtracker;
        break;
    case 'g':
        maze_algo = Maze_Algos::Growing_Tree;
        break;
    case 'e':
        maze_algo = Maze_Algos::Ellers;
        break;
    case 'p':
        maze_algo = Maze_Algos::Prims;
        std::cout << "Prim's" << std::endl;
        break;
    case 'k':
        maze_algo = Maze_Algos::Kruskals;
        break;
    default:
        return false;   //invalid key entered
    }
    std::cout << "maze algorithm selected: " << key << std::endl;
    return true;
}


void Maze_Run::Setup_Maze(Maze_Algos type) {
 
switch (type) {
    case Maze_Algos::Binary_Tree:
            bt.Generate(0, 0);
            dfs.Solve(sz.get_Total_Rows() - 1, 0);
            //m_solver = std::make_unique<Depth_First_Search>(maze);
            //m_solver->Solve(sz.get_Total_Rows() - 1, 0);
            break;
        case Maze_Algos::Sidewinder:
            sw.Generate(maze.GetNumRows() - 1, 0);
            m_solver = std::make_unique<Depth_First_Search>(maze);
            m_solver->Solve(sz.get_Total_Rows() - 1, 0);
            break;
        case Maze_Algos::Prims:
            int rnd_row, rnd_col;
            prim.Gen_Rnd_Cell(rnd_row, rnd_col);
            prim.Generate(rnd_row, rnd_col);
            m_solver = std::make_unique<Dijkstra>(maze);
            m_solver->Solve(rnd_row, rnd_col);
            break;
        }
c_render = std::make_unique<Cell_Renderer>(maze, m_solver.get());
}

void Maze_Run::Render(int frame){
    if (c_render) {
        c_render->Draw(frame);
    }
    else {
        std::cout << "ordered list error" << std::endl;
        return;
    }

}

void Maze_Run::Print_List() {
    dfs.printGridFlat();
}