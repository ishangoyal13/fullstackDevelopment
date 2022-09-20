
//Stack Data Strucuture implemented in Java
public class Stacks {
    
    private int maxSize;
    private long[] stackArray;
    private int top;
    //Class implement
    public Stacks(int s){
        maxSize=s;
        stackArray=new long[maxSize];
        top = -1;
    
    
    }
    //Push method
    public void push(long j){
        stackArray[++top] =j;
    
    }
    //pop method remove top element
    public long pop(){
        return stackArray[top--];
    }
    //return top element
    public long peek(){
        return stackArray[top];
    }
    //check if stack is empty
    public boolean isEmpty(){
        return (top == -1);
    }
    //check if stack is full
    public boolean isFull(){
        return (top ==maxSize-1);
    }
    
    
    
    
    }