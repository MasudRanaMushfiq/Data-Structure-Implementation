#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
 
// Function to find precedence of
// operators.
int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}

int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}
 

int evaluate(string tokens){
    int i;
     
    // stack to store integer values.
    stack <int> values;
     
    // stack to store operators.
    stack <char> ops;
     
    for(i = 0; i < tokens.length(); i++){

        if(tokens[i] == ' ')
            continue;
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }
        else if(isdigit(tokens[i])){
            int val = 0;
            while(i < tokens.length() &&
                        isdigit(tokens[i]))
            {
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
             
            values.push(val);
              i--;
        }
    
        else if(tokens[i] == ')'){
            while(!ops.empty() && ops.top() != '('){
                int val2 = values.top();
                values.pop();
                 
                int val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
            if(!ops.empty())
               ops.pop();
        }
         
        
        else{
            while(!ops.empty() && precedence(ops.top())
                                >= precedence(tokens[i])){
                int val2 = values.top();
                values.pop();
                 
                int val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
             
 
            ops.push(tokens[i]);
        }
    }
     
   
    while(!ops.empty()){
        int val2 = values.top();
        values.pop();
                 
        int val1 = values.top();
        values.pop();
                 
        char op = ops.top();
        ops.pop();
                 
        values.push(applyOp(val1, val2, op));
    }
     
   
    return values.top();
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
    cout<<"Enter infix expression :";
    string exp;

    cin>>exp;
    
    string main = check(exp);
    cout<<main;
    cout<<evaluate(main);

    return 0;
    
}