#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> v;
    int a;
    for (auto i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }

    int k;
    cin >> k;
    deque<int> q(k); 
  
   
    int i; 
    for (i = 0; i < k; ++i) { 
       
        while ((!q.empty()) && v[i] >= v[q.back()]) 
            q.pop_back();         
        q.push_back(i); 
    }     
    for (; i < n; ++i) {         
        cout << v[q.front()] << " ";         
        while ((!q.empty()) && q.front() <= i - k) 
            q.pop_front(); 
        while ((!q.empty()) && v[i] >= v[q.back()]) 
            q.pop_back();        
        q.push_back(i); 
    }     
    cout << v[q.front()]; 
    
    return 0;
}
