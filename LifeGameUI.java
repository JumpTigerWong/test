package lifegame;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.*;

import javax.swing.*;
import javax.swing.border.Border;

public class LifeGameUI {
	public static JFrame lfgameui = new JFrame("生命游戏");
	static JButton[][] jb = new JButton[50][50];
	static boolean running = false;
	public static JPanel jp = new JPanel();
	public static boolean table[][] = new boolean[50][50];
	static int baseData[][] = new int[50][50];
	static JButton jb1 = new JButton("开始游戏");
	static JTextField jtf = new JTextField();
	// static JPanel [][]jp=new JPanel[50][50];
	
	static class Events implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			running = !running;
		}

	}

	static class ClickEvents implements ActionListener {
		public int row;
		public int col;

		ClickEvents(int row, int col) {
			this.row = row;
			this.col = col;
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			jb[row][col].setBackground(Color.red);
		}
	}

	public static void reflush() {//路径覆盖<2;>3;(table[i][j]=false)=3;=2(table[i][j]=true;)
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				if (baseData[i][j] < 2 || baseData[i][j] > 3) {
					jb[i][j].setBackground(Color.BLUE);
					baseData[i][j] = 0;
					table[i][j] = false;
				} else if (baseData[i][j] == 3) {
					jb[i][j].setBackground(Color.red);
					baseData[i][j] = 0;
					table[i][j] = true;
				} else {
					baseData[i][j] = 0;
				}
			}
		}
	}

	public static void init() {
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				if (jb[i][j].getBackground() == Color.RED) {
					table[i][j] = true;
				}else{
					table[i][j]=false;
				}//存在两种情况背景颜色为红，背景颜色为蓝。
			}
		}
	}

	public void creatUi() {
		lfgameui.setLayout(null);
		jp.setLayout(new GridLayout(50, 50));
		jp.setBounds(100, 10, 500, 500);
		jp.setVisible(true);
		lfgameui.setBounds(370, 200, 620, 550);//界面没有完全显示
		jb1.setBounds(10, 10, 80, 40);
		jb1.addActionListener(new Events());
		jtf.setBounds(10, 60, 80, 40);
		jtf.setText("已生存0代");
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				jb[i][j] = new JButton();
				Border originBorder = BorderFactory.createLineBorder(Color.LIGHT_GRAY, 1);
				jb[i][j].setBackground(Color.BLUE);
				// jb[i][j].setSize(10, 10);
				jb[i][j].setOpaque(true);
				// jb[i][j].setBorderPainted(false);
				jb[i][j].setBorder(originBorder);
				jb[i][j].addActionListener(new ClickEvents(i, j));
				jb[i][j].addMouseListener(new MouseListener() {
					@Override
					public void mouseClicked(MouseEvent e) {
					}

					@Override
					public void mousePressed(MouseEvent e) {
					}

					@Override
					public void mouseReleased(MouseEvent e) {
					}

					@Override
					public void mouseEntered(MouseEvent e) {
						if (e.getClickCount() > 0 && e.getComponent().getBackground() == Color.BLUE) {
							e.getComponent().setBackground(Color.RED);
						} else if (e.getClickCount() > 0 && e.getComponent().getBackground() == Color.RED) {
							e.getComponent().setBackground(Color.BLUE);
						}
					}

					@Override
					public void mouseExited(MouseEvent e) {
					}
				});
				jp.add(jb[i][j]);
			}
		}
		lfgameui.add(jp);
		lfgameui.add(jb1);
		lfgameui.setVisible(true);
		lfgameui.add(jtf);
		lfgameui.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				lfgameui.dispose();
			}
		});
	}
}
