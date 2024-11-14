#ifndef DYV_H
#define DYV_H
#include<iostream>
#include<vector>
#include<algorithm>


template <class T>
int BusquedaBinaria(T x,std::vector<T>& v, int ini, int fin){
    if(ini > fin){
        return -1;
    }
        int medio = (ini + fin) / 2;
        if(v[medio]== x){
            return medio;
        }else{
            if(v[medio] < x){
                return BusquedaBinaria(x, v, medio + 1, fin);
            }else{
                return BusquedaBinaria(x, v, ini, medio);
            }
        }
}
template <class T>
int BusquedaBinaria_INV(T x, std::vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        return -1;
    }
    int medio = (ini + fin) / 2;
    if (v[medio] == x) {
        return medio;
    } else {
        if (v[medio] > x) {
            return BusquedaBinaria_INV(x, v, medio + 1, fin);
        } else {
            return BusquedaBinaria_INV(x, v, ini, medio);
        }
    }
}
template <class T>
int Partition(std::vector<T>& v, int ini, int fin) {
    T pivote = v[fin];
    int i = ini;
    for (int j = ini; j < fin; j++) {
        if (v[j] <= pivote) {
            std::swap(v[i], v[j]);
            i++;
        }
    }
    std::swap(v[i], v[fin]);
    return i;
}

template <class T>
void QuickSort(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivote = Partition(v, ini, fin);
        QuickSort(v, ini, pivote - 1);
        QuickSort(v, pivote + 1, fin);
    }
}
template <class T>
int PartitionFirst(std::vector<T>& v, int ini, int fin) {
    std::swap(v[ini], v[fin]);
    return Partition(v, ini, fin);
}

template <class T>
void QuickSortFirst(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivote = PartitionFirst(v, ini, fin);
        QuickSortFirst(v, ini, pivote - 1);
        QuickSortFirst(v, pivote + 1, fin);
    }
}

template <class T>
int PartitionRandom(std::vector<T>& v, int ini, int fin) {
    int randomIndex = ini + rand() % (fin - ini + 1);
    std::swap(v[randomIndex], v[fin]);
    return Partition(v, ini, fin);
}

template <class T>
void QuickSortRandom(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivote = PartitionRandom(v, ini, fin);
        QuickSortRandom(v, ini, pivote - 1);
        QuickSortRandom(v, pivote + 1, fin);
    }
}


#endif