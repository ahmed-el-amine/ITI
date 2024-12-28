package MyPackage;

import javax.swing.*;

public class MarqueeText extends JFrame implements Runnable {
    private String message;
    private JLabel label;
    private int xPos;
    private final int WINDOW_WIDTH = 400;
    private final int WINDOW_HEIGHT = 300;
    private final int SLEEP_TIME = 10;

    public MarqueeText(String text) {
        message = text;
        setTitle("My Marquee App");
        setLayout(null);

        this.setBounds(50, 50, WINDOW_WIDTH, WINDOW_HEIGHT);
        this.setVisible(true);

        this.xPos = this.getWidth();

        label = new JLabel(message);

        label.setBounds(xPos, 20, message.length() * 15, 40); // Approximate width based on text length
        add(label);

        Thread thread = new Thread(this);
        thread.start();
    }

    @Override
    public void run() {
        while (true) {
            // Update position
            xPos--;

            // Reset position when text moves out off screen to the left
            if (xPos < -(message.length() * 15)) {
                xPos = this.getWidth();
            }

            // Update label position
            label.setLocation(xPos, 125);

            try {
                Thread.sleep(SLEEP_TIME);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
