import java.util.Scanner;

// Abstract Class: Account
abstract class Account {
    protected String accountNumber;
    protected double balance;

    public Account(String accountNumber, double balance) {
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    public abstract void deposit(double amount);

    public abstract void withdraw(double amount);

    public void displayBalance() {
        System.out.println(this);
    }

    @Override
    public String toString() {
        return "Account Number: " + accountNumber + "\nBalance: " + balance;
    }
}

// Subclass: SavingsAccount
class SavingsAccount extends Account {
    private double interestRate;

    public SavingsAccount(String accountNumber, double balance, double interestRate) {
        super(accountNumber, balance);
        this.interestRate = interestRate;
    }

    @Override
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            System.out.println("Deposit amount must be positive.");
        }
    }

    @Override
    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            System.out.println("Invalid withdraw amount.");
        }
    }

    public void addInterest() {
        balance += balance * interestRate / 100;
    }

    @Override
    public String toString() {
        return super.toString() + "\nInterest Rate: " + interestRate;
    }
}

// Subclass: CurrentAccount
class CurrentAccount extends Account {
    private double overdraftLimit;

    public CurrentAccount(String accountNumber, double balance, double overdraftLimit) {
        super(accountNumber, balance);
        this.overdraftLimit = overdraftLimit;
    }

    @Override
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            System.out.println("Deposit amount must be positive.");
        }
    }

    @Override
    public void withdraw(double amount) {
        if (amount > 0 && balance + overdraftLimit >= amount) {
            balance -= amount;
        } else {
            System.out.println("Invalid withdraw amount or overdraft limit exceeded.");
        }
    }

    @Override
    public String toString() {
        return super.toString() + "\nOverdraft Limit: " + overdraftLimit;
    }
}

// Main Class with Exception Handling
public class BankSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Enter account number: ");
            String accountNumber = scanner.nextLine();

            System.out.print("Enter initial balance: ");
            double balance = Double.parseDouble(scanner.nextLine());

            System.out.print("Enter account type (savings/current): ");
            String accountType = scanner.nextLine();

            Account account;

            if (accountType.equalsIgnoreCase("savings")) {
                System.out.print("Enter interest rate: ");
                double interestRate = Double.parseDouble(scanner.nextLine());
                account = new SavingsAccount(accountNumber, balance, interestRate);
            } else if (accountType.equalsIgnoreCase("current")) {
                System.out.print("Enter overdraft limit: ");
                double overdraftLimit = Double.parseDouble(scanner.nextLine());
                account = new CurrentAccount(accountNumber, balance, overdraftLimit);
            } else {
                throw new IllegalArgumentException("Invalid account type.");
            }

            System.out.print("Enter deposit amount: ");
            double depositAmount = Double.parseDouble(scanner.nextLine());
            account.deposit(depositAmount);

            System.out.print("Enter withdraw amount: ");
            double withdrawAmount = Double.parseDouble(scanner.nextLine());
            account.withdraw(withdrawAmount);

            account.displayBalance();

        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please enter a valid number.");
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
