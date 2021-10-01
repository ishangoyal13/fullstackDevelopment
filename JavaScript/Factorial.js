function factorial_recursive(n){
    if(n <= 1) return 1;
    return n* factorial_recursive(n-1);
}
function factorial_iterative(n){
    let fact = 1;
    for(let i = 1;i <= n;i++) fact *= i;
    return fact;}
console.log(factorial_iterative(10) , factorial_recursive(10));
