

x = int(input())

if -128 <= x and  x <128:
	print("byte\n")
elif -32768 <= x and  x <32768:
	print("short\n")
elif -2147483648 <= x and  x <2147483648:
	print("int\n")
elif -9223372036854775808 <= x and  x <9223372036854775808:
	print("long\n")
else: print("BigInteger\n")