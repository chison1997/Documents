/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DATA;

import static DATA.CONGVIECDATA.ps;
import Object.DanhBa;
import java.sql.ResultSet;
import javax.swing.JOptionPane;


public class DANHBADATA {
     public static ResultSet showTextfield(String sql) {
        try {
            ps = CONNECT.getConnect().prepareStatement(sql);
            return ps.executeQuery();
        } catch (Exception e) {
            return null;
        }
        
    }
     public static void InsertContact(DanhBa ct) {
        String sql = "insert into CONTACT values(?,?,?,?)";
        try {
            ps = CONNECT.getConnect().prepareStatement(sql);
            ps.setString(1, ct.getName());
            ps.setString(2, ct.getPhonenumber());
            ps.setString(3, ct.getEmail());
            ps.setString(4, ct.getAddress());
            ps.execute();
            JOptionPane.showMessageDialog(null,  "Đã thêm thành công!" , "Thông báo", 1);
        } catch(Exception e) {
            JOptionPane.showMessageDialog(null, e.getMessage() , "Thông báo", 1);
        }
    } 
     public boolean UpdateContact(DanhBa ct) {
        try {
            ps = CONNECT.getConnect().prepareStatement("UPDATE CONTACT SET name = ?,phone= ?,email= ?,address= ? where MACT = ?");
            ps.setInt(5, ct.getMACT());
            ps.setString(1, ct.getName());
             ps.setString(2, ct.getPhonenumber());
            ps.setString(3, ct.getEmail());
             ps.setString(4, ct.getAddress());
            return ps.executeUpdate() >0;
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, e.getMessage() , "Thông báo", 1);
            return false;
        }
    }
      
    public boolean DeleteContact(int MACT) {
        try {
            ps = CONNECT.getConnect().prepareStatement("DELETE FROM CONTACT WHERE MACT = ?");
            ps.setInt(1, MACT);
            return ps.executeUpdate() >0;
        } catch(Exception e) {
            return false;
        }
    }
    
}
