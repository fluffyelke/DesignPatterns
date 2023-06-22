/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>

struct BaseA {
    BaseA() {
        std::cout << "BaseA()" << std::endl;
    }
    virtual ~BaseA() {
        std::cout << "~BaseA destructor called" << std::endl;
    }
}; 
struct A : public BaseA{
    A() {
        std::cout << "A()" << std::endl;
    }
    ~A() {
        std::cout << "~A() destructor called" << std::endl;
    }
};

struct IBasePanel {
    IBasePanel() {
        std::cout << "IBasePanel() Constructor" << std::endl;
    }
    virtual ~IBasePanel() {
        std::cout << "~IBasePanel() Destructor" << std::endl;
    }
    virtual void drawField() = 0;
};
struct AlternativePanel : public IBasePanel {
    AlternativePanel() {
        std::cout << "AlternativePanel() Constructor" << std::endl;
    }
    ~AlternativePanel() {
        std::cout << "AlternativePanel() Destructor" << std::endl;
    }
    void drawField() override {
        std::cout << "AlternativePanel::drawField()" << std::endl; 
    }
};
struct NormalPanel : public IBasePanel {
    NormalPanel() {
        std::cout << "NormalPanel() Constructor" << std::endl;
    }
    ~NormalPanel() {
        std::cout << "NormalPanel() Destructor" << std::endl;
    }
    void drawField() override {
        std::cout << "NormalPanel::drawField()" << std::endl; 
    }
};

void usePanel(IBasePanel* panel) {
    panel->drawField();
}

struct Panel {
    IBasePanel* objPtr;
    Panel() {
        objPtr = new AlternativePanel();
    }
    ~Panel() {
        delete objPtr;
    }
    void changePtr() {
        delete objPtr;
        objPtr = nullptr;
        objPtr = new NormalPanel();
    }
};

void testPanel() {
    Panel p;
    usePanel(p.objPtr);
    p.changePtr();
    usePanel(p.objPtr);
}

void testInheritance() {
    BaseA *basePtr = new A();
    delete basePtr;
}