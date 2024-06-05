#include <iostream>
#include <vector>
#include <string>

std::vector<int> run_length_encode(const int* data, size_t size, size_t& encoded_size_each_row);
int* run_length_decode(const std::vector<std::vector<int>>& stored_encoded_data, size_t index);