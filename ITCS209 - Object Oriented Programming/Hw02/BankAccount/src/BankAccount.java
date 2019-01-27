public class BankAccount {
  public double balance;
  public BankAccount() {
    balance = 0;
  }
  public void deposit(double deposit) {
    balance += deposit;
  }
  public void withdraw(double withdraw) {
    balance -= withdraw;
  }
  public double getBalance() {
    return balance;
  }
}
