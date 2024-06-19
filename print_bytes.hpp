#ifndef PRINT_BYTES_HPP_
#define PRINT_BYTES_HPP_

#include <fast_io.h>

/**
 * @brief Print packet
 * 
 * @tparam array_type 
 * @param arr packet to print
 * @param prefix prefix to print
 */
template <typename array_type>
void printPacket(const array_type &arr, const std::string &prefix = "")
{
    fast_io::io::print(prefix);
    for (const auto &data : arr)
    {
        fast_io::io::print(fast_io::manipulators::hex(data), " ");
    }
    fast_io::io::println("");
}

/**
 * @brief MACRO for printing packet
 */
#define HR_DEBUG_PRINT_PACKET(packet) printPacket(packet, __func__ + std::string("()::") + #packet + std::string(" -> "))

/**
 * @brief Print bits of data
 * 
 * @param data 
 */
inline void printBits(const uint_fast8_t &data)
{
    fast_io::io::println(fast_io::manipulators::base<8>(data));
}

#endif //PRINT_BYTES_HPP_
