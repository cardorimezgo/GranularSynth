class RBrunner implements AlgoRunner //concrete class for command pattern
{
  private Recursive_Backtracker rb;
  
  public RBrunner(Recursive_Backtracker rb)
  {
    this.rb = rb;
  }
  
  public void execute()
  {
    rb.On();
  }
}
