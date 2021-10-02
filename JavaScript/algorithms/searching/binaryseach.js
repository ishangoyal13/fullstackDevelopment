function binarySearch(nums,x){
  // left side of the array
    let left = 0
  
  // right side of the array
  let right = nums.length - 1 
  
  while(left <= right){
  
       // finding the mid point of array
      let mid = Math.floor(left + (right - left) / 2);
      
      // if mid is equal to number the return index
      if(nums[mid] == x){
         return mid
         
        // if number is smaller than mid element
      }else if(nums[mid] > x){ 
      
          // decrease the right side to mid -1
        right = mid - 1 
        
        // if number is greater than mid element
      } else if(nums[mid] < x){
       
       // increse the left side to mid + 1
        left = mid + 1 
      }
    }
    
  // if the given number is not present in array then return -1
    return -1
}

const arr = [1, 2, 3, 4, 5, 6, 7, 8, 9];
// sending element 12 to find in the array list
let result = binarySearch(arr,4);
console.log(result)
// 2, as 12 is present at the index 2

// sending element 42 to find in the array list
let result1 = binarySearch(arr, 42)
console.log(result1)
// -1, as there is no element inside the array list
