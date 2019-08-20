#include <iostream>
#include <ctime>
#include <sstream>
#include <cstdlib>
using namespace std;

class persona
{
	public:
		void saludar();
		void obtener_nombre();
		int edad(int anio_nacimiento);
	private:
		string nombre;
};

void persona::obtener_nombre()
{
	cout<<"Porfavor ingrese su nombre :";
	cin>>nombre;
	cout<<"\n";
};

void persona::saludar()
{
	cout<<"Hola!, mi nombre es "+nombre+" \n";
};

int persona::edad(int e)
{
	time_t t = time(NULL);
	tm* PunteroTiempo = localtime(&t);
	
	stringstream ss_year;
	ss_year << PunteroTiempo->tm_year+1900-e; // aquí se realiza la operación para determinar la edad la cual se almacena en ss_year
	
	string su_edad = ss_year.str();
	
	return (atoi(su_edad.c_str()));

};

int main()
{	

	int anio;	

	persona p;
	
	p.obtener_nombre();
	
	cout<<"Ingrese su año de nacimiento\n";
	cin>>anio;
	
	p.saludar();
	
	cout<<"Mi edad es :"<<p.edad(anio)<<"\n";
	
}

