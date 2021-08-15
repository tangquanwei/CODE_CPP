# 常用算法

## 0 数值运算 numeric

---

iota 用从起始值开始连续递增的值填充一个范围

accumulate 对一个范围内的元素求和(或自定义操作)

inner_product 计算两个范围的元素的内积(或自定义操作)

adjacent_difference 计算范围内各相邻元素之间的差

## 1 不修改序列的操作

---

all_of
any_of
none_of 检查谓词是否对范围中所有、任一或无元素为

for_each
for_each_n 应用一个函数对象到序列的前

count
count_if 返回满足指定判别标准的元素数

mismatch 寻找两个范围出现不同的首个位置

find
find_if
find_if_not 寻找首个满足特定判别标准的元素
find_end 在特定范围中寻找最后出现的元素序列
find_first_of 搜索元素集合中的任意元素

adjacent_find 查找首对相邻的相同（或满足给定谓词的）元素

search 搜索一个元素范围
search_n 在范围中搜索一定量的某个元素的连续副本

## 2 修改序列的操作

---

copy
copy_if将某一范围的元素复制到一个新的位置

copy_backward按从后往前的顺序复制一个范围内的元素

move将某一范围的元素移动到一个新的位置

move_backward按从后往前的顺序移动某一范围的元素到新的位置

fill将一个给定值复制赋值给一个范围内的每个元素
fill_n将一个给定值复制赋值给一个范围内的

transform将一个函数应用于某一范围的各个元素，并在目标范围存储结果

generate
generate_n将相继的函数调用结果赋值给一个范围中的每个元素

remove
remove_if移除满足特定判别标准的元素

remove_copy
remove_copy_if复制一个范围的元素，忽略满足特定判别标准的元素

replace
replace_if将所有满足特定判别标准的值替换为另一个值

replace_copy
replace_copy_if复制一个范围内的元素，并将满足特定判别标准的元素替换为另一个值

swap交换两个对象的值

swap_ranges交换两个范围的元素

iter_swap交换两个迭代器所指向的元素

reverse逆转范围中的元素顺序

reverse_copy创建一个范围的逆向副本

rotate旋转范围中的元素顺序

rotate_copy复制并旋转元素范围

shift_left
shift_right迁移范围中的元素

random_shuffle
shuffle随机重排范围中的元素

sample从一个序列中随机选择

unique移除范围内的连续重复元素

unique_copy创建某范围的不含连续重复元素的副本

## 3 划分操作

---

is_partitioned判断范围是否已按给定的谓词划分

partition将范围中的元素分为两组

partition_copy复制一个范围，将各元素分为两组

stable_partition将元素分为两组，同时保留其相对顺序

partition_point定位已划分范围的划分点

## 4 排序操作

---

is_sorted检查范围是否已按升序排列

is_sorted_until找出最大的已排序子范围

sort将范围按升序排序

partial_sort排序一个范围的前

partial_sort_copy对范围内的元素进行复制并部分排序

stable_sort将范围内的元素排序，同时保持相等的元素之间的顺序

nth_element将给定的范围部分排序，确保其按给定元素划分

## 5 二分搜索操作（在已排序范围上）

---

lower_bound返回指向第一个不小于给定值的元素的迭代器

upper_bound返回指向第一个大于给定值的元素的迭代器

binary_search确定元素是否存在于某范围中

equal_range返回匹配特定键值的元素范围

## 6 其他已排序范围上的操作

---

merge归并两个已排序的范围

inplace_merge就地归并两个有序范围

### 7 集合操作（在已排序范围上）

---

includes 若一个序列是另一个的子列则返回

set_difference 计算两个集合的差集

set_intersection 计算两个集合的交集

set_union 计算两个集合的并集

set_symmetric_difference 计算两个集合的对称差

### 8 堆操作

---

is_heap检查给定范围是否为一个最大堆

is_heap_until查找能成为最大堆的最大子范围

make_heap从一个元素范围创建出一个最大堆

push_heap将一个元素加入到一个最大堆

pop_heap从最大堆中移除最大元素

sort_heap将一个最大堆变成一个按升序排序的元素范围

### 9 比较

---

max返回各给定值中的较大者

max_element返回范围内的最大元素

min返回各给定值中的较小者

min_element返回范围内的最小元素

minmax返回两个元素的较小和较大者

minmax_element返回范围内的最小元素和最大元素

equal确定两个元素集合是否是相同的

### 10 排列操作

---

is_permutation判断一个序列是否为另一个序列的排列

next_permutation产生某个元素范围的按字典顺序的下一个较大的排列

prev_permutation产生某个元素范围的按字典顺序的下一个较小的排列
