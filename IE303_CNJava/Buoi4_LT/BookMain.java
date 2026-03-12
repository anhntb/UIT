package Buoi4_LT;

import java.util.ArrayList;
import java.util.List;

public class BookMain {
    public static void main(String[] args) {
        // Tạo danh sách sách
        List<Book> books = new ArrayList<>();
        books.add(new Book("Clean Code", "Robert Martin", 450000.0));
        books.add(new Book("Java Basics"));
        books.add(new Book("Doraemon", "Fujiko Fujio", 30000.0));
        books.add(new Book("Clean Code", "Robert Martin", 450000.0));
        books.add(new Book());

        // In danh sách ban đầu
        System.out.println("==== DANH SACH SACH BAN DAU ====");
        for (Book book : books) {
            System.out.println(book);
        }

        // Cập nhật giảm giá
        books.get(0).applyDiscount(10); // Giảm 10%
        books.get(1).setPrice(50000.0); // Cập nhật giá
        books.get(2).applyDiscount(10); // Giảm 10%

        // In danh sách sau khi cập nhật
        System.out.println("\n==== SAU KHI CAP NHAT GIAM GIA ====");
        for (Book book : books) {
            System.out.println(book);
        }

        // Thống kê
        System.out.println("\n==== THONG KE ====");
        
        // Đếm sách có giá > 0
        int count = 0;
        for (Book book : books) {
            if (book.getPrice() > 0) {
                count++;
            }
        }
        System.out.println("So sach co gia > 0: " + count);

        // Tính tổng giá
        double totalPrice = 0;
        for (Book book : books) {
            totalPrice += book.getPrice();
        }
        System.out.println("Tong gia tat ca sach: " + totalPrice);

        // Tính giá trung bình
        double avgPrice = totalPrice / books.size();
        System.out.println("Gia trung binh: " + avgPrice);

        // Tìm sách có giá cao nhất
        Book maxPriceBook = books.get(0);
        for (Book book : books) {
            if (book.getPrice() > maxPriceBook.getPrice()) {
                maxPriceBook = book;
            }
        }
        System.out.println("Sach co gia cao nhat:");
        System.out.println(maxPriceBook);

        // Tìm các sách có giá lớn hơn giá trung bình
        System.out.println("\nCac sach co gia lon hon gia trung binh:");
        for (Book book : books) {
            if (book.getPrice() > avgPrice) {
                System.out.println(book);
            }
        }
    }
}
