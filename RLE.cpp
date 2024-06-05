#include "RLE.h"

// Run-length encode function
std::vector<int> run_length_encode(const int* data, size_t size, size_t& encoded_size_each_row) {
    std::vector<int> encoded_data; // Temporary storage for encoded data

    if (size == 0 && encoded_size_each_row == 0) {
        return encoded_data;
    }

    int count = 1; // Initialize counter to 1

    // Iterate over data starting from the second character
    for (size_t i = 1; i < encoded_size_each_row; ++i) {
        if (data[i] == data[i - 1]) { // If current element is the same as the previous one
            count++; // Increment the counter
        } else {
            // If current element is different from the previous one, add the previous element's count and element itself to the encoded result
            encoded_data.push_back(data[i - 1]);
            encoded_data.push_back(count);
            count = 1; // Reset counter to 1 for the new element
        }
    }

    // Handle the last element
    encoded_data.push_back(data[size - 1]);
    encoded_data.push_back(count);
    return encoded_data;

    // // Allocate memory for the encoded data to return type int*
    // encoded_size_each_row = encoded_data.size();
    // int* result = new int[encoded_size_each_row];
    // for (size_t i = 0; i < encoded_size_each_row; ++i) {
    //     result[i] = encoded_data[i];
    // }

    // return result; // Return the encoded result array
}

// Function to decode the encoded data at a specific row and column index
// store by column, so row_index->column attributes, col_index->row records
int* run_length_decode(const std::vector<std::vector<int>>& stored_encoded_data, size_t row_index, size_t col_index) {
    // Check if the row index is within bounds
    if (row_index >= stored_encoded_data.size()) {
        return nullptr; // Return nullptr if row index is out of bounds
    }

    // Get the encoded data for the specified row
    const std::vector<int>& encoded_data = stored_encoded_data[row_index];

    // Check if the column index is within bounds
    if (col_index >= encoded_data.size()) {
        return nullptr; // Return nullptr if column index is out of bounds
    }

    // Allocate memory for the decoded data
    int* decoded_data = new int[1]; // Initialize decoded_data with dummy value
    size_t current_index = 0;

    // Traverse the encoded data to find the value at the specified column index
    for (size_t i = 0; i < encoded_data.size(); i += 2) {
        int value = encoded_data[i];
        int count = encoded_data[i + 1];

        // Check if the column index falls within the range of this value
        if (col_index < current_index + count) {
            decoded_data[0] = value; // Set the decoded value
            break; // Exit the loop
        }

        current_index += count; // Move to the next value
    }

    return decoded_data; // Return the decoded data
}
