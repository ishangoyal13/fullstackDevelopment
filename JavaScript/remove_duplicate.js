
// remove duplicate values from array 
const names = ['Sam', 'Joe', 'Paul', 'Ringo', 'Sam'];
let unique = [...new Set(names)];
console.log(unique);

//Another Way

        var array = ["Aalim", "Monis", "Inayat","Faizan", "Umer", "Jeelani", "Aaqib", "Monis"];
                       
        var outputArray = [];
          
        // Count variable is used to add the
        // new unique value only once in the
        // outputArray.

        var count = 0;
          
        // Start variable is used to set true
        // if a repeated duplicate value is 
        // encontered in the output array.

        var start = false;
          
        for (j = 0; j < array.length; j++) {
            for (k = 0; k < outputArray.length; k++) {
                if ( array[j] == outputArray[k] ) start = true
            }
          
            count++;
          
            if (count == 1 && start == false) outputArray.push(array[j])
          
            start = false;
          
            count = 0;
        }
        console.log(outputArray);
