package LibraryManagementSystem.Library.Client;
import LibraryManagementSystem.Library.LibraryEntity;

public abstract class Client extends LibraryEntity {
    private String name;
    private String email;

    public Client(String name, String email)
    {
        super();
        this.name = name;
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void getClientDetails()
    {
        System.err.println("ID:" + this.id + " Name:" + name + " Email" + email);
    }
}
