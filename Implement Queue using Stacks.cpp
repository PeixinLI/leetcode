class Queue {
public:
    // Push element x to the back of queue.
    int top;
    stack<int> q;
    void push(int x) {
    	q.push(x);
    	top = x;        
    }

    // Removes the element from in front of queue.
    void pop(void) {
    	stack<int> temp;
    	int num = q.size();
    	for(int i=0; i< num; i++){
    		temp.push(q.top());
    		q.pop();  		
    		}
    	temp.pop();
    	for(int i=0; i < num-1; i++){
    		q.push(temp.top());
    		temp.pop();
    		}
        
    }

    // Get the front element.
    int peek(void) {
    	stack<int> temp;
    	int num = q.size();
    	int peek;
    	for(int i=0; i< num; i++){
    		temp.push(q.top());
    		q.pop();  		
    		}
      peek = temp.top();
      for(int i=0; i < num; i++){
    		q.push(temp.top());
    		temp.pop();
    		}
      return peek;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        q.empty();
    }
};