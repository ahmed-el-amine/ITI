package LibraryManagementSystem.Client;

public abstract class Client {
    private int id;
    private int name;
    private int email;

    public void getClientDetails()
    {
        System.err.println("ID:" + this.id + " Name:" + name + " Email" + email);
    }
}
