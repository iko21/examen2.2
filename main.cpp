#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include <fstream>

using namespace std;


class Animales{
    public:
    string raza;
    string nombre;
    int edad;
    string comida;

    Animales(string raza, string nombre, int edad, string comida)
    {
        this->raza=raza;
        this->nombre=nombre;
        this->edad=edad;
        this->comida=comida;
    }

};

class Zoolo{
    public:

     list<Animales*> lalista;

    void agregarAnimal(string raza, string nombre, int edad, string comida)
    {

        lalista.push_back(new Animales(raza, nombre, edad, comida));
    }

    void imprimir()
    {
        for(list<Animales*>::iterator i=lalista.begin(); i!=lalista.end();i++)
        {
            cout<<(*i)->raza<<endl;
            cout<<(*i)->nombre<<endl;
            cout<<(*i)->edad<<endl;
            cout<<(*i)->comida<<endl;
        }
    }

    void escri(string archivo)
    {
        ofstream at(archivo.c_str(), ios::binary);
        for(list<Animales*>::iterator i=lalista.begin(); i!=lalista.end(); i++)
         {
             const char* raza = (*i)->raza.c_str();
             const char* nombre =(*i)->nombre.c_str();
             int* edad = new int ((*i)->edad);
             const char* comida = (*i)->comida.c_str();

             at.write(raza,20);
             at.write(nombre, 20);
             at.write((char*)edad,4);
             at.write(comida, 20);
         }

    }

    void abrir(string archivo)
    {
        ifstream it(archivo.c_str(),ios::binary);
        lalista.clear();

        it.seekg(0,ios::end);
        int tam=it.tellg();
        it.seekg(0);

        while(it.tellg()<tam)
        {
            cout << it.tellg() << endl;
            char *raza_leido=new char[20];
            char *nombre_leido=new char[20];
            int *edad_leida=new int(0);
            char *comida_leido=new char[20];
            it.read(raza_leido,20);
            it.read(nombre_leido,20);
            it.read((char*)edad_leida,4);
            it.read(comida_leido,20);
            cout << it.tellg() << endl;
            string rz = raza_leido;
            string nmb = nombre_leido;
            int ed = *edad_leida;
            string comi = comida_leido;

            lalista.push_back(new Animales(rz,nmb,ed,comi));
        }
    }

    void special()
    {
        for(list<Animales*>::iterator i=lalista.begin(); i!=lalista.end();i++)
        {
            string temp1, temp2, temp4;
            int temp3;

            temp1=(*i)->raza;
            temp2=(*i)->nombre;
            temp3=(*i)->edad;
            temp4=(*i)->comida;

            if(temp3<1 || temp3>19)
            {
                cout<<temp1<<endl;
                cout<<temp2<<endl;
                cout<<temp3<<endl;
                cout<<temp4<<endl;
            }

        }
    }
};

int main()
{
    int opc=7;
    string raza, nombre, comida, archivo;
    int edad;
     Zoolo z;


  do{
    cout<<" ZOO "<<endl;
    cout<<"1. AGREGAR ANIMAL"<<endl;
    cout<<"2. IMPRIMIR"<<endl;
    cout<<"3. GUARDAR"<<endl;
    cout<<"4. ABRIR"<<endl;
    cout<<"5. CUIDADO ESPECIAL"<<endl;
    cout<<"Elija una opcion"<<endl;
    cin>>opc;

    switch(opc)
    {
        case 1:
            cout<<"Ingrese raza"<<endl;
            cin>>raza;
            cout<<"Ingrese nombre"<<endl;
            cin>>nombre;
            cout<<"Ingrese edad"<<endl;
            cin>>edad;
            cout<<"Ingrese comida"<<endl;
            cin>>comida;

            z.agregarAnimal(raza, nombre, edad, comida);
            break;

          case 2:
               z.imprimir();
            break;
          case 3:
                cout<<"Escriba el nombre del archivo"<<endl;
                cin>>archivo;
               z.escri(archivo);
             break;
          case 4:
              cout<<"Escriba el nombre del archivo"<<endl;
              cin>>archivo;
              z.abrir(archivo);
              break;
          case 5:
                z.special();
              break;
    }
  }while(opc!=0);

    return 0;
}
