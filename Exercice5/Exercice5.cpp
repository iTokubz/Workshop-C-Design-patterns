/**
 * @ Author: itokubz
 * @ Description: Exercice 7
 */


#include <iostream>
#include <vector>
#include <string>

//Didn't find any problem but keep in mind that observer is useful when you have to update a lot of objects when something changes.

class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

class Subject {
public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void unregisterObserver(Observer* observer) = 0;
    virtual void notifyObservers(const std::string& message) = 0;
};

class Server : public Subject {
private:
    std::vector<Observer*> observers;
public:
    //Complete the class with the functions in the interface Subject
};

class Client : public Observer {
private:
    std::string name;
public:
    Client(const std::string& name) : name(name) {}
    void update(const std::string& message) override {
        std::cout << "Client " << name << " a reçu le message : " << message << std::endl;
    }
};

int main() {
    Server server;

    Client client1("Alice");
    Client client2("Bob");
    server.registerObserver(&client1);
    server.registerObserver(&client2);

    server.notifyObservers("Bonjour tout le monde !");

    server.unregisterObserver(&client2);

    server.notifyObservers("Il est temps de jouer !");
    return 0;
}

//Note: in this exemple, the server is the subject and the clients are the observers.
// The server is the one that notifies the observers when a message is received.
// The observers are the ones that update themselves when they receive a message from the server.
// It's one of the most common design patterns in C++.
// It's one  implementation of the Observer pattern and it's called the Push model.
// The other implementation is called the Pull model and it's the one that we're going to see in the next exercice.

//Personnally it's one of my favorite design pattern because it's very useful and
// it's very easy to understand. It's also very easy to implement.
// I would have known this design pattern before, I would have used it in my previous projects.
