## [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)

Given a string s, return the longest palindromic substring in s.

*Example 1:* <br/>
*Input:* s = "babad" <br/>
*Output:* "bab" <br/>
*Explanation:* "aba" is also a valid answer. <br/>

*Example 2:* <br/>
*Input:* s = "cbbd" <br/>
*Output:* "bb" <br/>

### Solution
```
string longestPalindrome(string s) {
        int n = s.size();
        int st=0,en=0;
        int dp[n][n];
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g == 0){
                    dp[i][j] = true;
                }
                else if(g == 1){
                    if(s[i] == s[j]) 
                        dp[i][j] = true;
                    else 
                        dp[i][j] = false;
                }
                else{
                    if(s[i] == s[j] and dp[i+1][j-1]) 
                        dp[i][j] = true;
                    else 
                        dp[i][j] = false;
                }
                
                if(dp[i][j]){
                    st = i;
                    en = j-i+1;
                }
                
            }
        }
        
        return s.substr(st,en);
    }
```