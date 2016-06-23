#include<vector>
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    vector<char>p,q;
    string files[]={"/*Path for the first file*/","/*Path for the second file*/"};
    for(int i=0;i<2;i++){
        ifstream ins(files[i]);
        while (ins.good()) {
            char s;
            ins >> s;
            if(i==0)p.push_back(s);
            else q.push_back(s);
        };
    }
    int k=0;
    vector<char>::iterator i,j=q.begin(),m;
    for(i=p.begin();i!=p.end();i++){
        if(i==p.end()){
            m=j;
            while(*(m)!='#'||*(m-1)!='e'||*(m-2)!='s'||*(m-3)!='a'||*(m-4)!='C')
                m--;
            cout<<"Test file 1 has reached end while test file 2 reached Case #";
            while(*(++m)!=':')
                cout<<*m;
            cout<<endl;
            break;
        }
        if(i==q.end()){
            m=i;
            while(*(m)!='#'||*(m-1)!='e'||*(m-2)!='s'||*(m-3)!='a'||*(m-4)!='C')
                m--;
            cout<<"Test file 2 has reached end while test file 1 reached Case #";
            while(*(++m)!=':')
                cout<<*m;
            cout<<endl;
            break;
        }
        if(*i!=*j){
            m=i;
            while((*(m)!='#'||*(m-1)!='e'||*(m-2)!='s'||*(m-3)!='a'||*(m-4)!='C')&&m>=p.begin())
                m--;
            if(m<p.begin()){
                cout<<"Format Error:\n   Output file has no \"Case #\". "<<endl;
                return 0;
            }
            cout<<"Difference found in Case #";
            while(*(++m)!=':')
                cout<<*m;
            cout<<endl;
            k+=1;
            while((*i!='#'||*(i-1)!='e'||*(i-2)!='s'||*(i-3)!='a'||*(i-4)!='C')){
                if(i==p.end()){
                    m=j;
                    while(*(m)!='#'||*(m-1)!='e'||*(m-2)!='s'||*(m-3)!='a'||*(m-4)!='C')
                        m--;
                    cout<<"Test file 1 has reached end while test file 2 reached Case #";
                    while(*(++m)!=':')
                        cout<<*m;
                    cout<<endl;
                    goto out;
                }
                i++;
            }
            while((*j!='#'||*(j-1)!='e'||*(j-2)!='s'||*(j-3)!='a'||*(j-4)!='C')){
                if(j==q.end()){
                    m=i;
                    while(*(m)!='#'||*(m-1)!='e'||*(m-2)!='s'||*(m-3)!='a'||*(m-4)!='C')
                        m--;
                    cout<<"Test file 2 has reached end while test file 1 reached Case #";
                    while(*(++m)!=':')
                        cout<<*m;
                    cout<<endl;
                    goto out;
                }
                j++;
            }
        }
        j++;
    }
out:
    cout<<"Total differences: "<<k<<endl;
}
