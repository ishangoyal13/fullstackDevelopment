public class Cuboid {
	int width;
	int height;
	int depth;
	
	
	//Use of multiple constructors
	Cuboid(int width, int height, int depth){
		this.width = width;
		this.height = height;
		this.depth = depth;
	}
	
	Cuboid(int width, int height){
		this.width = width;
		this.height = height;
		this.depth =  10;
	}
	
	
//	to make a Cuboid a cube
	Cuboid(int dimension){
		width =  dimension;
		height = dimension;
		depth = dimension;
	}
	
	
	Cuboid(){
		this.width =10;
		this.height = 10;
		this.depth = 10;
	}
	
	//this is a behavior
	int volume() {
		return height*width*depth;
	}
	
	public static void main(String[] args){
		int volume;
		
		Cuboid stdCuboid = new Cuboid(10, 20, 15);
		volume = stdCuboid.volume();
		System.out.println("Volume of a simple cuboid is: "+ volume);
		
		
		Cuboid cuboidWithDefaults = new Cuboid(10, 20);
		volume = cuboidWithDefaults.volume();
		System.out.println("Volume of cuboid with the default depth is: "+ volume);
		
		Cuboid cube = new Cuboid(10);
		volume = cube.volume();
		System.out.println("Volume of cube is: "+ volume);
		
		//Without any constructor provided, JAVA provides a constructor which is a default constructor and all values of properties will be set
		// to default values of all the data types.Integer type default value is 0. String is empty string.
		Cuboid defaultCuboid = new Cuboid();
		volume = defaultCuboid.volume();
		System.out.println("Volume of cuboid with the default depth is: "+ volume);
		//but now it will work
		//so if any constructor is provided JAVA doesn't implicitly provide the default constructor but when not provided JAVA will obviously provide a default constructor
		
	}
}