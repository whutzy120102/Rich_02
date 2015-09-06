#include "function.h"

/**
*������getInput(char *str, unsigned int size)
*���ܣ���ȡ����
*������size���������ַ�����󳤶�
*/
void getInput(char *str, unsigned int size)
{
	if (fgets(str, size, stdin) == NULL)
	{
		return;
	}

	if (str[strlen(str) - 1] == '\n') //ɾ�� '\n'
	{
		str[strlen(str) - 1] = '\0';
	}
	else
	{
		fflush(stdin);
	}
}

// �ж�һ���ַ����Ƿ�Ϊ����
bool isDigit(char *str)
{
	while (*str)
	{
		if ((*str) == '-')
		{
			str++;
			continue;
		}
		if (!isdigit(*str)) return  false;

		str++;
	}
	return   true;
}

//��һ���ַ���ת��Ϊ�������ɹ���������ֵ��ʧ�ܷ��������С���� ֵ
int strToInt(char *str)
{
	int val;
	if (!isDigit(str))
	{
		return INT_MAX;
	}
	val = atoi(str);
	if (val == INT_MIN)
	{
		return INT_MAX;
	}
	return val;
}

//�������ַ�ת��Ϊ����,�ɹ����ظ�ֵ,ʧ�ܷ���-1
unsigned int charToInt(char ch)
{
	unsigned int val;
	switch (ch)
	{
	case '0':
		val = 0; break;
	case '1':
		val = 1; break;
	case '2':
		val = 2; break;
	case '3':
		val = 3; break;
	case '4':
		val = 4; break;
	case '5':
		val = 5; break;
	case '6':
		val = 6; break;
	case 7:
		val = 7; break;
	case '8':
		val = 8; break;
	case '9':
		val = 9; break;
	default:
		return -1;
	}
	return val;
}


//��һ���ַ���ȫ��ת��ΪСд
void toLower(char *str, char* result, unsigned int size)
{
	char *buf = (char *)malloc(size);
	//strncpy(buf, str, size);
	//strncpy(result, strlwr(buf), size);
	free(buf);
}

// 
//����㷨
int randomEx(int min, int max)
{
	static int count = 10000;
	count++;
	srand((unsigned)time(NULL) % count);
	return rand() % max + min;
}

/*
void ColoredPrintf(unsigned int color, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

#ifdef RICH_COMPILE_GCC
	vprintf(fmt, args);
#else
	const HANDLE stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// Gets the current text color.
	CONSOLE_SCREEN_BUFFER_INFO buffer_info;
	GetConsoleScreenBufferInfo(stdout_handle, &buffer_info);
	const WORD old_color_attrs = buffer_info.wAttributes;

	SetConsoleTextAttribute(stdout_handle, color | FOREGROUND_INTENSITY);
	vprintf(fmt, args);

	// Restores the text color.
	SetConsoleTextAttribute(stdout_handle, old_color_attrs);
#endif
	//printf(fmt,args);	
	va_end(args);
}
*/