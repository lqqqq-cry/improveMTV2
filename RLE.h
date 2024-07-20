#include <iostream>
#include <vector>
#include <string>

int* run_length_encode(const int* data, size_t size, size_t& encoded_size_each_row);

std::pair<int, int> run_length_decode(const int* stored_encoded_data, int encoded_size, int col_index) ;