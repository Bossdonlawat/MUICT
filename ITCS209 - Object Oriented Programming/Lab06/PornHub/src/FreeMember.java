public class FreeMember extends Member {
  private int numPrivateRepos = 0;

  FreeMember(String email, String password) {
    super(email, password);
  }

  public boolean addRepository(Repository repo) {
    if (repo.isPrivate()) {
      if (this.getNumPrivateRepo() == 3) {
        return  false;
      } else {
        numPrivateRepos++;
        super.addRepository(repo);
        return true;
      }
    } else {
      super.addRepository(repo);
      return true;
    }
  }

  public boolean removeRepository(Repository repo) {
    boolean isRemoved = super.removeRepository(repo);
    if (isRemoved == true && repo.isPrivate() == true) {
      numPrivateRepos--;
    }
    return isRemoved;
  }

  public void printMemberInfo() {
    System.out.println("---- FREE MEMBER ----");
    super.printMemberInfo();
  }

  public int getNumPrivateRepo() {
  return numPrivateRepos;
  }

}
