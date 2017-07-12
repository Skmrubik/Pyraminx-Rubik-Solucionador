#include <iostream>
#include <vector>
using namespace std;

struct arista{
  int num;
  char cara;
  arista(){
    num=0;
  }
};

class Pyra{
private:
  arista edges[6];
  int center[4];

public:
  Pyra(){
    for(int i=0; i<6;i++){
      edges[i].num=i;
      if(i<4)   center[i]=0;
    }
    edges[0].cara='F';
    edges[1].cara='F';
    edges[2].cara='D';
    edges[3].cara='A';
    edges[4].cara='A';
    edges[5].cara='A';
  }

  void EdgesCaras(const int ent[], const char a,const char b,const char c, bool const prima){
    if(!prima){
      for(int i=0; i<3;i++){
        if(edges[ent[i]].cara==a) edges[ent[i]].cara=c;
        else if(edges[ent[i]].cara==b) edges[ent[i]].cara=a;
        else if(edges[ent[i]].cara==c) edges[ent[i]].cara=b;
      }
    }
    else{
      for(int i=0; i<3;i++){
        if(edges[ent[i]].cara==a) edges[ent[i]].cara=b;
        else if(edges[ent[i]].cara==b) edges[ent[i]].cara=c;
        else if(edges[ent[i]].cara==c) edges[ent[i]].cara=a;
      }
    }
  }

  void PermutaAristas(int ent[]){
    arista aux;
    aux=edges[ent[0]];
    edges[ent[0]]=edges[ent[1]];
    edges[ent[1]]=edges[ent[2]];
    edges[ent[2]]=aux;
  }

  void PermutaCentros(int c, bool prima){
    if(!prima){
      if(center[c]!=2)    center[c]=center[c]+1;
      else                center[c]=0;
    }
    else{
      if(center[c]==0)    center[c]=2;
      else                center[c]=center[c]-1;
    }
  }

  void U(){
    int ent[]={0,1,2};
    PermutaAristas(ent);
    EdgesCaras(ent,'F','D','I',false);
    PermutaCentros(0,false);
  }

  void Up(){
    int ent[]={0,2,1};
    PermutaAristas(ent);
    EdgesCaras(ent,'F','D','I',true);
    PermutaCentros(0,true);
  }

  void R(){
    int ent[]={1,3,4};
    PermutaAristas(ent);
    EdgesCaras(ent,'F','D','A',true);
    PermutaCentros(2,false);
  }

  void Rp(){
    int ent[]={1,4,3};
    PermutaAristas(ent);
    EdgesCaras(ent,'F','D','A',false);
    PermutaCentros(2,true);
  }

  void L(){
    int ent[]={0,5,3};
    PermutaAristas(ent);
    EdgesCaras(ent,'F','I','A',false);
    PermutaCentros(1,false);
  }

  void Lp(){
    int ent[]={0,3,5};
    PermutaAristas(ent);
    EdgesCaras(ent,'F','I','A',true);
    PermutaCentros(1,true);
  }

  void B(){
    int ent[]={2,4,5};
    PermutaAristas(ent);
    EdgesCaras(ent,'D','I','A',true);
    PermutaCentros(3,false);
  }

  void Bp(){
    int ent[]={2,5,4};
    PermutaAristas(ent);
    EdgesCaras(ent,'D','I','A',false);
    PermutaCentros(3,true);
  }

  bool resuelto(){
    bool res=true;
    for(int i=0; i<4 and res;i++){
      if(center[i]!=0)      res=false;
    }
    if(res){
      for(int i=0; i<6 and res;i++){
        if(edges[i].num !=i)    res=false;
      }
    }
    if(res){
      char letras[]={'F','F','D','A','A','A'};
      for(int i=0; i<6 and res; i++)
        if(edges[i].cara!=letras[i])  res=false;
    }
    return res;
  }

  int centrosRotados(){
    int num=0;
    for(int i=0; i<4; i++){
      if(center[i]!=0)
        num++;
    }
    return num;
  }
  int aristasMalas(){
    int num=0;
    for(int i=0; i<6;i++){
      if(edges[i].num!=i)
        num++;
    }
    return num;
  }
};


void mostrar(vector<string> s){
  for(int i=0; i<s.size(); i++)
    cout << s[i];
  cout << endl;
}

void mueve(Pyra p, vector<string> mov, Pyra &paux, vector <string> &movAux, string notacion){
  paux=p;
  movAux=mov;
  if(notacion=="U ")    paux.U();
  if(notacion=="U' ")   paux.Up();
  if(notacion=="R ")    paux.R();
  if(notacion=="R' ")   paux.Rp();
  if(notacion=="L ")    paux.L();
  if(notacion=="L' ")   paux.Lp();
  if(notacion=="B ")    paux.B();
  if(notacion=="B' ")   paux.Bp();
  movAux.push_back(notacion);
}

void resuelve(vector<string> mov, Pyra p, int tam){
  if(tam==0){
    if(p.resuelto())    mostrar(mov);
  }
  else if(tam==1 and p.centrosRotados()>1){}
  else if(tam==1 and p.aristasMalas()>3){}
  else if(tam==2 and p.aristasMalas()==6){}
  else if(tam==2 and p.centrosRotados()>2){}
  else{
    Pyra aux=p;
    vector <string> MovAux;
    string ant, letras[]={"U ","U' ","R ","R' ","L ","L' ","B ","B' "};
    if(mov.size()>0)    ant=mov[mov.size()-1];
    else                ant="AA";

    for(int i=0; i<8; i=i+2){
      if(ant!=letras[i] and ant!= letras[i+1]){
        mueve(p,mov,aux,MovAux,letras[i]);
        resuelve(MovAux,aux,tam-1);
        mueve(p,mov,aux,MovAux,letras[i+1]);
        resuelve(MovAux,aux,tam-1);
      }
    }
  }
}

int main(){
  vector <string> movs;
  Pyra p1;
//Scramble
  p1.L();
  p1.Rp();
  p1.Lp();
  p1.R();
  p1.U();
  p1.R();
  p1.Up();
  p1.Rp();

  for(int i=1; i<15; i++){
    cout << "Con " << i << " movimientos" << endl;
    cout << "_________________" << endl;
    resuelve(movs,p1,i);
  }
}
