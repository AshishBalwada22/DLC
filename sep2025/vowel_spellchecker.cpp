https://leetcode.com/problems/vowel-spellchecker/description/?envType=daily-question&envId=2025-09-14

class Solution {
public:
    string convertintobasestring(string temp){
        for(int i=0;i<temp.length();i++){
            temp[i]=tolower(temp[i]);
        }
        return temp;
    }
    string vowelcorrection(string temp){
        for(int i=0;i<temp.length();i++){
           char ch=tolower(temp[i]);
           if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') temp[i]='*';
        }
        return temp;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string>s(wordlist.begin(),wordlist.end());
        unordered_map<string,string>m;// baseword -> first word
        unordered_map<string,string>m1;// vowel correction -> first word
        for(auto str:wordlist){
           string temp=str;
           temp=convertintobasestring(temp);
           if(m.find(temp)==m.end()) m[temp]=str;
           temp=str;
           temp=vowelcorrection(temp);
           temp=convertintobasestring(temp);
           if(m1.find(temp)==m1.end()) m1[temp]=str;
        }
        vector<string>ans;
        for(int i=0;i<queries.size();i++){
            string str=queries[i]; 
            if(s.find(str)!=s.end()){
                ans.push_back(str);
                continue;
            }
            string temp=str;
            temp=convertintobasestring(temp);
            if(m.find(temp)!=m.end()){
               ans.push_back(m[temp]);
               continue;
            }
            string temp1=str;
            temp1=vowelcorrection(temp1);
            temp1=convertintobasestring(temp1);
            if(m1.find(temp1)!=m1.end()){
                ans.push_back(m1[temp1]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};