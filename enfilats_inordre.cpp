#include "abin.hpp"
using namespace std;
#include <iostream>
   template <typename T>
   list<T> Abin<T>::inordre() const{
      list<T> a;
      node* p=_pri_inordre;
      if(p!=NULL)a.push_back(p->info);
      

      while(p!=NULL){
         if(p==_ult_inordre){
            /*
            a.pop_back();
            while(not p->thread_esq)p=p->f_esq;
            a.push_back(p->info);
            while(p!=_ult_inordre){
               cout<<p->info<<endl;
               p=p->f_dret;
               a.push_back(p->info);

               
               
            }
            p=NULL;
            */

         }

         else if(not p->thread_dret){//tenim fill dret dret
            if(p==_arrel){
               p=p->f_dret;
               while(not p->thread_esq)p=p->f_esq;
               a.push_back(p->info);
            }
            else{
               p=p->f_dret;
               a.push_back(p->info);
            }      
         }
         else if(p->thread_dret){//tenim fill esquerre
            p=p->f_dret;
            a.push_back(p->info);
         }
         
         
         




      }
      







      return a;


   }
