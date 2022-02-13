// #include <iostream>
// #include <ctype.h>
// #include <stack>

// using namespace std;

// int pres(char c){
//     if(c == '+'){
//         return 3;
//     }else if(c == '*'){
//         return 2;
//     }else if(c == '-'){
//         return 1;
//     }
//     return -1;
// }
// string intopostfix(string infix){
//     string postfix = "";
//     stack<char> opstack;
//     for(int i = 0; i < infix.length(); i++){
//         char c = infix[i];
//         if(isdigit(c)){
//             postfix += c;
//             continue;
//         }
//         while(!opstack.empty() && pres(c) <= pres(opstack.top())){
//             postfix += opstack.top();
//             opstack.pop();
//         }
//         opstack.push(c);
//     }
//     while(!opstack.empty()){
//         postfix += opstack.top();
//         opstack.pop();
//     }
//     return postfix;                  
// }   
// int eval(string postfix){
//     stack<int> ans;
//     for(int i = 0; i < postfix.length(); i++){
//         char c = postfix[i];
//         if(isdigit(c)){
//             ans.push(c - '0');
//         }else{
//             int val1 = ans.top(); ans.pop();
//             int val2 = ans.top(); ans.pop();
//             switch(c){
//                 case '+': ans.push(val1+val2); break;
//                 case '-': ans.push(val1-val2); break;
//                 case '*': ans.push(val1*val2); break;
//             }
//         }
//     }
//     int eval = ans.top();
//     return eval;
// }        
// int main(void){
//     string str;
//     getline(cin, str);
//     string infix = "";
//     for(int i = 0; i < str.length(); i++){
//         if(str[i] == ' '){
//             continue;
//         }
//         infix += str[i];
//     }
//     string postfix = intopostfix(infix);
//     int evalreturn = eval(postfix);
//     cout << evalreturn-40 << "\n";
//     return 0;
// }
/* C++ implementation to convert
infix expression to postfix*/

#include <iostream>
#include <ctype.h>
#include <stack>
using namespace std;

//Function to return precedence of operators
int prec(char c) {
	if(c == '+')
		return 3;
	else if(c == '*')
		return 2;
	else if(c == '-')
		return 1;
	else
		return -1;
}

int pres(char c){
    if(c == '+'){
        return 3;
    }else if(c == '*'){
        return 2;
    }else if(c == '-'){
        return 1;
    }
    return -1;
}
string intopostfix(string infix){
    string postfix = "";
    stack<char> opstack;
    for(int i = 0; i < infix.length(); i++){
        char c = infix[i];
        if(isdigit(c)){
            postfix += c;
            continue;
        }
        while(!opstack.empty() && pres(c) <= pres(opstack.top())){
            postfix += opstack.top();
            opstack.pop();
        }
        opstack.push(c);
    }
    while(!opstack.empty()){
        postfix += opstack.top();
        opstack.pop();
    }
    return postfix;                  
}

float scanNum(char ch){
   int value;
   value = ch;
   return value - '0';
}
int isOperator(char ch){
   if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
      return 1;//character is an operator
    return -1;//not an operator
}
int isOperand(char ch){
    if(ch >= '0' && ch <= '9'){
        return 1;
    }
    return -1;
}
int operation(int a, int b, char op){
      //Perform operation
    if(op == '+')
        return b + a;
    else if(op == '-')
        return b - a;
    else if(op == '*')
        return b * a;
    else if(op == '/')
        return b / a;
    else if(op == '^')
        return pow(b,a); //find b^a
    else
        return INT_MIN; //return negative infinity
}
int postfixEval(string postfix){
   int a, b;
   stack<int> stk;

   for(int i = 0; i < postfix.length(); i++){
      //read elements and perform postfix evaluation
      if(isOperator(postfix[i]) != -1){
         a = stk.top();
         stk.pop();
         b = stk.top();
         stk.pop();
         stk.push(operation(a, b, postfix[i]));
      }else if(isOperand(postfix[i]) > 0){
         stk.push(scanNum(postfix[i]));
      }
   }
   return stk.top();
}
int main(){
    string a;
    getline(cin, a);
    string b = "";
    for(int i = 0; i < a.length(); i++){
        char c = a[i];
        if(c != ' '){
            b+=a[i];
        }
    }
    string postfix = intopostfix(b);
	cout << postfixEval(postfix);
	return 0;
}
