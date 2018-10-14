#include <iostream>
#include <string>
#define MAX 100;
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

template <class Type>
class stack
{
private:
    Type* arr;
    int top;
    int stackSize;
public:

    stack()
    {
        stackSize=100;
        arr=new Type[stackSize];
        top=0;


         
    }
    ~stack(){delete [] arr;}
    int priority(char c)
    {
        if (c=='^')
            return 3;
        else if (c=='*'||c=='/')
            return 2;
        else if(c=='+'||c=='-')
            return 1;
        else if(c==')'||'(')
            return 0;
        else
            return -1;
    }
    bool is_empty() const
    {
        return (top==0);
    }
    template<class elem>
    void push(elem a)
    {
        arr[top]=a;
        top++;
    }
    Type top_element()
    {
        return arr[top-1];

    }
    void pop()
    {
        top--;

    }
    bool matching(Type a, Type b)
    {
        return((a==')' && b=='(')||(a=='{'&&b=='}')||(a=='['&&b==']'));
    }
    string infix_to_postfix(string input_expression)
    {
        char topElement; // to store the top element here
        string output_string; // to return the postfix through this variable
        int i=0;

        while(input_expression[i]!='\0') //iterate through the expression until we reach the end
        {
            bool match=false; // we need this variable to push characters in case we failed to find a match

            // if the character is number, add it to the outpu_string
            if(isdigit(input_expression[i]))
            {
                output_string+=input_expression[i];
            }

            else
            {
                // if the stack is empty, dump the charter in
                if(is_empty())
                {
                    push(input_expression[i]);
                    topElement=top_element();
                }
                    // if the character is '(', dump it in the stack regardless
                else if(input_expression[i]=='(')
                {
                    push(input_expression[i]);
                    topElement=top_element();

                }
                else
                {
                    // checking the precedence of each character, keeping the least one at the bottom cells of the stack
                    while(priority(input_expression[i])<=priority(topElement))   // priority(top_element()))
                    {
                        // if the character is ')', we need to match it with the '(', and break
                        if(matching(input_expression[i], top_element()))
                        {
                            pop();
                            topElement=top_element();
                            match=true;
                            break;
                        }
                            // if the precedence of the character is lower that the top element, pop the top element, add it to the out_string,then update the top element
                        else
                        {
                            output_string+=top_element();
                            pop();
                            topElement=top_element();
                        }
                    }
                    // after exiting the while loop, we will push the character into the stack
                    if(match==false)
                    {
                        push(input_expression[i]);
                        topElement=top_element();
                    }
                }

            }
            i++;
        }
        // poping the rest of the stack, and add them to the output_string
        while(top>0)
        {
            output_string+=top_element();
            top--;
        }


        return output_string;
    }
    string postfix_to_infix(string input_expression)
    {
        string topElement;
        string lowerElement;
        string stackElement;
        string output_expression;
        int i=0;
        while(input_expression[i]!='\0')
        {
            if(isspace(input_expression[i]))
            {
                push(input_expression[i]);

            }
            else
            {
                topElement=top_element();
                pop();
                lowerElement=top_element();
                stackElement="("+lowerElement+input_expression[i]+topElement+")";
                push(stackElement);
            }
            i++;


        }
        output_expression=top_element();

        return output_expression;
    }
    int postfix_evaluation(string input_expression)
    {
        int value;
        int topDigit;
        int lowerDigit;
        int digit;
        int i=0;
        while (input_expression[i]!='\0')
        {
            if (isdigit(input_expression[i]))
            {
                digit=input_expression[i]-'0';
                push(digit);
            }
            else
            {
                topDigit=top_element();
                pop();
                lowerDigit=top_element();
                pop();
                switch (input_expression[i])
                {
                    case '+':
                        value=lowerDigit+topDigit;
                        push(value);
                        break;
                    case '-':
                        value=lowerDigit-topDigit;
                        push(value);
                        break;
                    case '*':
                        value=lowerDigit*topDigit;
                        push(value);
                        break;
                    case '/':
                        value=lowerDigit/topDigit;
                        push(value);
                        break;
                    case'^':
                        value=pow(lowerDigit,topDigit);
                        push(value);
                        break;
                }
            }
            i++;
        }

        return value;
    }
};

int main()
{
    string expression;
    int menu_option;
    char restart_option;
    string trash;
    stack<char> st;
    stack<string> st2;
    stack<int>st3;

    do
    {
        cout << "Please give an expression: ";
        getline(cin, expression);
        cout << endl;

        cout << "             OPTIONS MENU" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "    [1] Infix to Postfix Evaulation" << endl;
        cout << "    [2] Postfix to Infix Evaulation" << endl;
        cout << "    [3] Evaulate Postfix" << endl << endl;

        cout << "Your menu option: ";
        cin >> menu_option;
        cout << endl << endl;

        switch (menu_option)
        {
            case 1:
                cout<<st.infix_to_postfix(expression)<<endl;
                break;
            case 2:
                cout<<st2.postfix_to_infix(expression)<<endl;
                break;
            case 3:
                cout<<st3.postfix_evaluation(expression)<<endl;
                break;
            default:
                cout << "Error: That is not an option." << endl << endl;
        }

        cout << "Would you like to enter another expression to convert or evaluate (y/n): " << endl;
        cin >> restart_option;

        cout << endl << endl;
        getline(cin, trash);

    } while (restart_option == 'y');

    return 0;
}
