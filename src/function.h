#ifndef _FUNTION_H_
#define _FUNCTION_H_
#include <iostream>
#include <ctime>
//��ȡ����
void getInput(char *str, unsigned int size);

// �ж�һ���ַ����Ƿ�Ϊ����
bool isDigit(char *str);

//���ַ���ת��Ϊ����
int strToInt(char *str);

//�������ַ�ת��Ϊ����
unsigned int charToInt(char ch);

//��һ���ַ���ȫ��ת��ΪСд
void toLower(char *str, char* result, unsigned int size);

//����㷨
int randomEx(int min, int max);
#endif