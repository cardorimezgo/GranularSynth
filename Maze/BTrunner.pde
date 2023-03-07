class BTrunner implements AlgoRunner //concrete class for command pattern
{
  private BinaryTree btrun;
  
  public BTrunner(BinaryTree btrun)
  {
    this.btrun = btrun;
  }
  
  public void execute()
  {
    btrun.On();
  }
}
