#ifndef CONVERT_BYTES_HPP_
#define CONVERT_BYTES_HPP_
#include <cstdint>
#include <cstddef>

struct convert16bitValue
{
	convert16bitValue() : unsigned_value(0) {}
	/**
	 * @brief 変換したいリトルエンディアンのデータを格納する.
	 * @param first8bit リトルエンディアンで、最初に格納される8bit
	 * @param last8bit	リトルエンディアンで、最後に格納される8bit
	 */
	void fromLittleEndian(uint8_t first8bit, uint8_t last8bit)
	{
		byte[0] = first8bit;
		byte[1] = last8bit;
	}

	/**
	 * @brief 変換したいビッグエンディアンのデータを格納する.
	 * @param first8bit ビッグエンディアンで、最初に格納される8bit
	 * @param last8bit	ビッグエンディアンで、最後に格納される8bit
	 */
	void fromBigEndian(uint8_t first8bit, uint8_t last8bit)
	{
		byte[0] = last8bit;
		byte[1] = first8bit;
	}
	union
	{
		uint8_t byte[2];
		uint_fast16_t unsigned_value;
		int_fast16_t signed_value;
	};
};

struct convert32bitValue
{
	convert32bitValue() : unsigned_value(0) {}
	template <class arrayItr>
	void fromLittleEndian(arrayItr first8bitItr, arrayItr last8bitItr)
	{
		size_t i = 0;
		for (auto itr = first8bitItr; (itr <= last8bitItr) && (i < 4); itr++, i++)
		{
			byte[i] = *itr;
		}
	}

	template <class arrayItr>
	void fromBigEndian(arrayItr first8bitItr, arrayItr last8bitItr)
	{
		size_t i = 0;
		for (auto itr = last8bitItr; (itr >= first8bitItr) && (i < 4); itr--, i++)
		{
			byte[i] = *itr;
		}
	}
	union
	{
		uint8_t byte[4];
		uint_fast32_t unsigned_value;
		int_fast32_t signed_value;
		float float_value;
	};
};
#endif // !CONVERT_BYTES_HPP_