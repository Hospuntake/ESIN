#include <vector>
 using namespace std;
 typedef unsigned int nat;
#include <iostream>

 
 class graf {
   // Graf dirigit i no etiquetat.
   // Les arestes es guarden en una matriu d’adjacència.
   public:
     // Constructora per defecte. Crea un graf buit.
     graf();
 
     // Destructora
     ~graf();
 
     // Llegeix les dades del graf del canal d’entrada
     void llegeix();
 
     vector<nat> quants_succ_succ() const;
     // Pre: Cert
     // Post: Retorna quants successors diferents tenen els successors de cada vèrtex
     // del graf
 
   private:
     nat n; // Nombre de vèrtexs
     nat m; // Nombre d’arestes
     vector<vector<bool> > a; // Matriu d’adjacència
 
     // Aquí va l’especificació dels mètodes privats addicionals
     void successors(nat &xd,vector<bool> &pasat, nat fila)const;
 };
 
 // Aquí va la implementació del mètode públic quants_succ_succ i privats addicionals

    vector<nat> graf::quants_succ_succ() const{
        vector<nat> resp(n);
        int kappa=0;
        for(unsigned int i =0;i<n;++i){
            vector<bool > pasats(n,false);
            nat nene=0;
            kappa=0;
            for(unsigned int j=0;j<n;++j){
                if(a[i][j]){
                    
                     kappa=0;

                    //cout<<"fila: "<<i<<endl;
                    //cout<<"col: "<<j<<endl;
                    successors(nene,pasats,j);
                    kappa=kappa+nene;
                }
            }
            resp[i]=kappa;
        }
        
        return resp;

    }
    void graf::successors(nat &xd,vector<bool> &pasat,nat fila)const{
        for(unsigned int i=0;i<n;++i){
            if(a[fila][i] &&  (not pasat[i])){
                ++xd;
                pasat[i]=true;
                
            }
        }
    }



//_----------------------------



graf::graf() : n(0), m(0) {}

graf::~graf() {}

void graf::llegeix() {
  // Llegim el nombre de vèrtexs i arestes
  cin >> n >> m;

  // Creem la matriu d'adjacència
  a = vector<vector<bool> >(n, vector<bool>(n, false));

  // Llegim les m arestes
  nat u, v;
  for(nat i = 0; i < m; i++) {
    cin >> u >> v; // Aresta que connecta vèrtex u amb vèrtex v
    a[u][v] = true;
  }
}

int main() {
  graf g;
  g.llegeix();
  vector<nat> resultat = g.quants_succ_succ();
  for(nat i=0; i<resultat.size(); i++) {
    cout << resultat[i] << " ";
  }
  cout << endl;
  return 0;
}

