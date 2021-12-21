#include <iostream>
using namespace std;
#include <vector>
void merge(vector<double> &R,int inicio,int mitad,int final){
    int i,j,k;
    int Izq=mitad-inicio+1;
    int Der= final-mitad;
    vector<double> izquierdo(Izq);
    vector<double> derecho(Der);
    for(int i = 0; i < Izq; i++){
        izquierdo[i] = R[inicio+i];
    }
    for(int j = 0; j < Der; j++){
        derecho[j] = R[mitad + 1 + j];
    }
    i = 0;
    j = 0;
    k = inicio;
    while(i < Izq && j < Der){
        if(izquierdo[i] <= derecho[j]){
            R[k] = izquierdo[i];
            i++;
        }
        else{
            R[k] = derecho[j];
            j++;
        }
        k++;
    }

    while(j < Der){
        R[k] = derecho[j];
        j++;
        k++;
    }

    while(i < Izq){
        R[k] = izquierdo[i];
        i++;
        k++;
    }



}

void MergeSort(vector<double> &R,int inicio,int final){
    if(inicio<final){
        int mitad=inicio+(final-inicio)/2;
        MergeSort(R,inicio,mitad);
        MergeSort(R,mitad+1,final);
        merge(R,inicio,mitad,final);


    }


}
void ordena_per_fusio(vector<double>& v){

    MergeSort(v,0,v.size()-1);
}
/*
int main(){
    vector<int> ord;
    int a;
    int r;
    while( cin>>a){
        ord.push_back(a);
    }
    r=ord.size()-1;
    MergeSort(ord,0,r);
    for(unsigned int i=0;i<ord.size();++i){
        cout<<ord[i]<<",";
    }
    cout<<endl;

}
*/