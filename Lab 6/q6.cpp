/*Task 6 – Infix to Prefix Conversion using Stack
Write a program to convert an infix expression into prefix form using stack rules.
1. Include operator precedence and associativity handling.
2. Evaluate the prefix expression as well.*/


#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

template <typename T>
class Stack{
    T* arr;
    int capacity;
    int top;

    public:
    Stack(int n){
        capacity = n;
        arr = new T[capacity];
        top = -1;
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == capacity - 1;
    }

    void push(T data){
        if(isFull()){
            cout << "Stack is Full." << endl;
            return;
        }

        arr[++top] = data;
    }

    T pop(){
        if(isEmpty()){
            cout << "Stack is Empty." << endl;
            return '\0' ;
        }

        char temp = arr[top];
        top--;
        return temp;
    }

    T peek_top(){
        if(isEmpty()){
            cout << "Stack is Empty. " << endl;
            return '\0';
        }

        return arr[top];
    }

    void display(){
        if(isEmpty()){
            cout << "Stack is Empty." << endl;
            return ;
        }

        cout << "Stack Elements are :" ;
        for(int i = 0 ; i <= top ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int precedence(char data){
        if(data == '^'){
            return 3;
        }
        else if(data == '*' || data == '/'){
            return 2;
        }
        else if(data == '+' || data == '-'){
            return 1;
        }
        else {return -1;}
}

string reverseString(string infix){
    string revinfix = infix;
    reverse(revinfix.begin() , revinfix.end());
    int n = revinfix.length();
    for(int i = 0 ; i < n ; i++){
        if(revinfix[i] == '('){
            revinfix[i] = ')';
        }
        else if(revinfix[i] == ')'){
            revinfix[i] = '(';
        }
    }
    return revinfix;
}

string infix_to_prefix(string infix){
    string prefix = "";
    int n = infix.length();
    Stack<char> s(n);
    string rev = reverseString(infix);
    for(int i = 0 ; i < n ; i++){
        if((rev[i] >= 'A' && rev[i] <= 'Z') || (rev[i] >= 'a' && rev[i] <= 'z') || (rev[i] >= '0' && rev[i] <= '9')){
            prefix += rev[i];
        }
        else if(rev[i] == '('){
            s.push(rev[i]);
        }
        else if(rev[i] == ')'){
            while(!s.isEmpty() && s.peek_top() != '('){
                prefix += s.peek_top();
                s.pop();
            }
            if(s.peek_top()  == '('){
                s.pop();
            }
        }
        else{
            if(rev[i] == '^'){
            while(!s.isEmpty() && precedence(rev[i]) <= precedence(s.peek_top())){
                prefix += s.peek_top();
                s.pop();
            }
            }
            else{
                while(!s.isEmpty() && precedence(rev[i]) < precedence(s.peek_top())){
                    prefix += s.peek_top();
                    s.pop();
                }
            }
            s.push(rev[i]);
        }

       
    }
     while(!s.isEmpty()){
        char op = s.peek_top();
            prefix = prefix + op;
            s.pop();
        }
    reverse(prefix.begin(),prefix.end());
    return prefix;
}

 int operat(int a ,int b ,char op){
    if(op == '+'){return a + b;}
    else if(op == '-'){return a - b;}
    else if(op == '*'){return a * b;}
    else if(op == '/'){return a / b;}
    else if(op == '^'){return static_cast<int> (pow(a,b));}
    else{return -1;}

}

int evaluate_prefix(const string& result){
    int n = result.length();
    Stack<int> st(n);
    for(int i = n -1 ; i >= 0 ; i--){
        if(result[i] >= '0' && result[i] <= '9'){
            st.push(result[i] - '0');
        }
        else{
            int op1 = st.peek_top();
            st.pop();
            int op2 = st.peek_top();
            st.pop();
            int res = operat(op1 , op2 , result[i]);
            st.push(res);
        }
    }
    if(st.isEmpty()) return 0;
    return st.peek_top();
}

int main(){
     string input;
    cout << "Enter the string to convert to prefix: ";
    cin >> input;

    string result = infix_to_prefix(input);

    cout << "The prefix expression is: " << result << endl;
    cout << "The result for Expression is: " << evaluate_prefix(result) << endl;
}

