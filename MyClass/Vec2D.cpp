#include <cmath>
#include <iostream>

// 优先级：std > 第三方 > 用户的
// 包含文件的路径中，一定不要使用绝对路径
// 代变量应使用i,j,k等字母。j,k等应仅用于嵌套循环中
// 大作用域的变量应使用长名字，小作用域的变量应使用短名字
// 优先级和结合性不变
// 重载的运算符必须和用户定义的class类型一起使用
// 重载的运算符的参数至少应有一个是类对象(或类对象的引用)
// 参数不能全部是C++的标准类型,以防止用户修改用于标准类型数据的运算符的性质。
namespace vec2d
{
    class Vec2D
    {
    private:
        double x, y;

    public:
        Vec2D() : Vec2D(0, 0) {}
        Vec2D(double x, double y) : x{x}, y{y} {}
        Vec2D(const Vec2D &vct) // 必须是const
        {
            this->x = vct.x;
            this->y = vct.y;
        }
        Vec2D(const Vec2D *vct)
        {
            this->x = vct->x;
            this->y = vct->y;
        }
        const Vec2D &operator=(const Vec2D &vct)
        {
            this->x = vct.x;
            this->y = vct.y;
            return (*this);
        }
        const Vec2D &operator=(const Vec2D *vct)
        {
            this->x = vct->x;
            this->y = vct->y;
            return (*this);
        }

        ~Vec2D() {}
        Vec2D operator+(const Vec2D &vct)
        {
            return add(vct);
        }
        Vec2D operator+=(const Vec2D &vct)
        {
            *this = this->add(vct);
            return *this;
        }

        Vec2D operator-(Vec2D &vct)
        {
            return subtract(vct);
        }
        double operator*(Vec2D &vct)
        {
            return dot(vct);
        }
        Vec2D operator*(double k)
        {
            return multiply(k);
        }

        bool operator==(Vec2D &vct)
        {
            return equals(vct);
        }

        bool operator!=(Vec2D &vct)
        {
            return !equals(vct);
        }

        bool operator>(Vec2D &vct)
        {
            return (compareTo(vct) > 0);
        }
        bool operator<(Vec2D &vct)
        {
            return (compareTo(vct) < 0);
        }
        double &operator[](const unsigned int &index)
        { //不能重载为友元函数，只能重载为成员函数
            if (index == 0)
                return x;
            else if (index == 1)
                return y;
            else
            {
                std::cout << "index out of bound" << std::endl;
                exit(0);
            }
        }
        const double &operator[](const unsigned int &index) const
        { //不能重载为友元函数，只能重载为成员函数
            if (index == 0)
                return x;
            else if (index == 1)
                return y;
            else
            {
                std::cout << "index out of bound" << std::endl;
                exit(0);
            }
        }
        Vec2D operator-()                       //作为对象成员的一元运算符无参数
        {                                       //unary operator '-'
            return Vec2D(-(this->x), -this->y); // 返回匿名临时对象
        }
        Vec2D operator++() // prefix
        {
            x += 1;
            y += 1;
            return *this;
        }

        Vec2D operator++(int dummy) // postfix dummy占位符
        {
            Vec2D temp(this->x, this->y);
            x += 1;
            y += 1;
            return temp;
        }
        Vec2D operator--() // prefix
        {
            x -= 1;
            y -= 1;
            return *this;
        }

        Vec2D operator--(int dummy) // postfix dummy占位符
        {
            Vec2D temp(this->x, this->y);
            x -= 1;
            y -= 1;
            return temp;
        }
        // std::ostream &operator<<(std::ostream &stream);
        // std::istream &operator>>(std::istream &stream);//和习惯不一样
        friend std::ostream &operator<<(std::ostream &stream, Vec2D &vct)
        { //cout << v1;
            stream << "(" << vct[0] << ", " << vct[1] << ")" << std::endl;
            return stream;
        }

        friend std::istream &operator>>(std::istream &stream, Vec2D &vct)
        {
            stream >> vct.x >> vct.y;
            return stream;
        }

        operator double() //重载对象转换运算符，没有返回类型
        {
            return magnitude();
        }
        Vec2D add(const Vec2D &vct)
        {
            x += vct.x;
            y += vct.y;
            return (*this);
        }

        double compareTo(Vec2D &vct)
        {
            return (magnitude() - vct.magnitude());
        }

        Vec2D decrease()
        {
            --x;
            --y;
            return (*this);
        }
        double drection()
        {
            return std::atan(y / x);
        }
        double dot(Vec2D &vct)
        {
            return x * vct.x + y * vct.y;
        }
        bool equals(Vec2D &vct)
        {
            if (vct.x == x && vct.y == y)
                return true;
            else
                return false;
        }

        Vec2D increase()
        {
            ++x;
            ++y;
            return (*this);
        }
        double magnitude()
        {
            return sqrt(x * x + y * y);
        }
        Vec2D multiply(double k)
        {
            x *= k;
            y *= k;
            return (*this);
        }
        Vec2D negative()
        {
            x = -x;
            y = -y;
            return (*this);
        }
        Vec2D subtract(Vec2D &vct)
        {
            x -= vct.x;
            y -= vct.y;
            return (*this);
        }
        std::string toString()
        {
            return "\nx = " + std::to_string(this->x) + "\ny = " + std::to_string(this->y);
        }
        void show()
        {
            std::cout << "(" << (*this)[0] << ", " << (*this)[1] << ")" << std::endl;
        }
    };

    class PrintStr
    {
    private:
        std::ostream &os;
        char sep;

    public:
        PrintStr(std::ostream &os = std::cout, char sep = '\n') : os(os), sep(sep) {}
        void operator()(const std::string &s) const { os << s << sep; }
        /* 重载函数调用运算符 */
    };
}
using namespace vec2d;
int main()
{
    Vec2D v1(1, 1), v2(2, 2);
    std::cout << typeid(v1).name() << v1.toString() << std::endl;
    std::cout << typeid(v2).name() << v2.toString() << std::endl;
    std::cout << (v1.compareTo(v2) >= 0 ? "大了" : (v1.compareTo(v2) ? "小了" : "相等")) << std::endl;
    std::cout << "Angel: " << v1.drection() << " (rad)" << std::endl;
    v1.add(v2);
    std::cout << typeid(v1).name() << v1.toString() << std::endl;
    v1 + v2;
    std::cout << typeid(v1).name() << v1.toString() << std::endl;
    std::cout << typeid(v1).name() << (v1 += v2).toString() << std::endl;
    Vec2D v3 = -v1;
    v1.show();
    v2.show();
    v3.show();
    Vec2D v4;
    std::cin >> v4;
    std::cout << v4 << std::endl;
    std::cout << v4.magnitude() << std::endl;
    double m = static_cast<double>(v4);
    std::cout << m << std::endl;
    std::cout << m + v4 << std::endl; //自动转化
    PrintStr print;
    print(v4.toString());

    return 0;
}
