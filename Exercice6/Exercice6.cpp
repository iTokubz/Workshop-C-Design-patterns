/**
 * @ Author: iTokubz
 * @ Description: Exercice 6
 */


//Pull model:


#include <iostream>
#include <vector>

class Subject;

class Observer {
public:
    virtual void update(Subject *subject) = 0;
};

class Subject {
private:
    std::vector<Observer *> observers_;
    int state_;

public:
    void attach(Observer *observer) {
        //complete
    }

    void setState(int state) {
        state_ = state; //basic logic
    }

    int getState() {
        return state_;
    }

    void notifyObservers() {
        //complete
    }
};

class PullObserver : public Observer {
public:
    void update(Subject *subject) override {
        std::cout << "PullObserver received update: " << subject->getState() << std::endl;
    }
};

int main() {
    Subject *subject = new Subject();

    PullObserver *pullObserver = new PullObserver();

    subject->attach(pullObserver);

    subject->setState(42);

    subject->notifyObservers();

    delete subject;
    delete pullObserver;

    return 0;
}

//The Pull model is often considered more resource-efficient, as clients only receive the data they explicitly request,
// whereas in the Push model, clients can receive data they don't use, which can lead to resource overload. However,
// the Push model may be more suitable for certain applications, such as real-time broadcasting or event notifications.

//Spoiler: It's not only C++ you can implement your own observer pattern in C and it's generally the same for all design patterns in C++.