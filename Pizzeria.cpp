/* venta de vehiculos
datos a almacenar:
Placa, Marca, anho, precio
funciones
grabar a un archivo
leer archivo y sumatoria 
*/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct pizza{
	string tipo;
	float precio, des;
};
void mp(); //definicion de la funcion 
void inventario();
void leer_archivo();
int main(){	
	mp();	
	//return 0;
}
void mp(){ // menu principal
	
	int resp;
	//string nombrearchivo;
	//cout<<"Indique nombre de archivo: ";
	//getline(cin,nombrearchivo);
	
	do{
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingrese Pedido"<<"\n";
		cout<<" 2 - Reporte de pedidos "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			inventario();			
		}
		else if (resp==2){		
			system("CLS");
			leer_archivo();
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}
void inventario(){
	string tipo_p;
	float precio_p;
	float des_p, desc;
	ofstream archivo; //grabar archivo
	fflush(stdin);
	cout<<"Ingrese Tipo de Pizza: "<<endl;
	getline(cin,tipo_p);
	fflush(stdin);
	cout<<"Ingrese Precio Unitario: "<<endl;
	cin>>precio_p;
		fflush(stdin);
	if(tipo_p == "GRANDE" or "grande"){
		desc=precio_p*0.10;
		des_p= precio_p-desc;
		cout<< "Precio Total"<<des_p<<endl;
		
	}	
	if(tipo_p == "FAMILIAR" or "famliar"){
		desc=precio_p*0.15;
		des_p= precio_p-desc;
		cout<< "Precio Total"<<des_p<<endl;
		

	}
	if(tipo_p == "FIESTA" or "fiesta"){
		desc=precio_p*0.20;
		des_p= precio_p-desc;
		cout<< "Precio Total"<<des_p<<endl;
		
	}
		
	archivo.open("Pizzeria.txt",ios::app); //abrir archivo append
	archivo<<tipo_p<<"\t"<<precio_p<< "\t"<<des_p<<endl;
	archivo.close();
		
}
void leer_archivo(){
	ifstream archivo; //leer archivo 
	archivo.open("Pizzeria.txt",ios::in); // leer archivo
	int lineas,i=0;
	string s,linea;	
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	pizza recordset[lineas];
	
	archivo.open("Pizzeria.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
	/*Leer datos del archivo*/
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }
        archivo>>recordset[i].tipo>>recordset[i].precio>>recordset[i].des;
        
      
    }
    archivo.close(); 
    for(int i = 0; i <lineas; i++){
    	cout<<recordset[i].tipo<<"\t"<<recordset[i].precio<<"\t"<<recordset[i].des<<endl;
    	 while(archivo>>recordset[i].des!=0){
       	recordset[i].des+recordset[i].des;
       	
	   }
	   
    	//sumatoriadescuento+=recordset[i].des;
	}
	cout<< "EL total de ventas es: "<<recordset[i].des + recordset[i].des<<endl;
	system("Pause");
	

}
