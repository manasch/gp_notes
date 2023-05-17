// Encapsulation: Nested classes can be used to 
// hide implementation details from the outside world,
// making the outer class more modular and maintainable. 
// The inner class can access the private members of the
// outer class, allowing it to perform operations on 
// them in a way 
// that is hidden from the rest of the code.
#include <iostream>

class BankAccount {
private:
    class Transaction {
    public:
        int amount;
        void processTransaction() {
            // Perform the transaction
        }
    };

public:
    Transaction transaction;
    void performTransaction() {
        transaction.processTransaction();
    }
};

int main() {
    BankAccount account;
    account.transaction.amount = 100;
    account.performTransaction();
    return 0;
}
