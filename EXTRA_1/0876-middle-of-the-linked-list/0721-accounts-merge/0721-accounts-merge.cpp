//https://leetcode.com/problems/accounts-merge/description/?envType=problem-list-v2&envId=w5zahxti
class Solution {
    private:
    unordered_map<string, string> parent;
    unordered_map<string, string> owner;
    string find(string s){
        if (parent.find(s) == parent.end()){
            parent[s] = s;
        }
        if (parent[s] == s){
            return s;
        }
        return parent[s] = find(parent[s]);
    }
    void unite(string a, string b){
        string rootA = find(a);
        string rootB = find(b);
        if (rootA != rootB){
            parent[rootA] = rootB;
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(auto& acc : accounts){
            string name = acc[0];
            string firstEmail = acc[1];

            for (int i=1; i<acc.size();i++){
                string currentEmail = acc[i];
                unite(firstEmail, currentEmail);
                owner[currentEmail] = name;
                owner[firstEmail] = name;
            }
        }
        unordered_map<string, vector<string>> groups;
        for(auto& p : owner){
            string email = p.first;
            string root = find(email);
            groups[root].push_back(email);
        }

        vector<vector<string>> result;
        for (auto& g:groups){
            string rootEmail = g.first;
            vector<string>& emailList = g.second;
            sort(emailList.begin(), emailList.end());
            vector<string> account;
            account.push_back(owner[rootEmail]);
            account.insert(account.end(), emailList.begin(), emailList.end());
            result.push_back(account);
        }
        return result;
    }
};