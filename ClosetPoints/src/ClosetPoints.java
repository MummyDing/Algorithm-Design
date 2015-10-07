/*
 * Author: MummyDing
 * Date :  7/10/2015
 * GitHub: https://github.com/MummyDing
 */
import java.util.Scanner;

public class ClosetPoints {
	private static PairPoint onePoint =new PairPoint(new Point(0,0,0),new Point(10000,10000,0)); //无穷大
	public static PairPoint DivCloset(PointSet pointSet){
		double tmpDistance;
		PairPoint tmpPairPoint;
		int setSize = pointSet.getSize() ;
		/*
		 * 如果不多于一个点 则无法构成点对 返回距离无穷大点对
		 */
		if(setSize <= 1) return onePoint;
		/*
		 * 两个点 则只可能构成一个点对 直接返回
		 */
		if(setSize == 2) return new PairPoint(pointSet.getPoint(0),pointSet.getPoint(1));
		/*
		 * 以横坐标作为参考，获取中间点横坐标
		 */
		double midX = pointSet.getPoint((setSize+1)/2).getX();
		/*
		 * 获取左边最近点对
		 */
		PairPoint pairPointLeft = DivCloset(pointSet.getLeftSet());
		double disLeft = pairPointLeft.getDistance();
		/*
		 * 获取右边最近点对
		 */
		PairPoint pairPointRight = DivCloset(pointSet.getRightSet());
		double disRight = pairPointRight.getDistance();
		/*
		 * 比较两边对点 取最短点对
		 */
		if(disLeft < disRight) {
			tmpDistance = disLeft;
			tmpPairPoint = pairPointLeft; 
		}else{
			tmpDistance = disRight;
			tmpPairPoint = pairPointRight;
		}
		/*
		 * 遍历 距离横坐标距离 中点 小于 当前最短点对的距离(tmpDistance) 的点
		 * 获取该区域点对距离 取最小值
		 */
		for(int i = setSize/2 ; i >=0 ; i--)
			if(pointSet.getPoint(i).getX() > midX - tmpDistance)
				for(int j = setSize/2 +1 ; j <= setSize-1 ; j++)
					if(pointSet.getPoint(j).getX() < midX + tmpDistance){
						if(pointSet.getPoint(i).getY() - tmpDistance < pointSet.getPoint(j).getY()
								&&pointSet.getPoint(j).getY() < pointSet.getPoint(i).getY() + tmpDistance){
							PairPoint tmpPair = new PairPoint(pointSet.getPoint(i),pointSet.getPoint(j));
							double tmpDis =tmpPair.getDistance();
							if(tmpDis < tmpDistance){
								tmpDistance = tmpDis;
								tmpPairPoint = tmpPair;
							}
			}else break;
		}else break;
		
		return tmpPairPoint;
	}
	 public static void main(String[] args) {
		 int n = 0;
		 Scanner sc = new Scanner(System.in);;
		 while(n <= 1){
		 System.out.println("请输入点的个数(必须大于1)");
		 n = sc.nextInt();
		 }
		PointSet testPoints = new PointSet(n);
		for(int i = 0 ; i < n ; i++){
			System.out.println("请输入点"+i+"横纵坐标:");
			double x= sc.nextDouble();
			double y = sc.nextDouble();
			testPoints.addPoint(new Point(x,y,i));
		}
		PairPoint resPair = DivCloset(testPoints);
		System.out.println("最近点对:  ("+resPair.getP1Num()+","+resPair.getP2Num()+"):  "+resPair.getDistance() );
	}
}
/*
 * 测试数据
11
  1 2
  9 4
  -23 22
  -24 21
  9 3
  34 23
  12 11
  0 0 
  1 5
  -2.3 -21
  1.2 12.3

 */
