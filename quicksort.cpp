#include <iostream>
using namespace std;
#include <vector>
int particio(vector<int> &R,int inicio,int final){
    int pivote=R[inicio];
    int i = inicio+1;
    for(int j=i;j<=final;++j){
        if(R[j] <pivote){
            swap(R[i],R[j]);
            i++;
        }
    }
    swap(R[inicio],R[i-1]);
    return i-1;

    
}

void quicksort(vector<int> &R,int inicio,int final){
    if(inicio<final){
        int pivote=particio(R,inicio,final);
        quicksort(R,inicio,pivote);
        quicksort(R,pivote+1,final);

    }


}


int main(){
    vector<int> ord;
    int a;
    int r;
    while( cin>>a){
        ord.push_back(a);
    }
    r=ord.size()-1;
    quicksort(ord,0,r);
    for(unsigned int i=0;i<ord.size();++i){
        cout<<ord[i]<<",";
    }
    cout<<endl;

}
