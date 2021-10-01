def myAtoi(str):
  ls = list(str.strip())
  if not ls:
      return 0
  sign = 1
  if ls[0] in ['-', '+']:
      if ls[0] == '-':
          sign = -1
      ls = ls[1:]

  res, i = 0, 0
  while i < len(ls) and ls[i].isdigit():
      res = res*10 + ord(ls[i]) - ord('0')
      i += 1
  return max(-2**31, min(sign * res, 2**31-1))
