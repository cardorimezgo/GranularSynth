class Dijkstra
{
  Cell root = g.visit_cell(0 , 0); // Cell (0,0) as start of maze
Cell goal = g.visit_cell(g.rows - 1 , g.cols - 1); // maze's End/Goal 

  //Assign distance to each cell from root
  Integer distance(Cell cell) 
  {
    return (root.distances().cells.get(cell));
  }
  
  //Shortest Path
  Integer shortest_path(Cell cell)
  {
    Integer dist_to_goal = root.distances().path_to(goal).cells.get(cell);
    if (dist_to_goal != null )
    {
      return dist_to_goal;
    }
    else 
    return 0;
  }
  
  //Longest Path
  Integer longest_path(Cell cell)
  {
    Integer longest_path = root.distances().path_to(root.distances().max_dist()).cells.get(cell);
    if (longest_path != null )
    {
      return longest_path;
    }
    else
    return 0;
  }
}
