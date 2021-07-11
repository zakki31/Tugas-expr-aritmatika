/*
Anggota Kelompok
1. Ahmad Muzakki - 2017051037
2. Indah Nirmala Zahra Nabil - 2057051004
3. Muhammad Fahmi Bastari - 2057051005
Link Github : https://github.com/zakki31/Tugas-expr-aritmatika.git
*/

/*
  Buat program untuk mengonversi string infix ke dalam bentuk postfix.
*/

#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string infix, str = "";
    int len;
    
    getline(cin, infix);
    
    len = infix.size();
    
    for(int i=0; i<len; i++) {
        if(isalnum(infix[i])) {
            str += infix[i];
            if(!(isalnum(infix[i+1])))
                str += ' ';
        }
        else if(infix[i]=='-') {
            if(isalnum(infix[i+1])) {
                str += infix[i];
                if(i!=0)
                    str += ' ';
            }
            else if(infix[i+1]=='(') {
                if(isalnum(infix[i-1])) {
                    str += infix[i];
                    str += ' ';
                }
                else {
                    str += "-1 * ";
                }
            }
            
