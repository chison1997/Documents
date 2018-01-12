
package DATA;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import javax.swing.JOptionPane;


public class CONNECT {
    private  static Connection con;
    
    public static Connection getConnect(){
        
        if(con != null ) return con;
        
        try {
           System.out.println( DriverManager.getLoginTimeout());
            DriverManager.setLoginTimeout(10);
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            con = DriverManager.getConnection("jdbc:sqlserver://localhost:1433;" +  
	         "databaseName=OOP;integratedSecurity=false", "sa", "123");
            
        } catch (Exception e) {
           
             JOptionPane.showMessageDialog(null, e.getMessage() ,"kết nối sql chưa thành công" , 1);
        }
        return con;
    }
    
    public static Connection getInstant()
            {
                if( con == null) con = CONNECT.getConnect();
                return con;
            }
    
    
    public static String testConnect() {
        try{
            con = CONNECT.getConnect();
            return "Kết nối thành công";
        }
        catch(Exception e) {
            return "Kết nối thất bại";
        }
    } 
}
