/*
Anggota Kelompok
1. Ahmad Muzakki - 2017051037
2. Indah Nirmala Zahra Nabil - 2057051004
3. Muhammad Fahmi Bastari - 2057051005
Link Github : https://github.com/zakki31/Tugas-expr-aritmatika.git
*/

#include <bits/stdc++.h>
using namespace std;

bool isOperator(char X){
    if(X == '+' || X == '-' || X == '*' || X == '/' || X == '%')
    {
        return true;
    }else{
        return false;
    }
}

int putFirst(string X){
    if(X == "+" || X == "-")
	{
        return 1;
    }
    if(X == "*" || X == "/" || X == "%")
	{
        return 2;
    }
    return 0;
}

bool large(string X, string Y)
{
    int num1, num2;
	
	string temp;
vector <string> infix;
vector <string> postfix;
vector <string>::iterator iterator1;
vector <string>::iterator it;
vector <string>::iterator iter;

void input()
{
    string str;
    char kar;
    while(cin.get(kar))
	{
        if(kar == '\n')
		{
            break;
        }
        if(kar != ' ')
		{
            str.push_back(kar);
        }
    }
    int length = str.length();
    for(int i = 0; i < length; i++)
	{
        if(str[i] == '(' || str[i] == ')')
		{
            if(temp.length() != 0)
			{
                infix.push_back(temp);
                temp.clear();
            }
            infix.push_back(str.substr(i, 1));
        }
        if(isdigit(str[i]) || (str[i] == '-' && i == 0 && isdigit(str[i+1])))
		{
            temp.push_back(str[i]);
            continue;
        }
        if(isOperator(str[i]))
		{
            if(temp.length() != 0)
			{
                infix.push_back(temp);
                temp.clear();
            }
            if((str[i] == '-' && isOperator(str[i-1])) || 
               (str[i] == '-' && i == 0 && str[i+1] == '(') || 
               (str[i] == '-' && str[i-1] == '(')){
                infix.push_back("-1");
                infix.push_back("*");
            }else{
                infix.push_back(str.substr(i, 1));
            }
        }
    }
    if(temp.length() != 0)
	{
        infix.push_back(temp);
        temp.clear();
    }
}
void toPostfix()
{
    stack <string> stk;
    int i = 0;
    for(iterator1 = infix.begin(); iterator1 != infix.end() ; iterator1++, i++)
	{
        if(isdigit(infix[i].back()))
		{
            postfix.push_back(infix[i]);
            continue;
        }
        if(infix[i] == "(")
		{
            stk.push(infix[i]);
            continue;
        }
        if(infix[i] == ")")
		{
            while(!stk.empty() && (stk.top() != "("))
			{
                string toPush = stk.top();
                postfix.push_back(toPush);
                stk.pop();
            }
            stk.pop();
            continue;
        }
        if(isOperator(infix[i][0]))
		{
            if(stk.empty() || stk.top() == "(")
			{
                stk.push(infix[i]);
            }
            else{
                while(!stk.empty() && (stk.top() != "(") && 
                      large(infix[i], stk.top())){
                    string toPush = stk.top();
                    postfix.push_back(toPush);
                    stk.pop();
                }
                stk.push(infix[i] );
            }
            continue;
        }
    }
    while(!stk.empty())
	{
        string toPush = stk.top();
        postfix.push_back(toPush);
        stk.pop();
    }
}
void result(){
    stack <string> stk;
    int i = 0;
    double res;
    for(iter = postfix.begin(); iter != postfix.end() ; iter++, i++){
        if(isdigit(postfix[i].back())){
            stk.push(postfix[i]);
        }
        else{
            double A = strtod((stk.top()).c_str(), NULL);
            stk.pop();
            double B = strtod((stk.top()).c_str(), NULL);
            stk.pop();
            res = run(B, A, postfix[i]);
            stk.push(to_string(res));
        }
    }
    res = strtod((stk.top()).c_str(), NULL);
    cout << res << endl;
}
int main()
{
    input();
    toPostfix();
    result();
}
    num1 = putFirst(X);
    num2 = putFirst(Y);
    return num1 <= num2;
}

double run (double X, double Y, string n)
{
    if(n == "+")
	{
        return X+Y;
    }
    else if(n == "-")
	{
        return X-Y;
    }
    else if(n == "*")
	{
        return X*Y;
    }
    else if(n == "/")
	{
        return X/Y;
    }
    else if(n == "%")
	{
        return (int) X % (int) Y;
    }
    return 0;
}
