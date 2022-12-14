# CPlusLearning_Caizh
Used to individual learing

If you use the wsl to compile the program, please not to clone this repository to the directory in windows.

**某次模板类BST编译的过程中出现undefined reference问题**

这是由于模板类和模板函数的书写都必须在头文件 .h 中，而不能在头文件中声明，但在cpp文件中进行编译，这样的话会导致编译器无法确定模板中的实例

**Reference:**https://zhuanlan.zhihu.com/p/81681440

