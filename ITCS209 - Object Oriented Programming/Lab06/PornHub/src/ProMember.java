import java.util.ArrayList;

public class ProMember extends Member {
  private double fee = 0;
  private static double COLLOABORATOR_FEE = 80;
  private ArrayList<String> collaborators = new ArrayList<String>();

  ProMember(String email, String password, double fee) {
    super(email, password);
    this.fee = fee;
  }

  public void printMemberInfo() {
    System.out.println("---- PRO MEMBER ----");
    System.out.println("Member fee: " + fee);
    super.printMemberInfo();
    System.out.println("---------------------");
    System.out.println("List of collaborators");
    for (String collaborator: collaborators) {
      System.out.print(collaborator + ", ");
    }
    System.out.println();
  }

  public boolean addCollaborator(String username) {
    if (username == null) {
      return false;
    } else {
      collaborators.add(username);
      return true;
    }
  }

  public boolean removeCollaborator(String username) {
    boolean isRemoved = false;
    for (int i = 0 ; i < collaborators.size() ; i++) {
      if (username == collaborators.get(i)) {
        collaborators.remove(i);
        isRemoved = true;
        break;
      }
    }
    return isRemoved;
  }

  public double getMonthlyBill() {
    return COLLOABORATOR_FEE * collaborators.size() + fee;
  }
}
