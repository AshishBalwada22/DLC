class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream obj1(version1), obj2(version2);
        string word1="", word2="";
        while(true){
            getline(obj1,word1,'.');
            getline(obj2,word2,'.');
            if(word1==""&&word2!=""){
              if(stoi(word2)>0) return -1;
              while(getline(obj2,word2,'.')){
                if(stoi(word2)>0) return -1;
            }
              return 0;
            } 
            if(word1!=""&&word2==""){
               if(stoi(word1)>0) return 1;
               while(getline(obj1,word1,'.')){
                if(stoi(word1)>0) return 1;
               }
               return 0;
            } 
            if(word1==""&&word2=="") break;
            int val1=stoi(word1);
            int val2=stoi(word2);
            if(val1<val2) return -1;
            else if(val1>val2) return 1;
            word1="";
            word2="";
        }
        return 0;
    }
};