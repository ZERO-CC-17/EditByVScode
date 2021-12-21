/*
#include <stdio.h>

void test1();//在main函数之前声明test函数，不然main函数没法调用。

int main() {
    test1();   
    return 0;
}
static int b =10;

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