// class Solution {
// public:
//     void reverseWords(string &s) {
//       int size = s.size();
//
//       if(size == 0)
//         return;
//
//
//       int begin = 0;
//       int end = 0;
//       int dlt = 0;
//       for(int i = 0; i < size - dlt; i++){
//          //cout <<begin<<" "<<end<<endl;
//         if(s[i] == ' '){ // deal with the redundant " "
//          //cout << "here is a  "<<endl;
//           if(end >= begin && s[begin] != ' '){
//             reverseWord(s, begin, end);
//             begin = i;
//             end = begin;
//           }
//           else
//             begin = i;
//
//         }
//
//         else if(begin > end){
//          // cout <<"begin > end"<<endl;
//           dlt = begin - end;
//           if(dlt > 0){
//             for(int j = end; j < size - dlt; j++){
//               s[j] = s[j + dlt];
//             }
//             s.resize(size - dlt);
//             size = size - dlt;
//           }
//           begin = i;
//           end = begin;
//         }
//
//         else if(end >= begin){
//           end = i;
//         }
//       }
//      // cout <<begin <<" "<<end<<" "<<size<<endl;
//
//       if(begin > end){
//         dlt = begin - end;
//         if(dlt != 0){
//           for(int j = end; j < size - dlt; j++){
//             s[j] = s[j + dlt];
//           }
//           s.resize(size - dlt);
//           size = size - dlt;
//         }
//       }
//
//       else if(end > begin){
//
//         reverseWord(s, begin, end-1);
//         cout <<"begin < end " << s <<endl;
//       }
//
//       else if(begin == end && s[begin] == ' '){
//           s.resize(size - 1);
//       }
//       //cout<<size<<" "<<s<<endl;
//       reverseWord(s, 0, size-1);
//       //cout<<s<<endl;
//
//       if(s[size - 1] == ' ')
//          s.resize(size -1);
//
//       //cout<<s<<endl;
//       return;
//     }
//
//
//     void reverseWord(string &s, int begin, int end){
//         cout << s.size() <<"*"<<begin<<" "<<end<<endl;
//       while(begin <= end){
//         char temp = s[begin];
//         s[begin++] = s[end];
//         s[end--] = temp;
//       }
//     }
//
//
// };

class Solution {
public:
    void reverseWords(string &s) {
      stack<string> res;

      int size = s.size();

      for(int i = 0; i < size; i++){
        if(s[i] == ' ')
          continue;
        else{
          string temp = "";
          while(i < size && s[i] !=' '){
            temp += s[i];
            i++;
          }
          cout<<temp<<endl;
          res.push(temp);
        }
      }

      s = "";
      if(!res.empty()){
        s += res.top();
        res.pop();
      }
      while(!res.empty()){
        s += ' ' + res.top();
        res.pop();
      }


    }
};
