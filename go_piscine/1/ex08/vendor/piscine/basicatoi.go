package piscine

func StrLen(s string) int {
	var len int = 0;

	for range s {
		len++
	}
	return len
}

func BasicAtoi(s string) int {
	i := 0
	res := 0;
	s_array := []rune(s)
	s_len := StrLen(s)

	for i < s_len && s_array[i] == 0 {
		i++;
	}

	for i < s_len {
		res += int(s_array[i] - '0')
		res *= 10
		i++
	}
	res /= 10
	return (res)
}
