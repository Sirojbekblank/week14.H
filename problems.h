//
// Created by Sirojbek on 11/27/2024.
//

#include <vector>
using namespace std;
void delete11 ( vector < int > & v ) {
    int *ptr = &v[0];
    for(int i = 0; i < v.size(); i++ ) {
        if(*(ptr+i)%11==0) {
            *v.erase(v.begin()+i);
        }
    }
}
void insertMany ( vector < int > &v , int a , int b ) {
    int x=v.size();
    if(v.size()%2==0) {
        x/=2;
        for(int i = x; i < x+a; i++ ) {
            v.emplace(v.begin()+i,b);
        }
    }
    else {
        x=x/2+1;
        for(int i = x; i < x+a; i++ ) {
            v.emplace(v.begin()+i,b);
        }
    }
}

int* allocateAndSet(int a, int b){
    int *arr = new int[b-a+1];
    if(a<=b) {
        for(int i = 0; i < b-a; i++ ) {
            arr[i] = a+i;
        }
    }
    else if(a>b) {
        return NULL;
    }
    return arr;
}
void deallocate(int* arr) {
    delete[] arr;
    arr = nullptr;
}
int*reallocate(int *arr, int N, int n) {
    int size =N-n;
    int *newArr=new int[size];
    for(int i = 0; i < size; i++) {
        *(newArr+i)=*(arr+i+n);
    }

    return newArr;
}



int **transposed(int **arr, int n, int m) {
    int **newArr = new int*[m];
    for(int i = 0; i < m; i++) {
        *(newArr+i) = new int[n];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            *(*(newArr+j)+i) = *(*(arr+i)+j);
        }
    }

    return newArr;
}
void deallocateMatrix(int**& matrix, int rows) {
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

