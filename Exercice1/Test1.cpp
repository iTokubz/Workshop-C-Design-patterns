#include "Exercice1.hpp"
#include <assert.h>
#include <iostream>

void test_stock_manager()
{
    StockManager *manager1 = StockManager::get_instance();
    StockManager *manager2 = StockManager::get_instance();
    assert(manager1 == manager2);

    manager1->add_product("Produit 1", 10);
    manager2->add_product("Produit 2", 20);
    assert(manager1->get_stock("Produit 1") == 10);
    assert(manager1->get_stock("Produit 2") == 20);
    assert(manager2->get_stock("Produit 1") == 10);
    assert(manager2->get_stock("Produit 2") == 20);

    manager1->remove_product("Produit 1", 5);
    assert(manager1->get_stock("Produit 1") == 5);
    assert(manager2->get_stock("Produit 1") == 5);

    manager2->add_product("Produit 2", 5);
    assert(manager1->get_stock("Produit 2") == 25);
    assert(manager2->get_stock("Produit 2") == 25);
}

int main()
{
    test_stock_manager();
    std::cout << "Tous les tests passent." << std::endl;
    return 0;
}