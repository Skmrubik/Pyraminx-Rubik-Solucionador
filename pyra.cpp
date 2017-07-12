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
  void U(){

    if(edges[0].cara=='F') edges[0].cara='I';
    else if(edges[0].cara=='D') edges[0].cara='F';
    else if(edges[0].cara=='I') edges[0].cara='D';
    if(edges[1].cara=='F') edges[1].cara='I';
    else if(edges[1].cara=='D') edges[1].cara='F';
    else if(edges[1].cara=='I') edges[1].cara='D';
    if(edges[2].cara=='F') edges[2].cara='I';
    else if(edges[2].cara=='D') edges[2].cara='F';
    else if(edges[2].cara=='I') edges[2].cara='D';

    arista aux;
    aux=edges[0];
    edges[0]=edges[1];
    edges[1]=edges[2];
    edges[2]=aux;


    if(center[0]==0)        center[0]=1;
    else if(center[0]==1)   center[0]=2;
    else                    center[0]=0;
  }
  void Up(){
    arista aux;
    aux=edges[0];
    edges[0]=edges[2];
    edges[2]=edges[1];
    edges[1]=aux;

    if(edges[0].cara=='F') edges[0].cara='D';
    else if(edges[0].cara=='D') edges[0].cara='I';
    else if(edges[0].cara=='I') edges[0].cara='F';
    if(edges[1].cara=='F') edges[1].cara='D';
    else if(edges[1].cara=='D') edges[1].cara='I';
    else if(edges[1].cara=='I') edges[1].cara='F';
    if(edges[2].cara=='F') edges[2].cara='D';
    else if(edges[2].cara=='D') edges[2].cara='I';
    else if(edges[2].cara=='I') edges[2].cara='F';

    if(center[0]==0)        center[0]=2;
    else if(center[0]==1)   center[0]=0;
    else                    center[0]=1;
  }
  void R(){
    arista aux;
    aux=edges[1];
    edges[1]=edges[3];
    edges[3]=edges[4];
    edges[4]=aux;

    if(edges[1].cara=='F') edges[1].cara='D';
    else if(edges[1].cara=='D') edges[1].cara='A';
    else if(edges[1].cara=='A') edges[1].cara='F';
    if(edges[3].cara=='F') edges[3].cara='D';
    else if(edges[3].cara=='D') edges[3].cara='A';
    else if(edges[3].cara=='A') edges[3].cara='F';
    if(edges[4].cara=='F') edges[4].cara='D';
    else if(edges[4].cara=='D') edges[4].cara='A';
    else if(edges[4].cara=='A') edges[4].cara='F';

    if(center[2]==0)        center[2]=1;
    else if(center[2]==1)   center[2]=2;
    else                    center[2]=0;
  }
  void Rp(){
    arista aux;
    aux=edges[1];
    edges[1]=edges[4];
    edges[4]=edges[3];
    edges[3]=aux;

    if(edges[1].cara=='F') edges[1].cara='A';
    else if(edges[1].cara=='D') edges[1].cara='F';
    else if(edges[1].cara=='A') edges[1].cara='D';
    if(edges[3].cara=='F') edges[3].cara='A';
    else if(edges[3].cara=='D') edges[3].cara='F';
    else if(edges[3].cara=='A') edges[3].cara='D';
    if(edges[4].cara=='F') edges[4].cara='A';
    else if(edges[4].cara=='D') edges[4].cara='F';
    else if(edges[4].cara=='A') edges[4].cara='D';

    if(center[2]==0)        center[2]=2;
    else if(center[2]==1)   center[2]=0;
    else                    center[2]=1;
  }
  void L(){
    arista aux;
    aux=edges[0];
    edges[0]=edges[5];
    edges[5]=edges[3];
    edges[3]=aux;

    if(edges[0].cara=='F') edges[0].cara='A';
    else if(edges[0].cara=='I') edges[0].cara='F';
    else if(edges[0].cara=='A') edges[0].cara='I';
    if(edges[3].cara=='F') edges[3].cara='A';
    else if(edges[3].cara=='I') edges[3].cara='F';
    else if(edges[3].cara=='A') edges[3].cara='I';
    if(edges[5].cara=='F') edges[5].cara='A';
    else if(edges[5].cara=='I') edges[5].cara='F';
    else if(edges[5].cara=='A') edges[5].cara='I';

    if(center[1]==0)        center[1]=1;
    else if(center[1]==1)   center[1]=2;
    else                    center[1]=0;
  }
  void Lp(){
    arista aux;
    aux=edges[0];
    edges[0]=edges[3];
    edges[3]=edges[5];
    edges[5]=aux;

    if(edges[0].cara=='F') edges[0].cara='I';
    else if(edges[0].cara=='I') edges[0].cara='A';
    else if(edges[0].cara=='A') edges[0].cara='F';
    if(edges[3].cara=='F') edges[3].cara='I';
    else if(edges[3].cara=='I') edges[3].cara='A';
    else if(edges[3].cara=='A') edges[3].cara='F';
    if(edges[5].cara=='F') edges[5].cara='I';
    else if(edges[5].cara=='I') edges[5].cara='A';
    else if(edges[5].cara=='A') edges[5].cara='F';

    if(center[1]==0)        center[1]=2;
    else if(center[1]==1)   center[1]=0;
    else                    center[1]=1;
  }
  void B(){
    arista aux;
    aux=edges[2];
    edges[2]=edges[4];
    edges[4]=edges[5];
    edges[5]=aux;

    if(edges[2].cara=='D') edges[2].cara='I';
    else if(edges[2].cara=='I') edges[2].cara='A';
    else if(edges[2].cara=='A') edges[2].cara='D';
    if(edges[4].cara=='D') edges[4].cara='I';
    else if(edges[4].cara=='I') edges[4].cara='A';
    else if(edges[4].cara=='A') edges[4].cara='D';
    if(edges[5].cara=='D') edges[5].cara='I';
    else if(edges[5].cara=='I') edges[5].cara='A';
    else if(edges[5].cara=='A') edges[5].cara='D';

    if(center[3]==0)        center[3]=1;
    else if(center[3]==1)   center[3]=2;
    else                    center[3]=0;
  }
  void Bp(){
    arista aux;
    aux=edges[2];
    edges[2]=edges[5];
    edges[5]=edges[4];
    edges[4]=aux;

    if(edges[2].cara=='D') edges[2].cara='A';
    else if(edges[2].cara=='I') edges[2].cara='D';
    else if(edges[2].cara=='A') edges[2].cara='I';
    if(edges[4].cara=='D') edges[4].cara='A';
    else if(edges[4].cara=='I') edges[4].cara='D';
    else if(edges[4].cara=='A') edges[4].cara='I';
    if(edges[5].cara=='D') edges[5].cara='A';
    else if(edges[5].cara=='I') edges[5].cara='D';
    else if(edges[5].cara=='A') edges[5].cara='I';

    if(center[3]==0)        center[3]=2;
    else if(center[3]==1)   center[3]=0;
    else                    center[3]=1;
  }
  void mostrarPyra(){
    cout << "CENTROS = [";
    for(int i=0; i<3;i++){
      cout << center[i] << " , ";
    }
    cout << center[3] << "]"<< endl;
    cout << "ARISTAS [" << endl;
    for(int i=0; i<6;i++){
      cout << edges[i].num << " | " << edges[i].cara << endl;
    }
    cout << "]" << endl;
  }
  bool resuelto(){
    bool res=true;
    for(int i=0; i<4 and res==true;i++){
      if(center[i]!=0){
        res=false;
      }
    }
    if(res){
      for(int i=0; i<6 and res==true;i++){
        if(edges[i].num !=i){
          res=false;
        }
      }
    }
    if(res){
      if(edges[0].cara!='F')  res=false;
      if(edges[1].cara!='F')  res=false;
      if(edges[2].cara!='D')  res=false;
      if(edges[3].cara!='A')  res=false;
      if(edges[4].cara!='A')  res=false;
      if(edges[5].cara!='A')  res=false;
    }
    return res;
  }
};

void mostrar(vector<string> s){
  for(int i=0; i<s.size(); i++){
    cout << s[i];
  }
  cout << endl;
}
void resuelve(vector<string> mov, Pyra p, int tam){
  if(tam==0){
    if(p.resuelto()){
      mostrar(mov);
    //  p.mostrarPyra();
    }
  }
  else{
    Pyra aux=p;
    string ant;
    if(mov.size()>0){
      ant=mov[mov.size()-1];
    }
    else{
      ant="AA";
    }
    vector <string> MovAux=mov;
    if(ant!="U " and ant!= "U' "){
      aux.U();
      MovAux.push_back("U ");
      resuelve(MovAux,aux,tam-1);
    }
    if(ant!="U " and ant!= "U' "){
      aux=p;
      MovAux=mov;
      aux.Up();
      MovAux.push_back("U' ");
      resuelve(MovAux,aux,tam-1);
    }
    if(ant!="R " and ant!= "R' "){
      aux=p;
      MovAux=mov;
      aux.R();
      MovAux.push_back("R ");
      resuelve(MovAux,aux,tam-1);
    }
    if(ant!="R " and ant!= "R' "){
      aux=p;
      MovAux=mov;
      aux.Rp();
      MovAux.push_back("R' ");
      resuelve(MovAux,aux,tam-1);
    }
    if(ant!="L " and ant!= "L' "){
      aux=p;
      MovAux=mov;
      aux.L();
      MovAux.push_back("L ");
      resuelve(MovAux,aux,tam-1);
    }
    if(ant!="L " and ant!= "L' "){
      aux=p;
      MovAux=mov;
      aux.Lp();
      MovAux.push_back("L' ");
      resuelve(MovAux,aux,tam-1);
    }
    if(ant!="B " and ant!= "B' "){
      aux=p;
      MovAux=mov;
      aux.B();
      MovAux.push_back("B ");
      resuelve(MovAux,aux,tam-1);
    }
    if(ant!="B " and ant!= "B' "){
      aux=p;
      MovAux=mov;
      aux.Bp();
      MovAux.push_back("B' ");
      resuelve(MovAux,aux,tam-1);
    }
  }
}

int main(){
  vector <string> movs;
  Pyra p1;

//Scramble
  p1.R();
  p1.Up();
  p1.Rp();
  p1.Up();
  p1.R();
  p1.Up();
  p1.Rp();

  for(int i=1; i<15; i++){
    cout << "Con " << i << " movimientos" << endl;
    cout << "_________________" << endl;
    resuelve(movs,p1,i);
  }
}
