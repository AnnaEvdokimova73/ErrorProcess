#include <iostream>

class Figure {
public:
    Figure() : sidesCount{ 0 }, name{ "Фигура" } {
        if (this->sidesCount != 0)
        {
            throw std::invalid_argument("Ошибка создания фигуры.Причина: количество сторон не равно 0\n");
        }
    }

    virtual void printInfo()
    {
        std::cout << this->name;
        std::cout << " создана" << std::endl;
    }

    int getSidesCount()
    {
        return this->sidesCount;
    }

protected:
    std::string name;
    int sidesCount;
};

class Triangle : public Figure {
public:
    Triangle(int _sidesCount, int _a, int _b, int _c, int _A, int _B, int _C) : Figure()
    {
        if (_sidesCount != 3)
        {
            throw std::invalid_argument("Ошибка создания треугольника. Причина: количество сторон не равно 3\n");
        }
        if (_A + _B + _C != 180)
        {
            throw std::invalid_argument("Ошибка создания треугольника. Причина: сумма углов не равна 180\n");
        }

        this->name = "Треугольник";
        this->sidesCount = _sidesCount;
        this->a = _a;
        this->b = _b;
        this->c = _c;
        this->A = _A;
        this->B = _B;
        this->C = _C;
    }

    virtual void printInfo() override
    {
        std::cout << this->name;
        std::cout << " (стороны ";
        std::cout << this->geta() << ", ";
        std::cout << this->getb() << ", ";
        std::cout << this->getc() << "; ";
        std::cout << "углы ";
        std::cout << this->getA() << ", ";
        std::cout << this->getB() << ", ";
        std::cout << this->getC() << ") ";
        std::cout << "создан" << std::endl;
    }

    int geta()
    {
        return this->a;
    }

    int getb()
    {
        return this->b;
    }

    int getc()
    {
        return this->c;
    }

    int getA()
    {
        return this->A;
    }

    int getB()
    {
        return this->B;
    }

    int getC()
    {
        return this->C;
    }

protected:
    int a, b, c;
    int A, B, C;
};

class Quadrilateral : public Figure {
public:
    Quadrilateral(int _sidesCount, int _a, int _b, int _c, int _d, int _A, int _B, int _C, int _D) : Figure()
    {
        if (_sidesCount != 4)
        {
            throw std::invalid_argument("Ошибка создания четырехугольника. Причина: количество сторон не равно 4\n");
        }
        if (_A + _B + _C + _D != 360)
        {
            throw std::invalid_argument("Ошибка создания четырехугольника. Причина: сумма углов не равна 360\n");
        }

        this->name = "Четырехугольник";
        this->sidesCount = _sidesCount;
        this->a = _a;
        this->b = _b;
        this->c = _c;
        this->d = _d;
        this->A = _A;
        this->B = _B;
        this->C = _C;
        this->D = _D;
    }

    virtual void printInfo() override
    {
        std::cout << this->name;
        std::cout << " (стороны ";
        std::cout << this->geta() << ", ";
        std::cout << this->getb() << ", ";
        std::cout << this->getc() << ", ";
        std::cout << this->getd() << "; ";
        std::cout << "углы ";
        std::cout << this->getA() << ", ";
        std::cout << this->getB() << ", ";
        std::cout << this->getC() << ", ";
        std::cout << this->getD() << ") ";
        std::cout << "создан" << std::endl;
    }

    int geta()
    {
        return this->a;
    }

    int getb()
    {
        return this->b;
    }

    int getc()
    {
        return this->c;
    }

    int getd()
    {
        return this->d;
    }

    int getA()
    {
        return this->A;
    }

    int getB()
    {
        return this->B;
    }

    int getC()
    {
        return this->C;
    }
    int getD()
    {
        return this->D;
    }

protected:
    int a, b, c, d;
    int A, B, C, D;
};

// Прямоугольный треугольник
class RectTrian : public Triangle {
public:
    RectTrian(int _sidesCount, int _a, int _b, int _c, int _A, int _B, int _C) :
        Triangle(_sidesCount, _a, _b, _c, _A, _B, _C)
    {
        if (!(_A == 90 || _B == 90 || _C == 90))
        {
            throw std::invalid_argument("Ошибка создания прямоугольного треугольника. Причина: отсутствует прямой угол\n");
        }
        this->name = "Прямоугольный треугольник:";
    }
};

// Равнобедренный треугольник
class IsoTrian : public Triangle {
public:
    IsoTrian(int _sidesCount, int _a, int _b, int _c, int _A, int _B, int _C) :
        Triangle(_sidesCount, _a, _b, _c, _A, _B, _C)
    {
        if (!(_a == _b || _a == _c || _b == _c))
        {
            throw std::invalid_argument("Ошибка создания равнобедренного треугольника. Причина: отсутствуют равные стороны\n");
        }
        if (!(_A == _B || _A == _C || _B == _C))
        {
            throw std::invalid_argument("Ошибка создания равнобедренного треугольника. Причина: отсутствуют равные углы\n");
        }
        this->name = "Равнобедренный треугольник:";
    }
};

// Равносторонний треугольник
class EqualTrian : public IsoTrian {
public:
    EqualTrian(int _sidesCount, int _a, int _b, int _c, int _A, int _B, int _C) :
        IsoTrian(_sidesCount, _a, _b, _c, _A, _B, _C)
    {
        if (!(_a == _b && _a == _c))
        {
            throw std::invalid_argument("Ошибка создания равностороннего треугольника. Причина: стороны не равны\n");
        }
        if (!(_A == _B && _A == _C))
        {
            throw std::invalid_argument("Ошибка создания равностороннего треугольника. Причина: углы не равны\n");
        }
        this->name = "Равносторонний треугольник:";
    }
};

// Параллелограмм
class Parall : public Quadrilateral {
public:
    Parall(int _sidesCount, int _a, int _b, int _c, int _d, int _A, int _B, int _C, int _D) :
        Quadrilateral(_sidesCount, _a, _b, _c, _d, _A, _B, _C, _D)
    {
        if (!((_a == _b && _c == _d) || (_a == _c && _b == _d) || (_a == _d && _b == _c)))
        {
            throw std::invalid_argument("Ошибка создания параллелограмма. Причина: стороны попарно не равны\n");
        }
        if (!((_A == _B && _C == _D) || (_A == _C && _B == _D) || (_A == _D && _B == _C)))
        {
            throw std::invalid_argument("Ошибка создания параллелограмма. Причина: углы попарно не равны\n");
        }
        this->name = "Параллелограмм:";
    }
};

// Прямоугольник
class Rectangle : public Parall {
public:
    Rectangle(int _sidesCount, int _a, int _b, int _c, int _d, int _A, int _B, int _C, int _D) :
        Parall(_sidesCount, _a, _b, _c, _d, _A, _B, _C, _D)
    {
        if (!(_A == 90 && _A == _B && _A == _C && _A == _D))
        {
            throw std::invalid_argument("Ошибка создания прямоугольника. Причина: есть хотя бы 1 непрямой угол\n");
        }
        this->name = "Прямоугольник:";
    }
};

// Квадрат
class Square : public Rectangle {
public:
    Square(int _sidesCount, int _a, int _b, int _c, int _d, int _A, int _B, int _C, int _D) :
        Rectangle(_sidesCount, _a, _b, _c, _d, _A, _B, _C, _D)
    {
        if (!(_a == _b && _a == _c && _a == _d))
        {
            throw std::invalid_argument("Ошибка создания квадрата. Причина: стороны не равны\n");
        }
        this->name = "Квадрат:";
    }
};

// Ромб
class Rhombus : public Parall {
public:
    Rhombus(int _sidesCount, int _a, int _b, int _c, int _d, int _A, int _B, int _C, int _D) :
        Parall(_sidesCount, _a, _b, _c, _d, _A, _B, _C, _D)
    {
        if (!(_a == _b && _a == _c && _a == _d))
        {
            throw std::invalid_argument("Ошибка создания ромба. Причина: стороны не равны\n");
        }
        this->name = "Ромб:";
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    int sidesTrian = 3, sidesQuad = 4;
    int a = 10, b = 20, c = 30, d = 40;
    int A = 50, B = 60, C = 70, D = 80;

    try
    {
        Triangle trian(sidesTrian, a, b, c, A, B, C);
        trian.printInfo();
    }
    catch (const std::invalid_argument& except)
    {
        std::cout << except.what();
    }

    try
    {
        RectTrian recTrian(sidesTrian, a, b, c, 45, 45, 90);
        recTrian.printInfo();
    }
    catch (const std::invalid_argument& except)
    {
        std::cout << except.what();
    }

    try
    {
        IsoTrian isoTrian(sidesTrian, a, b, a, 50, 80, 50);
        isoTrian.printInfo();
    }
    catch (const std::invalid_argument& except)
    {
        std::cout << except.what();
    }

    try
    {
        EqualTrian eqTrian(sidesTrian, a, a, a, B, B, B);
        eqTrian.printInfo();
    }
    catch (const std::invalid_argument& except)
    {
        std::cout << except.what();
    }

    try
    {
        Quadrilateral quad(sidesQuad, a, b, c, d, 60, 100, 90, 110);
        quad.printInfo();
    }
    catch (const std::invalid_argument& except)
    {
        std::cout << except.what();
    }

    try
    {
        Rectangle rect(sidesQuad, a, b, a, b, 90, 90, 90, 90);
        rect.printInfo();
    }
    catch (const std::invalid_argument& except)
    {
        std::cout << except.what();
    }

    try
    {
        Square squar(sidesQuad, c, c, c, c, 90, 90, 90, 90);
        squar.printInfo();
    }
    catch (const std::invalid_argument& except)
    {
        std::cout << except.what();
    }

    try
    {
        Parall par(sidesQuad, a, b, a, b, 80, 100, 80, 100);
        par.printInfo();
    }
    catch (const std::invalid_argument& except)
    {
        std::cout << except.what();
    }

    try
    {
        Rhombus rhom(sidesQuad, d, d, d, d, 80, 100, 80, 100);
        rhom.printInfo();
    }
    catch (const std::invalid_argument& except)
    {
        std::cout << except.what();
    }
}
