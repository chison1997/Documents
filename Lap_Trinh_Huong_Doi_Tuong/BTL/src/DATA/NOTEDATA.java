
package DATA;

import static DATA.CONGVIECDATA.ps;
import Object.Note;
import java.sql.ResultSet;
import javax.swing.JOptionPane;


public class NOTEDATA {
   public static ResultSet showTextfield(String sql) {
        try {
            ps = CONNECT.getConnect().prepareStatement(sql);
            return ps.executeQuery();
        } catch (Exception e) {
            return null;
        }
        
    }
     public static void InsertNOTE(Note n) {
        String sql = "insert into NOTE values(?)";
        try {
            ps = CONNECT.getConnect().prepareStatement(sql);
            ps.setString(1, n.getNoidung());
            ps.execute();
            JOptionPane.showMessageDialog(null, "Đã thêm thành công!" , "Thông báo", 1);
        } catch(Exception e) {
            JOptionPane.showMessageDialog(null, e.getMessage() , "Thông báo", 1);
            
        }
    } 
     public boolean UpdateNOTE(Note n) {
        try {
            ps = CONNECT.getConnect().prepareStatement("UPDATE NOTE SET noidung= ? where MAN = ?");
            ps.setInt(2, n.getMAN());
            ps.setString(1,n.getNoidung());
            System.out.println("UPDATE OK!");
            return ps.executeUpdate() >0;
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, e.getMessage() , "Thông báo", 1);
            return false;
        }
    }
      
    public boolean DeleteNOTE(int MAN) {
        try {
            ps = CONNECT.getConnect().prepareStatement("DELETE FROM NOTE WHERE MAN = ?");
            ps.setInt(1, MAN);
            return ps.executeUpdate() >0;
        } catch(Exception e) {
              JOptionPane.showMessageDialog(null, e.getMessage() , "Thông báo", 1);
            return false;
        }
    }
}
