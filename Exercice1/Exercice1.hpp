/**
 * @ Author: iTokubz
 * @ Description: Exercice 1
 */

// Problem:
// You are working on a project to develop a stock management software
// for an online selling company. This company needs to manage a centralized
//  inventory of the products they sell on multiple online platforms.
//  To ensure data consistency, there must be only one instance of the
//  "StockManager" class that is shared by different parts of the application.
//
// How can you use the Singleton design pattern to ensure that there is only one 7
// instance of the "StockManager" class at any time and that this instance is shared
// by all parts of the application that need it?

#include <iostream>
#include <map>
#include <string>

class StockManager
{
public:
    static StockManager *get_instance()
    {
        //Complete this method
    }

    void add_product(std::string product_name, int quantity)
    {
        stock[product_name] += quantity;
    }

    void remove_product(std::string product_name, int quantity)
    {
        if (stock.find(product_name) != stock.end()) {
            stock[product_name] -= quantity;
            if (stock[product_name] < 0) {
                stock[product_name] = 0;
            }
        }
    }

    int get_stock(std::string product_name)
    {
        if (stock.find(product_name) != stock.end()) {
            return stock[product_name];
        }
        return 0;
    }
private:
    static StockManager *instance;
    std::map<std::string, int> stock;
    StockManager() = default;
    // The constructor of a Singleton is set to private (or protected, as appropriate)
    // to prevent the creation of instances of the class from outside the class.
};

StockManager *StockManager::instance = nullptr;

//Note: the singleton pattern is not thread-safe by default.
//If you want to make it thread-safe, you can use the double-checked locking pattern.
//See https://en.wikipedia.org/wiki/Double-checked_locking