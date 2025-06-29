#include<bits/stdc++.h>
#define N 10000
using namespace std;

int stk[N];
int ind = -1;

void psh(int x) {
    if(ind+1 == N){
        cout<<"Overflow\n";
        return;
    }
    ind = ind + 1;
    stk[ind] = x;
    return;
}

int pop() {
    if(ind == -1) {
        cout<<"Underflow\n";
        return -1;
    }
    int val = stk[ind];
    ind--;
    return val;
}

int top() {
    return stk[ind];
}

int main() {
    char a[100];
    char x;
    int i = 0;
    while(cin>>x) {
        a[i] = x;
        i++;
    }

    for(int j = 0; j < i; j++) {
        if(a[j] >= '0' && a[j] <= '9') {
            psh(a[j] - '0');
        }
        if(a[j] >= 'a' && a[j] <= 'z'){
            if(a[j] == 'a') psh(3);
            else if(a[j] == 'b') psh(2);
            else psh(1);
        }
        else {
            if(a[j] == '+') {
                int first = pop();
                int second = pop();
                psh(second+first);
            }
            else if(a[j] == '-') {
                int first = pop();
                int second = pop();
                psh(second-first);
            }
            else if(a[j] == '*') {
                int first = pop();
                int second = pop();
                psh(second*first);
            }
            else if(a[j] == '/') {
                int first = pop();
                int second = pop();
                psh(second/first);
            }
            else if(a[j] == '^') {
                int first = pop();
                int second = pop();
                psh(pow(second,first));
            }
        }
    }
    cout<<top()<<"\n";
}
