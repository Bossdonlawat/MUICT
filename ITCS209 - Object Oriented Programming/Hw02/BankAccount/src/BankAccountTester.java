public class BankAccountTester {
  public static void main(String args[]) {
    BankAccount account = new BankAccount();
    account.deposit(1000);
    account.withdraw(500);
    account.withdraw(400);
    System.out.println(account.getBalance());
  }
}
