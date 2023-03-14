/**
 * @ Author: iTokubz
 * @ Description: Exercice 1
 */

//Problème:
//Vous travaillez sur un projet de développement d'un logiciel de gestion de stocks pour une
//entreprise de vente en ligne. Cette entreprise doit gérer un inventaire centralisé des produits
//qu'elle vend sur plusieurs plateformes en ligne. Pour assurer la cohérence des données, il doit y
//avoir une seule instance de la classe "StockManager" qui est partagée par différentes parties de l'application.

//Comment pouvez-vous utiliser le design pattern Singleton pour garantir qu'il n'y a qu'une seule
//instance de la classe "StockManager" à tout moment et que cette instance est partagée par toutes
//les parties de l'application qui en ont besoin?

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
    //Le constructeur d'un Singleton est en private (ou protected, selon le cas)
    //pour empêcher la création d'instances de la classe à partir de l'extérieur
    //de la classe
};

StockManager *StockManager::instance = nullptr;
