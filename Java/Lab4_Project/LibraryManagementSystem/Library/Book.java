package LibraryManagementSystem.Library;

public class Book extends LibraryItem {
    public final ItemsType ItemType = ItemsType.Book;
    public Book(int bookID, String bookTitle)
    {
        super(bookID, bookTitle);
    }
}
