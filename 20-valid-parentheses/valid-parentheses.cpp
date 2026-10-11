class Solution {
public:
    bool isValid(string s) {
        stack<char> store;
        for(char a : s){
            if(a=='('|| a=='['|| a=='{'){
                store.push(a);
            }
            else{
                if(store.empty()) return false;
                char last = store.top();
                if((a==')'&&last!='(')||(a=='}'&&last!='{')||(a==']'&&last!='[')){
                    return false;
                }
                store.pop();
            }
        }
        return store.empty();
        
    }
};