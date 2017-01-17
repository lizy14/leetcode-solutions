class Solution {
public:
bool validateBrackets(const std::string str, const std::string brackets = "()[]{}<>"){
	std::stack<char> stack; //holds 
	for(char chr: str){
		int pos = brackets.find(chr);
		if(pos == std::string::npos)
			continue;
		if(pos % 2 == 0){
			//it's left
			stack.push(chr);
		}else{
			//it's right
			if(stack.empty())
				return false;//extra right
			if(pos == brackets.find(stack.top())+1){
				//match
				stack.pop();
			}else{
				return false;//mismatch
			}
		}
	}
	if(!stack.empty())
		return false;//extra left
	return true;
}
    bool isValid(string s) {
        return validateBrackets(s);
    }
};
