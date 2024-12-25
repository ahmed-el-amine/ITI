package LibraryManagementSystem.Library;

public class Magazine extends LibraryItem {
    public final ItemsType ItemType = ItemsType.Magazine;
    public Magazine(int magazineID, String magazineTitle)
    {
        super(magazineID, magazineTitle);
    }
}
