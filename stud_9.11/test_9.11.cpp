#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <functional>
#include <map>
#include <vector>
#include <windows.h>

// 使用模板函数的示例
template<class F, class T>
T useF(F f, T x)
{
    static int count = 0;
    std::cout << "count:" << ++count << std::endl;
    return f(x);
}

// 定义一个接受double参数的函数
double f(double i)
{
    return i / 2;
}

// 定义一个函数对象
struct Functor
{
    double operator()(double d)
    {
        return d / 3;
    }
};

// 主函数
int main()
{
    // 使用函数指针调用useF
    //std::cout << useF(f, 11.11) << std::endl;

    // 使用函数对象调用useF
    Functor ft;
    std::cout << useF(ft, 11.11) << std::endl;

    // 使用lambda表达式调用useF
    std::cout << useF([](double d)->double { return d / 4; }, 11.11) << std::endl;

    return 0;
}

// 以下代码未在main函数中使用，可以删除
// 定义一个接受int参数的函数
int f(int a, int b)
{
    return a + b;
}

// 定义一个类，其中包含一个函数对象
class Functor
{
public:
    int operator() (int a, int b)
    {
        return a + b;
    }
};

// 以下代码未在main函数中使用，可以删除
// 定义一个类，其中包含静态和非静态成员函数
class Plus
{
public:
    static int plusi(int a, int b)
    {
        return a + b;
    }

    int plusd(int a, int b)
    {
        return a + b * 10;
    }

private:
    int x = 10;
};

// 以下代码未在main函数中使用，可以删除
// 使用std::function绑定函数和对象
int main()
{
    // 使用std::function绑定函数指针
    std::function<int(int, int)> f1;
    f1 = f;
    std::cout << f1(1, 2) << std::endl;

    // 使用std::function绑定函数对象
    std::function<int(int, int)> f2 = Functor();
    std::cout << f2(1, 2) << std::endl;

    // 使用std::function绑定lambda表达式
    std::function<int(int, int)> f3 = [](const int a, const int b) { return a + b; };
    std::cout << f3(1, 3) << std::endl;

    // 使用std::function绑定类的静态成员函数
    std::function<int(int, int)> f4 = &Plus::plusi;
    std::cout << f4(1, 2) << std::endl;

    // 使用std::function绑定类的非静态成员函数
    Plus plus;
    std::function<int(Plus, int, int)> f5 = &Plus::plusd;
    std::cout << f5(plus, 1, 2) << std::endl;

    // 使用std::function绑定lambda表达式，捕获类对象
    std::function<int(int, int)> f6 = [&plus](int x, int y) -> int { return plus.plusd(x, y); };
    std::cout << f6(1, 2) << std::endl;

    return 0;
}

// 以下代码未在main函数中使用，可以删除
// 使用std::bind绑定函数和对象
int x1()
{
    // 使用std::bind绑定函数
    //std::function<int(int, int)> func1 = std::bind(Plus, std::placeholders::_1, std::placeholders::_2);
    //std::cout << func1(1, 2) << std::endl;

    // 使用std::bind绑定函数，调整参数顺序
    //std::function<int(int, int)> func2 = std::bind(SubFunc, std::placeholders::_2, std::placeholders::_1);
    //std::cout << func2(1, 2) << std::endl;

    // 使用std::bind绑定比较函数
    std::function<bool(int, int)> gt = std::bind(std::less<int>(), std::placeholders::_2, std::placeholders::_1);
    std::cout << gt(1, 2) << std::endl;

    // 使用std::bind绑定类成员函数，绑定固定参数
    //std::function<int(Sub, int, int)> func3 = std::bind(&Sub::sub, Sub(), std::placeholders::_1, std::placeholders::_2);
    //std::cout << func3(10, 20) << std::endl;

    return 0;
}