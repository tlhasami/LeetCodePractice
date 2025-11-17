class Solution {
public:
    bool isAvalible(const string& current , const string& word , const int& n) {
        bool changed = false;
        

        for (int i = 0; i < n ; i++){
            if (current[i] != word[i]){
                if (changed) return false;
                else changed = changed ? false:true;
            } 
        }

        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>qu;
        qu.push(beginWord);

        int steps = 1;
        int n = beginWord.length();
        int listSize = wordList.size();

        vector<bool>visited( listSize, false);
        while(!qu.empty()){
            int level = qu.size();

            for (int i = 0 ; i < level ; i++){
                string current = qu.front() ; qu.pop();

                //if (current == endWord) return steps;

                for (int i = 0 ; i < listSize ; i++){
                    if (!visited[i] && isAvalible(current,wordList[i], n)){
                        qu.push(wordList[i]);
                        //cout << wordList[i] << " " << steps << endl;
                        visited[i] = true;

                        if (wordList[i] == endWord) 
                            return steps+1;
                    }
                }

                // for (bool s:visited) cout << s << " " ;
                // cout << endl;
            }

            steps++;
        }

        return 0;
    }
};