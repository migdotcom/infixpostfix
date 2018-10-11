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

int main() {
    MyStack<char> infix;
    infix.Push(10);
    infix.Push('=');
    infix.Push(2);
    infix.Push('*');
    cout << infix.Pop();
    return 0;
}
//int main()
//{
//    string expression;
//    int menu_option;
//    char restart_option;
//    string trash;
//
//    do
//    {
//        cout << "Please give an expression: ";
//        getline(cin, expression);
//        cout << endl;
//
//        cout << "             OPTIONS MENU" << endl;
//        cout << "----------------------------------------------" << endl;
//        cout << "    [1] Infix to Postfix Evaulation" << endl;
//        cout << "    [2] Postfix to Infix Evaulation" << endl;
//        cout << "    [3] Evaulate Postfix" << endl << endl;
//
//        cout << "Your menu option: ";
//        cin >> menu_option;
//        cout << endl << endl;
//
//        switch (menu_option)
//        {
//            case 1:
//                break;
//            case 2:
//                break;
//            case 3:
//                break;
//            default:
//                cout << "Error: That is not an option." << endl << endl;
//        }
//
//        cout << "Would you like to enter another expression to convert or evaluate (y/n): " << endl;
//        cin >> restart_option;
//
//        cout << endl << endl;
//        getline(cin, trash);
//
//    } while (restart_option == 'y');
//
//    return 0;
//}