#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}
    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    string text;
    getline(cin, text);
    bool leave = false;
    stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
	    opening_brackets_stack.push(Bracket(next,position));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(opening_brackets_stack.empty())
            {
                cout<<position+1<<endl;
                leave=true;
                break;
                
            }
            else
            {
                auto a=opening_brackets_stack.top();
                if(a.Matchc(next))
                {
                    opening_brackets_stack.pop();
                    
                }
                else
                {
                    cout<<position+1<<endl;
                    leave=true;
                    break;                    
                }
            }

            
        }
    }
    if(opening_brackets_stack.empty()&& !leave)
        cout<<"Success"<<endl;
    else if(!leave)
    {
        auto a=opening_brackets_stack.top();
        cout<<a.position+1<<endl;
    }
    // Printing answer, write your code here

    return 0;
}