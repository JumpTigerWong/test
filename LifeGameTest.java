package lifegame;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class LifeGameTest {
	int expecteds[][] = new int[50][50];
	@Before
	public void setUp() throws Exception {
		for(int i=0;i<50;i++) {
			for(int j=0;j<50;j++) {
				LifeGameUI.baseData[i][j]=0;
			}
		}
	}

	@Test
	public void testNextGener() {
		//全0的情况
		for(int i=0;i<50;i++) {
			for(int j=0;j<50;j++) {
				LifeGameUI.table[i][j]=false;
			}
		}
		LifeGame.nextGener();
		for(int i=0;i<50;i++) {
			for(int j=0;j<50;j++) {
				expecteds[i][j]=0;
			}
		}
		org.junit.Assert.assertArrayEquals(expecteds, LifeGameUI.baseData);
		//全1情况
		for(int i=0;i<50;i++) {
			for(int j=0;j<50;j++) {
				LifeGameUI.table[i][j]=true;
			}
		}
		LifeGame.nextGener();
		expecteds[0][0]=3;
		expecteds[0][49]=3;
		expecteds[49][0]=3;
		expecteds[49][49]=3;
		for(int i=1;i<49;i++) {
			expecteds[0][i]=5;
			expecteds[i][0]=5;
			expecteds[49][i]=5;
			expecteds[i][49]=5;
		}
		for(int i=1;i<49;i++) {
			for(int j=1;j<49;j++) {
				expecteds[i][j]=8;
			}
		}
		org.junit.Assert.assertArrayEquals(expecteds, LifeGameUI.baseData);
		//fail("Not yet implemented");
	}

}
