//NO ME CREO NI YO Q FUNCIONE JAJA

void mcj_enters::unir(const mcj_enters& B){ //XD
        if(ini==NULL and B.ini==NULL){

        }
        else if(B.ini==NULL){
            
        }
        else if(ini==NULL){
            mcj_enters aux(B);
            *this=aux;
        }
        else{
            node* aux=ini;
            node* aux2=B.ini;
            node* awa;
            mcj_enters Resp;
            while(aux!=NULL or aux2!=NULL){


                if(aux2==NULL /*and acabat1*/){
                    while(aux!=NULL){
                        if(Resp._pl==0){
                            Resp.ini=new node;
                            Resp.fi=Resp.ini;          
                        }
                        else{
                            awa=new node;
                            Resp.fi->seg=awa;
                            Resp.fi=awa;   
                        }
                        Resp.fi->info=aux->info;
                        Resp.fi->seg=NULL;
                        Resp._pl=Resp._pl+1;
                        aux=aux->seg;
                    }
                }
                //DONE
                else if(aux==NULL /*and acabat1*/){
                    while(aux2!=NULL){
                        if(Resp._pl==0){
                            Resp.ini=new node;
                            Resp.fi=Resp.ini;          
                        }
                        else{
                            awa=new node;
                            Resp.fi->seg=awa;
                            Resp.fi=awa;   
                        }
                        Resp.fi->info=aux2->info;
                        Resp.fi->seg=NULL;
                        Resp._pl=Resp._pl+1;
                        aux2=aux2->seg;
                    }
                }
                //DONE2

                
                else if(aux->info == aux2->info){
                    if(Resp._pl==0){
                        Resp.ini=new node;
                        Resp.fi=Resp.ini;          
                    }
                    else{
                        awa=new node;
                        Resp.fi->seg=awa;
                        Resp.fi=awa;   
                    }
                    Resp.fi->info=aux->info;
                    Resp.fi->seg=NULL;
                    Resp._pl=Resp._pl+1;
                    aux=aux->seg;
                    aux2=aux2->seg;
                }
                else if(aux->info < aux2->info){

                    if(Resp._pl==0){
                        Resp.ini=new node;
                        Resp.fi=Resp.ini;          
                    }
                    else{
                        awa=new node;
                        Resp.fi->seg=awa;
                        Resp.fi=awa;   
                    }
                    Resp.fi->info=aux->info;
                    Resp.fi->seg=NULL;
                    Resp._pl=Resp._pl+1;
                    aux=aux->seg;
                }
                //DONE3 ARRIBA
                else if(aux->info > aux2->info){
                    if(Resp._pl==0){
                            Resp.ini=new node;
                            Resp.fi=Resp.ini;          
                        }
                        else{
                            awa=new node;
                            Resp.fi->seg=awa;
                            Resp.fi=awa;   
                        }
                        Resp.fi->info=aux2->info;
                        Resp.fi->seg=NULL;
                        Resp._pl=Resp._pl+1;
                        aux2=aux2->seg;
                }
            
            }
            *this=Resp;
        }
    }
