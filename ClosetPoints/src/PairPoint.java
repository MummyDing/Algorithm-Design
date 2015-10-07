/*
 * 存储点对
 */
public class PairPoint {
	private Point point1;
	private Point point2;
	public PairPoint(Point point1, Point point2) {
		super();
		this.point1 = point1;
		this.point2 = point2;
	}
	/*
	 * 获取点对距离
	 */
	public double getDistance(){
		double disX = Math.abs(point1.getX()-point2.getX());
		double disY = Math.abs(point1.getY()-point2.getY());
		double dis = Math.sqrt(disX*disX+disY*disY);
		return dis;
	}
	public int getP1Num(){
		return point1.getNum();
	}
	public int getP2Num(){
		return point2.getNum();
	}
}
