package LibraryManagementSystem.Library.Items;

import LibraryManagementSystem.Library.ItemsType;

public class Magazine extends LibraryItem {
    public Magazine(String magazineTitle)
    {
        super(magazineTitle, ItemsType.Magazine);
    }
}
