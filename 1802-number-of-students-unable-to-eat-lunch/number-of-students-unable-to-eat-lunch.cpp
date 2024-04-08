class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = sandwiches.size();
        queue<int>stud;
        for(auto i:students){
            stud.push(i);
        }
        stack<int>sand;
        for(int i=n-1;i>=0;i--){
            sand.push(sandwiches[i]);
        }
        int cnt =n;
        int curr =0;
        while(!stud.empty()){
            if(curr==cnt) return cnt;
            if(sand.top()==stud.front()){
                sand.pop();
                stud.pop();
                cnt--;
                curr=0;
            }
            else{
                int x = stud.front();
                stud.pop();
                stud.push(x);
                curr++;
            }
        }
        return cnt;
    }
};