class ABrunner implements AlgoRunner //concrete class for command pattern
{
  private AldousBroder ab;
  
  public ABrunner(AldousBroder ab)
  {
    this.ab = ab;
  }
  
  public void execute()
  {
    ab.On();
  }
}
