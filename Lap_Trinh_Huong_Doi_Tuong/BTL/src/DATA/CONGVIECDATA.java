/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DATA;

import Object.CongViec;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import javax.swing.JOptionPane;

public class CONGVIECDATA {
    CongViec tn=new CongViec();
    public static PreparedStatement ps;
    public static ResultSet rs;
     public static ResultSet showTextfield(String sql) {
        try {
            ps = CONNECT.getConnect().prepareStatement(sql);
            return ps.executeQuery();
        } catch (Exception e) {
            return null;
        }
      }
   public static void InsertCONGVIEC(CongViec tn) {
        String sql = "insert into CONGVIEC values(?,?,?,?,?,?,?,?,?)";
        try {
            ps = CONNECT.getConnect().prepareStatement(sql);
           
            ps.setString(1, tn.getCongviec()); 
            ps.setString(2, tn.getChitiet());
            ps.setString(3, tn.getTrangthai());
            ps.setTime  (4, tn.getTimeStart());
            ps.setTime  (5, tn.getTimeEnd());
            ps.setDate  (6, (Date) tn.getDateStart());
            ps.setDate  (7, (Date) tn.getDateEnd());
            ps.setString(8, tn.getUutien());
            ps.setBoolean(9,tn.isNhacnho());
            ps.execute();
            
            JOptionPane.showMessageDialog(null, "Đã thêm công việc thành công!" , "Thông báo", 1);
        } catch(Exception e) {
            JOptionPane.showMessageDialog(null, e.getMessage() , "Thông báo", 1);
        }
    }
    public boolean UpdateCONGVIEC(CongViec tn) {
        try {
            ps = CONNECT.getConnect().prepareStatement("UPDATE CONGVIEC SET congviec= ?,chitiet= ?,trangthai= ?,timeStart= ?,timeEnd= ?,dateStart= ?,dateEnd = ?, uutien= ?, nhacnho= ? where MACV = ?");
            ps.setInt(10, tn.getMaCV());
            ps.setString(1, tn.getCongviec());
            ps.setString(2, tn.getChitiet());
            ps.setString(3, tn.getTrangthai());
            ps.setTime(4, tn.getTimeStart());
            ps.setTime(5, tn.getTimeEnd());
            ps.setDate(6, (Date) tn.getDateStart());
            ps.setDate(7, (Date) tn.getDateEnd());
            ps.setString(8, tn.getUutien());
            
            ps.setBoolean(9, tn.isNhacnho());
            JOptionPane.showMessageDialog(null, "Sửa thành công!" , "Thông báo", 1);
            return ps.executeUpdate() >0;
            
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Sửa thất bại!" , "Thông báo", 1);
            return false;
        }
    }
    public boolean DeleteCONGVIEC(String MACV) {
        try {
            ps = CONNECT.getConnect().prepareStatement("DELETE FROM CONGVIEC WHERE MACV = ?");
            ps.setString(1, MACV);
            return ps.executeUpdate() >0;
        } catch(Exception e) {
            return false;
        }
    } 
    
}
