// SISTEMA DE UNA BODEGA

#include <iostream>
#include <conio.h>
#include <string.h>

struct Producto
  {
    char idProducto[15];
    char nProducto[100];
	char codigoBarra[50];
	char tipoProducto[100];
	double precioVenta;
	double precioCompra;	
	int stock;
  };

using namespace std;
int main(int argc, char** argv) 
{
	Producto Prod[15],Temp;
	int i,j,N,op1,cont=0,k=0,pos,band,posi;
	char op2,tecla,dato,idProdbus[15],CBarrabus[50];
	
	  do{
	  	  system("cls");
	  	  cout<<"*** REGISTRO DE PRODUCTOS DE UNA BODEGA****\n";
		  cout<<"*** MENU DE OPCIONES ****\n";
		  cout<<"1)--> INGRESO DE PRODUCTOS           				   \n";
		  cout<<"2)--> MOSTRAR PRODUCTOS			  				   \n";
		  cout<<"3)--> MOSTRAR PRODUCTOS SIN STOCK					   \n";
		  cout<<"4)--> BUSQUEDA POR CODIGO DE BARRA DEL PRODUCTO       \n";
		  cout<<"5)--> ORDENAR POR NOMBRE PRODUCTO					   \n";
		  cout<<"6)--> ELIMINAR POR CODIGO PRODUCTO      			   \n";
		  
	  	  cout<<"\n...Elija una opcion por favor: ";
	  	  cin>>op1;
	    	switch(op1)
	    	{
	    		case 1: cout<<"Cuantos Productos?: ";
	    				cin>>k;
	    				N=cont+k;
	    				for(i=cont;i<N;i++)
	    				 {
	    				 	cout<<"\nCASILLA "<<i<<"\n";
							cout<<"Codigo: ";
							fflush(stdin);
							cin.getline(Prod[i].idProducto,15,'\n');
							cout<<"Nombre Producto: ";
							cin.getline(Prod[i].nProducto,100,'\n');
							fflush(stdin);
							cout<<"Codigo de Barras: ";
							cin.getline(Prod[i].codigoBarra,50,'\n');
							cout<<"Tipo de Producto: ";
							cin.getline(Prod[i].tipoProducto,100,'\n');
							cout<<"Precio Venta: ";
							cin>>Prod[i].precioVenta;
							cout<<"Precio Compra: ";
							cin>>Prod[i].precioCompra;
							cout<<"Stock: ";
							cin>>Prod[i].stock;
	    				 	cont++;
						 }
	    			    break;
	    			    
	    		case 2: system ("cls");
						
						cout<<"------ LOS PRODUCTOS INGRESADOS SON:------\n";
	    				for(i=0;i<N;i++)
	    				  {
						    
    						cout<<"\n****CASILLA "<<i<<"\n";
							cout<<"\nCodigo: "<<Prod[i].idProducto;
							cout<<"\nNombre Producto: "<<Prod[i].nProducto;
							cout<<"\nCodigo de Barras: "<<Prod[i].codigoBarra;
							cout<<"\nTipo de Producto: "<<Prod[i].tipoProducto;
							cout<<"\nPrecio Venta: "<<Prod[i].precioVenta;
							cout<<"\nPrecio Compra: "<<Prod[i].precioCompra;
							cout<<"\nStock: "<<Prod[i].stock<<endl;
												
						  }
						break;
				case 3: 
				   system("cls");
				   cout<<"\nREGISTRO DE PRODUCTOS SIN STOCK: \n";	
					
					for(i=0;i<N;i++)
					 if(Prod[i].stock==0)
					  {
					  		cout<<"\nCodigo: "<<Prod[i].idProducto;
							cout<<"\nNombre Producto: "<<Prod[i].nProducto;
							cout<<"\nCodigo de Barras: "<<Prod[i].codigoBarra;
							cout<<"\nTipo de Producto: "<<Prod[i].tipoProducto;
							cout<<"\nPrecio Venta: "<<Prod[i].precioVenta;
							cout<<"\nPrecio Compra: "<<Prod[i].precioCompra;
							cout<<"\nStock: "<<Prod[i].stock<<endl;
					  }				
					break;		 
				case 4: 
				   system("cls");
				   cout<<"\nBUSQUEDA POR CODIGO DE BARRA DEL PRODUCTO: \n";
				   ////indicar de codigo a buscar
				    cout<<"Ingrese Codigo de Barra del Producto a buscar: ";
				    cin>>CBarrabus;
				   ///comparar cada casilla con el codigo ingresado
				    band=0;
					for(i=0;i<N;i++)
					 if(strcmp(CBarrabus,Prod[i].codigoBarra)==0)                
				       {
				       	posi=i;
				       	band=1;
				       	cout<<"\nPRODUCTO HALLADO, EN EL CASILLERO: "<<posi<<endl;
				      		cout<<"\nCodigo: "<<Prod[i].idProducto;
							cout<<"\nNombre Producto: "<<Prod[i].nProducto;
							cout<<"\nCodigo de Barras: "<<Prod[i].codigoBarra;
							cout<<"\nTipo de Producto: "<<Prod[i].tipoProducto;
							cout<<"\nPrecio Venta: "<<Prod[i].precioVenta;
							cout<<"\nPrecio Compra: "<<Prod[i].precioCompra;
							cout<<"\nStock: "<<Prod[i].stock<<endl;
						break;	     
					   }
				
				    if(band==0)
				       cout<<"\nEl Codigo de Producto ingresado no existe en la Base de Datos\n";
				break;	
				case 5:	system ("cls");
						//ORDENAMIENTO POR EL METODO BURBUJA
					   for(i=0;i<N-1;i++)
					   for(j=i+1;j<N;j++)
					   if(strcmp(Prod[i].nProducto,Prod[j].nProducto)>0)
					   {
					   	 Temp=Prod[i];
						 Prod[i]=Prod[j];
						 Prod[j]=Temp;	
					   }
					   
					   cout<<"\nLISTA DE PRODUCTOS ORDENANDOS POR NOMBRE EN FORMA ASCENDENTE \n";
					   
					   	for(i=0;i<N;i++)
					   {
					   	cout<<"\nCodigo: "<<Prod[i].idProducto;
						cout<<"\nNombre Producto: "<<Prod[i].nProducto;
						cout<<"\nCodigo de Barras: "<<Prod[i].codigoBarra;
						cout<<"\nTipo de Producto: "<<Prod[i].tipoProducto;
						cout<<"\nPrecio Venta: "<<Prod[i].precioVenta;
						cout<<"\nPrecio Compra: "<<Prod[i].precioCompra;
						cout<<"\nStock: "<<Prod[i].stock<<endl;			     
				       }
					break;
				case 6:	
				system("cls");
					cout<<"\nELIMINAR UN PRODUCTO\n";
					cout<<"Ingrese Codigo del Producto a Eliminar: ";
					cin>>idProdbus;
					///////buscando elemento /////
					band=0;
					if(N==0){
						cout<<"Lista Vacia";
				    	break;
					}
					if(N>0) {
						for(i=0;i<N;i++){
							 if(strcmp(idProdbus,Prod[i].idProducto)==0)
						 	 {
						 	   posi=i;	
						 	   band=1;
						 	   break;
							 }
						}
					}   
						
					if(band==1) //cout<<"El producto Si existe y esta en la posicion: "<<posicion;
					 {
					   if(posi==(N-1))
					    {
					    	N=N-1;
					    	cont=cont-1;
						}
					   else
					    {
					    	for(i=posi;i<(N-1);i++) //ubicacion en la fila
					    	 {
							   Prod[i] = Prod[i+1];
					         }
							N=N-1;
					    	cont=cont-1; 
						}
						cout<<"------ REGISTRO ACTUALIZADO DE LOS PRODUCTOS:------\n";
						for(i=0;i<N;i++)
	    				  {					
    						cout<<"\nCodigo: "<<Prod[i].idProducto;
							cout<<"\nNombre Producto: "<<Prod[i].nProducto;
							cout<<"\nCodigo de Barras: "<<Prod[i].codigoBarra;
							cout<<"\nTipo de Producto: "<<Prod[i].tipoProducto;
							cout<<"\nPrecio Venta: "<<Prod[i].precioVenta;
							cout<<"\nPrecio Compra: "<<Prod[i].precioCompra;
							cout<<"\nStock: "<<Prod[i].stock<<endl;			     						
						  }
				     }
					else{
					cout<<"\nEl Codigo del Producto No existe en la Base de Datos...\n";	
					}
										
				break;	
	    		default: cout<<"\n...¡¡Esa opcion no existe...";	   
			}
		  cout<<"\nDesea continuar s/n?: ";
		  cin>>op2; 	
	    }while(op2=='s' || op2=='S');

	return 0;
}