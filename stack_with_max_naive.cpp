#include<bits/stdc++.h>
using namespace std;


class StackWithMax {
    
    
  public:
    stack <int> s;
stack <int> max;
    void Push(int value) {
        s.push(value);
        if(max.empty())
            max.push(value);
        else if(value>=max.top())
            {
        max.push(value);
        }
    }

    void Pop() {
        if(!s.empty())
        {
        if(max.top()==s.top())
            max.pop();
        s.pop();
        }

    }

    int Max() const {
       if(!max.empty())
        return max.top();
    return -9999;
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}