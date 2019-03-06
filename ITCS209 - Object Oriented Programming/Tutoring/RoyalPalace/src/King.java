public class King extends Person {
  private int number;
  private boolean isDead;

  public King(String name, int wife, int number, boolean isDead) {
    super(name, wife);
    this.number = number;
    this.isDead = isDead;
  }

  @Override
  public String toString() {
    String echo = "[KING] " + this.getName();

    if (isDead == true) {
      echo += " is dead";
    }

    return echo;
  }
}
