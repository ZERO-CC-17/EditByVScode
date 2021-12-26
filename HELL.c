/*
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

*/


// #include <stdio.h>
// int main(void) {
//   const int vx = 10;
//   const int vy = 10;
//   int arr[vx] = {1, 2, 3};  // [错误1] 使用非常量表达式定义定长数组；此时程序仍是不可修改述职的变量而已。
//   switch(vy) {
//     case vx: {  // [错误2] 非常量表达式应用于 case 语句；
//       printf("Value matched!");
//       break;
//     }
//   }
// }

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

//读变量与字面量常量的一个最重要的不同点是，使用 const 修饰的只读变量不具有“常量表达式”的属性，因此无法用来表示定长数组大小，或使用在 case 语句中。常量表达式本身会在程序编译时被求值，而只读变量的值只能够在程序实际运行时才被得知。并且，编译器通常不会对只读变量进行内联处理，因此其求值不符合常量表达式的特征。


