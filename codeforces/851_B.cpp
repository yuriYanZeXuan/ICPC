#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[10];
        int d=0;
        for(;n;d++){
            A[d]=n%10;
            n/=10;
        }
        int x=0,y=0,f=0,base=1;
        for(int i=0;i<d;i++,base*=10){
            if(A[i]&1){
                if(f){
                    x+=base*(A[i]>>1);
                    y+=base*(A[i]-(A[i]>>1));
                }else{
                    y+=base*(A[i]>>1);
                    x+=base*(A[i]-(A[i]>>1));
                }
                    f=!f;
            }else{
                x+=base*(A[i]>>1);
                y+=base*(A[i]>>1);
            }
        }
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}