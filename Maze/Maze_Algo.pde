public class Maze_Algo  /// invoker of command pattern
{
  List<AlgoRunner> algoList = new ArrayList<AlgoRunner>();

  public void addAlgo(AlgoRunner a)
  {
    algoList.add(a);
  }

  List listAlgo()
  {
    return algoList;
  }

  public void runAlgo(int n)
  {   
    algoList.get(n).execute();
  }
}
