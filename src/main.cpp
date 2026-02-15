#include <iostream>
#include <vector>
#include <algorithm>

// Print helper
void print(const std::vector<int>& a) {
    std::cout << "[";
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i];
        if (i + 1 < a.size()) std::cout << ", ";
    }
    std::cout << "]\n";
}

// Geeft de digit op positie exp (1 = eenheden, 10 = tientallen, 100 = honderdtallen, ...)
int digit(int value, int exp) {
    return (value / exp) % 10;
}

// Vindt het maximum (zo weten we hoeveel passses we nodig hebben)
int max_value(const std::vector<int>& a) {
    int m = 0;
    for (int x : a) {
        if (x > m) m = x;
    }
    return m;
}

// Bucket sort voor non negative integers. Als tijd over is, uitbreiden naar neg getallen
void bucket_sort_non_negative(std::vector<int>& numbers) {

    int size = numbers.size();
    if (size <= 1) return;

    std::vector<std::vector<int>> bucket_table(10, std::vector<int>(size));
    std::vector<int> bucket_sizes(10, 0);

    int largest_number = max_value(numbers);

    for (int place_value = 1; largest_number / place_value > 0; place_value *= 10) {

        for (int bucket_index = 0; bucket_index < 10; ++bucket_index) {
            bucket_sizes[bucket_index] = 0;
        }

        // distribution
        for (int number : numbers) {

            int bucket_index = digit(number, place_value);

            bucket_table[bucket_index][bucket_sizes[bucket_index]] = number;
            bucket_sizes[bucket_index]++;
        }

        // Gathering
        int write_position = 0;

        for (int bucket_index = 0; bucket_index < 10; ++bucket_index) {
            for (int element_index = 0; element_index < bucket_sizes[bucket_index]; ++element_index) {

                numbers[write_position] =
                    bucket_table[bucket_index][element_index];

                write_position++;
            }
        }
    }
}

int main() {
    std::vector<int> a = {97, 3, 100, 42, 7, 0, 155};

    std::cout << "Before: ";
    print(a);

    bucket_sort_non_negative(a);

    std::cout << "After : ";
    print(a);

    std::cout << "Sorted? "
              << (std::is_sorted(a.begin(), a.end()) ? "yes" : "no")
              << "\n";

    return 0;
}
