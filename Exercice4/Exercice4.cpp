/**
 * @ Author: iTokubz
 * @ Description: Exercice 4
 */

//imaginons que nous avons une classe Rectangle qui a une méthode draw() et une classe VectorDrawing qui a une méthode drawVectorRectangle()
//nous voulons adapter VectorDrawing pour qu'il puisse dessiner des rectangles
//pour cela, nous allons utiliser le design pattern Adapter

#include <iostream>

class Rectangle
{
public:
    virtual void draw() = 0;
    virtual ~Rectangle()
    {
    }
};

class VectorDrawing
{
public:
    void drawVectorRectangle()
    {
        std::cout << "Dessin d'un rectangle vectoriel" << std::endl;
    }
};

class VectorDrawingAdapter : public //complete
{
public:
    //complete
private:
   //complete
};

int main()
{
    Rectangle *r = new VectorDrawingAdapter(new VectorDrawing());
    r->draw();

    delete r;
    return 0;
}

// Note: I think the Adapter design pattern is very useful
//  for integrating third-party components into an existing application.

// However, it should be noted that the use of the adapter
//  can lead to a performance overhead. Therefore,
//  it is important to design the adapter well to minimize
//  this overhead.

// I don't know if you will find a usecases for this pattern in your projects, personally i nerver used it due to the performance overhead.
