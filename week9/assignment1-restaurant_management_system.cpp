/*
This program is quite bloated/messy. 
I planned to split this into multiple files, although time got ahead of me.
With this, the only function unfinished is the kitchen view for prepping and pending orders. 
The Final program will be more polished and organized.
Oh, by the way, the passcode is 1234.
*/
#include <iostream>
#include <limits>
#include <cstdio>
#include <sstream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <memory>
#include <functional>
#include <algorithm>
#include <numeric>
using namespace std;


//Input Validations
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


int getIntInput() {
    int value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a number: ";
        clearInputBuffer();
    }
    clearInputBuffer();  
    return value;
}


double getDoubleInput() {
    double value;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a decimal: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}

//Enums
enum class MenuCategory {
    APPETIZER,
    MAIN_COURSE,
    DESSERT,
    BEVERAGE

};

enum class OrderStatus {
    PENDING,
    PREPARING,
    READY,
    SERVED,
    CANCELLED

};

enum class ItemSize{
    SMALL,
    MEDIUM,
    LARGE,
    FAMILY

};

enum class PaymentMethod{
    CASH,
    CREDIT_CARD,
    DEBIT_CARD,
    MOBILE_PAY

};

enum class Priority{
    LOW,
    MEDIUM,
    HIGH,
    URGENT

};


class MenuItem {
private:
    string id;
    double price;
    string name;
    MenuCategory category;
    int preptime;

    static constexpr double SIZE_MULTIPLIERS[] = {1.0, 1.3, 1.6, 2.0};
    static constexpr double APPETIZER_BASE = 8.50;
    static constexpr double MAIN_COURSE_BASE = 18.00;
    static constexpr double DESSERT_BASE = 6.75;
    static constexpr double BEVERAGE_BASE = 3.25;


public: 
    //Constructor
    MenuItem() : id(" "), price(0.0), name(" "), category(MenuCategory::MAIN_COURSE), preptime(0) {}
    MenuItem(string i, double p, string n, MenuCategory cat, int pt)
        : id{move(i)}, price{p}, name{move(n)}, category{cat}, preptime{pt} {
            if (price <= 0) throw invalid_argument("Price must be positive");
            if (preptime <= 0) throw invalid_argument("Preptime must be positive");
        }

    //Getters
    string getMenuItemId() const { return id; }
    double getMenuItemPrice() const { return price; }
    const string& getMenuItemName() const { return name; }
    MenuCategory getMenuItemCategory() const { return category; }
    int getMenuItemPrepTime() const { return preptime; }

    double getPriceAppetizer() const { return APPETIZER_BASE; }
    double getPriceMain() const { return MAIN_COURSE_BASE; }
    double getPriceDessert() const { return DESSERT_BASE; }
    double getPriceBev() const { return BEVERAGE_BASE; }

    //Setters
    void setMenuItemId(string i) { id = i; } 
    void setMenuItemPrice(double p) { price = p; }
    void setMenuItemName(string n) { name = n; }
    void setMenuItemCategory(MenuCategory cat) { category = cat; }
    void setMenuItemPrepTime(int pt) { preptime = pt; }
    
    //Price calculation using the enum of size
    auto calculatePrice(ItemSize size) const {
        double newprice = 0.0;

        switch(size) {

            case ItemSize::SMALL:
                newprice = SIZE_MULTIPLIERS[0];
                break;
            case ItemSize::MEDIUM:
                newprice = SIZE_MULTIPLIERS[1];
                break;
            case ItemSize::LARGE:
                newprice = SIZE_MULTIPLIERS[2];
                break;
            case ItemSize::FAMILY:
                newprice = SIZE_MULTIPLIERS[3];
                break;
            default:
                cout << "\n - Error in Price Calculation - \n";
                break;

        }

        return newprice;
    }

    //Adding to menu for admins
    auto addMenuItem() {
        //Initializing user entered data and defaults in case of error
        string id, name;
        double price = 0.0;
        int preptime = 0;
        MenuCategory category = MenuCategory::MAIN_COURSE;
        ItemSize size = ItemSize::SMALL;
        int choice = 0;
        int size_choice = 0;

        cout << "\nEnter the item name: ";
        getline(cin, name);

        //Checks for size
        cout << "\nEnter the item's size (0 for small/1 for medium/2 for large/3 for family): ";
        size_choice = getIntInput();
        switch(size_choice) {
            case 0:
                size = ItemSize::SMALL;
                break;
            case 1:
                size = ItemSize::MEDIUM;
                break;
            case 2:
                size = ItemSize::LARGE;
                break;
            case 3:
                size = ItemSize::FAMILY;
                break;
            default:
                cout << "-Invalid entry (defaulted to Small Size) -";
                break;
        }

        //Checks for and enters category
        cout << "\nEnter the item category \n(0 for Appetizer/1 for Main Course/2 for Dessert/3 for Beverage): ";
        choice = getIntInput();
        switch(choice) {
            case 0:
                category = MenuCategory::APPETIZER;
                price = APPETIZER_BASE * calculatePrice(size);
                break;
            case 1:
                category = MenuCategory::MAIN_COURSE;
                price = MAIN_COURSE_BASE * calculatePrice(size);
                break;
            case 2:
                category = MenuCategory::DESSERT;
                price = DESSERT_BASE * calculatePrice(size);
                break;
            case 3:
                category = MenuCategory::BEVERAGE;
                price = BEVERAGE_BASE * calculatePrice(size);
                break;
            default:
                cout << "-Invalid entry (defaulted to Main Course) -";
                break;
        }


        cout << "\nEnter the item id: ";
        getline(cin, id);
        
        cout << "\nEnter the item prep time: ";
        preptime = getIntInput();

        return MenuItem(id, price, name, category, preptime);
    }



    //displays whole menu
    void displayMenu() const {
        cout << "\nDish: " << name;
        cout << "\nID: " << id;
        cout << "\nCategory: ";
        if (category == MenuCategory::MAIN_COURSE) {cout << "Main Course";};
        if (category == MenuCategory::APPETIZER) {cout << "Appetizer";};
        if (category == MenuCategory::DESSERT) {cout << "Dessert";};
        if (category == MenuCategory::BEVERAGE) {cout << "Beverage";};
        cout << "\nPrice: $" << price;
        cout << "\nPrep Time: " << preptime << " minutes\n----\n";

        return;        

    }
    
};


class Order {
private:
    vector<MenuItem> items;
    OrderStatus status;
    double totalprice;

public:

//Constructor
    Order() : status(OrderStatus::PENDING), totalprice(0.0) {}

    Order(OrderStatus stat, double tp)
        : status{stat}, totalprice{tp} {
            if (totalprice < 0) throw invalid_argument("-Price must be positive-");
        }


    //Getters
    double getTotalPrice() const { return totalprice; }
    OrderStatus getStatus() const { return status; } 

    //Setters
    void setStatus(OrderStatus stat) { status = stat; }

    //Displays the order status enum
    void displayState() const {
        switch (status) {
            case OrderStatus::PENDING: cout << "Pending"; break;
            case OrderStatus::PREPARING: cout << "Preparing"; break;
            case OrderStatus::READY: cout << "Ready"; break;
            case OrderStatus::SERVED: cout << "Served"; break;
            case OrderStatus::CANCELLED: cout << "Cancelled"; break;
        }
    }

    //Adds menu items to order for reading later
    void addOrderItem(const MenuItem& item) {
        items.push_back(item);
    }

    //Displays items in menu for selection to order
    void displayOrderMenu() const {
        cout << "=== Menu ===\n";
        for (size_t i = 0; i < items.size(); i++){
            cout << i + 1 << ". " << items[i].getMenuItemName()
            << " - $" << items[i].calculatePrice(ItemSize::SMALL) * items[i].getMenuItemPrice()
            << " (S) / $" << items[i].calculatePrice(ItemSize::MEDIUM) * items[i].getMenuItemPrice()
            << " (M) / $" << items[i].calculatePrice(ItemSize::LARGE) * items[i].getMenuItemPrice()
            << " (L) / $" << items[i].calculatePrice(ItemSize::FAMILY) * items[i].getMenuItemPrice()
            << " (F)\n";

        }

    }

    //Places order from user input
    void placeOrder(vector<Order>& orders) {
        bool error = false;
        bool order_run = true;
        int choice = 0;
        double totalprice = 0.0;
        orders[0].displayOrderMenu();


        while (order_run != false) {
            int item_number = 0;
            double item_price = 0;
            int size_choice = 0;
            ItemSize size;
            cout << "\n - Placing Order - \n";
            cout << "\nEnter item number: ";
            item_number = getIntInput();
            //Here, if input is invalid, throw error, if not, get the item's price from the category enum
            if (item_number <= 0 || item_number > orders[0].items.size()) {
                cout << "Invalid Entry";
                item_number = 0;
            }
            else {
                if (orders[0].items[item_number - 1].getMenuItemCategory() == MenuCategory::APPETIZER) { item_price = items[0].getPriceAppetizer();};
                if (orders[0].items[item_number - 1].getMenuItemCategory() == MenuCategory::MAIN_COURSE) { item_price = items[0].getPriceMain();};
                if (orders[0].items[item_number - 1].getMenuItemCategory() == MenuCategory::DESSERT) { item_price = items[0].getPriceDessert();};
                if (orders[0].items[item_number - 1].getMenuItemCategory() == MenuCategory::BEVERAGE) { item_price = items[0].getPriceBev();};
            }

            //Grabs the size and appends to user's choice
            cout << "\nSelect size (1=Small, 2=Medium, 3=Large, 4=Family): ";
            size_choice = getIntInput();
            if (size_choice <= 0 || size_choice > 4) {
                cout << "Invalid Entry";
                size_choice = 0;
            }
            else {
                if (size_choice == 1) {size = ItemSize::SMALL;};
                if (size_choice == 2) {size = ItemSize::MEDIUM;};
                if (size_choice == 3) {size = ItemSize::LARGE;};
                if (size_choice == 4) {size = ItemSize::FAMILY;};
            }

            //Error check for invalid numbers
            if (item_number == 0 || size_choice == 0) {
                cout << "\n -- Order not entered due to error -- ";
                error = true;
            }
            else {
                totalprice = items[0].calculatePrice(size) * item_price;
            }

            cout << "\nAdd another item? (0 for no/1 for yes): ";
            choice = getIntInput();

            if (choice == 1) {
                order_run = true;
            }
            else {
                if (error == true) {
                    return;
                }
                else {
                    //Diplays order summary
                    cout << "\n\nOrder Summary:\n";
                    cout << "- " << orders[0].items[item_number - 1].getMenuItemName() 
                    << ": $" << orders[0].items[item_number - 1].calculatePrice(size);
                    cout << "\nSubtotal: $" << totalprice;
                    cout << "\nTax (8.5%): $" << fixed << setprecision(2) << totalprice * 0.085;
                    cout << "\nTotal: $" << fixed << setprecision(2) << totalprice *1.085;

                    //Confirms order and adds to order vector
                    char confirm;
                    cout << "\n\nConfirm Order? (y/n): ";
                    cin >> confirm;
                    clearInputBuffer();
                    if (toupper(confirm) == 'Y') {
                        Order neworder(OrderStatus::PENDING, totalprice);
                        orders.push_back(neworder);        
                        cout << "\n-Order Created Successfully-\n";                
                        cout << "Estimated Wait: 20 minutes (Order Pending)";
                    }
                    else {
                        cout << "-Order not confirmed-";
                    }


                }    

                order_run = false;       
            }

        }


    }

    //Updates existing orders
    void updateOrder(vector<Order>& orders, int choice) {
        int stat = 0;

        //Grabs status from user and sets it to the chosen order
        cout << "\nWhat would you like the status to be?\n";
        cout << "(0 for Preparing/1 for Ready, 2 for Served, 3 for Cancelled)";
        stat = getIntInput();
        switch (stat) {
            case 0:
                orders[choice].setStatus(OrderStatus::PREPARING);
                cout << "\n - Order Status Updated - \n";
                break;

            case 1:
                orders[choice].setStatus(OrderStatus::READY);
                cout << "\n - Order Status Updated - \n";
                break;

            case 2:
                orders[choice].setStatus(OrderStatus::SERVED);
                cout << "\n - Order Status Updated - \n";
                break;

            case 3:
                orders[choice].setStatus(OrderStatus::CANCELLED);
                cout << "\n - Order Status Updated - \n";
                break;

            default:
                cout << "-Error-";
                break;

        };

    }


    //void kitchenView(vector<Order>& orders, int i) const {
        //if (orders[i].getStatus() == OrderStatus::PENDING || orders[i].getStatus() == OrderStatus::PREPARING) {
    	//    cout << orders[i].items[i].getMenuItemName();
        //}
    //}

};


class Inventory {
private:
    string ingredient;
    int quantity;
    int reserved_quantity;

    bool isValidQuantity(int q, int rq) const {
        if (q < 0) {
            return false;
        }
        else if (rq < 0) {
            return false;
        }
    }

public:
//Constructor
    Inventory() : ingredient("Salmon"), quantity(12), reserved_quantity(3) {}
    Inventory(const string& in, int q, int rq)
        : ingredient(in), quantity(q), reserved_quantity(rq) {}  


    //Getters
    string getInventoryIngredient() const { return ingredient; }
    int getInventoryQuantity() const { return quantity; }
    int getInventoryReserved() const { return quantity; }

//Validation check
    Inventory(int q, int rq) {
        if (isValidQuantity(q, rq)) {
            quantity = q;
            reserved_quantity = rq;
        }
        else {
            quantity = 0;
            reserved_quantity = 0;
        }
    }
//Validation check
    bool setInventory(int q, int rq) {
        if (isValidQuantity(q, rq)) {
            quantity = q;
            reserved_quantity = rq;
            return true;
        }
        return false; 
    }

    //Adds ingredeints and quantities to inventory
    auto addIngredient() {
        bool error = true;
        string ingredient;
        int quantity = 0;
        int reserved_quantity = 0;

        cout << "\nEnter Ingredient: ";
        getline(cin, ingredient);
        cout << "\nEnter Quantity: ";
        quantity = getIntInput();
        cout << "\nEnter Reserved Quantity: ";
        reserved_quantity = getIntInput(); 

        //I was going to use the isValidQuantity function, although it wouldn't work properly
        //Here, this is the replacement check function
        if (quantity < 0 || reserved_quantity < 0) {
            error = true;
        }
        else {
            error = false;
        }
    
        //Checks for error, if none, appends to inventory
        if (error == true) {
            cout << " - Error, invalid entry - ";
            quantity = 0;
            reserved_quantity = 0;
            return Inventory(ingredient, quantity, reserved_quantity);

        }
        else {
            return Inventory(ingredient, quantity, reserved_quantity);
        }
    }

    //Displays inventory 
    void displayInventory() const {
        cout << "\nItem: " << ingredient;
        cout << "\nAmount: " << quantity;
        cout << "\nReserved Amount: " << reserved_quantity;
        cout << "\n----";

    }

};



//user menu
int displayMenu() {
    cout << "\n======== RESTAURANT SYSTEM ========\n";
    cout << "1. View Menu\n";
    cout << "2. Place New Order\n";
    cout << "3. View Order Status\n";
    cout << "4. Update Order\n";
    cout << "5. Kitchen View (pending/preparing orders)\n"; 
    cout << "6. Inventory Status\n"; 
    cout << "7. Exit\n";
    cout << "Enter your choice (1-7): ";

    return getIntInput();
}


//Unfinished display for entire kitchen with orders, status, and inventory (time restraint)
void initialDisplay(vector<Order> orders) {
    cout << "=== RESTAURANT MANAGEMENT SYSTEM == \n\n";
    //cout << "Order #" << "[status]";
    //cout << "Menu Item 1 (size) - ready in PREPTIME min";
    //cout << "Priority PRIORITY"; 



}


//Initiallizes values for orders, menu items, and inventory as to save time for user
auto initializeRestaurant(vector<MenuItem>& whole_menu, vector<Order>& orders, vector<Inventory>& inventory) {
    MenuItem menupop1("101", 18.00, "Grilled Salmon", MenuCategory::MAIN_COURSE, 15);
    MenuItem menupop2("102", 18.00, "Ribeye Steak", MenuCategory::MAIN_COURSE, 20);
    MenuItem menupop3("103", 8.5, "Cesar Salad", MenuCategory::APPETIZER, 10);
    MenuItem menupop4("104", 8.5, "Buffalo Wings", MenuCategory::APPETIZER, 12);

    whole_menu.push_back(menupop1);
    whole_menu.push_back(menupop2);
    whole_menu.push_back(menupop3);
    whole_menu.push_back(menupop4);


    Order orderpop1(OrderStatus::PENDING, 0.0);
    Order orderpop2(OrderStatus::CANCELLED, 0.0);
    orders.push_back(orderpop1);
    orders.push_back(orderpop2);
    orders[0].addOrderItem(menupop1);
    orders[0].addOrderItem(menupop2);
    orders[0].addOrderItem(menupop3);
    orders[0].addOrderItem(menupop4);

    Inventory inv1("Salmon", 10, 5);
    Inventory inv2("Steak", 15, 5);
    Inventory inv3("Buffalo Wings", 21, 2);

    inventory.push_back(inv1);
    inventory.push_back(inv2);
    inventory.push_back(inv3);

    return whole_menu, orders, inventory;
}

//Main function
int main() {
    //Initializes user values and passwords
    bool running = true;
    char admin_entry_char = 'n';
    string admin_entry_pass = "1234"; 
    int choice = 0;

    //Initializes classes
    vector<MenuItem> whole_menu;
    MenuItem menu;

    vector<Order> orders;
    Order order;

    vector<Inventory> inventory;
    Inventory inv;
    

    initializeRestaurant(whole_menu, orders, inventory);


    initialDisplay(orders);


        while (running) {
            int choice = displayMenu();

            switch (choice) {
                case 1: //View menu

                    cout << "Would you like to add to the menu? (Enter y/n) [Admins Only]";
                    cin >> admin_entry_char;
                    clearInputBuffer();

                    //Checks if user has admin priviledges
                    if (toupper(admin_entry_char) == 'Y') {
                        cout << "Enter the passcode: ";
                        getline(cin, admin_entry_pass);
                        if (admin_entry_pass == "1234") {
                            whole_menu.push_back(menu.addMenuItem());
                            
                        }
                        else {
                            cout << "-Incorrect Password-";
                        }
                    }

                    //Displays menu
                    else { 
                        cout << "\n~~~~~~ Menu ~~~~~~\n";
                        for (size_t i = 0; i < whole_menu.size(); i++) {
                            whole_menu[i].displayMenu();
                        }; 
                    }
                    break;

                case 2: //Place order

                    order.placeOrder(orders);
                    break;

                case 3: //View order stats

                    for (size_t i = 0; i < orders.size(); i++) {
                        cout << "Order #" << i + 1 << ": ";
                        orders[i].displayState();
                        cout << "\n";
                    }
                    break;

                case 4: //update order

                    cout << "\nWhich order would you like to update? (1-" << orders.size() << ")";
                    choice = getIntInput() - 1;
                    if (choice < 0 || choice > orders.size()) {
                        cout << "\n-Invalid Entry-";
                        break;
                    };
                    orders[choice].updateOrder(orders, choice);
                    break;

                case 5: //kitchen view
                    //for (size_t i = 0; i < orders.size(); i++) {
                    //    orders[i].kitchenView(orders, i);
                    //}
                    break;

                case 6: //inventory status

                    cout << "Would you like to add to the inventory? (Enter y/n) [Admins Only]";
                    cin >> admin_entry_char;
                    clearInputBuffer();

                    //Checks if user has admin priviledges
                    if (toupper(admin_entry_char) == 'Y') {
                        cout << "Enter the passcode: ";
                        getline(cin, admin_entry_pass);
                        if (admin_entry_pass == "1234") {
                            inventory.push_back(inv.addIngredient()); 
                        }
                        else {
                            cout << "-Incorrect Password-";
                        }
                    }

                    //Diplays Inventory
                    cout << "\n--== Inventory ==--\n";
                    for (size_t i = 0; i < inventory.size(); i++) {
                        inventory[i].displayInventory();
                    };
                    cout << "\n\n----End of Inventory----\n";
                    break;


                case 7: // Exit
                    cout << "\n -- Exiting System -- \n";
                    running = false;
                    break;

                default:
                    cout << "\nInvalid choice. Please try again.\n";
            }
        }

    return 0;
}
