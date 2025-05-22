#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 10



struct Student{
    char name[100];
    int math;
    int phy;
    int inf;
    int total;
};
 //выбором
void Selectsort(struct Student students[N]){
    for (int i=0; i<N;i++){
        int mi=i;
        struct Student temp;
        for (int j=i+1; j<N; j++){
            if (students[mi].total<students[j].total){
                mi=j;
            }
        }
    temp=students[i];
    students[i]=students[mi];
    students[mi]=temp;

    }

}

//Каунтсорт
void Csort(struct Student students[N]) {
    int M = students[0].total;
    for (int i = 1; i < N; i++) {
        if (students[i].total > M) {
            M = students[i].total;
        }
    }

    int* countArr = (int*)calloc(M + 1, sizeof(int));

    for (int i = 0; i < N; i++) {
        countArr[students[i].total]++;
    }

    for (int i = 1; i <= M; i++) {
        countArr[i] += countArr[i - 1];
    }

    struct Student* outputArr = (struct Student*)malloc(N * sizeof(struct Student));

    for (int i = 0; i < N; i++) {
        outputArr[N - countArr[students[i].total]] = students[i];
        countArr[students[i].total]--;
    }

    for (int i = 0; i < N; i++) {
        students[i] = outputArr[i];
    }

    free(countArr);
    free(outputArr);
}


void QuickSort(struct Student students[], int left, int right){
    if (left<right){
        int p = students[left+rand()%(right-left+1)].total;
        int i = left;
        int j =right;

        while(i<=j){
            while (students[i].total<p) i++;
            while (students[j].total>p) j--;
            if (i<=j){
                struct Student t=students[i];
                students[i]=students[j];
                students[j]=t;
                i++;
                j--;
            }
        }
        QuickSort(students,left,j);
        QuickSort(students,i,right);
    }

}


struct Student addStudent(char name[], int math, int phy, int inf){
    struct Student stud;
    strcpy(stud.name, name);
    stud.math=math;
    stud.phy=phy;
    stud.inf=inf;
    stud.total=math+phy+inf;
    return stud;

};


void printStudent(struct Student Student){
    puts(Student.name);
    printf("\n");
    printf("мат %d физ %d инф %d итоговый балл %d \n", Student.math, Student.phy, Student.inf, Student.total); 
}



int main(){
srand(time(NULL));
time_t strt=clock();

struct Student *students = (struct Student*)malloc(N*sizeof(struct Student));
for (int i=0; i<N; i++){
    char name[100];
    char n[10]="Student";
    sprintf(name, "Student%d", i);
    int math = rand()%101;
    int phy = rand()%101;
    int inf=rand()%101;
    students[i]=addStudent(name, math, phy, inf);
}
// for (int i=0; i<N; i++)
// printStudent(students[i]);

// printf("\n");
// printf("\n");
// printf("\n");
QuickSort(students, 0, N-1);
for (int i=0; i<N;i++){
printStudent(students[i]);}
printf("\n");
printf("\n");
time_t end = clock();
double time_spent = difftime(end, strt);
printf("Время выполнения: %f секунд\n", time_spent/1000000); //микросек

free (students);

//lscpu модель и частоту процессора
}