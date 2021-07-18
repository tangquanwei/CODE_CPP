/* 减少枚举变量 */
/* 减小枚举范围 */
/* 循环+判断 */
#include <iostream>
using namespace std;
void hundredYuanForCock()
{
    for (int i = 1; i <= 14; ++i)
    {
        if ((100 - 7 * i) % 4 == 0)
        {
            int y = (100 - 7 * i) / 4;
            int z = 100 - i - y;
            if (5 * i + 3 * y + z / 3 == 100 && z % 3 == 0)
            {
                cout << "Cock = " << i << "; hen = " << y << "; Chicken = " << z << endl;
            }
        }
    }
}
void stone(){
    
}
int main()
{

    return 0;
}