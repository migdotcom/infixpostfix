#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

#define MaxSize = 100
template <class Type>
class MyStack
{
public:
    MyStack(int MaxSize);
    MyStack(const MyStack<Type> &OtherStack);
    ~MyStack(void);

     void        Push(const Type &Item); // Adds Item to the top
     Type        Pop(void);              // Returns Item from the top

private:
    Type     *input;           // The  input array
    int       top;    // The top number of elements
    const int MAX_NUM;        // Maximum number of elements
};


// Stack Constructor function
template <class Type>
MyStack<Type>::MyStack(int) :
        MAX_NUM( 100 )    // Initialize the constant
{
    input = new Type[MAX_NUM];
    top = 0;
}

// Stack Destructor function
template <class Type>
MyStack<Type>::~MyStack(void)
{
    delete[] input;
}

// Push() function
template <class Type>
void MyStack<Type>::Push(const Type &Item)
{

    assert(top < MAX_NUM);

    input[top++] = Item;
}

// Pop() function
template <class Type>
Type MyStack<Type>::Pop(void)
{

    assert(top > 0);

    return input[--top];
}
bool realOperand(char character);
bool realOperator(char character);
bool realOperand(char character){
    if( character >= '0' && character <='9' || character >= 'A' && character <='Z'||character >= 'a' && character <='z'){
        return true;
    }
    return false;
}
bool  realOperator(char character){
    if( character == '*' && character =='+' || character >= '/' && character <='$'){
        return true;
    }
    return false;
}
int main() {
    MyStack<char> infix;
    infix.Push(10);
    infix.Push('=');
    infix.Push(2);
    infix.Push('*');
    cout << infix.Pop();

    return 0;
}
