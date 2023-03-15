//It's one of the design patterns that once created, you can use it in a lot of different projects.
//It's an template itrator that can iterate over any type of data.
//It's a very useful design pattern because it allows you to iterate over any type of data without having to create a specific iterator for each type of data.
//It's also very useful because it allows you to iterate over any type of data without having to know the type of data.
// Feel free to implement every data structure you want with this iterator.

#include <iostream>
#include <vector>
#include <string>

template <typename T>
class Iterator {
public:
    virtual /*complete\*/ next() = 0;
    virtual bool hasNext() = 0;
};

class StringIterator : public /*complete*/ {
private:
    std::vector<std::string> strings_;
    int current_;

public:
    StringIterator(std::vector<std::string> strings)
        : strings_(strings), current_(0)
    {
    }

    std::string next() override
    {
        if (hasNext()) {
            //complete
        }
        else {
            throw std::out_of_range("End of iterator");
        }
    }

    bool hasNext() override
    {
        return current_ < strings_.size();
    }
};

template <typename T>
void printData(Iterator<T> *iterator)
{
    while (iterator->hasNext()) {
        std::cout << iterator->next() << std::endl;
    }
}

int main()
{
    std::vector<std::string> strings = {"Hello", "world", "!"};

    Iterator<std::string> *stringIterator = new StringIterator(strings);
    printData(stringIterator);

    delete stringIterator;
    return 0;
}

//Note: It's not a must design pattern, but it's still useful to iterate of any type of data.
// It can be vector, hash map, list, etc.
// and it can be string, int, float, etc.
// Be careful when you're working in group because it's hard to understand the code if you don't know the type of data etc.