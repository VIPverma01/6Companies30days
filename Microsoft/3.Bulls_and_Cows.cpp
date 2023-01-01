/*
link: https://leetcode.com/problems/bulls-and-cows/
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int arrSecret[10] = {0}, arrGuess[10] = {0}, n = secret.length(), Bulls = 0, Cows = 0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]) {
                Bulls++;
                continue;
            }
            arrSecret[secret[i]-'0']++;
            arrGuess[guess[i]-'0']++;
        }
        for(int i=0;i<10;i++){
            Cows += min(arrSecret[i],arrGuess[i]);
        }
        return to_string(Bulls)+"A"+to_string(Cows)+"B";
    }
};