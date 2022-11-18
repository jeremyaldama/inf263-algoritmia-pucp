#include <bits/stdc++.h>
using namespace std;
#define CANT_ENTEROS 4

vector<string> cadenas_validas;
string cadena_actual;
int num=0;

void GenerarIPs(string cadena_ip, int n, int pos_actual, int cantidad_num_enteros
                , int num_actual){
    if (cantidad_num_enteros>CANT_ENTEROS || pos_actual>n){
        return;
    }
    if (cantidad_num_enteros==CANT_ENTEROS && pos_actual==n && cadena_actual[cadena_actual.size()-1]!='.'){
        cadenas_validas.push_back(cadena_actual);
        return;
    }

    for (int i=0; i<2; i++){
        int ant_can_num_ent = cantidad_num_enteros;
        //cout<<"pos: "<<pos_actual<<endl;
        num_actual = num_actual*10 + int(cadena_ip[pos_actual]-'0');

        if (i==0){
            cadena_actual.push_back(cadena_ip[pos_actual]);
            cadena_actual.push_back('.');
            cantidad_num_enteros++;
        }
        else{
            cadena_actual.push_back(cadena_ip[pos_actual]);
        }
        
        if (num_actual>=0 && num_actual<=255){
            if (i==0)
                GenerarIPs(cadena_ip, n, pos_actual+1, cantidad_num_enteros, 0);
            else
                GenerarIPs(cadena_ip, n, pos_actual+1, cantidad_num_enteros, num_actual);
        }
        
        if (i==0){
            cadena_actual.pop_back();
            cadena_actual.pop_back();
            cantidad_num_enteros = ant_can_num_ent;
            num_actual /= 10;
        }
        else{
            cadena_actual.pop_back();
        }
    }
    return;
}

int main(){
    string cadena_ip;
    cout<<"Ingrese cadena de digitos: "<<endl;
    cin>>cadena_ip;
    int n = cadena_ip.size();

    GenerarIPs(cadena_ip, n, 0, 1, 0);
    
    for (int i=0; i<cadenas_validas.size(); i++){
        cout<<cadenas_validas[i]<<endl;
    }
}