// Source can be found at: https://github.com/rayriffy/MUICT

public class Lad extends Person {
  public Lad(String name, int wife) {
    super(name, wife);
  }

  public Lad(String name) {
    super(name, 0);
  }

  @Override
  public String toString() {
    return "[LAD] " + super.getName();
  }
}
