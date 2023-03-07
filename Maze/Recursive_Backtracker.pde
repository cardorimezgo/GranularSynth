/// - create stack (list) with push(add) and pop(remove) features //<>// //<>//
///1 - random start
///2 - push cell onto stack (cell at top of stack = current cell)
///3 - search for unvisited neighbors & choose one at random
///4 - carve path, push cell onto stack 
///5 - continue until dead-end
///6 - pop dead-end cell off the stack (previous cell becomes current cell)
///7 - continue until every cell has been visited
///8 - stack should end empty. backtracking and poping cells until we arrive at origin cell
///////////////////////////////////////////////////////////////////////////////////////////

class Recursive_Backtracker
{
  void On()
  {
    //grid config
    g.create_grid();
    g.config_cells();
    Random rand = new Random();

    List<Cell> stack = new ArrayList<Cell>();
    List<Cell> visited = new ArrayList<Cell>();
    Cell current_cell =  g.random_cell();
    stack.add(current_cell);
    visited.add(current_cell);

    while (stack.size() != 0)
    {
      if (not_visit_n(current_cell, visited).size() == 0)//dead-end
      { 
        if (stack.size() != 1)
        {
          stack.remove(stack.size()-1); 
          current_cell = stack.get(stack.size()-1);
        } else if (stack.size() == 1)
        {
          stack.clear();
        }
      } else {
        int num_cell = rand.nextInt(not_visit_n(current_cell, visited).size());
        Cell neighbor = not_visit_n(current_cell, visited).get(num_cell);
        current_cell.link(neighbor);
        current_cell = neighbor;
        stack.add(current_cell);
        visited.add(current_cell);
      }
    }
  }
}
