package lifegame;

import static org.junit.Assert.*;

import java.awt.Color;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.border.Border;

import org.junit.Before;
import org.junit.Test;

public class LifeGameUITest {
	void initButton(){
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				LifeGameUI.jb[i][j] = new JButton();
				Border originBorder = BorderFactory.createLineBorder(Color.LIGHT_GRAY, 1);
				LifeGameUI.jb[i][j].setBackground(Color.BLUE);
				}
			}
	}
	static boolean flag=false;
	boolean expecteds[][]=new boolean[50][50] ;
	void initf_t(boolean flag) {
		if(flag) {
			for(int i=0;i<50;i++) {
				 for(int j=0;j<50;j++) {
					 LifeGameUI.table[i][j]=true;
				 }
			 }
		}else {
			for(int i=0;i<50;i++) {
				 for(int j=0;j<50;j++) {
					 LifeGameUI.table[i][j]=false;
				 }
			 }
		}
	}
	void initArray(boolean a[][],boolean temp) {
		for(int i=0;i<50;i++) {
			for(int j=0;j<50;j++) {
				a[i][j]=temp;
			}
		}
	}
	@Before
	public void setUp() throws Exception {
		 initf_t(flag);
		 initButton();
	}

	@Test
	public void testReflush() {
		//第一种情况<2;>3;(table[i][j]=false)
		flag=true;
		try {
			setUp();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		for(int i=0;i<50;i++) {
			for(int j=0;j<50;j++) {
				LifeGameUI.baseData[i][j]=1;
			}
		}
		LifeGameUI.reflush();
		initArray(expecteds,false);
		org.junit.Assert.assertArrayEquals(expecteds, LifeGameUI.table);
		flag=true;
		try {
			setUp();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		for(int i=0;i<50;i++) {
			for(int j=0;j<50;j++) {
				LifeGameUI.baseData[i][j]=4;
			}
		}
		LifeGameUI.reflush();
		initArray(expecteds,false);
		org.junit.Assert.assertArrayEquals(expecteds, LifeGameUI.table);
		//第二种情况=3;=2(table[i][j]=true;)
		flag=false;
		try {
			setUp();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		for(int i=0;i<50;i++) {
			for(int j=0;j<50;j++) {
				LifeGameUI.baseData[i][j]=3;
			}
		}
		LifeGameUI.reflush();
		initArray(expecteds,true);
		org.junit.Assert.assertArrayEquals(expecteds, LifeGameUI.table);
		flag=false;
		try {
			setUp();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		for(int i=0;i<50;i++) {
			for(int j=0;j<50;j++) {
				LifeGameUI.baseData[i][j]=2;
			}
		}
		LifeGameUI.reflush();
		initArray(expecteds,false);//等于2值不变
		org.junit.Assert.assertArrayEquals(expecteds, LifeGameUI.table);
		//fail("Not yet implemented");
	}

	@Test
	public void testInit() {
		
		//第一种情况全是红色
		flag=false;
		try {
			setUp();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		for(int i=0;i<50;i++) {
			for(int j=0;j<50;j++) {
				LifeGameUI.jb[i][j].setBackground(Color.RED);
			}
		}
		LifeGameUI.init();
		initArray(expecteds,true);
		org.junit.Assert.assertArrayEquals(expecteds, LifeGameUI.table);
		flag=true;
		try {
			setUp();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		for(int i=0;i<50;i++) {
			for(int j=0;j<50;j++) {
				LifeGameUI.jb[i][j].setBackground(Color.BLUE);
			}
		}
		LifeGameUI.init();
		initArray(expecteds,false);//没有在LifeGameUI.init()中改变
		org.junit.Assert.assertArrayEquals(expecteds, LifeGameUI.table);
		//fail("Not yet implemented");
	}

}
