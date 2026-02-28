class Solution {
public:
    string interpret(string command) {
        string result = "";

        for (int i = 0; i < command.length(); i++) {
            if (command[i] == 'G') {
                result += 'G';
            }
            else if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    result += 'o';
                    i++; // skip ')'
                } else { // must be "(al)"
                    result += "al";
                    i += 3; // skip "al)"
                }
            }
        }

        return result;
    }
};