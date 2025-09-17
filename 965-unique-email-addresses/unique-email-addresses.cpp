class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>uniqueEmails;

        for (string email : emails){
            int idx = 0 , n = email.size();
            string currentEmail = "";

            for(int i = 0 ; i < n ; i++){
                char alpha = email[i];

                if (alpha == '@'){
                    idx++;currentEmail += "@";
                } else if (alpha == '.' && idx == 0){
                    continue;
                } else if (alpha == '+' && idx == 0){

                    while (i+1< n && email[i+1] != '@'){
                        i++;
                    }
                } else {
                    currentEmail += alpha;
                }
            }

            uniqueEmails.insert(currentEmail);

        }

        return uniqueEmails.size();
    }
};