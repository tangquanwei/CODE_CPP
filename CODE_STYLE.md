# 这是我的代码规范
## C/C++
```c
#define BUF_SIZE 1024       // 宏定义全部大写,下划线分隔
constexpr ARRAY_LEN 265     // 常量全部大写,用下划线分隔

/** 
变量命名要有意义
变量名尽量不缩写 
作用域越大, 名字可以越长 
*/
                            // 注释对齐
char* my_name = nullptr;    // 变量全部小写用下划线分隔
int g_flag;                 // 全局变量 g_xxx

class FileManage            // 类名大驼峰
{                           // 函数名一般用动宾，变量名一般用名词
privite:
    string m_name;          // 成员变量 m_xxx    

public:
    bool isFind;            // 布尔变量应写成谓词
    static string s_name;   // 静态变量 s_xxx 
    string getName();       // 小驼峰
    bool isExsit();
}

```
### 常用类型
```c
类型            对应缩写        对应单词    
指针             p               Pointer 
函数             fn              Function
无效             v               Void
长整型           l               Long
实型             r               Real
无符号           u               Unsigned
字符             ch              Char
整型             i               Int
字节             by              Byte 
布尔             b               Boolean
浮点型           f               float 
字符串           s               String   
双精度浮点        d               Double
计数             c               Computed
```
### 常用描述
```c
类型            对应描述          
最大值             Max                
最小值             Min             
初始化             Ini           
求和               Sum 
添加               Add  
删除               Del
更新               Upd
获取               Get
设置               Set
密码               Pwd
```
### 注释
```c
注释:

1.单行注释： // 注释内容

2. 多行注释：/* 注释内容 */

3. 文档注释：/** 注释内容 */

4. 注释尽量用英文(避免编码问题)

```