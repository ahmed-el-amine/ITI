package LibraryManagementSystem.Library;

import java.util.UUID;

public abstract class LibraryEntity {
    protected String id = UUID.randomUUID().toString();
    
    public String getId() {
        return id;
    }
}
