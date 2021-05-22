/*1. Описать структуру с именем AEROFLOT, содержащую следующие ноля:
• название пункта назначения рейса;
• номер рейса;
• тип самолета.
 Написать программу, выполняющую следующие действия:
• ввод с клавиатуры данных в массив, состоящий из семи элементов типа
AEROFLOT; записи должны быть размещены в алфавитном порядке по
названиям пунктов назначения;
• вывод на экран пунктов назначения и номеров рейсов, обслуживаемых
самолетом, тип которого введен с клавиатуры;
• если таких рейсов нет, выдать на дисплей соответствующее сообщение.*/
#include <iostream>
#include <string>
#include <clocale>

using namespace std;

struct Aeroflot
{
	string pynkt;// пункт назначения
	int num_r;// номер рейса
	string type;// тип самолета
};

void vvod_dan(Aeroflot *a,const int & k)
{

	for(int i(0);i<k;++i)
	{
		cout<<"ВВедите пункт назначения:";
		cin>>a[i].pynkt;
		cout<<"ВВедите номер рейса:";
		cin>>a[i].num_r;
		cout<<"ВВедите тип самолета:";
		cin>>a[i].type;
	}
}

// сортировка по возрастанию номеров рейса
void sort_nomr(Aeroflot *a,const int &k)
{
	for(int i(k-1);i>=0;i--)
		for(int j(0);j<i;j++)
			if(a[j].num_r>a[j+1].num_r)
				swap(a[j].num_r,a[j+1].num_r);
}

void sravn(Aeroflot *a,const int &k,string &s)
{

	int n(0);
	for(int i(0);i<k;++i)
	{
		if(a[i].pynkt==s)cout<<a[i].num_r<<" "<<a[i].type<<endl;
		else n++;

	}
	if(n==k)cout<<"Таких рейсов нет\n";

}

int main()
{	setlocale(LC_CTYPE,"rus");

	Aeroflot *air;
	const int kol=7;
	// выделяем место в памяти под 7 структур
	air=new Aeroflot[kol];

	vvod_dan(air,kol);
	sort_nomr(air,kol);
	//строка с которой будем сравнивать
	string str;
	cout<<endl<<"Введите пункт назначения:";
	cin>>str;
	sravn(air,kol,str);
	delete []air;
	return 0;
}
/* Описать структуру с именем MARSH, содержащую следующие поля:
• название начального пункта маршрута;
• название конечного пункта маршрута;
• номер маршрута.
 Написать программу, выполняющую следующие действия:
• ввод с клавиатуры данных в массив, состоящий из восьми элементов
типа MARSH; записи должны быть упорядочены по номерам маршрутов;
• вывод на экран информации о маршруте, номер которого введен с
клавиатуры;
• если таких маршрутов нет, выдать на дисплей соответствующее
сообщение*/
//создать массив структур о маршрутах
#include <cstdlib> 
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int i,n,np;
    bool priz=true;
    struct {
    	     string np;
    	     string kp;
    	     int nom;
	}  marsh[8];
// заполнение массива и вывод на экран    
    for (int i=0; i<8; i++)
    {
      cout<<"маршрут "<<i+1<<":"<<endl;
      cout<<"название начального пункта маршрута: ";  cin>>marsh[i].np; 
      cout<<"название конечного пункта маршрута: ";  cin>>marsh[i].kp;
      cout<<"номер маршрута: ";  cin>>marsh[i].nom;
    }
//сортировка массива по полю nom	
    while (priz)
    {
       priz=false;	
       for (int i=1; i<8; i++)
       {
         if (marsh[i].nom<marsh[i-1].nom)
         {  swap(marsh[i].np,marsh[i-1].np);
            swap(marsh[i].kp,marsh[i-1].kp);
            swap(marsh[i].nom,marsh[i-1].nom);
            priz=true;	} 
       }
    }
//вывод информации по запросу
    cout<<endl<<"поиск маршрута"<<endl;
    while (true)
    {
      cout<<endl<<"номер маршрута: ";  cin>>n;   i=0;
      while ((marsh[i].nom!=n) and (i<8)) i++;
      if (i==8)  cout<<endl<<"маршрутов нет "<<n<<endl;
      else
      {   
        cout<<endl<<"начальный маршрут: "<<marsh[i].np<<"   ";
        cout<<"конечный маршрут: "<<marsh[i].kp<<"  номер маршрута: "<<marsh[i].nom<<endl;
      }
      cout<<endl<<"если продолжить нажмите 1, иначе 0: ";  cin>>np;
      if (np==0)  break;
    }
   
   cout<<endl; 
   system("pause"); 
   return(0);
}
