#include <iostream>
using namespace std;
#include <queue>
#include <string>
#include <vector>

int main(){

    string a;
    vector<queue<string>> caracter(26);
    queue<string> cua;
    while(cin>>a){
        cua.push(a);
    }
    
    int size=a.size();
    for(int i=0;i<size;++i){
        while(not cua.empty()){
            string a=cua.front();
            cua.pop();
            int zas=a[size-i-1]-'a';
            caracter[zas].push(a);
        }
        
        for(int j=0;j<26;++j){
            if(not caracter[j].empty()){
                while(not caracter[j].empty()){
                    a=caracter[j].front();
                    caracter[j].pop();
                    cua.push(a);

                }
                
            }
        }
        
    }
    if(not cua.empty()){
        cout<<cua.front();
        cua.pop();

    }
    while(not cua.empty()){
        cout<<" "<<cua.front();
        cua.pop();
    }
    cout<<endl;
}
