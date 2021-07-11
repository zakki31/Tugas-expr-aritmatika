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
