
#include <stdio.h>
#include <stdlib.h>

double** make_matrix(int m, int n) {
    double** matrix = calloc(m, sizeof(double*));

    int i;
    for (i = 0; i< m; i += 1) {
        matrix[i] = calloc(n, sizeof(double));
    }

    return matrix;
}

void free_matrix(double** matrix, int m, int n) {
    int i;
    for(i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}


int main(int argc, char** argv) {
    printf("Hello, World!\n");

    int m;
    int n;

    scanf("%d", &m);
    scanf("%d", &n);
    printf("m = %d, n = %d\n", m, n);
    printf("\n");

    double** a = make_matrix(m, n);
	double*	 b = calloc(n, sizeof(double));
	double*	 c = calloc(n, sizeof(double));

    int i;
    int j;

    /*
        NOTE: Read integer program
    */
    for(i = 0; i < n; i++) {
        scanf("%lf", &c[i]);
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    for(i = 0; i < m; i++) {
        scanf("%lf", &b[i]);
    }

    /*
        NOTE: Print integer program nicely
    */
    printf("max z = %10.3lf * x0", c[0]);
    for(i = 1; i < n; i++) {
        printf(" + %10.3lf * x%d", c[i], i);
    }
    printf("\n");

    printf("\n");
    for (i = 0; i < m; i++) {
        printf("        %10.3lf * x0", a[i][0]);
        for (j = 1; j < n; j++) {
            printf(" + %10.3lf * x%d", a[i][j], j);
        }
        printf(" \u2264 %10.3lf\n", b[i]);
    }
    printf("\n");

    free_matrix(a, m, n);
    free(b);
    free(c);

    return 0;
}

