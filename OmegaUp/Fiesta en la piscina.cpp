#include <stdio.h>
const int kMaxN = 2002;
int n, preguntas = 0, conocido[kMaxN][kMaxN], personA, personB, dp[2005];
bool aKnowsB, bKnowsA;

int Preguntar(int a, int b) {
    ++preguntas;
    printf("Se ha llamado a Preguntar(%d, %d).\n", a, b);
    if (a != b && 1 <= a && a <= n && 1 <= b && b <= n) {
        if (conocido[a][b] == 1)
            printf("La persona %d conoce a la persona %d.\n\n", a, b);
        else
            printf("La persona %d NO conoce a la persona %d.\n\n", a, b);
        return conocido[a][b];
    }
    if (a < 1 || n < a) puts("Error: El valor de a no esta entre 1 y n.\n");
    if (b < 1 || n < b) puts("Error: El valor de b no esta entre 1 y n.\n");
    if (a == b) puts("Error: Preguntaste por una misma persona.\n");
    return -1;
}

//My Code Starts Here
int isCool(int person, int N) {
	for(int i=1; i<=N; i++)
		if(i!= person && Preguntar(person, i))
			return 0;
	return person;
}

int BusquedaCool(int N) {
	if (N == 1) return 1;
	personA = 1, personB = 1;
	for(int i=0; i<N; i++) {
		if(personA == personB) personB++;
		if(dp[personA]) personA = personB+1;
		if(dp[personB]) personB = personA+1;
		if(personA>N && personB>N) return 0;
		if(personA>N) return isCool(personB, N);
		if(personB>N) return isCool(personA, N);
		aKnowsB = Preguntar(personA, personB);
		bKnowsA = Preguntar(personB, personA);
		if(aKnowsB == bKnowsA)
			personA++, personB++;
		else if(aKnowsB && !bKnowsA)
			dp[personA++] = 1;
		else if(bKnowsA && !aKnowsB)
			dp[personB++] = 1;
	}
	return 0;
}

//My Code Ends Here

int main() {
    scanf("%d", &n);
    int popular; scanf("%d", &popular);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &conocido[i][j]);
    if (popular == 0)
        puts("No hay un chico popular aqui.\n");
    else
        printf("El chico popular es la persona %d.\n\n", popular);
    int tu_respuesta = BusquedaCool(n);
    printf("Tu funcion retorno %d", tu_respuesta);
    printf(" y realizo %d preguntas.\n", preguntas);
    if (tu_respuesta == popular)
        puts("Has resuelto correctamente el problema!");
    else
        puts("No has logrado resolver el problema...");
    return 0;
}
