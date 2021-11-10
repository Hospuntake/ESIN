#include <cstdlib>
 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class Abin {
   public:
     Abin(): _arrel(NULL) {};
     // Pre: cert
     // Post: el resultat és un arbre sense cap element
     Abin(Abin<T> &ae, const T &x, Abin<T> &ad);
     // Pre: cert
     // Post: el resultat és un arbre amb un element i dos subarbres
 
     // Les tres grans
     Abin(const Abin<T> &a);
     ~Abin();
     Abin<T>& operator=(const Abin<T>& a);
 
     // operador << d’escriptura
     template <class U> friend std::ostream& operator<<(std::ostream&, const Abin<U> &a);
 
     // operador >> de lectura
     template <class U> friend std::istream& operator>>(std::istream&, Abin<U> &a);
     
     
 void insereix(int e);
     // Modifica el contingut de l’arbre per tal de guardar a cada node el factor
     // d’equilibri (diferència entre l’altura fill esquerra i l’altura fill dret).
     bool el_trobem(int e);
     
 
   private:
     struct node {
       node* f_esq;
       node* f_dret;
       T info;
     };
     node* _arrel;
     static node* copia_nodes(node* m);
     static void esborra_nodes(node* m);
     static void print_nodes(node* m, ostream &os, string d1);
      void insereix2(int e,node* x);
     // Aquí va l’especificació dels mètodes privats addicionals
     

 };
 
 // Aquí va la implementació del mètode arbre_factors_equilibri




 

template <typename T>
typename Abin<T>::node* Abin<T>::copia_nodes(node* m) {
/* Pre: cert */
/* Post: si m és NULL, el resultat és NULL; sinó,
   el resultat apunta al primer node d'un arbre binari
   de nodes que són còpia de l'arbre apuntat per m */
  node* n;
  if (m == NULL) n = NULL;
  else {
    n = new node;
    try {
      n->info = m->info;
      n->f_esq = copia_nodes(m->f_esq);
      n->f_dret = copia_nodes(m->f_dret);
    } catch(...) {
      delete n;
      throw;
    }
  }
  return n;
};

template <typename T>
void Abin<T>::esborra_nodes(node* m) {
/* Pre: cert */
/* Post: no fa res si m és NULL, sinó allibera
   espai dels nodes de l'arbre binari apuntat per m */
  if (m != NULL) {
    esborra_nodes(m->f_esq);
    esborra_nodes(m->f_dret);
    delete m;
  }
};

template <typename T>
Abin<T>::Abin(Abin<T>& ae, const T& x, Abin<T>& ad) {
/* Pre: cert */
/* Post: el resultat és un arbre amb x com arrel, ae com a fill
esquerre i ad com a fill dret. No fa còpia dels arbres ae i ad */
  _arrel = new node;
  try {
    _arrel->info = x;
  }
  catch (...) {
    delete _arrel;
    throw;
  }
  _arrel->f_esq = ae._arrel;
  ae._arrel = NULL;
  _arrel->f_dret = ad._arrel;
  ad._arrel = NULL;
}
template <typename T>
bool Abin<T>::el_trobem(int e)
{
  node* p=_arrel;
  bool ere=false;
  while(p!=NULL and not ere){
    if(p->info==e){

      ere=true;
    }
    else {
      if(e<p->info){//esq
        p=p->f_esq;
      }
      else if(e>p->info) {//dreta
        p=p->f_dret;
      }

    }
    
    
  }

  return ere;


}

template <typename T>
Abin<T>::Abin(const Abin<T> &a) {
  _arrel = copia_nodes(a._arrel);
};

template <typename T>
Abin<T>::~Abin() {
  esborra_nodes(_arrel);
};



template <typename T>
void Abin<T>::insereix2(int e,node* x)
/* Pre: cert */
/* Post: el paràmetre implícit se li fica e en bfs */
{
  if(x->info>e){//Esquerra
    if(x->f_esq==NULL){
      node* ere=new node;
      x->f_esq=ere;
      ere->info=e;
      ere->f_dret=NULL;
      ere->f_esq=NULL;

    }
    else insereix2(e,x->f_esq);



  }
  else if(x->info<e){ //Dreta
    if(x->f_dret==NULL){
      node* ere=new node;
      x->f_dret=ere;
      ere->info=e;
      ere->f_dret=NULL;
      ere->f_esq=NULL;

    }
    else insereix2(e,x->f_dret);


  }
}
template <typename T>
void Abin<T>::insereix(int e) 
/* Pre: cert */
/* Post: el paràmetre implícit se li fica e en bfs */
{
    insereix2(e,_arrel);
}
template <typename T>
Abin<T>& Abin<T>::operator=(const Abin<T>& a) {
  if (this != &a) {
    node* aux;
    aux = copia_nodes(a._arrel);
    esborra_nodes(_arrel);
    _arrel = aux;
  }
  return (*this);
};

template <typename T>
void Abin<T>::print_nodes(node* p, ostream &os, string prefix) {
  if (p == NULL) 
    os << ".";
  else {
    string prefix2;
    os << "["<<p->info << "]\n" << prefix << " \\__";
    prefix2 = prefix + " |  ";
    print_nodes(p->f_dret, os, prefix2);
    os << "\n" << prefix << " \\__";
    prefix2 = prefix + "    ";
    print_nodes(p->f_esq, os, prefix2);
  }
}

// operador << d'escriptura
template <class U>
ostream& operator<<(ostream &os, const Abin<U> &a) {
  a.print_nodes(a._arrel, os, "");
  os << "\n";
  return os;
}

// operador >> de lectura
template <class U>
istream& operator>>(istream &is, Abin<U> &a) {  
  int valor;
  cin >> valor;
  if (valor != -1) {
    Abin<U> ae;
    is >> ae;
    Abin<U> ad;
    is >> ad;
    a = Abin<U>(ae, valor, ad);
  }
  return is;
}
Abin<int> llegir(){

    Abin<int> A, A1, A2;
    int n = 0; cin >> n;

    if(n != -1){
        A1 = llegir();
        A2 = llegir();
        A = Abin<int>(A1,n,A2);
    }

    return A;
}
int main() {


 
   int num;
  cin>>num;
  
    Abin<int> resp;
    int cont=1;
    int a;
    cin>>a;
    Abin<int> respr(resp,a,resp);
    while(cont<num){
      cin>>a;
      if(a!=-1){
        
        respr.insereix(a);
        ++cont;
        
      }
    } 
    //cout<<respr<<endl;
    


    
    int e;
    while(cin>>e){
      if(e==-1){}
      else if(respr.el_trobem(e))cout<<e<<" "<<"1"<<endl;
      else cout<<e<<" "<<"0"<<endl;
    }
  
  

  
  
}
