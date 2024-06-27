package com.pintu.ui;

import javax.swing.*;
import javax.swing.border.BevelBorder;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;

public class GameJFrame extends JFrame implements KeyListener, ActionListener {


    int[][] data = new int[4][4];
    int x, y;
    String path = "../GamePintu/src/com/pintu/image/animal/animal3/";
    int[][] win = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};
    int step = 0;

    JMenuItem replayItem = new JMenuItem("重新游戏");
    JMenuItem reLoginItem = new JMenuItem("重新登录");
    JMenuItem closeItem = new JMenuItem("关闭游戏");

    JMenuItem accountItem = new JMenuItem("公众号");

    public GameJFrame() {
        initJFrame();

        // 初始化 menubar
        initJMenuBar();

        initData();

        initImage();

        this.setVisible(true);
    }


    private void initData() {
        int[] tmp = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

        Random r = new Random();
        for (int i = 0; i < tmp.length; i++) {
            int index = r.nextInt(tmp.length);

            int temp = tmp[i];
            tmp[i] = tmp[index];
            tmp[index] = temp;
        }

        for (int i = 0; i < tmp.length; i++) {
            if (tmp[i] == 0) {
                x = i / 4;
                y = i % 4;
            }
            data[i / 4][i % 4] = tmp[i];
        }
    }

    private void initImage() {
        this.getContentPane().removeAll();

        if (victory()) {
            JLabel winJLabel = new JLabel(new ImageIcon("../GamePintu/src/com/pintu/image/win.png"));
            winJLabel.setBounds(203, 283, 197, 73);
            this.getContentPane().add(winJLabel);
        }

        JLabel stepCount = new JLabel("步数  " + step);
        stepCount.setBounds(50, 30, 100, 20);
        this.getContentPane().add(stepCount);
 

        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 4; j ++) {
                int member = data[i][j];
                JLabel jLabel = new JLabel(new ImageIcon(path + member + ".jpg"));
                jLabel.setBounds(105 * j + 83, 105 * i + 134, 105, 105);
                jLabel.setBorder(new BevelBorder(BevelBorder.LOWERED));
                this.getContentPane().add(jLabel);
            }
        }

        JLabel background = new JLabel(new ImageIcon("../GamePintu/src/com/pintu/image/background.png"));
        background.setBounds(40, 40, 508, 560);
        this.getContentPane().add(background);

        this.getContentPane().repaint();
    }

    private void initJMenuBar() {
        JMenuBar jmenuBar = new JMenuBar();


        JMenu functionJmenu = new JMenu("功能");
        JMenu aboutJmenu = new JMenu("关于我们");


        //创建更换图片
        JMenu changeImage = new JMenu("更换图片");

        JMenuItem girl = new JMenuItem("美女");
        JMenuItem animal = new JMenuItem("动物");
        JMenuItem sport = new JMenuItem("运动");
        JMenuItem repalyItem = new JMenuItem("重新游戏");
        JMenuItem reLoginItem = new JMenuItem("重新登录");
        JMenuItem closeItem = new JMenuItem("关闭游戏");
        JMenuItem accountItem = new JMenuItem("公众号");



        changeImage.add(girl);
        changeImage.add(animal);
        changeImage.add(sport);



        functionJmenu.add(changeImage);
        functionJmenu.add(replayItem);
        functionJmenu.add(reLoginItem);
        functionJmenu.add(closeItem);

        aboutJmenu.add(accountItem);

        girl.addActionListener(this);
        animal.addActionListener(this);
        sport.addActionListener(this);
        
        replayItem.addActionListener(this);
        reLoginItem.addActionListener(this);
        closeItem.addActionListener(this);
        accountItem.addActionListener(this);

        jmenuBar.add(functionJmenu);
        jmenuBar.add(aboutJmenu);

        this.setJMenuBar(jmenuBar);

        

    }

    private void initJFrame() {
        this.setSize(603, 680);
        this.setTitle("拼图小游戏 1.0");
        this.setAlwaysOnTop(true); // zhi ding

        this.setLocationRelativeTo(null); // ju zhong
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        this.setLayout(null);
        this.addKeyListener(this);
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {
        int code = e.getKeyCode();
        if (code == 65) {
            this.getContentPane().removeAll();

            JLabel all = new JLabel(new ImageIcon(path + "all.jpg"));
            all.setBounds(83, 134, 420, 420);
            this.getContentPane().add(all);


            JLabel background = new JLabel(new ImageIcon("../GamePintu/src/com/pintu/image/background.png"));
            background.setBounds(40, 40, 508, 560);
            this.getContentPane().add(background);
            this.getContentPane().repaint();
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
        if (victory()) {
            return ;
        }


        int code = e.getKeyCode();
        if (code == 37) {
            System.out.println("向左移动");
            //逻辑：
            //把空白方块右方的数字往左移动
            if (y == 3) {

            } else {
                data[x][y] = data[x][y + 1];
                data[x][y + 1] = 0;
                y++;
                //调用方法按照最新的数字加载图片
                step ++;
                initImage();
            }

        } else if (code == 38) {
            System.out.println("向上移动");
            //逻辑：
            //把空白方块下方的数字往上移动
            //x，y  表示空白方块
            //x + 1， y 表示空白方块下方的数字
            //把空白方块下方的数字赋值给空白方块
            if (x == 3) {

            } else {
                data[x][y] = data[x + 1][y];
                data[x + 1][y] = 0;
                x++;
                //调用方法按照最新的数字加载图片
                step ++;
                initImage();
            }

        } else if (code == 39) {
            System.out.println("向右移动");
            //逻辑：
            //把空白方块左方的数字往右移动
            if (y == 0) {

            } else {
                data[x][y] = data[x][y - 1];
                data[x][y - 1] = 0;
                y--;
                //每移动一次，计数器就自增一次。
                step ++;
                initImage();
            }

        } else if (code == 40) {
            System.out.println("向下移动");
            //逻辑：
            //把空白方块上方的数字往下移动
            if (x == 0) {

            } else {
                data[x][y] = data[x - 1][y];
                data[x - 1][y] = 0;
                x--;
                //调用方法按照最新的数字加载图片
                step ++;
                initImage();
            }

        } else if (code == 65) {
            initImage();
        } else if (code == 87) {
            data = new int[][]{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};
            initImage();
        }
    }

    public boolean victory() {
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < data[i].length; j++) {
                if (data[i][j] != win[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Object obj = e.getSource();
        if (obj == reLoginItem) {

            this.setVisible(false);
            new LoginJFrame();
        } else if (obj == replayItem) {
            step = 0;
            initData();
            initImage();

        } else if (obj == closeItem) {
            System.exit(0);
        } else if (obj == accountItem) {
            JDialog jDialog = new JDialog();

            JLabel jLabel = new JLabel("游戏感觉还行", JLabel.CENTER);

            jDialog.getContentPane().add(jLabel);
            jDialog.setSize(344, 344);
            jDialog.setLocationRelativeTo(null);
            jDialog.setAlwaysOnTop(true);
            jDialog.setModal(true);
            jDialog.setVisible(true);
        } else if (obj == girl)
    }
}
