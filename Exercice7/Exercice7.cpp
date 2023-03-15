/**
 * @ Author: Your name
 * @ Create Time: 2023-03-14 23:10:06
 * @ Modified by: Your name
 * @ Modified time: 2023-03-14 23:20:48
 * @ Description:
 */

#include <iostream>


//I won't provide any code to complete because as you can see it's very basic implementation but the logic behind is worth it

class EnemyBehaviour {
public:
    virtual void attack() = 0;
};

class FastAttackBehaviour : public EnemyBehaviour {
public:
    void attack() override {
        std::cout << "Ennemi attaque rapidement" << std::endl;
    }
};

class StrongAttackBehaviour : public EnemyBehaviour {
public:
    void attack() override {
        std::cout << "Ennemi attaque puissamment" << std::endl;
    }
};

class Enemy {
private:
    EnemyBehaviour* behaviour_;

public:
    Enemy(EnemyBehaviour* behaviour) : behaviour_(behaviour) {}

    void attack() {
        behaviour_->attack();
    }
};

main() {
    EnemyBehaviour* behaviour1 = new FastAttackBehaviour();
    Enemy* enemy1 = new Enemy(behaviour1);

    EnemyBehaviour* behaviour2 = new StrongAttackBehaviour();
    Enemy* enemy2 = new Enemy(behaviour2);

    enemy1->attack();
    enemy2->attack();
    delete behaviour1;
    delete enemy1;
    delete behaviour2;
    delete enemy2;

    return 0;
}

//Note: Once again it's one implementation of the strategy pattern, there are many others in function of the context.
// So this pattern is useful to make your code flexible, here there is only attack methods, but we can define many others.
//Setting different type of behaviours, combine them, etc...