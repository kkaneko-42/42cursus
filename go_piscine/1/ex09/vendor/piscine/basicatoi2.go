package piscine

func StrLen(s string) int {
	var len int = 0

	for range s {
		len++
	}
	return len
}

func IsDigit(r rune) bool {
	if '0' <= r && r <= '9' {
		return true
	} else {
		return false
	}
}

func IsSpace(r rune) bool {
	if r == '\t' || r == '\n' || r == '\v' || r == '\r' || r == ' ' {
		return true
	} else {
		return false
	}
}

func BasicAtoi2(s string) int {
	i := 0
	res := 0
	s_array := []rune(s)
	s_len := StrLen(s)

	for i < s_len && s_array[i] == 0 {
		i++
	}

	for i < s_len {
		if !IsDigit(s_array[i]) {
			return 0
		}
		res += int(s_array[i] - '0')
		res *= 10
		i++
	}
	res /= 10
	return (res)
}
