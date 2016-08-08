class Solution {
public:
    string getHint(string secret, string guess) {
    	int bulls = 0;
    	int cows = 0;
    	int size1 = secret.size(), size2 = guess.size();
       	map<int, bool> find;

    	for(int i = 0; i <10; i++)
    		find.insert(pair<int, bool>(i , false));

    	int i = 0;
    	while( i < size1 && i < size2){
    		if(secret[i] == guess[i]){
    			bulls++;
    			find[secret[i]] = true;
    		}
    		i++;
    	}

    	for(int j = 0; j < size2 ; j ++){
    		if(find[guess[j]] == true)
    			cows++;
    	}

    	string res = to_string(bulls) + "A" + to_string(cows) + "B";

    	return res;
        
    }
};