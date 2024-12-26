package MyApp;

import java.util.Date;
import java.awt.BorderLayout; // Added missing import
import javax.swing.JFrame;
import javax.swing.JLabel;

public class DateTimeApp extends JFrame implements Runnable {
    Thread th;
    Date d = new Date();
    JLabel timeLabel = new JLabel();

    public DateTimeApp() {
        this.setTitle(d.toString());
        timeLabel.setHorizontalAlignment(JLabel.CENTER);
        timeLabel.setText(d.toString());
        this.add(timeLabel, BorderLayout.CENTER);

        th = new Thread(this);
        th.start();
    }

    public void run() {
        while (true) {
            d = new Date();
            this.setTitle(d.toString());
            timeLabel.setText(d.toString());
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        DateTimeApp app = new DateTimeApp();
        app.setBounds(50, 50, 600, 400);
        app.setVisible(true);
    }
}