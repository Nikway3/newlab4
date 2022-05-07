#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Вариант - 19
// D) Равносторонний треугольник
// H) Эллипс

// Интерфейс "Геометрическая фигура"
class IGeoFig {
public:
    // Площадь
    virtual double square()=0;
    // Перимет
    virtual double perimeter()=0;
};

// Вектор
class Vector2D {
public:
    double x, y;
};

// Интерфейс "Физический объект"
class PhysObject {
public:
    // Масса, кг
    virtual double mass() =0;
    // Координаты центра масс, м
    virtual Vector2D position()=0;
    // Сравнение по массе.
    virtual bool operator== (PhysObject& ob) const=0;
    // Сравнение по массе.
    virtual bool operator< (PhysObject& ob) const=0;
};

// Интерфейс "Отображаемый"
class Printable {
public:
    // Отобразить на экране(выводить в текстово виде параметры фигуры)
    virtual void draw()=0;
};

// Интерефейс для классов, которые можно задать через диалог с пользователем
class DialogInitiable {
    // Задать параметры объекта с помошью диалога с пользователем
    virtual void initFromDialog()=0;
};

// Интерфейс "Класс"
class BaseObject {
public:
    // Имя класса (типа данных)
    virtual const char* classname()=0;
    // Размер занимаемой памяти
    virtual int size()=0;
};
class Tmp_figure: public IGeoFig,
                  public PhysObject,
                  public Printable,
                  public DialogInitiable,
                  public BaseObject{};

class Equilateral_Triangle:
        Tmp_figure{
private:
    Vector2D v1, v2, v3;
    double mass_in;
public:
    Equilateral_Triangle();
    void initFromDialog() override;
    double square() override;
    double perimeter() override;
    double mass() override;
    Vector2D position() override;
    bool operator== (PhysObject& ob) const override{
        return (mass_in == ob.mass());
    }
    bool operator< (PhysObject& ob) const override {
        return (mass_in < ob.mass());
    }
    void draw() override;
    const char* classname() override;
    int size() override;
};

class Ellipse:
        Tmp_figure {

private:
    double xCenter, yCenter;
    double a, b;
    double mass_in;
public:
    Ellipse();
    void initFromDialog() override;
    double square() override;
    double perimeter() override;
    double mass() override;
    Vector2D position() override;
    bool operator== (PhysObject& ob) const override {
        return (mass_in == ob.mass());
    }
    bool operator< (PhysObject& ob) const override {
        return (mass_in < ob.mass());
    }
    void draw() override;
    const char* classname() override;
    int size() override;
};