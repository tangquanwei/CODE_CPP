# 使用cpp出现的问题

## 缺少 类模板 "ArrayList" 的参数列表
```cpp
template <class T>
class ArrayList {
private:
	T* array;
	unsigned int length;

public:
	ArrayList() {}
	ArrayList(int n);

};
ArrayList::ArrayList(int n){
}
```
模板类是带参数的类，要求在接口实现中的类名称后面加入模板类参数
```cpp
template <class T>
ArrayList<T>::ArrayList(int n){
}
```
## collect2.exe: error: ld returned 1 exit status 

1. 编译成功的例子在后台执行，有时一闪而过，如果再次build ，则会提示上述错误。

解决方法：打开任务管理器，找到相应的exe进程，关闭即可；  或者直接关闭IDE。

2. 没有编译成功的情况下，最常见情况是程序本身需要include的头文件被遗漏了

解决方法：细心查找基类所用的头文件，include之后即可。

3. .h文件中相关的函数在cpp文件中没有定义，或者说函数的声明(.h中)与定义(.cpp中)不一致
解决方法：查找遗漏的函数，根据需要，具体的定义。将函数名修改一致

4. 同名函数存在，并且都进行了使用解决方案：修改相同函数名

5. 对xxx未定义的引用
解决方案：是链接库的问题，可能缺少源文件或者.so文件缺少，在/usr/local/lib里找到需要的.so文件并添加

## declaration of template parameter 'T' shadows template parameter
```c++
	friend std::ostream& 
	operator<<(std::ostream&, const ArrayList<T>*); 
``
模板的友元分三类：非模板友元、约束模板友元、非约束模板友元
1.非模板友元：
	在模板类中将一个常规函数（类）声明为友元。
2.模板类的约束模板友元：（一对一友好关系）（VC++ 6.0不支持）
想要将友元关系限定在特定的实例化上，则相关的类或函数必须在其友元声明之前进行声明。

