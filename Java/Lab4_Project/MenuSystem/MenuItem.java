package MenuSystem;

import java.util.UUID;

public class MenuItem {
    private final String ID = UUID.randomUUID().toString();
    private String itemText;
    private Runnable action = null;

    public MenuItem(String itemText)
    {
        this.itemText = itemText;
    }

    public MenuItem(String title, Runnable action)
    {
        this.itemText = title;
        this.action = action;
    }

    public String getItemText() {
        return itemText;
    }

    public String getID() {
        return ID;
    }

    public void startAction()
    {
        if (!this.hasAction()) return;
        this.action.run();
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
