# 1 常用容器

## 1.1 **vector**

### 1.1.1 构造函数

```c++
// C++11 初始化器列表语法：
std::vector<std::string> words1 {"the", "frogurt", "is", "also", "cursed";
std::cout << "words1: " << words1 << '\n';

// words2 == words1
std::vector<std::string> words2(words1.begin(), words1.end());
std::cout << "words2: " << words2 << '\n';

// words3 == words1
std::vector<std::string> words3(words1);
std::cout << "words3: " << words3 << '\n';

// words4 为 {"Mo", "Mo", "Mo", "Mo", "Mo"}
std::vector<std::string> words4(5, "Mo");
std::cout << "words4: " << words4 << '\n';
```

### 1.1.2 元素访问  

---

- at 访问指定的元素，同时进行越界检查

- operator[] 访问指定的元素

- front 访问第一个元素

- back 访问最后一个元素

- data 直接访问底层数组

### 1.1.3 迭代器  

---

- begin cbegin 返回指向起始的迭代器

- end cend 返回指向末尾的迭代器

- rbegin crbegin 返回指向起始的逆向迭代器

- rend crend 返回指向末尾的逆向迭代器

### 1.1.4 容量

---

- empty 检查容器是否为空

- size 返回容纳的元素数

- max_size 返回可容纳的最大元素数

- reserve 预留存储空间

- capacity 返回当前存储空间能够容纳的元素数

- shrink_to_fit 通过释放未使用的内存减少内存的使用

### 1.1.5 修改器

---

- clear 清除内容  

- insert 插入元素  

- emplace 原位构造元素

- erase 擦除元素

- push_back 将元素添加到容器末尾

- emplace_back 在容器末尾就地构造元素  

- pop_back 移除末元素

- resize 改变容器中可存储元素的个数  

- swap 交换内容

### 1.1.6 非成员函数

---

- operator==

- operator<=>

- std::swap(std::vector) 特化 std::swap 算法

## 1.2 **list**

### 1.2.1 构造函数

```c++
// C++11 初始化器列表语法：
std::list<std::string> words1 {"the", "frogurt", "is", "also", "cursed"};
std::cout << "words1: " << words1 << '\n';

// words2 == words1
std::list<std::string> words2(words1.begin(), words1.end());
std::cout << "words2: " << words2 << '\n';

// words3 == words1
std::list<std::string> words3(words1);
std::cout << "words3: " << words3 << '\n';

// words4 为 {"Mo", "Mo", "Mo", "Mo", "Mo"}
std::list<std::string> words4(5, "Mo");
std::cout << "words4: " << words4 << '\n';
```

### 1.2.2元素访问

---

- front 访问第一个元素

- back 访问最后一个元素

### 1.2.3容量

---

- empty 检查容器是否为空

- size 返回容纳的元素数

- max_size 返回可容纳的最大元素数

### 1.2.4修改器

---

- clear 清除内容

- insert 插入元素

- emplace 原位构造元素

- erase 擦除元素

- push_back 将元素添加到容器末尾

- emplace_back 在容器末尾就地构造元素

- pop_back 移除末元素

- push_front 插入元素到容器起始

- emplace_front 在容器头部原位构造元素

- pop_front 移除首元素

- resize 改变容器中可存储元素的个数

- swap 交换内容

### 1.2.5操作

---

- merge 合并二个已排序列表

- splice 从另一个list中移动元素

- remove remove_if 移除满足特定标准的元素

- reverse 将该链表的所有元素的顺序反转

- unique 删除连续的重复元素

- sort 对元素进行排序

## 1.3 **map**

### 1.3.1 构造函数

```c++
// (1) 默认构造函数
std::map<std::string, int> map1;
map1["something"] = 69;
map1["anything"] = 199;
map1["that thing"] = 50;

// (2) 范围构造函数
std::map<std::string, int> iter(map1.find("anything"), map1.end());

// (3) 复制构造函数
std::map<std::string, int> copied(map1);

// (4) 移动构造函数
std::map<std::string, int> moved(std::move(map1));

// (5) initializer_list 构造函数
const std::map<std::string, int> init {
  {"this", 100},
  {"can", 100},
  {"be", 100},
  {"const", 100},
};
```

### 1.3.2 修改器

- clear 清除内容

- insert 插入元素或结点

- insert_or_assign 插入元素，或若键已存在则赋值给当前元素

- emplace   原位构造元素

- emplace_hint   使用提示原位构造元素

- try_emplace   若键不存在则原位插入，若键存在则不做任何事

- erase 擦除元素

- swap 交换内容

- extract   从另一容器释出结点

- merge   从另一容器接合结点

### 1.3.3 查找

---

- count 返回匹配特定键的元素数量

- find 寻找带有特定键的元素

- contains (C++20)检查容器是否含有带特定键的元素

- equal_range 返回匹配特定键的元素范围

- lower_bound 返回指向首个不小于给定键的元素的迭代器

- upper_bound 返回指向首个大于给定键的元素的迭代器

### 1.3.4 观察器

---

- key_comp 返回用于比较键的函数

- value_comp 返回用于在value_type类型的对象中比较键的函数。

## 1.4 **set**

### 1.4.1 构造函数

```c++
// (1) 默认初始化器
std::set<std::string> a;
a.insert("cat");
a.insert("dog");
a.insert("horse");

// (2) 迭代器初始化器
std::set<std::string> b(a.find("dog"), a.end());

// (3) 复制构造函数
std::set<std::string> c(a);
c.insert("another horse");

// (4) 移动构造函数
std::set<std::string> d(std::move(a));

// (5) initializer_list 构造函数
std::set<std::string> e {"one", "two", "three", "five", "eight"};

// 自定义比较
struct Point { double x, y; };
struct PointCmp {
    bool operator()(const Point& lhs, const Point& rhs) const { 
        return std::hypot(lhs.x, lhs.y) < std::hypot(rhs.x, rhs.y); 
    }//hypot  计算 x 与 y 平方和的平方根，而不会在计算的中间阶段有过度的上溢或下溢
};
std::set<Point, PointCmp> z = {{2, 5}, {3, 4}, {1, 1}};
z.insert({1, -1}); // 这会失败，因为 1,-1 的长度等于 1,1
```

### 1.4.2 修改器

---

- clear 清除内容

- insert 插入元素或结点

- emplace   原位构造元素

- emplace_hint   使用提示原位构造元素

- erase 擦除元素

- swap 交换内容

extract   从另一容器释出结点

merge   从另一容器接合结点

### 1.4.3 查找

---

- count 返回匹配特定键的元素数量

- find 寻找带有特定键的元素

- contains  (C++20)检查容器是否含有带特定键的元素

- equal_range 返回匹配特定键的元素范围

- lower_bound 返回指向首个不小于给定键的元素的迭代器

- upper_bound 返回指向首个大于给定键的元素的迭代器

## 1.5 **multi_map**

### 1.5.1 构造函数

```c++
struct Point { double x, y; };
struct PointCmp {
bool operator()(const Point& lhs, const Point& rhs) const { 
    return lhs.x < rhs.x; // NB 。有意忽略 y
}
};
std::multimap<int, int> m = {{1,1},{2,2},{3,3},{4,4},{5,5},{4,4},{3,3},{22},{1,1}};
for(auto& p: m) std::cout << p.first << ' ' << p.second << '\n';
// 定制比较
std::multimap<Point, double, PointCmp> mag{
    { {5, 12}, 13 },
    { {3, 4}, 5 },
    { {8, 15}, 17 },
    { {3, -3}, -1 },
};
```

### 1.5.2 修改器

---

- clear 清除内容

- insert 插入元素或结点

- emplace   原位构造元素

- emplace_hint   使用提示原位构造元素

- erase 擦除元素

- swap 交换内容

- extract   从另一容器释出结点

- merge   从另一容器接合结点

### 1.5.3 查找

---

- count 返回匹配特定键的元素数量

- find 寻找带有特定键的元素

- contains  (C++20)检查容器是否含有带特定键的元素

- equal_range 返回匹配特定键的元素范围

- lower_bound 返回指向首个不小于给定键的元素的迭代器

- upper_bound 返回指向首个大于给定键的元素的迭代器
