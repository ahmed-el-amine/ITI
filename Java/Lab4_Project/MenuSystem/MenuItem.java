package MenuSystem;

import java.util.UUID;

public class MenuItem {
    private final String ID = UUID.randomUUID().toString();
    private String title;
    private Runnable action = null;

    public MenuItem(String title)
    {
        this.title = title;
    }

    public MenuItem(String title, Runnable action)
    {
        this.title = title;
        this.action = action;
    }

    public String getTitle() {
        return title;
    }

    public String getID() {
        return ID;
    }

    public void startAction()
    {
        if (this.action != null) {
            this.action.run();
        }
    }

    public void setAction(Runnable action)
    {
        this.action = action;
    }

    public Runnable getAction() {
        return action;
    }

    public boolean hasAction()
    {
        return this.action != null;
    }
    
}
