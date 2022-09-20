/*
basically how a list works in js
how to create
convert
find
*/

// converts given aray to a list
function arrayToList ( array )
{
	let list = null;

	for ( let i = 0, n = array.length; i < n; i++ )
	{
		list =
		{
			value : array[ n - i - 1 ],
			rest : list,
		};
	}

	return list;
}

// converts given list to array
function listToArray ( list )
{
	let array = [];
	function usingrecursion ( list )
	{
		if ( list.rest === null )
		{
			array.push ( list.value );
			return 1;
		}
		else
		{
			array.push ( list.value );
			return usingrecursion ( list.rest );
		}
	}

	usingrecursion ( list );

	return array;
}

// add a element to the start of the given list
function prepend ( element, list )
{
	list = 
	{
		value: element,
		rest: list,
	};

	return list;
}

// finds the nth element in the given list
function nth ( list, number )
{
	function usingRecursion ( list )
	{
		if ( number > 0 )
		{
			number--;
			if ( list.rest )
				return usingRecursion ( list.rest );
			else
				return undefined;
		}
		else
		{
			return list.value;
		}
	}

	return usingRecursion ( list );
}

console.log(arrayToList([10, 20]));
// → {value: 10, rest: {value: 20, rest: null}}
console.log(listToArray(arrayToList([10, 20, 30])));
// → [10, 20, 30]
console.log(prepend(10, prepend(20, null)));
// → {value: 10, rest: {value: 20, rest: null}}
console.log(nth(arrayToList([10, 20, 30]), 1));
// → 20