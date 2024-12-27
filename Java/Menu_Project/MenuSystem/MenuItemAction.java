package MenuSystem;

@FunctionalInterface
public interface MenuItemAction extends Runnable {

    public abstract void run();
    // void action();
}
