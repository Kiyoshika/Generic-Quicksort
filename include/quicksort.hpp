#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <vector>
#include <functional>
#include <iostream>

namespace quicksort
{
    template <typename T>
    bool default_comparator_asc(T a, T b)
    {
        return a < b;
    }

    template <typename T>
    bool default_comparator_desc(T a, T b)
    {
        return a > b;
    }

    template <>
    bool default_comparator_asc<std::string>(std::string a, std::string b)
    {
        return a.compare(b) < 0;
    }

    template <>
    bool default_comparator_desc<std::string>(std::string a, std::string b)
    {
        return a.compare(b) > 0;
    }

    template <typename T>
    static void swap(std::vector<T>& vec, 
                    size_t a, 
                    size_t b)
    {
        T temp = vec[a];
        vec[a] = vec[b];
        vec[b] = temp;
    }

    /*
    {1,2,4,5,3|6}
    gvp: 6
    */
    template <typename T>
    static int partition(std::vector<T>& vec, 
                        int lower_bound, 
                        int upper_bound,
                        bool (*comparator)(T, T))
    {
        T pivot_value = vec[upper_bound];
        size_t greater_value_ptr = lower_bound;
        for (size_t i = lower_bound; i < upper_bound; ++i)
        {

            //if (vec[i] <= pivot_value)
            if (comparator(vec[i], pivot_value))
            {
                swap(vec, i, greater_value_ptr);
                greater_value_ptr++;
            }
        }
        swap(vec, greater_value_ptr, upper_bound);
        return greater_value_ptr;
    }

    template <typename T>
    static void perform_sort(std::vector<T>& vec,
                            int lower_bound, 
                            int upper_bound,
                            bool (*comparator)(T, T))
    {
        if (lower_bound >= upper_bound) return;
        int pivot_index = partition<T>(vec, lower_bound, upper_bound, comparator);
        perform_sort<T>(vec, lower_bound, pivot_index - 1, comparator);
        perform_sort<T>(vec, pivot_index + 1, upper_bound, comparator);
    }

    template <typename T>
    void sort(std::vector<T>& vec, bool ascending = true)
    {
        bool (*comparator)(T, T) = nullptr;
    
        if (ascending)
            comparator = &default_comparator_asc;
        else
            comparator = &default_comparator_desc;

        perform_sort<T>(vec, 0, vec.size() - 1, comparator);
    }
};

#endif