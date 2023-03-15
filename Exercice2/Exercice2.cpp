#include <iostream>
#include <vector>

// Suppose you are developing a food ordering application for a restaurant,
// where customers can create customized orders from an online menu.
// The orders can include main dishes, drinks, desserts, etc.
// Each dish may have different options (e.g. size, extra ingredients, etc.).
// Implement the Builder pattern to create orders with customized dishes.

class Dish {
public:
    std::string &getName() { return name; }
    int &getPrice() { return price; }
    std::vector<std::string> &getOptions() { return options; }

    void print() {
        std::cout << name << " ($" << price << ")" << std::endl;
        for (std::string option : options) {
            std::cout << " - " << option << std::endl;
        }
    }
private:
    std::string name;
    int price;
    std::vector<std::string> options;

};

class OrderBuilder {
public:
    //complete
};

class CustomOrderBuilder : public OrderBuilder {
private:
    Dish order;

public:
    virtual void addMainDish() {
        //complete
    }

    virtual void addDrink() {
        //Complete

    }

    virtual void addDessert() {
        //Complete
    }

    virtual Dish getOrder() {
        //complete
    }
};

class OrderDirector {
public:
    //Complete
private:
    //complete
};


int main() {
    OrderBuilder* builder = new CustomOrderBuilder();
    OrderDirector director(/*complete\*/);
    Dish order = director.createOrder();
    order.print();
    return 0;
}

// Expected ouput:
// Custom Main Dish ($10)
//  - Large
//  - Extra cheese
//  - Soda
//  - Large
//  - Ice Cream
//  - Chocolate sauce

//Note: Put anything you want in the builder, this implementation is just an example
// The Builder can be useful in situations where object creation is complex and requires
// multiple configuration steps, or when the final object may have significant configuration variations.

// At Epitech you won't have many situations where you will need to use the Builder pattern, but it's still a good thing to know.


