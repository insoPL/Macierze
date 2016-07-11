#include<iostream>

using namespace std;

class macierz
{
private:
  int** tab;
  int x,y;

public:
  macierz(int xx,int yy):x(xx),y(yy)
  {
    tab= new int*[y];
    for(int foo=0;foo<y;foo++)  tab[foo]=new int[x];
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

  int get(int x, int y) const {  return tab[y][x]; }
  int getX() const { return x; }
  int getY() const { return y; }

  int wyznacznik() const
  {
    int w=0;
    if(getX()==2  &&  getY()==2)
    {
      w=get(0,0)*get(1,1);
      w-=get(0,1)*get(1,0);
      return w;
    }
    if(getX()==3 &&  getY()==3)//  Metoda Sarrusa
    {
      w=get(0,0)*get(1,1)*get(2,2);
      w+=get(1,0)*get(2,1)*get(0,2);
      w+=get(0,1)*get(1,2)*get(2,0);

      w-=get(0,2)*get(1,1)*get(2,0);
      w-=get(0,1)*get(1,0)*get(2,2);
      w-=get(2,1)*get(1,2)*get(0,0);

      return w;
    }
  }

  friend ostream& operator<<(std::ostream& stream, const macierz& maci);
};

ostream& operator<<(std::ostream& stream, const macierz& maci)
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
  macierz xyz(2,2);

  cout<<xyz.wyznacznik();

  char c;
  cin>>c;
  return 0;
}
