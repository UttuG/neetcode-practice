class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> charStack;

        int counter = 0;
        string result = "";

        for(int i = 0; i < s.size(); i++) {

            // If digit, build the number
            if(isdigit(s[i])) {
                int num = 0;
                while(i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                numStack.push(num);
                i--; // step back since loop will increment
            }

            // If opening bracket
            else if(s[i] == '[') {
                charStack.push("[");
                counter++;
            }

            // If closing bracket
            else if(s[i] == ']') {

                string temp = "";

                // Pop until '['
                while(!charStack.empty() && charStack.top() != "[") {
                    temp = charStack.top() + temp;
                    charStack.pop();
                }

                // remove '['
                charStack.pop();

                int repeat = numStack.top();
                numStack.pop();

                string expanded = "";
                for(int j = 0; j < repeat; j++) {
                    expanded += temp;
                }

                charStack.push(expanded);
                counter--;
            }

            // Normal character
            else {
                string ch(1, s[i]);
                charStack.push(ch);
            }
        }

        // Build final result
        while(!charStack.empty()) {
            result = charStack.top() + result;
            charStack.pop();
        }

        return result;
    }
};