class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;

        for (string e : emails) {
            int i = 0;
            string local = "";
            while (i < e.length() && e[i] != '@' && e[i] != '+') {
                if (e[i] != '.') {
                    local += e[i];
                }
                i++;
            }

            while (i < e.length() && e[i] != '@') {
                i++;
            }
            string domain = e.substr(i + 1);
            unique.insert(local + "@" + domain);
        }
        return unique.size();
    }
};