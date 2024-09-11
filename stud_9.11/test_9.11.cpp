#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <functional>
#include <map>
#include <vector>
#include <windows.h>

// ʹ��ģ�庯����ʾ��
template<class F, class T>
T useF(F f, T x)
{
    static int count = 0;
    std::cout << "count:" << ++count << std::endl;
    return f(x);
}

// ����һ������double�����ĺ���
double f(double i)
{
    return i / 2;
}

// ����һ����������
struct Functor
{
    double operator()(double d)
    {
        return d / 3;
    }
};

// ������
int main()
{
    // ʹ�ú���ָ�����useF
    //std::cout << useF(f, 11.11) << std::endl;

    // ʹ�ú����������useF
    Functor ft;
    std::cout << useF(ft, 11.11) << std::endl;

    // ʹ��lambda���ʽ����useF
    std::cout << useF([](double d)->double { return d / 4; }, 11.11) << std::endl;

    return 0;
}

// ���´���δ��main������ʹ�ã�����ɾ��
// ����һ������int�����ĺ���
int f(int a, int b)
{
    return a + b;
}

// ����һ���࣬���а���һ����������
class Functor
{
public:
    int operator() (int a, int b)
    {
        return a + b;
    }
};

// ���´���δ��main������ʹ�ã�����ɾ��
// ����һ���࣬���а�����̬�ͷǾ�̬��Ա����
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

// ���´���δ��main������ʹ�ã�����ɾ��
// ʹ��std::function�󶨺����Ͷ���
int main()
{
    // ʹ��std::function�󶨺���ָ��
    std::function<int(int, int)> f1;
    f1 = f;
    std::cout << f1(1, 2) << std::endl;

    // ʹ��std::function�󶨺�������
    std::function<int(int, int)> f2 = Functor();
    std::cout << f2(1, 2) << std::endl;

    // ʹ��std::function��lambda���ʽ
    std::function<int(int, int)> f3 = [](const int a, const int b) { return a + b; };
    std::cout << f3(1, 3) << std::endl;

    // ʹ��std::function����ľ�̬��Ա����
    std::function<int(int, int)> f4 = &Plus::plusi;
    std::cout << f4(1, 2) << std::endl;

    // ʹ��std::function����ķǾ�̬��Ա����
    Plus plus;
    std::function<int(Plus, int, int)> f5 = &Plus::plusd;
    std::cout << f5(plus, 1, 2) << std::endl;

    // ʹ��std::function��lambda���ʽ�����������
    std::function<int(int, int)> f6 = [&plus](int x, int y) -> int { return plus.plusd(x, y); };
    std::cout << f6(1, 2) << std::endl;

    return 0;
}

// ���´���δ��main������ʹ�ã�����ɾ��
// ʹ��std::bind�󶨺����Ͷ���
int x1()
{
    // ʹ��std::bind�󶨺���
    //std::function<int(int, int)> func1 = std::bind(Plus, std::placeholders::_1, std::placeholders::_2);
    //std::cout << func1(1, 2) << std::endl;

    // ʹ��std::bind�󶨺�������������˳��
    //std::function<int(int, int)> func2 = std::bind(SubFunc, std::placeholders::_2, std::placeholders::_1);
    //std::cout << func2(1, 2) << std::endl;

    // ʹ��std::bind�󶨱ȽϺ���
    std::function<bool(int, int)> gt = std::bind(std::less<int>(), std::placeholders::_2, std::placeholders::_1);
    std::cout << gt(1, 2) << std::endl;

    // ʹ��std::bind�����Ա�������󶨹̶�����
    //std::function<int(Sub, int, int)> func3 = std::bind(&Sub::sub, Sub(), std::placeholders::_1, std::placeholders::_2);
    //std::cout << func3(10, 20) << std::endl;

    return 0;
}