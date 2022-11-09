首先需要包含头文件
#include <unordered_map> 
using namespace std;

unordered_map在< >中需要指明两个变量类型，第一个是key的类型，第二个是key对应的value的类型
unordered_map<int, int> hashtable;

查找哈希表中的某个key是否存在，可以使用count()函数，因为键不能重复使用，所以count()的返回值只有0 or 1
hashtable.count();
也可以使用find，返回的是被查找元素的key，没有则返回hashtable.end()
hashtable.find();

取得哈希表中的key和value
（auto被解释为一个自动存储变量的关键字，也就是申明一块临时的变量内存）
auto it = hashtable.begin();
it->second; //取得哈希表中的value
it->first;  //取得哈希表中的key

哈希表就是一个空间与值的关系
