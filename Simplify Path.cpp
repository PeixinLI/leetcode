class Solution {
public:
    string simplifyPath(string path) {
    	stack<string> Path;
    	string name = "";
    	int length = path.size();

    	for(int i = 0; i < length; i++){
    		if(path[i] == '/'){
    			if (name == "" || name == ".") {
    				name = "";
    				continue;
    			}
    		    if(name == ".."){
    		        if(! Path.empty())
    		           Path.pop();
    			}
    			else{
    				Path.push(name);
    				cout << name<<endl;
    			}
    			name = "";
    		}
    		else
    			name += path[i];
    	}
    	if(path[length-1] != '/' && name != "." && name != "..")
    	    Path.push(name);
    	else if(name == ".."){
    	    if(!Path.empty())
    	       Path.pop();
    	}
    	   
    	string res = "";
    	
    	if(!Path.empty()){
    	    while(!Path.empty()){
    	        string temp = Path.top();
    	        res = "/" + temp + res;
    	        Path.pop();
    	    }
    	}
    	else res = "/";
    	
    	return res;
        
    }
};