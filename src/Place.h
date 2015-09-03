#pragma once
class Place
{
public:
	Place();
	~Place();
	void setSign(char sign);//设置地块显示字符
	char getSign();//获取地块显示字符

private:
	char sign;	//地块显示字符
};

