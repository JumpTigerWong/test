package lifegame;


public class LifeGame {
	/**
	* 
	*
	* @author 汪虎跃
	*/
	static Thread gameStart = new Thread();
	static int numofgener = 0;

	public static void main(String[] args) {
		LifeGameUI lg = new LifeGameUI();
		lg.creatUi();
		while (true) {
			if (LifeGameUI.running) {
				lg.init();
				nextGener();
				lg.reflush();
				try {
					Thread.sleep(120);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			} else {
				try {
					Thread.sleep(120);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}

	public static void nextGener() {//由于数量较多，选择测试全0和全1的情况
		for (int r = 0; r < 50; r++) {// row
			for (int c = 0; c < 50; c++) {// col
				if (r - 1 >= 0 && c - 1 >= 0 && LifeGameUI.table[r - 1][c - 1])
					{LifeGameUI.baseData[r][c]++;}
				if (r - 1 >= 0 && LifeGameUI.table[r - 1][c])
					{LifeGameUI.baseData[r][c]++;}
				if (r - 1 >= 0 && c + 1 < 50 && LifeGameUI.table[r - 1][c + 1])
					{LifeGameUI.baseData[r][c]++;}
				if (c - 1 >= 0 && LifeGameUI.table[r][c - 1])
					{LifeGameUI.baseData[r][c]++;}
				if (c + 1 < 50 && LifeGameUI.table[r][c + 1])
					{LifeGameUI.baseData[r][c]++;}
				if (r + 1 < 50 && LifeGameUI.table[r + 1][c])
					{LifeGameUI.baseData[r][c]++;}
				if (r + 1 < 50 && c + 1 < 50 && LifeGameUI.table[r + 1][c + 1])
					{LifeGameUI.baseData[r][c]++;}
				if (r + 1 < 50 && c - 1 >= 0 && LifeGameUI.table[r + 1][c - 1])
					{LifeGameUI.baseData[r][c]++;}
			}
		}
		numofgener++;
		LifeGameUI.jtf.setText("已生存" + numofgener + "代");
	}
}

