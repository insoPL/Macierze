#include<iostream>
#include <math.h>

using namespace std;

template<typename T>
class macierz
{
private:
  T** tab;
  int x,y;

public:
  macierz(int xx,int yy):x(xx),y(yy)
  {
    tab= new T*[y];
    for(int foo=0;foo<y;foo++)  tab[foo]=new T[x];//creating 2D array

    for(int foo=0;foo<y;foo++)
    {
      cout<<"linia: "<<foo+1<<endl;
      for(int bar=0;bar<x;bar++)
      {
        cin>>tab[foo][bar];
      }
      cout<<endl;
    }
  }

  macierz(int xx,int yy,T* inputArray):x(xx),y(yy){
    tab= new T*[y];
    for(int foo=0;foo<y;foo++)  tab[foo]=new T[x];//creating 2D array

    int it=0;
    for(int foo=0;foo<y;foo++)
    {
      for(int bar=0;bar<x;bar++)
      {
        tab[foo][bar]=inputArray[it++];
      }
  }
}

macierz(int xx,int yy,T initValue):x(xx),y(yy){
  tab= new T*[y];
  for(int foo=0;foo<y;foo++)  tab[foo]=new T[x];//creating 2D array

  for(int foo=0;foo<y;foo++)
  {
    for(int bar=0;bar<x;bar++)
    {
      tab[foo][bar]=initValue;
    }
}
}

  T get(int x, int y) const {  return tab[y][x]; }
  int getX() const { return x; }
  int getY() const { return y; }

  isSquare() const
  {
    if(getX()==getY()) return getX();
    else return 0;
  }

template<typename Te> friend ostream& operator<<(ostream& , const macierz<Te>& );

  macierz<T> wykreslenie(int i,int j) const
  {
    T* initArray=new T[(this->getX()-1)*(this->getY()-1)];
    int it=0;

      for(int foo=0;foo<this->getY();foo++)
      {
        for(int bar=0;bar<this->getX();bar++)
        {
          if(foo!=j &&  bar!=i) initArray[it++]=this->tab[foo][bar];
        }
      }

    macierz<T> w(this->getX()-1,this->getY()-1,initArray);

      return w;
  }

  T wyznacznik() const
  {
    if(!isSquare())cerr << "/* Proba liczenia wyznacznika macierzy nie kwadratowej */" << std::endl;

    T w=0;
    if(this->getX()==2)
    {
      w=this->get(0,0)*this->get(1,1);
      w-=this->get(0,1)*this->get(1,0);
      return w;
    }
    else if(this->getX()==3)//  Metoda Sarrusa
    {
      w=this->get(0,0)*this->get(1,1)*this->get(2,2);
      w+=this->get(1,0)*this->get(2,1)*this->get(0,2);
      w+=this->get(0,1)*this->get(1,2)*this->get(2,0);

      w-=this->get(0,2)*this->get(1,1)*this->get(2,0);
      w-=this->get(0,1)*this->get(1,0)*this->get(2,2);
      w-=this->get(2,1)*this->get(1,2)*this->get(0,0);

      return w;
    }
    else
    {// Rozwinięcie Laplaca
      for(int rzad=0;rzad<this->getX();rzad++)
      {
        w+=this->get(rzad,0)*pow(-1,rzad)*(this->wykreslenie(rzad,0)).wyznacznik();
      }
    return w;
    }
  }
};

template<typename T>
ostream& operator<<(std::ostream& stream, const macierz<T>& maci)
{
  cout<<endl;
  for(int foo=0;foo<maci.getY();foo++)
  {
    cout<<"|";
    for(int bar=0;bar<maci.getX();bar++)
    {
      cout<<maci.get(bar,foo);
      if(bar+1<maci.getX())cout<<" ";
    }
    cout<<"|"<<endl;
  }
  cout<<endl;
}

int main()
{
  //macierzkw<long> xyz(3);
  int tab[]={1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4};
  const macierz<int> abc(4,4);


  cout<<abc.wyznacznik();

  char c;
  cin>>c;
  return 0;
}
