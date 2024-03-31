def convert_to_binary(number):
	binary_str = bin(number)[2:]
	binary_32_bit = binary_str.zfill(32)
	return binary_32_bit

# Example usage
number = 12
result = convert_to_binary(number)
print(f"32-Bit Binary Format : {result}")

