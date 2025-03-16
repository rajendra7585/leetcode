class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        int c=0;
        int i=0;
        queue<int>q;
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }
        while(q.size()!=0 && c!=n){
            if(q.front()==sandwiches[i]){
                c=0;
                q.pop();
                i++;

            }
            else{
                c++;
                q.push(q.front());
                q.pop();
            }
        } 
        return q.size();
    }
};