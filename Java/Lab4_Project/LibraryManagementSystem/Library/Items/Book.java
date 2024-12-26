package LibraryManagementSystem.Library.Items;

import LibraryManagementSystem.Library.ItemsType;

public class Book extends LibraryItem {
    public Book(String bookTitle)
    {
        super(bookTitle, ItemsType.Book);
    }
}
