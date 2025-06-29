#include <bits/stdc++.h>
using namespace std;
 
bool isOperand(char c){
    return isdigit(c);
}
 
double evaluatePrefix(string exprsn){
    stack<double> Stack;

    for (int j = exprsn.size() - 1; j >= 0; j--) {
 
        if (isOperand(exprsn[j]))
            Stack.push(exprsn[j] - '0');
        else{
 
            double o1 = Stack.top();
            Stack.pop();
            double o2 = Stack.top();
            Stack.pop();
 
            switch (exprsn[j]) {
            case '+':
                Stack.push(o1 + o2);
                break;
            case '-':
                Stack.push(o1 - o2);
                break;
            case '*':
                Stack.push(o1 * o2);
                break;
            case '/':
                Stack.push(o1 / o2);
                break;
            case '^':
                Stack.push(pow(o1,o2));
            }
        }
    }
 
    return Stack.top();
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
    string post;

    cout<<"Enter prefix notation\n";
    cin>>post;
    string main = check(post);
    cout<<"\nValue = ";
    cout << evaluatePrefix(main) << endl;
    return 0;
}