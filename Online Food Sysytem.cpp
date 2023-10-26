#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FoodItem {
public:
    string name;
    double price;

    FoodItem(string n, double p) : name(n), price(p) {}
};

class Order {
public:
    string customerName;
    vector<FoodItem> items;

    Order(string name) : customerName(name) {}

    void addItem(FoodItem item) {
        items.push_back(item);
    }

    double calculateTotal() {
        double total = 0.0;
        for (const FoodItem &item : items) {
            total += item.price;
        }
        return total;
    }
};

class Menu {
public:
    vector<FoodItem> menuItems;

    void addItem(string name, double price) {
        menuItems.push_back(FoodItem(name, price));
    }

    void displayMenu() {
        cout << "Menu:\n";
        for (int i = 0; i < menuItems.size(); i++) {
            cout << i + 1 << ". " << menuItems[i].name << " - $" << menuItems[i].price << endl;
        }
    }

    int size() {
        return menuItems.size();
    }

    FoodItem getItem(int index) {
        return menuItems[index];
    }
};

int main() {
    Menu menu;
    menu.addItem("Veg Burger", 5.99);
    menu.addItem("Non-Veg Burger", 6.99);
    menu.addItem("Pizza", 8.99);
    menu.addItem("Shake", 3.49);
    menu.addItem("Veg Rolls", 6.99);
    menu.addItem("Non-Veg Rolls", 7.99);

    string customerName;
    cout << "Welcome to the Food Ordering System\n";
    cout << "Enter your name: "<<endl;
    cin >> customerName;
    

    Order order(customerName);

    while (true) {
        menu.displayMenu();
        cout << "Enter the item number to add to your order (0 to finish): ";
        int choice;
        cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > menu.size()) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        if (menu.getItem(choice - 1).name == "Pizza") {
            // If the user selected "Pizza," ask for the type of pizza
            cout << "Select the type of pizza:\n";
            cout << "1. Veg Pizza - $8.99\n";
            cout << "2. Non-Veg Pizza - $9.99\n";
            int pizzaChoice;
            cin >> pizzaChoice;

            if (pizzaChoice == 1) {
                order.addItem(FoodItem("Veg Pizza", 8.99));  // Add "Veg Pizza"
            } else if (pizzaChoice == 2) {
                order.addItem(FoodItem("Non-Veg Pizza", 9.99));  // Add "Non-Veg Pizza"
            } else {
                cout << "Invalid choice for pizza type. Please try again." << endl;
            }
        } else {
            order.addItem(menu.getItem(choice - 1));  // Add other items
        }
    }

    cout << "Order summary for " << order.customerName << ":\n";
    for (const FoodItem &item : order.items) {
        cout << item.name << " - $" << item.price << endl;
    }

    cout << "Total: $" << order.calculateTotal() << endl;
    cout << "Thank you for your order!" << endl;

    return 0;
}
