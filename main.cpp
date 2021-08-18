#include <iostream>

class Memento;

class DataManager {
public:
    int getInt(Memento& m);
    void setInt(int i, Memento& m);
};

class Memento {
private:
    int memento;
public:
    friend int DataManager::getInt(Memento& m);
    friend void DataManager::setInt(int i, Memento& m);
};

class Object {
private:
    Memento m;
    DataManager c;
    void modifyState(int i) { c.setInt(i, m); }
public:
    Object() { c.setInt(0, m); }
    Memento getState() const { return m; }
    bool addOne();
};

int DataManager::getInt(Memento& m) {
    return m.memento;
}

void DataManager::setInt(int i, Memento& m) {
    m.memento = i;
}

bool Object::addOne() {
    int newInt = c.getInt(m) + 1;

    if (newInt < 10) {
        c.setInt(newInt, m);
        return true;
    }
    else
    {
        return false;
    }
}

int main(int, char**) {
    Object o;

    o.getState();

    std::cout << "Hello, no!\n";
}
