#include <iostream>
#define elemtype int
#define maxsize 100
typedef struct
{
    elemtype data[maxsize];
    int top;
} stack;

void initstack(stack &S)
{
    S.top = -1;
}
void push(stack &s, char e)
{
    //入栈操作
}
void pop(stack &s, char e)
{
    //出栈操作
}
bool isempty(stack s)
{
    //判栈空
}
//栈实现括号匹配算法
bool bracketscheck(char *str)
{
    stack s;
    initstack(s);
    int i = 0;
    char e;
    while (str[i] != '\0')
    {
        switch (str[i])
        {
            //左括号入栈
        case '(':
            push(s, '(');
            break;
        case '[':
            push(s, '[');
            break;
        case '{':
            push(s, '{');
            break;
        //遇到右括号，检测栈顶
        case ')':
            pop(s, e);
            if (e != '(')
                return false;
            break;
        case ']':
            pop(s, e);
            if (e != '[')
                return false;
            break;
        case '}':
            pop(s, e);
            if (e != '{')
                return false;
            break;
        default:
            break;
        }
        i++;
    }
    if (!isempty(s))
    {
        std::cout << "括号不匹配" << std::endl;
        return false;
    }
    else
    {
        std::cout << "括号匹配" << std::endl;
        return true;
    }
}

