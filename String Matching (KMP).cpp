    // apna collage
    vector<int> prefix_function(string &s){
        int n = s.size();
        vector<int> pi(n, 0);
        for(int i = 1; i < n; i++){
            int j = pi[i-1];
            
            while(j > 0 && s[j] != s[i]){
                j = pi[j-1];
            }

            if(s[i] == s[j]){
                j++;
            }

            pi[i] = j;
        }
        return pi;
    }
    // implemented below function by own ..Think carefully you will get it
    vector<int> matchString(string &txt, string &pattern){
        // return all the matched indices
        vector<int> pi = prefix_function(pattern); // prefix and suffix matched longest lengths for each index of pattern
        int n = txt.size(), m = pattern.size(), j = 0, prev = -1;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(j == m){
                ans.push_back(i-m);
                while(j > 0 && txt[i] != pattern[j]){
                    j = pi[j-1];
                }
            }
            if(txt[i] == pattern[j]){
                j++;
            }else{
                while(j > 0 && txt[i] != pattern[j]){
                    j = pi[j-1];
                }
                if(txt[i] == pattern[j]){
                    j++;
                }
            }
        }
        if(j == m){
            ans.push_back(n - m);
        }
        return ans;

    }