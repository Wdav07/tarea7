#include <iostream>
using namespace std;

// ambito global
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;	
};
void leer();
void crear();
main(){
	crear();
	system("pause");

}
void leer (){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if(!archivo){
		archivo=fopen(nombre_archivo,"w,b");
	}
	Estudiante estudiante ;
	int id=0;
	fread(&estudiante,sizeof(estudiante),1,archivo);
	do{
		cout<<id<<","<<estudiante.codigo<<","<<estudiante.nombres<<","<<estudiante.apellidos<<","<<estudiante.telefono<<endl;
		fread(&estudiante,sizeof(estudiante),1,archivo);
		id+=1;
	}while(feof(archivo)==0);
	fclose(archivo);
}
void crear (){
	FILE* archivo = fopen(nombre_archivo,"a+b");
	char res;
	Estudiante estudiante;
	do{
		fflush(stdin);
		cout<<"Ingrese codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese nombres: ";
		cin.getline(estudiante.nombres,50);
		
		cout<<"Ingrese apellidos: ";
		cin.getline(estudiante.apellidos,50);
		
		cout<<"Ingrese telefono: ";
		cin>>estudiante.telefono;
		
		//en un archivo solo se pueden hacer 2 cosas (leer y escribir)(escribir = modificar, crear, eliminar)
		// & para llamar a la clase
		//en sizeof le tenemos que colocar la escritura =  Estudiante en nuestro caso
		//bandera (0,1,2,3,4) / 1 = escritura o lectura
		//el nombre que aparece despues de file
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		
		cout<<"Desea ingresar otro estudiante (s/n): ";
		cin>>res;
	}while(res=='s' || res=='S');
	//despues del while para que cierre despues de que ingresamos todos los datos
	fclose(archivo);
	leer();
}