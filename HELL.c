
#include <stdio.h>

void test1();//在main函数之前声明test函数，不然main函数没法调用。

int main() {
    test1();   
    return 0;
}
static int b =10;            //静态声明，只有静态声明以下的程序才能使用  b变量

//test函数的实现
void test1(){
    printf("%d\n",b);//可以使用变量b，因为处于变量b的作用域。
}

//函数声明与实现




#include <stdio.h>
int main(void) {
  const int vx = 10;
  const int vy = 10;
  int arr[vx] = {1, 2, 3};  // [错误1] 使用非常量表达式定义定长数组；此时程序仍是不可修改述职的变量而已。
  switch(vy) {
    case vx: {  // [错误2] 非常量表达式应用于 case 语句；
      printf("Value matched!");
      break;
    }
  }
}



#include <stdio.h>
#define vx 10
#define vy 10
int main(void) {
  // int vx = 10;
  // int vy = 10;
  int arr[vx] = {1, 2, 3};  // [错误1] 使用非常量表达式定义定长数组；数组是定长，define定义的是常量，固然可以。
  switch(vy) {
    case vy: {  // [错误2] 非常量表达式应用于 case 语句；
      printf("Value matched!");
      break;
    }
  }
}

//只读变量与字面量常量的一个最重要的不同点是，使用 const 修饰的只读变量不具有“常量表达式”的属性，因此无法用来表示定长数组大小，或使用在 case 语句中。常量表达式本身会在程序编译时被求值，而只读变量的值只能够在程序实际运行时才被得知。并且，编译器通常不会对只读变量进行内联处理，因此其求值不符合常量表达式的特征。




//****************总之，程序在进行强制类型转换时，不会影响其底层数据的实际存储方式。***********//
#include <stdio.h>
int main(void) {
  signed char x = -10;            //存储的补码为   1 111 0110   （-10）
  unsigned char y = (unsigned char)x;   //强制转为无符号后，运算方式全变，八位存的均是正数，对应十六进制为 F6 ，对应十进制为246
  printf("%d\n", y);  // output: 246.
  return 0;
}


//*****************  变量类型的隐式转换  ***************************//
#include <stdio.h>
int main(void) {
  int x = -10;    //C 中 常用数据变量 均是默认为有符号数 
  unsigned int y = 1;      //程序逻辑在真正进入到条件语句之前，变量 x 的类型会首先被隐式转换为 unsigned int,原先存放有 -10 补码的位模式会被解释为一个十分庞大的正整数，而这个数则远远大于 1。
  if (x < y) {
    printf("x is smaller than y.");
  } else {
    printf("x is bigger than y.");   // this branch is picked!，将输出此语句  X>Y 因为 x被强制转无符号数
   }
}

/* 在进行运算时，以表达式中所占字节最多的数据类型为主，其他数据的类型均转换为这种数据类型，再进行运算。
转换规则:
char,short ——>int——>unsigned——>long——>double */

 解决方法：运算判断时将y进行强制转为有符号数即可，即 if（x<(int)y）
 if (x<(int)y) {
    printf("x is smaller than y.");   //将输出此语句
  } else {
    printf("x is bigger than y.");   
   }  
