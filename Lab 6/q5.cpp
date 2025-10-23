/*Task 5 – Infix to Postfix Conversion using Stack
Write a program to convert an infix expression into postfix form using a stack. Also, evaluate the
postfix expression afterward.*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

template <typename T>
class Stack{
    T* arr;
    int capacity;
    int top;

    public:
    Stack(int n){
        capacity = n;
        arr = new char[capacity];
        top = -1;
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == capacity - 1;
    }

    void push(char data){
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


string infix_to_postfix(string infix){
    string postfix = "";
    int n = infix.length();
    Stack<char> st(n);

    for(int i = 0 ; i < n ; i++){
        if((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= '0' && infix[i] <= '9')){
            postfix += infix[i];
        }
        else if(infix[i] == '('){
            st.push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(!st.isEmpty() && st.peek_top() != '('){
                postfix += st.peek_top();
                st.pop();
            }
            if(st.peek_top()  == '('){
                st.pop();
            }
        }
        else{
            while(!st.isEmpty() && precedence(infix[i]) <= precedence(st.peek_top())){
                postfix += st.peek_top();
                st.pop();
            }
            st.push(infix[i]);
        }

       
    }
     while(!st.isEmpty()){
        char op = st.peek_top();
            postfix = postfix + op;
            st.pop();
        }
    return postfix;
}

int operat(int a ,int b ,char op){
    if(op == '+'){return a + b;}
    else if(op == '-'){return a - b;}
    else if(op == '*'){return a * b;}
    else if(op == '/'){return a / b;}
    else if(op == '^'){return static_cast<int> (pow(a,b));}
    else{return -1;}

}

int evaluate_postfix(string postfix_){
    int n = postfix_.length();
    Stack<int> s(n);
    for(int i = 0 ; i < n ; i++){
        if(postfix_[i] > '0' && postfix_[i] < '9'){
            s.push(postfix_[i] - '0');
        }
        else {
            int op2 = s.peek_top();
            s.pop();
            int op1 = s.peek_top();
            s.pop();
            int res = operat(op1 , op2 , postfix_[i]);
            s.push(res);
        }
    }

    return s.peek_top();
}

int main(){
    
    string input;
    cout << "Enter the string to convert to postfix: ";
    cin >> input;

    string result = infix_to_postfix(input);

    cout << "The postfix expression is: " << result << endl;
    cout << "The result for the expression is: " << evaluate_postfix(result) << endl;
}