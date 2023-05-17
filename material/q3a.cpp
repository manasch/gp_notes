#include <iostream>
#include <vector>
#include <string>

struct Sales {
    int cust_id;
    std::string product_name;
    int qty;
    double value;
    std::string date;
};

bool compare(const Sales& a, const Sales& b) {
    return (a.product_name == b.product_name) && (a.qty == b.qty);
}

void bummer(int cust_id, const std::vector<Sales>& data, const std::string& start_date, const std::string& end_date) {
    std::cout << "Products purchased by customer " << cust_id << " between " << start_date << " and " << end_date << ":" << std::endl;
    for (const auto& sale : data) {
        if (sale.cust_id == cust_id && sale.date >= start_date && sale.date <= end_date) {
            std::cout << sale.product_name << " (qty: " << sale.qty << ", value: " << sale.value << ")" << std::endl;
        }
    }
}

int main() {
    // Example data
    std::vector<Sales> data = {
        {1, "Apple", 10, 15.50, "2022-01-01"},
        {1, "Banana", 5, 8.25, "2022-01-02"},
        {1, "Apple", 8, 12.40, "2022-01-03"},
        {2, "Banana", 12, 10.20, "2022-01-04"},
        {2, "Apple", 6, 9.30, "2022-01-05"}
    };

    // Example usage
    Sales a = {1, "Apple", 10, 15.50, "2022-01-01"};
    Sales b = {1, "Apple", 8, 12.40, "2022-01-03"};
    std::cout << "Are sales a and b the same? " << (compare(a, b) ? "Yes" : "No") << std::endl;

    bummer(1, data, "2022-01-01", "2022-01-03");

    return 0;
}
