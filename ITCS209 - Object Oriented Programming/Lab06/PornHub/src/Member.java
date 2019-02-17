import java.util.ArrayList;

public class Member {
  private String email;
  private String password;
  private ArrayList<Repository> repoList = new ArrayList<Repository>();

  Member(String email, String password) {
    this.email = email;
    this.password = password;
  }

  public boolean addRepository(Repository repo) {
    if (repo == null) {
      return false;
    } else {
      repoList.add(repo);
      return true;
    }
  }

  public boolean removeRepository(Repository repo) {
    boolean isRemoved = false;
    for (int i = 0 ; i < repoList.size() ; i++) {
      if (repo == repoList.get(i)) {
        repoList.remove(i);
        isRemoved = true;
        break;
      }
    }
    return isRemoved;
  }

  public void printMemberInfo() {
    System.out.println("Email: " + email + " (pwd: " + password + ")");
    System.out.println("List of repositories");
    for (Repository repo: repoList) {
      System.out.println(repo.toString());
    }
  }

}
