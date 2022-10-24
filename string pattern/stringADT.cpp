#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int nxt[maxn];
char st[maxn];
struct string_fix
{
    int len;
    char str[maxn];
    void init(int l=maxn){
        len=l;
        printf("请输入串\n");
        scanf("%s",str);
        len=strlen(str);
    }
    void destroy(){
        //先清除，再销毁
        clear();
        len=0;
    }
    void clear(){
        memset(str,0,sizeof(str));
        //将所有位置0
    }
    int getlen(){
        return len;
    }
    int kmp(string_fix T){
        // cout<<"in"<<endl;
        // //利用模式串T的next函数求T在主串S中第pos个字符之后的位置
        int i=0,j=-1;
        nxt[0]=-1;
        while(i<T.len){//初始化nxt数组
            if(j==-1||T.str[i]==T.str[j]){
                ++i,++j;//匹配成功,i,j都增加
                nxt[i]=j;
            }else{
                j=nxt[j];//失配，j借助nxt向前跳
            }
        }
        i=0,j=0;   
        while(i<len&&j<len){//kmp算法
            if(j==-1||str[i]==T.str[j]){
                ++i,++j;if(j>=T.len){
                    cout<<"break"<<endl;
                    break;//只找第一次出现位置
                }
            }else{
                j=nxt[j];
            }
        }
        if(j>=T.len)return i-T.len;//指针到达模式串的最后，表明匹配成功
        else return -1;
    }

    string_fix getsubstr(int pos,int length){
        string_fix ans;
        ans.len=length;//从指定位置，获取一定长度的字串
        for(int i=pos;i<pos+length;i++){
            ans.str[i-pos]=str[i];//将指定位置后的字符逐个复制到返回值中
        }
        return ans;
    }

    void Replace(string_fix *S,string_fix T,string_fix V){
        //用 V 替换主串 S 中出现的所有与 T 相等的不重叠的子串
        int pos;
        while((pos=S->kmp(T))!=-1){
            //先移位,pos之后全部后移delta
            int delta=V.len-T.len;
            char *s=(char*)malloc(sizeof(char)*(S->len-pos));
            memcpy(s,S->str+pos+T.len,S->len-pos-T.len);
            memcpy(S->str+pos+V.len,s,S->len-pos-T.len);
            for(int i=pos,j=0;j<V.len;i++,j++){
                S->str[i]=V.str[j];
            }
            S->len+=delta;//替换S时更新长度
        }
    }
    void print(){
        cout<<"字符串长度"<<len<<endl;
        for(int i=0;i<len;i++){
            cout<<str[i];
        }
        cout<<endl;
    }
    string_fix merge (string_fix T)
    {
        //合并字符串
        string_fix res;
        res.len=T.len+this->len;
        //新字符串的长度是两个字符串的和
        memcpy(res.str,this->str,this->len);
        memcpy(res.str+len,T.str,T.len);
        return res;
    }
};
struct string_flt
{
    int len;
    char *str;
    void init(){
        printf("请输入串\n");
        scanf("%s",st);
        len=strlen(st);
        //用临时字符串做缓冲区
        str=(char*)malloc(sizeof(char)*len);
        //声明空间
        if(str==NULL)
        {
            cout<<"分配空间失败！\n"<<endl;
            exit(0);
        }
        memcpy(str,st,sizeof(char)*len);
        //初始化
    }
    void destroy(){
        clear();//清空后将指针释放
        free(str);
        len=0;
    }
    void clear(){
        for(int i=0;i<len;i++){
            str[i]='\0';
        }
        len=0;
    }
    int getlen(){
        return len;
    }
    int kmp(string_flt T){
        // cout<<"in"<<endl;
        // //利用模式串T的next函数求T在主串S中第pos个字符之后的位置
        memset(nxt,0,sizeof(nxt));
        int i=0,j=-1;
        nxt[0]=-1;
        while(i<T.len){
            if(j==-1||T.str[i]==T.str[j]){
                ++i,++j;
                nxt[i]=j;
            }else{
                j=nxt[j];
            }
        }
        i=0,j=0;   
        while(i<len&&j<len){
            if(j==-1||str[i]==T.str[j]){
                ++i,++j;if(j>=T.len){
                    cout<<"break"<<endl;
                    break;//只找第一次出现位置
                }
            }else{
                j=nxt[j];
                
            }
        }
        if(j>=T.len)return i-T.len;//指针到达模式串的最后，表明匹配成功
        else return -1;
    }

    string_flt getsubstr(int pos,int length){
        string_flt ans;
        ans.len=0;
        if(pos+length>len){
            printf("字串越界！返回值无效\n");
            return ans;
        }
        ans.len=length;
        for(int i=pos;i<pos+length;i++){
            ans.str[i-pos]=str[i];
        }
        return ans;
    }

    void Replace(string_flt *S,string_flt T,string_flt V){
        //用 V 替换主串 S 中出现的所有与 T 相等的不重叠的子串
        int pos;
        while((pos=S->kmp(T))!=-1){
            //先移位,pos之后全部后移delta
            int delta=V.len-T.len;
            S->str=(char *)realloc(S->str,S->len+delta);//扩充空间
            char *s=(char*)malloc(sizeof(char)*(S->len-pos));
            memcpy(s,S->str+pos+T.len,S->len-pos-T.len);
            memcpy(S->str+pos+V.len,s,S->len-pos-T.len);
            for(int i=pos,j=0;j<V.len;i++,j++){
                S->str[i]=V.str[j];
            }
            S->len+=delta;
        }
        
    }
    void print(){
        cout<<"字符串长度"<<len<<endl;
        for(int i=0;i<len;i++){
            cout<<str[i];
        }
        cout<<endl;
    }
    string_flt merge (string_flt T)
    {
        // 合并字符串
        string_flt res;
        res.len=T.len+this->len;
        //新字符串的长度是两个字符串的和
        res.str=(char *)malloc(sizeof(char)*(res.len));
        //为返回值声明空间
        if(res.str==NULL){
            cout<<"分配空间失败"<<endl;
            exit(0);
        }
        memcpy(res.str,this->str,this->len);
        memcpy(res.str+len,T.str,T.len);
        //将对应段的数据粘贴
        return res;
    }
};

int main(){
    //初始化nxt数组
    memset(nxt,0,sizeof(nxt));
    string_flt s1,s2,s3,s4;
    s1.init();
    // s1.print();
    s2.init();
    // s2.print();
    s3.init();
    // s3.print();
    int pos=s1.kmp(s2);
    cout<<"子串第一次出现位置"<<pos<<endl;
    s1.Replace(&s1,s2,s3);
    printf("替换结果\n");
    s1.print();
    printf("s1+s2=\n");
    s4=s1.merge(s2);
    s4.print();
    return 0;
}