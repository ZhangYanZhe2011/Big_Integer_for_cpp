不支持位运算。

当big_int与一个低精度数运算时，请把big_int放在运算符前面，比如：
```cpp
big_int a;
a=a+1; //编译通过
//a=1+a; //编译不通过
```
