/////- loop-erased random walk:if the path it is forming happens to intersect
/////- with itself and form a loop, it erases that loop before continuing on
// 1 - choose a point on the grid—any point—and mark it visited
// 2 - choose any unvisited cell in the grid and does one of these loop-erased
//// - random walks until it encounters a visited cell
// 3 - at that point add the path it followed to the maze, marking as visited
//// - each of the cells along that path
// 4 - the process repeats until all the cells in the grid have been visited
/////////////////////////////////////////////////////////////////////////////////

class Wilson
{
  Cell[][] On()
  {
    //grid config
    g.create_grid();
    g.config_cells();   

    ///creation of first visited cell & path initialiation
    Cell start_cell = g.random_cell();
    HashMap<Cell, Boolean> visited = new HashMap();
    visited.put(start_cell, true);
    List <Cell> path = new ArrayList();

    //univisited cell, creation of neighbor
    Cell current_cell = g.random_cell();
    Cell neighbor = get_ran_nebr(current_cell);

    while (visited.size() <  g.g_size()) //<>//
    { 
      if (!is_visited(visited, neighbor) && !loop_path(path, neighbor)) //continue
      {
        path.add(neighbor);
        current_cell = neighbor;
        neighbor = get_ran_nebr(current_cell);
      } else if (is_visited(visited, neighbor) && !loop_path(path, neighbor)) //finish loop
      { 
        path.add(neighbor);
        for (int i = 0; i < path.size() - 1; i++)
        {
          visited.put(path.get(i), true);
          path.get(i).link(path.get(i+1));
        }
        current_cell = g.random_cell();
        neighbor = get_ran_nebr(current_cell);
        path.clear();
      } else if ((!is_visited(visited, neighbor) && loop_path(path, neighbor)) || 
        (is_visited(visited, neighbor) && loop_path(path, neighbor))) //clear loop & restart
      {
        current_cell = path.get(0); // TEST WITH FIRST NUMS 
        neighbor = get_ran_nebr(current_cell);
        path.clear();
      }
    }println("w");
    return g.matrix;
  }
  
  /// check for match with visited cells
  boolean is_visited(HashMap _visited, Cell _neighbor) 
  {
    Iterator visited_itera = _visited.entrySet().iterator();
    for (int i = 0; i < _visited.size(); i++)
    {
      Map.Entry map_d = (Map.Entry)visited_itera.next();
      Cell cell = (Cell)map_d.getKey();
      if (cell == _neighbor)
      {
        return true;
      }
    }
    return false;
  }

  boolean loop_path(List<Cell> _path, Cell _neighbor)
  {
    for (int i = 0; i < _path.size(); i++)
    {
      if (_neighbor == _path.get(i)) 
      {
        return true;
      }
    }
    return false;
  }
}
