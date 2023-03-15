/**
 * @ Author: iTokubz
 * @ Description: Exercice 7
 */

#include <iostream>
#include <memory>

class Shape;
class Line;

// Suppose you are developing a card game for PC that uses a graphics library to
// display cards and animations. You initially decided to use SFML for the graphics
// design, but after launching the game, you receive feedback from players who prefer
// playing with a different graphics library, such as SDL2 or Ncurses.
//
// Instead of developing specific implementations of the game logic for each
// graphics library, you can use the Abstract Factory to create graphics objects
// that are tailored to each graphics library. Thus, by simply modifying the Factory
// used by the game, you could change the graphics library used.
//
// For example, you could create a GraphicsFactory interface that defines methods to
// create graphics elements such as cards, animations, and buttons, as well as implementations
// of this interface for each graphics library you wish to support. Then, you can use the Abstract Factory
// to create graphics objects that are adapted to each graphics library on the fly, depending on the option
// chosen by the player.


class GraphicsFactory
{
public:
    virtual ~GraphicsFactory() = default;
    virtual std::unique_ptr<Shape> createShape() = 0;
    virtual std::unique_ptr<Line> createLine() = 0;
};

class Shape
{
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

class Shape2D : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing 2D shape..." << std::endl;
    }
};

class Shape3D : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing 3D shape..." << std::endl;
    }
};

class Line
{
public:
    virtual ~Line() = default;
    virtual void draw() const = 0;
};

class Line2D : public Line
{
public:
    void draw() const override
    {
        std::cout << "Drawing 2D line..." << std::endl;
    }
};

class Line3D : public Line
{
public:
    void draw() const override
    {
        std::cout << "Drawing 3D line..." << std::endl;
    }
};

class Graphics2DFactory : public // complete
{
public:
    // Complete
};

class Graphics3DFactory : public // complete
{
public:
    // Complete
};

class GraphicObject
{
public:
    virtual ~GraphicObject() = default;
};

class DrawingApplication
{
public:
    DrawingApplication(/*Complete\*/)
        : // complete
    {
    }
    void draw()
    {
        auto shape = factory_->createShape();
        auto line = factory_->createLine();
        shape->draw();
        line->draw();
    }

private:
    GraphicsFactory *factory_;
};

int main()
{
    auto factory2D = std::make_unique<Graphics2DFactory>();
    auto app2D = DrawingApplication(factory2D.get());
    app2D.draw();

    auto factory3D = std::make_unique<Graphics3DFactory>();
    auto app3D = DrawingApplication(factory3D.get());
    app3D.draw();

    return 0;
}

//Note: In summary, the Abstract Factory pattern allows for the flexible
// and extensible creation of families of related or dependent objects. It
// provides an interface for creating objects without knowing their concrete
// class in advance, which enables greater modularity and better scalability
// of the code.


//Once again, this is just a basic and easy example.
//If you have properly understood what an abstract factory is,
//you will see some use cases in your Epitech projects.