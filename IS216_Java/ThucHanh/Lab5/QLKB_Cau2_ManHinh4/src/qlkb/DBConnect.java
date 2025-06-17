package qlkb;

import java.sql.Connection;
import java.sql.DriverManager;

public class DBConnect {
//    public static boolean connectToDatabase() {
//        Connection con = null;
//        String url = "jdbc:mysql://localhost:3306/QLKB?user=root&password=mySQLuser@@5&useUnicode=true&characterEncoding=utf8";
//        String driver = "com.mysql.cj.jdbc.Driver";
//
//        try {
//            Class.forName(driver);
//            con = DriverManager.getConnection(url);
//            System.out.println("Connected to the database");
//            return true;
//        } catch (Exception e) {
//            e.printStackTrace();
//            return false;
//        }
//    }
    
    public static Connection getConnection() throws Exception {
        String url = "jdbc:mysql://localhost:3306/QLKB?user=root&password=mySQLuser@@5&useUnicode=true&characterEncoding=utf8";
        String driver = "com.mysql.cj.jdbc.Driver";
        Class.forName(driver);
        return DriverManager.getConnection(url);
    }
}


