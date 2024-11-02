#include <stdio.h>

#define MAX 15  // Максимальный размер матрицы
//записываем матрицу по столбикам через энтер. ввод чисел после равно будет выполнен после ввода полной матрицы
double determinant(double matrix[MAX][MAX], int n) { // Функция для вычисления определителя матрицы
    double det = 0;
    if (n == 1) {
        return matrix[0][0];} 
    else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];} 
    else {
        double submatrix[MAX][MAX];
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x) continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix, n - 1);
        }
    }
    return det;
}

int main() {
    int n;
    double matrix[MAX][MAX];
    double pos[MAX]; //числа после равно записываем
    double new[MAX]; //переменаая для запоминания что было в матрице при замене ее столбца на цифры после запятой
    printf("Введите размер матрицы (n): ");
    scanf("%d", &n);

    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    printf("Введите элементы после равно:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &pos[i]);
    }
    double delta = determinant(matrix, n); //нашли определитель
    if (delta == 0){
        printf("Нет единственного решения. \n"); // проверка на множество решений
    }
    else{
        printf("%lf \n", delta);
        for (int b=0; b<n; b++){
            for (int m=0; m<n; m++ ){
                new[m]=matrix[b][m];
                matrix[b][m]=pos[m];
                
            }
            // for (int y=0; y<n; y++){
            //         for (int z =0; z<n; z++){
            //             printf("%lf \n", matrix[y][z]);
            //    }
            //    }
            //printf("%lf", determinant(matrix,n)); // для отладки программы проверял определители каждого из корней
            double l = determinant(matrix, n)/delta;
            printf("корень: %lf \n", l);
            for (int t=0; t<n; t++){
                matrix[b][t]=new[t];
            }
        }
    }
}