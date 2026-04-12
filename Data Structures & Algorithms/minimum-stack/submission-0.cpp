#include <vector>
#include <climits>
using namespace std;

class MinStack {
public:
    vector<int> st;
    vector<int> mins;

    MinStack() {
    }
    
    void push(int val) {
        st.push_back(val);
        
        if (mins.empty()) {
            mins.push_back(val);
        } else {
            mins.push_back(min(val, mins.back()));
        }
    }
    
    void pop() {
        st.pop_back();
        mins.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return mins.back();
    }
};