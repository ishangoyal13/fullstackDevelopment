/*
self made deep comparrison program
may be incorrect for unknown cases
*/

// deepEqual checks for equality of objects by going inside them and indiviually checking each element
function deepEqual ( object1, object2 )
{
	for ( let element of Object.keys ( object1 ) )
	{
		let temp = 0;
		if ( typeof object1[ element ] === 'object' )
			temp++;
		if ( typeof object2[ element ] === 'object' )
			temp++;

		switch ( temp )
		{
			// both elements of respective objects are objects themselves
			case 2: 
			if ( deepEqual ( object1[ element ], object2[ element ] ) === false )
			{
				return false;
			}
			break;

			// neither elements of respective objects are objects themselves
			// we can simply check
			case 0:
			if ( !( object1[ element ] === object2[ element ] ) )
			{
				return false;
			}
			break;

			// if they have different types then definately different parent objects
			case 1:
			return false;
			break;
		}
	}
	return true;
}

let obj = {here: {is: "an"}, object: 2};
console.log(deepEqual(obj, obj));
// → true
console.log(deepEqual(obj, {here: 1, object: 2}));
// → false
console.log(deepEqual(obj, {here: {is: "an"}, object: 2}));
// → true