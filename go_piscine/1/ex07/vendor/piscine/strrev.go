package piscine

func StrLen(s string) int {
	var len int = 0;

	for range s {
		len++
	}
	return len
}

func SwapRune(a *rune, b *rune) {
	var tmp rune

	tmp = *a
	*a = *b
	*b = tmp
}

func StrRev(s string) string {
	res := []rune(s)
	s_len := StrLen(s)

	for i := 0; i < s_len / 2; i++{
		SwapRune(&res[i], &res[s_len - i - 1])
	}

	return (string(res))
}
