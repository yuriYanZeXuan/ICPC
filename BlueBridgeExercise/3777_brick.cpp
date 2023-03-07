#include<bits/stdc++.h>
using namespace std;
void print(vector<int> &v){
    for(int i=0;i<v.size();i++){
        if(i)cout<<" ";
        cout<<v[i];
    }
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int b=0,w=0;
        for(int i=0;i<n;i++){
            if(s[i]=='B'){
                b++;
            }else{
                w++;
            }
        }
        if(w==0||b==0){
            cout<<0<<endl;
        }
        else if(b%2&&w%2){
            cout<<-1<<endl;
        }else{//10001->01001->00101->00011->00000
                //10001->11101->11110->no solution
            string t=s;
            int sum1=0,sum2=0;
            vector<int> v1,v2;
            for(int i=0;i<n-1;i++){
                if(t[i]=='W')
                {
                    t[i]='B';
                    t[i+1]=(t[i+1]=='W'?'B':'W');
                    v1.push_back(i+1);
                    sum1++;
                }
            }
            if(t.back()!=t[t.length()-2])sum1=-1;
            t=s;
            for(int i=0;i<n-1;i++){
                if(t[i]=='B')
                {
                    t[i]='W';
                    t[i+1]=(t[i+1]=='B'?'W':'B');
                    v2.push_back(i+1);
                    sum2++;
                }
            }
            if(t.back()!=t[t.length()-2])sum2=-1;
            if(sum1!=-1&&sum2!=-1){
                cout<<min(sum1,sum2)<<endl;
                if(sum1<sum2)
                {
                    print(v1);
                }else{
                    print(v2);
                }
            }else if(sum1!=-1){
                cout<<sum1<<endl;
                print(v1);
            }else{
                cout<<sum2<<endl;
                print(v2);
            }

        }
    }
    return 0;
}