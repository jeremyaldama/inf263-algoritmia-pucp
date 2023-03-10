#ifndef AMPLITUD_H
#define AMPLITUD_H


/*Busqueda en Amplitud
 * Estructudas de datos a usar:
 *   Estados -> contiene la cola de nodos del grafo que van siendo procesados
 *   Visitados -> contiene toda la lista de nodos que se han visitado a lo largo del algoritmo
 *   P -> nodo del grafo que está siendo procesado en cada iteración
 *   Hijos_P -> lista de nodos adyacentes a P
 *   Estado_Inicial y Estado_Meta -> nodos y/o valores particulares
 * Pseudocódigo:
 *   Inicio B_Amplitud (Grafo, Estados, Estado_Inicial, Estado_Meta, Estado Meta)
 *     Estados = NULL
 *     Visitados = NULL
 *     Encolar(Estado Inicial, Estados)
 *     Mientras (Cola_Vacia(Estados)==Falso y P!=Estado_Meta) hacer
 *     Inicio
 *       P = Atender(Estados)
 *       Procesar P
 *       Insertar(P, Visitados)
 *       Hijos_P = Adyacente(Grafo, P)
 *       Para cada u que pertenece a Hijos_P tal que u no pertenece a Visitados Hacer
 *         Encolar (u, Estados)
 *     Fin Mientras
 *   Fin B_Amplitud
 */

void BusquedaEnAmplitud(TNodoVertice *ptrListaVertices, TNodoGrafo Estado_Inicial, TNodoGrafo Estado_Meta);

#endif /* AMPLITUD_H */

