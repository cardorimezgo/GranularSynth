// 1 - Give a starting point
// 2 - look at all of the unvisited neighbors to that cell
// 3 - algorithm assigns same value to each neighbor cell or frontier 
// 4 - algorithm moves to the frontier 
// 5 - repeat step 3
// repeat process until every cell in the maze has been visited
//////////////////////////////////////////////////////////////////////

class Distances
{
  HashMap <Cell, Integer> cells;
  Cell root;

  Distances(Cell root)
  {  
    this.root = root;
    cells = new HashMap();
    cells.put(root, 0); //Integer.valueOf(0)
  }

  void add_d(Cell cell, int dist)
  {
    if (isKnown(cell))
    {
      throw new IllegalArgumentException("not added");
    }
    if (dist == 0)
    {
      root = cell;
    }
    cells.put(cell, Integer.valueOf(dist));
  }

  int get_dist(Cell cell) //query distance of a given cell
  {
    if (! cells.containsKey(cell))
    {
      return -1;
    }
    return cells.get(cell).intValue();
  }

  void set_dist(Cell cell, int dist) //recording distance for a given cell
  {
    cells.put(cell, dist);
  }

  boolean isKnown(Cell cell)
  {
    return cells.containsKey(cell);
  }

  Set cells() //get the list of all of the cells that are present
  {
    return cells.keySet();
  }

  Distances path_to(Cell goal)
  {
    Cell current = goal;
    Distances breadcrumbs = new Distances(root);
    breadcrumbs.cells.put(current, cells.get(current));

    while (current != root)
    {
      for (Cell neighbor : current.links())
      {
        if (cells.get(neighbor) < cells.get(current))
        {
          breadcrumbs.cells.put(neighbor, cells.get(neighbor));
          current = neighbor;
        }
      }
    }
    return breadcrumbs;
  }

  Cell max_dist()
  {
    int max_dist = 0;
    Cell max_cell = root;
    HashMap <Cell, Integer> ph = new HashMap();
    for (Cell cell : cells.keySet())
    {
      if (cells.get(cell) > max_dist)
      {
        max_cell = cell;
        max_dist = cells.get(cell);
        ph.put(max_cell, max_dist);
      }
    }
    return max_cell;
  }

  @Override
    String toString()
  {
    return "??"+cells.keySet();
  }
}
