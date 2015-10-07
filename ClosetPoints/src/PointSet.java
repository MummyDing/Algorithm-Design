import java.util.Arrays;
import java.util.Comparator;
/*
 * 存放点集
 */
public class PointSet {
	private int size = 0;
	private int maxSize ;
	private Point [] points;
	public int getSize() {
		return size;
	}
	public PointSet(int Size) {
		maxSize = Size ;
		points = new Point[maxSize];
	}
	/*
	 * 添加点  当添加完成后自动按横坐标排序
	 */
	public void addPoint(Point point){
		if(size < maxSize) 
		points[size++] = point;
		if(size == maxSize){
			Arrays.sort(points,new Comparator<Point>(){
				public int compare(Point p1, Point p2) {
					 if(p1.getX() > p2.getX()) return 1;
					 else if(p1.getX() < p2.getX())return -1;
					 else return 0; 
				}
			});
		}
	}
	/*
	 * 获取点集中的点
	 */
	public Point getPoint(int num){
		if(num < size) return points[num];
		return null;
	}
	/*
	 * 获取左边点集
	 */
	public PointSet getLeftSet(){
		int tmpSetSize = (size+1)/2 ;
		PointSet tmpPointSet = new PointSet(tmpSetSize);
		for(int i=0 ; i< tmpSetSize;i++)
			tmpPointSet.addPoint(getPoint(i));
		return tmpPointSet;
	}
	/*
	 * 获取右边点集
	 */
	public PointSet getRightSet(){
		int tmpSetSize = size/2 ;
		PointSet tmpPointSet = new PointSet(tmpSetSize);
		for(int i= (size+1)/2 +1  ; i< size;i++)
			tmpPointSet.addPoint(getPoint(i));
		return tmpPointSet;
	}
}
