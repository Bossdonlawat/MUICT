import java.util.ArrayList;

public class Palace {
  private String name;
  private ArrayList<King> kings = new ArrayList<King>();
  private ArrayList<Lad> lads = new ArrayList<Lad>();

  public Palace(String name) {
    this.name = name;
  }

  public void addPerson(Person person) {
    if (person instanceof King) {
      kings.add((King) person);
    } else {
      lads.add((Lad) person);
    }
  }

  public String toString() {
    String out = "Palace: " + this.name + "\nLads\n====\n";

    for(Lad lad: lads) {
      out += lad.toString() + "\n";
    }

    out += "Kings\n=====\n";

    for(King king: kings) {
      out += king.toString() + "\n";
    }

    return out;
  }
}
