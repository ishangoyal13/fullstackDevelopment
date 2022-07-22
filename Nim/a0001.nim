import std/[strutils, sequtils]

var
  myList: seq[int] = map(stdin.readLine().split(' '), proc(
      x: string): int = x.parseInt())
  k: int = stdin.readLine().parseInt()
  c: int = 0
  flag: bool = false

for i in myList:
  c = k - i
  if myList.contains(c) and c != i:
    flag = true
    break

echo flag
