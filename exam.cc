#include <vector>
#include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename Clau>
 class bst {
 
   public:
     // Constructora per defecte. Crea un BST buit.
     bst();
 
     // Destructora
     ~bst();
 
     // Aquí va l’especificació dels mètodes públics addicionals
          void insereix(Clau e);
               void ordena2(vector<Clau>& v);


 
   private:
     struct node {
       Clau _k;      // Clau
       node* _esq;   // fill esquerre
       node* _dret;  // fill dret
     };
     node *_arrel;
 
     static void esborra_nodes(node* m);
 
     // Aquí va l’especificació dels mètodes privats addicionals
     void insereix2(Clau e,node* x);
     void ordena2def(vector<Clau>& v,node* x);
 };
    template <typename T>
    void ordena(vector<T>& v){
        /*
        PRE: donat un vector 
        POST:  Retorna el mat4eix vector ordenat


        */
        cout<<"asd ";
        int size=v.size();
        bst<T> ere;
        for(int i=0;i<size;++i){
            
            ere.insereix(v[i]);
        }
        ere.ordena2(v);
        //RECORREM EN INORDRE
    }
    template <typename Clau>
    void bst<Clau>::insereix(Clau e){
        /*
    PRE: donat un valor
    POST:  Fica dins d'un bst el valor


        */
        if(_arrel==NULL){
            node* ere=new node;
            _arrel=ere;
            ere->_esq=NULL;
            ere->_dret=NULL;
            _arrel->_k=e;

        }

        else insereix2(e,_arrel);
    }
    template <typename Clau>
    void bst<Clau>::insereix2(Clau e,node* x){
        /*
    PRE: donat un valor i un nombre
    POST:  Fica dins d'un bst el valor en ordre al bst


        */
                
            if(_arrel==NULL){
                


            }
        else if(x->_k>=e){//Esquerra
            if(x->_esq==NULL){
                node* ere=new node;
                x->_esq=ere;
                ere->_k=e;
                ere->_dret=NULL;
                ere->_esq=NULL;

            }
            else insereix2(e,x->_esq);



        }
        else if(x->_k<e){ //Dreta
            if(x->_dret==NULL){
                node* ere=new node;
                x->_dret=ere;
                ere->_k=e;
                ere->_dret=NULL;
                ere->_esq=NULL;

            }
            else insereix2(e,x->_dret);


        }





    }
    template <typename Clau>
    void bst<Clau>::ordena2(vector<Clau>& v){
        /*
    PRE: donat un vector i un arbre bst no buit
    POST:  esborra el vector i posa en inordre els valors de l'arbre bst


        */
        int size=v.size();
        for(int i=0;i<size;++i)v.pop_back();

        ordena2def(v,_arrel);
        



    }
    template <typename Clau>
    void bst<Clau>::ordena2def(vector<Clau>& v,node* x){
        /*
    PRE: donat un arbre i un vector buit
    POST: posa en inordre al vector els valors de l'arbre bst


        */

        if(_arrel!=NULL){
            ordena2def(v,x->_esq);
            v.push_back(x->_k);
            ordena2def(v,x->_dret);
        }


    }
 // Aquí va la implementació dels mètodes públics i privats de bst
 
 // Aquí va la implementació del procediment ordena


//--------------------------------------------------

template <typename Clau>
bst<Clau>::bst() : _arrel(NULL) {}

template <typename Clau>
void bst<Clau>::esborra_nodes(node* m) {
  if (m != NULL) {
    esborra_nodes(m->_esq);
    esborra_nodes(m->_dret);
    delete m;
  }
}

template <typename Clau>
bst<Clau>::~bst() {
  esborra_nodes(_arrel);
}

template <typename T>
void ordena(vector<T>& v);

template <typename T>
void mostra(vector<T> v) {
  for (nat i=0; i < v.size(); ++i) {
    cout << v[i] << ' ';
  }
  cout << endl;
}

int main() {
  nat n;
  while (cin >> n) {
    vector<double> v(n);
    for (nat i=0; i < n; ++i) {
      cin >> v[i];
    }
    ordena<double>(v);

    mostra<double>(v);
  }
  return 0;
}
