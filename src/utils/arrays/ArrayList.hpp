#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <algorithm>

#define SIZE_START 10

namespace algorithms::utils
{
    template <typename T>
    class Array_list
    {
    private:
        int valueAtual;
        int capacidade;
        T *vet;
        inline void create_new_vector()
        {
            capacidade *= 2;
            T* aux = new T[capacidade];

            std::copy(vet, vet + valueAtual, aux);

            delete[] vet;
            vet = aux;
        }

    public:
        explicit Array_list() : valueAtual(0), capacidade(SIZE_START)
        {
            vet = new T[SIZE_START];
        };
        inline ~Array_list()
        {
            delete[] vet;
        }

        inline T add(T value)
        {
            if (valueAtual >= capacidade)
            {
                create_new_vector();
            }
            vet[valueAtual] = value;
            valueAtual++;
            return value;
        }
    };
};


#endif