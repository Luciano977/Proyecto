#include <iostream>
#include <ctime>
using namespace std;



int main (){
    srand(time(nullptr));
    int vDados6Caras[11]{};
    ///Aca declaro cuantos dados tienen al comenzar.
    int cantidadDadosInicioP1=6;
    int cantidadDadosInicioP2=6;
    ///Los dos dados de 12 Caras.
    int dado12Caras1 =rand() % 12 + 1;///cuenta matematica para sacar de 1 a 12.
    int dado12Caras2 =rand() % 12 + 1;
    int resultadoSuma12caras;
    int auxVecCodigoElegido;
    ///Muestro los dos dados de 12 Caras.
    cout<<"Dado objetivo 1 = "<<dado12Caras1<<endl;
    cout<<"Dado objetivo 2 = "<<dado12Caras2<<endl;
    ///Suma, de los 2 dados de 12 Caras.
    resultadoSuma12caras=dado12Caras1+dado12Caras2;
    cout<<"Resultado de dados objetivos= "<<resultadoSuma12caras<<endl;

    for (int i=0;i<cantidadDadosInicioP1;i++)
    {
        vDados6Caras[i]=rand()%6+1;
        cout<<"Muestro vDados en indice "<<i << " es " <<vDados6Caras[i] <<endl;
    }
    int cantidadDeDadosPorElegir=0;///ELEGIR LA SUMA CORRECTA QUE SUME EL TOTAL DE DADOS OBJETIVOS.
    cout<<"Cuantos dados deseas elegir?"<<endl;
    cin>>cantidadDeDadosPorElegir;//4
	///VERIFICACION DE CANTIDAD DE DADOS SEAN IGUAL A LA CANTIDAD DE DADOS STOCK.
	while(cantidadDeDadosPorElegir<1 || cantidadDeDadosPorElegir>cantidadDadosInicioP1)
	///VERIFICA QUE EL NUMERO SEA EL CORRECTO
	{
		if (cantidadDeDadosPorElegir<1 || cantidadDeDadosPorElegir>cantidadDadosInicioP1)
		///SI EL NUMERO ES INCORRECTO SIGUE  CON ESTE IF POR CULPA DEL WHILE.
		{
			cout<<"Cantidad incorrecta. Difiere al numero de dados stock. "<<endl;
			cout<<"ingresar una cantidad de dados correcta...."<<endl;
			cin>>cantidadDeDadosPorElegir;
		}
	}
	cout<<"Elige "<<cantidadDeDadosPorElegir<<" dados."<<endl;
	///Aca AGREGAMOS UN VERIFICADOR DE LA VARIABLE auxiliarVecCodigoElegido;
	///por si ingresan el numero 612.
    cout<<"   Elige los numeros de sus posiciones: "<<endl;
    int sumaDadosElegidos=0;
    for(int i=1;i<=cantidadDeDadosPorElegir;i++)
    {
        cin>>auxVecCodigoElegido;
	///	if (auxVecCodigoElegido<1 || auxVecCodigoElegido>cantidadDadosInicioP1)
		///{volver a iterar auxiliar codigo.asi busca una posicion de vetor codigo correcta.

        sumaDadosElegidos=sumaDadosElegidos+vDados6Caras[auxVecCodigoElegido-1];
    }
     cout<<"sumaDadosElegidos "<<sumaDadosElegidos<<endl;

	if(sumaDadosElegidos==resultadoSuma12caras)
	{
		cout<<"Felicidades!los numeros coinciden y se le otorgaran "<<cantidadDeDadosPorElegir<<" dados mas para tu contrincante y a ti se te restaran para la siguiente ronda "<<endl;
	}
    else
    {
        cout<<"esta mal tu calculo volve a ingresar la suma"<<endl;
    }
return 0;
}
