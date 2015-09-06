#ifndef _FUNTION_H_
#define _FUNCTION_H_
#include <iostream>
#include <ctime>
//获取输入
void getInput(char *str, unsigned int size);

// 判断一个字符串是否为数字
bool isDigit(char *str);

//将字符串转化为整数
int strToInt(char *str);

//将单个字符转化为整数
unsigned int charToInt(char ch);

//将一个字符串全部转化为小写
void toLower(char *str, char* result, unsigned int size);

//随机算法
int randomEx(int min, int max);
#endif