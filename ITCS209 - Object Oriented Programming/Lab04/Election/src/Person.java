public class Person {
  private MyDate birthday;
  private String firstname, lastname;

  public Person(String firstname, String lastname) {
    this.firstname = firstname;
    this.lastname = lastname;
    this.birthday = new MyDate();
  }

  public Person(String firstname, String lastname, int year, int month, int day) {
    this.firstname = firstname;
    this.lastname = lastname;
    this.birthday = new MyDate(year, month, day);
  }

  public int getAge(MyDate aDate) {
    return MyDate.yearDiff(birthday, aDate);
  }

  public boolean isEligible(MyDate elecDate) {
    if (this.getAge(elecDate) >= 18) {
      return true;
    }
    else {
      return false;
    }
  }

  public void printPersonInfo() {
    System.out.println("Person: " + this.firstname + " " + this.lastname);
    System.out.println("Birthday: " + this.birthday.toString());
  }
}
