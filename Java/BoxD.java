class Box{
    double length;
    double breadth;
    double height;

Box(double l,double b,double h){
   length=l;
   breadth=b;
   height=h;
}

//compute and return volume
double volume(){
    return length*breadth*height;
}
}
class BoxD{
    public static void main(String args[]){
        Box a=new Box(3.9,9.8,7.6);
        Box b=new Box(4.8,10.8,8.9);

        System.out.println(a.volume());
        System.out.println(b.volume());
    }
}