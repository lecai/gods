import java.util.Scanner;

/**
 * 项目名称:
 * 创建人: lecai
 * 创建时间: 14-5-25
 * 类描述:
 * 版本:
 */
public class Test {
    public static void main(String[] args){
        double num=0;
        Scanner s = new Scanner(System.in);
        System.out.println("请输入你需要计算的个数：");
        int n = s.nextInt();
        double[] list=new double[n];
        for (int i = 1; i <= n; i++) {
            System.out.println("请输入第"+i+"个数:");
            list[i-1]=s.nextDouble();
            num+=list[i-1];
        }
        double mean=num/n;
        double var=0;
        for(double d:list){
            var+=(d-mean)*(d-mean);
        }
        System.out.println("方差是:"+var/n);
    }
}
