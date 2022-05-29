/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
 //https://leetcode.com/problems/flatten-nested-list-iterator/
struct Data{
    vector<NestedInteger> &list;
    int pos; //which index of the list we currently at
};

class NestedIterator {
    stack<Data> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        st.push({nestedList,0});
        while(not st.empty())
        {
            Data res{st.top()}; 
            if(res.list.size() == 0){
                st.pop();
                continue;
            }
            if(res.list[res.pos].isInteger()) //the element on top of the stack is an integer!
                return;
            st.pop();
            
            if(res.pos < res.list.size() - 1)
                st.push({res.list, res.pos + 1}); //next index of the current list
            if(res.list[res.pos].getList().size())
                st.push({res.list[res.pos].getList(),0});
        } 
    }
    
    int next() {
        int ans = INT_MIN;
        while(not st.empty())
        {
            Data res{st.top()};             
            if(res.list.size() == 0){
                st.pop();
                continue;
            }
            if(res.list[res.pos].isInteger()){
                if(ans != INT_MIN)
                    return ans;
                else //We found the answer. But need to put a valid next element on the top of the stack.
                    ans = res.list[res.pos].getInteger();
                    
            }
            st.pop();
            
            if(res.pos < res.list.size() - 1)
                st.push({res.list, res.pos + 1}); //next index of the current list. 
            
            if(res.list[res.pos].getList().size()) 
                st.push({res.list[res.pos].getList(),0}); //we enter inside the current NestedInteger
         
        }
        
        return ans;
    }
    
    bool hasNext() {
        return not st.empty();
    }
};