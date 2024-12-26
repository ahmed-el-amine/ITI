import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class Main extends JFrame {
    public Main() {
        setTitle("Animation Ball Application");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        add(new BallPanel());
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            Main app = new Main();
            app.setBounds(50, 50, 600, 400);
            app.setVisible(true);
        });
    }
}

class BallPanel extends JPanel implements Runnable {
    private double ballX = 100;
    private double ballY = 100;
    private final int BALL_SIZE = 30;
    private double dx = 3;
    private double dy = 3;
    private Thread animationThread;
    private final int DELAY = 16;
    private Color ballColor;

    public BallPanel() {
        setBackground(Color.WHITE);
        // Create a gradient color for the ball
        ballColor = new Color(255, 0, 0);
        setPreferredSize(new Dimension(400, 400));

        // Start the animation thread
        animationThread = new Thread(this);
        animationThread.start();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;

        // Enable antialiasing for smoother rendering
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);

        // Create gradient paint for the ball
        GradientPaint gradient = new GradientPaint(
                (float) ballX, (float) ballY, ballColor,
                (float) (ballX + BALL_SIZE), (float) (ballY + BALL_SIZE),
                Color.ORANGE);
        g2d.setPaint(gradient);

        // Draw the ball
        g2d.fillOval((int) ballX, (int) ballY, BALL_SIZE, BALL_SIZE);

        // Add a shine effect
        g2d.setColor(new Color(255, 255, 255, 100));
        g2d.fillOval((int) (ballX + BALL_SIZE / 4),
                (int) (ballY + BALL_SIZE / 4),
                BALL_SIZE / 4, BALL_SIZE / 4);
    }

    private void moveBall() {
        // Update position
        ballX += dx;
        ballY += dy;

        // Check for collision with walls
        if (ballX <= 0) {
            ballX = 0;
            dx = Math.abs(dx); // Reverse direction
            changeDirection();
        } else if (ballX >= getWidth() - BALL_SIZE) {
            ballX = getWidth() - BALL_SIZE;
            dx = -Math.abs(dx); // Reverse direction
            changeDirection();
        }

        if (ballY <= 0) {
            ballY = 0;
            dy = Math.abs(dy); // Reverse direction
            changeDirection();
        } else if (ballY >= getHeight() - BALL_SIZE) {
            ballY = getHeight() - BALL_SIZE;
            dy = -Math.abs(dy); // Reverse direction
            changeDirection();
        }
    }

    private void changeDirection() {
        // Add some randomness to the direction when hitting walls
        Random rand = new Random();
        dx += (rand.nextDouble() - 0.5) * 0.5; // Small random adjustment
        dy += (rand.nextDouble() - 0.5) * 0.5;

        // Keep speed within reasonable bounds
        double speed = Math.sqrt(dx * dx + dy * dy);
        if (speed > 6) {
            dx = (dx / speed) * 6;
            dy = (dy / speed) * 6;
        } else if (speed < 2) {
            dx = (dx / speed) * 2;
            dy = (dy / speed) * 2;
        }
    }

    @Override
    public void run() {
        while (true) {
            try {
                moveBall();
                repaint();
                Thread.sleep(DELAY);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}