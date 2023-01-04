#include <iostream>
using namespace std;

int CalcularMaximoSumaTareas(int tareas[], int n_tareas, int horas_turno){
    int dp[n_tareas+1][horas_turno+1];

    int i, j;

    for (j=0; j<horas_turno+1; j++){
        dp[0][j] = 0;
    }
    for (i=0; i<n_tareas+1; i++){
        dp[i][0] = 0;
    }

    int horas_actual;
    for (i=1; i<n_tareas+1; i++){
        for (horas_actual=1; horas_actual<horas_turno+1; horas_actual++){
            if (horas_actual>=tareas[i-1]){
                int resto_horas = horas_actual-tareas[i-1];
                dp[i][horas_actual] = tareas[i-1] + dp[i-1][resto_horas];
            }
            else{
                dp[i][horas_actual] = dp[i-1][horas_actual];
            }
        }
    }

    return dp[n_tareas][horas_turno];
}

int main(){
    int cantidad_tareas;
    printf("Ingrese la cantidad de tareas: ");
    scanf("%d", &cantidad_tareas);

    int tareas_tiempo[cantidad_tareas];
    printf("Ingrese el tiempo que demora cada tarea: ");
    for (int i=0; i<cantidad_tareas; i++){
        scanf("%d", &tareas_tiempo[i]);
    }
    cout<<""<<endl;
    int maximo_1turno = CalcularMaximoSumaTareas(tareas_tiempo, 
                                                cantidad_tareas, 8);
    int maximo_2turnos = CalcularMaximoSumaTareas(tareas_tiempo, 
                                                cantidad_tareas, 16);
    int maximo_3turnos = CalcularMaximoSumaTareas(tareas_tiempo, 
                                                cantidad_tareas, 24);
    if (8-maximo_1turno>0){
        cout<<"Si se usa el turno maniana se desperdicia "<<8-maximo_1turno
            <<" del turno maniana y las tareas suman como maximo "<<maximo_1turno
            <<endl;
    }
    else{
        cout<<"No se desperdicia ninguna hora de los turnos, ya que las tareas" 
            "como maximo suman "<<maximo_1turno<<endl;
    }
    cout<<""<<endl;
    if (16-maximo_2turnos>0){
        cout<<"Si se usa el turno maniana y tarde se desperdicia "<<16-maximo_2turnos
            <<" del turno maniana y las tareas suman como maximo "<<maximo_2turnos
            <<endl;
    }
    else{
        cout<<"No se desperdicia ninguna hora de los turnos, ya que las tareas" 
            " como maximo suman "<<maximo_2turnos<<endl;
    }
    cout<<""<<endl;
    if (24-maximo_3turnos>0){
        cout<<"Si se usa el turno maniana, tarde y noche se desperdicia "<<24-maximo_3turnos
            <<" del turno maniana y las tareas suman como maximo "<<maximo_3turnos
            <<endl;
    }
    else{
        cout<<"No se desperdicia ninguna hora de los turnos, ya que las tareas" 
            "como maximo suman "<<maximo_3turnos<<endl;
    }
    cout<<""<<endl;
    return 0;
}