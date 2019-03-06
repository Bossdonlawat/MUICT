// Source can be found at: https://github.com/rayriffy/MUICT

public class Thailand {
  public static void main(String[] args) {

    // Create palace
    Palace royalPalace = new Palace("Royal Palace");

    // Add King
    royalPalace.addPerson(new King("Ananda", 1, 8, true));
    royalPalace.addPerson(new King("Bhumibol", 1, 9, true));
    royalPalace.addPerson(new King("Vajiralongkorn ", 8, 10, false));

    // Add Lads
    royalPalace.addPerson(new Lad("But Patamasarin", 1));
    royalPalace.addPerson(new Lad("Chit Singhaseni", 1));
    royalPalace.addPerson(new Lad("Chaliew Pathumrot"));

    // Print
    System.out.println(royalPalace.toString());

  }
}
