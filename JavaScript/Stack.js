function Stack () {
  const data = [];
  
  return {
    add(item) {
      data.push(item)
    }
    peek() {
      return data[data.length - 1]
    }
    pop() {
      data.pop())
    }
  }
}

const bookStorage = Stack()

bookStorage.add('The $100 Startup')
bookStorage.add('Atomic Habit')

console.log(bookStorage.peek())
// Atomic Habit

bookStorage.pop()

console.log(bookStorage.peek())
// The $100 Startup

bookStorage.add('Design Principle')
console.log(bookStorage.peek())
//Design Principle
