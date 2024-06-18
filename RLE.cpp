#include "RLE.h"

// Run-length encode function
int* run_length_encode(const int* data, size_t size, size_t& encoded_size_each_row) {
     std::vector<int> encoded_data; // Temporary storage for encoded data
     
     if (size == 0) {
        encoded_size_each_row = 0;
        return nullptr;
    }

    int count = 1; // Initialize counter to 1
    int n = 0; //n: the number of elements in int * result

    // Iterate over data starting from the second character
    for (size_t i = 1; i < encoded_size_each_row; ++i) {
        if (data[i] == data[i - 1]) { // If current element is the same as the previous one
            count++; // Increment the counter
        } else {
            // If current element is different from the previous one, add the previous element's count and element itself to the encoded result
            encoded_data.push_back(data[i - 1]);
            encoded_data.push_back(count);
            count = 1; // Reset counter to 1 for the new element
            n = n + 2;
        }
    }

    // Handle the last element
    encoded_data.push_back(data[size - 1]);
    encoded_data.push_back(count);
    n = n + 2;
    
    // Allocate memory for the encoded data to return
    encoded_size_each_row = encoded_data.size() + 1; // +1: n need to be stored in result
    int* result = new int[encoded_size_each_row];
    result[0] = n;
    std::copy(encoded_data.begin(), encoded_data.end(), result + 1);

    return result; // Return the encoded result array
}

// Function to decode the encoded data at a specific row and column index
// store by column, so row_index->column attributes, col_index->row records
std::pair<int, int> run_length_decode(const int* stored_encoded_data, size_t encoded_size, size_t col_index) {
    // Check if the encoded data is empty
    if (encoded_size == 0) {
        return std::make_pair(0, 0); // Return 0 if the encoded data is empty
    }

    // // Check if the column index is within bounds
    // size_t total_size = 0;
    // for (size_t i = 2; i < encoded_size; i += 2) {
    //     total_size += stored_encoded_data[i];
    // }
    // if (col_index >= total_size) {
    //     return std::make_pair(0, 0); // Return 0 if column index is out of bounds
    // }

    // Allocate memory for the decoded data
    size_t current_index = 0;

    // Traverse the encoded data to find the value at the specified column index
    for (size_t i = 1; i < encoded_size; i += 2) {
        int value = stored_encoded_data[i];
        int count = stored_encoded_data[i + 1];

        // Check if the column index falls within the range of this value
        if (col_index < current_index + count) {
            return std::make_pair(value, count); // Return the decoded value and count
        }

        current_index += count; // Move to the next value
    }

    return std::make_pair(0,0); // Return 0 if column index is out of bounds
}
// int run_length_decode(const std::vector<std::vector<int>>& stored_encoded_data, size_t row_index, size_t col_index) {
//     // Check if the row index is within bounds
//     if (row_index >= stored_encoded_data.size()) {
//         return 0; // Return nullptr if row index is out of bounds
//     }

//     // Get the encoded data for the specified row
//     const std::vector<int>& encoded_data = stored_encoded_data[row_index];

//     // Check if the column index is within bounds
//     if (col_index >= encoded_data.size()) {
//         return 0; // Return nullptr if column index is out of bounds
//     }

//     // Allocate memory for the decoded data
//     int decoded_data = 0; // Initialize decoded_data with dummy value
//     size_t current_index = 0;

//     // Traverse the encoded data to find the value at the specified column index
//     for (size_t i = 0; i < encoded_data.size(); i += 2) {
//         int value = encoded_data[i];
//         int count = encoded_data[i + 1];

//         // Check if the column index falls within the range of this value
//         if (col_index < current_index + count) {
//             decoded_data = value; // Set the decoded value
//             break; // Exit the loop
//         }

//         current_index += count; // Move to the next value
//     }

//     return decoded_data; // Return the decoded data
// }