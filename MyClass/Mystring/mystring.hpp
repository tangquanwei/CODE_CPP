#ifndef __MYSTRING__
#define __MYSTRING__

class String
{ // with pointer 
private:
    char *m_data;

public:
    String(const char *cstr = nullptr);
    String(const String &str);           //拷贝构造
    String &operator=(const String &str);//拷贝赋值
    ~String();
    char *getCStr() const { return m_data; }
};

#endif