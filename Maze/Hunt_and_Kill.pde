///1 - Pick random cell  //<>// //<>// //<>// //<>// //<>// //<>// //<>// //<>// //<>//
///2 - perform random walk avoiding any cell that we've already visited
///3 - When end up surrounded by visited cell, (hunt phase)scan left to right from 
//// - northwest corner until we encounter an unvisited cell, bordered by at least one
//// - visited cell
///4 - Make it current cell and link to any one of its neighboring visited cells 
///5 - Repeat random walk
///6 - Repeat until hunt phase cannot find any more unvisited cells
/////////////////////////////////////////////////////////////////////////////////////////

class Hunt_and_Kill
{
  void On()
  {
    //grid config
    g.create_grid();
    g.config_cells();  

    Cell current_cell = g.random_cell();
    List<Cell> visited = new ArrayList<Cell>();
    visited.add(current_cell);
    Random ran = new Random();
    Cell neighbor = get_ran_nebr(current_cell);

    while (visited.size() < g.g_size())   //<>//
    { 
      if (not_visit_n(current_cell, visited).size() > 0) // is there at least one neighbor that's not visited
      {
        int rand_int_neighbor = ran.nextInt(not_visit_n(current_cell, visited).size());
        neighbor = not_visit_n(current_cell, visited).get(rand_int_neighbor);
        current_cell.link(neighbor);
        current_cell = neighbor;
        visited.add(current_cell);
      } else if (not_visit_n(current_cell, visited).size() == 0) //all surrounding cells visited
      { 
      outerloop:
        for (int r = 0; r < g.rows; r++) //hunting time
        {
          for (int c = 0; c < g.cols; c++)
          {
            Cell cell = g.visit_cell(r, c); 
            if (cell.links().isEmpty() && visited_n(cell, visited).size() != 0) 
            { 
              if (not_visit_n(cell, visited).size() <= 0) //every neighbor is visited
              {
                visited.add(cell);
                cell.link(get_ran_nebr(cell));
                current_cell = cell;
                break outerloop;
              } else /// link to visited neighbor
              {
                int ran_visit = ran.nextInt(visited_n(cell, visited).size());
                neighbor = visited_n(cell, visited).get(ran_visit);
                visited.add(cell);
                cell.link(neighbor);
                current_cell = cell;
                break outerloop;
              }
            }
          }
        }
      }
    }
  }
}

//list of not_visited neighbors 
List<Cell> not_visit_n(Cell c, List <Cell> v)
{  
  Direction[] dirs = new Direction[]{Direction.SOUTH, Direction.EAST, Direction.WEST, Direction.NORTH};
  List <Cell> nsew = c.get_neighbors(dirs); 
  List <Cell> not_visited = new ArrayList<Cell>(); 

  for (int i = 0; i < nsew.size(); i++)
  { 
    int cnt = 0;
    for ( int j = 0; j < v.size(); j++)
    {
      if (nsew.get(i) != v.get(j))
      {
        cnt++;
      }
    }
    if (cnt == v.size())
    {
      not_visited.add(nsew.get(i));
    }
  }
  return not_visited;
}

List<Cell> visited_n(Cell c, List <Cell> v)
{  
  Direction[] dirs = new Direction[]{Direction.SOUTH, Direction.EAST, Direction.WEST, Direction.NORTH};
  List <Cell> nsew = c.get_neighbors(dirs); 
  List <Cell> visited = new ArrayList<Cell>(); 

  for (int i = 0; i < nsew.size(); i++)
  { 
    for ( int j = 0; j < v.size(); j++)
    {
      if (nsew.get(i) == v.get(j))
      {
        visited.add(nsew.get(i));
      }
    }
  }
  return visited;
}

Cell get_ran_nebr(Cell c)
{
  Random rand = new Random();
  Direction[] dirs = new Direction[]{Direction.NORTH, Direction.SOUTH, Direction.EAST, Direction.WEST};
  List <Cell> neighbors = c.get_neighbors(dirs);
  int rand_int = rand.nextInt(neighbors.size());
  Cell neighbor = neighbors.get(rand_int);

  return neighbor;
}
