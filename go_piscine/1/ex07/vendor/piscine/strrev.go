package piscine

func StrLen(s string) int {
	var len int = 0

	for range s {
		len++
	}
	return len
}

func StrRev(s string) string {
	var res []rune
	s_len := StrLen(s)

	for i, c range s {
		res[i]
	}
}
