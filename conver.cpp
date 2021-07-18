#include <iostream>
#include "conver.hpp"

using namespace std;

int main()
{
     unsigned char c1, c2;
     char s[20];
     int x;

     cout << "这是一个进制转换程序！" << endl;
     cout << "请输入：(例如：)\n2进制：b 1001\n8进制：o 766\n16进制：x AF29" << endl;
lab1:
     cin >> c1 >> s;

     switch (c1)
     {
     case 'b':
     case 'B':
          x = conver2(s);
          break;
     case 'o':
     case 'O':
          x = conver8(s);
          break;
     case 'x':
     case 'X':
          x = conver16(s);
          break;
     default:
          cout << "你的输入有误，请重新输入 :(" << endl;
          goto lab1;
     }
     if (x != -1)
     {
          cout << c1 << " " << s << " 转换成10进制后是: " << x << endl;
          cout << "还有要转化的数字吗？:)\t(有,无/y,n)" << endl;
          cin >> c2;
          if (c1 == 'y' || c1 == 'Y')
               goto lab1;
          else
               cout << "谢谢使用 :)" << endl;
     }
     else
     {
          cout << "你输入待转换的数字有误，请重新输入 :(" << endl;
          goto lab1;
     }
     return 0;
}

int conver2(char *s)
{
     int x(0);
     while (*s != '\0')
     {
          if (*s == '1')
               x = (x << 1) + 1;
          else if (*s == '0')
               x = x << 1;
          else
               x = -1;
          s++;
     }
     return x;
}

int conver8(char *s)
{
     int x(0);
     while (*s != '\0')
     {
          if (x >= '0' && x <= '8')
               x = (x << 3) + *s - '0';
          else
               x = -1;
          s++;
     }
     return x;
}

int conver16(char *s)
{
     int x(0);
     while (*s != '\0')
     {
          if (*s >= '0' && *s <= '9')
               x = (x << 4) + *s - '0';
          else if (*s >= 'a' && *s <= 'z')
               x = (x << 4) + *s - 'a';
          else if (*s >= 'A' && *s <= 'Z')
               x = (x << 4) + *s - 'A';
          else
               x = -1;
          s++;
     }
     return x;
}