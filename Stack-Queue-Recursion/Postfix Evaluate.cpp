#include<bits/stdc++.h>
using namespace std;
string post;
float scanNum(char ch){
   int value;
   value = ch;
   return float(value-'0');//return float from character
}
//9 == 109 0 == 100 9-0 == 109-100 = 9float
//abc*+d-

int isOperator(char ch){
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
      return 1;//character is an operator
      return -1;//not an operator
   }
   int isOperand(char ch){
      if(ch >= '0' && ch <= '9')
         return 1;//character is an operand
      return -1;//not an operand
   }
   float operation(int a, int b, char op){
      //Perform operation
      if(op == '+')
         return b+a;
      else if(op == '-')
         return b-a;
      else if(op == '*')
         return b*a;
      else if(op == '/')
         return b/a;
      else if(op == '^')
         return pow(b,a); //find b^a
      else
   return INT_MIN; //return negative infinity
}
float postfixEval(string postfix){
   int a, b;
   stack<float> stk;
   string::iterator it;
   for(it=postfix.begin(); it!=postfix.end(); it++){
      //read elements and perform postfix evaluation
      if(isOperator(*it) != -1){
         a = stk.top();
         stk.pop();
         b = stk.top();
         stk.pop();
         stk.push(operation(a, b, *it));
      }else if(isOperand(*it) > 0){
         stk.push(scanNum(*it));// 60
      }
   }
   return stk.top();
}

string check(string s){
   char c;
   for(int i = 0; i < s.length(); i++){
      if((s[i] >= 'A' && s[i] <='Z') || (s[i] >= 'a' && s[i] <= 'z')){
         cout<<"Enter the value for "<<s[i]<< " : "<<endl;
         cin>>c;
         s[i] = c;
      }
   }
   return s;
}
int main(){
   
   cout<<"Enter postfix notation\n";
   cin>>post;
   string main = check(post);
   
   cout <<postfixEval(main);

   return 0;
}
