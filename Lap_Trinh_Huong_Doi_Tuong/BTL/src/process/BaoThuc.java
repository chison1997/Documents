/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package process;

import DATA.CONNECT;
import java.sql.SQLException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Timer;
import java.util.TimerTask;
import static process.Tuan.ps;
import static process.Tuan.rs;


public class BaoThuc {
    
    Timer Timer = new Timer();
    TimerTask t;
   
    public boolean soSanhDateTime(java.sql.Date sqlDate0, java.sql.Time sqlTime0){
        java.util.Date current = new java.util.Date();
        int k = 0; 
        // so sánh ngày tháng năm (phải chuyển về string mới so đc
        DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
        String strSqlDate0 = dateFormat.format(sqlDate0);
        String strCurrent  = dateFormat.format(current);

        if(strSqlDate0.equals(strCurrent)){
            k++;
            System.out.println("-----Cùng ngày");
        } 

        // so sánh giờ phút
        DateFormat timeFormat = new SimpleDateFormat("HH:mm:ss");
        String strCurrentTime = timeFormat.format(current);
        String strTime        = timeFormat.format(sqlTime0);
        System.out.println("current:"+strCurrentTime);
        System.out.println("timeStart:"+strTime);
        if (strTime.equals(strCurrentTime)){
            k++;
            System.out.println("---------------------Cùng time");
        }
        return k==2;
    }
    public BaoThuc(){
        this.t = new TimerTask(){
            @Override
            public void run(){
                
                java.sql.Date sqlDate0;
                java.sql.Time sqlTime0;
                String sql = "select dateStart, timeStart from CONGVIEC where nhacnho = 1";
                try{
                    ps = CONNECT.getConnect().prepareStatement(sql);
                    rs=ps.executeQuery();
                    while(rs.next()){
                        sqlDate0 = rs.getDate(1);
                        sqlTime0= rs.getTime(2);
                    
                        boolean n = soSanhDateTime(sqlDate0, sqlTime0);
                        if (n){
                            ThongBao t = new ThongBao();
                            t.setVisible(true);
                            break;  
                        }
                                               
                    }
                }catch(SQLException e){
                    System.out.println("**********************"+e + " | "+e.getMessage());
                    //JOptionPane.showMessageDialog(null, e+"bao thuc ||", e.getMessage(), 0);
                }                               
            }
        };        
    }
    
       
    public void start(){
        Date date = new Date();
        
        Timer.scheduleAtFixedRate(t, date, 1000);
      //  Timer.scheduleAtFixedRate(t, date, 60000);
    }
    public static void main(String[] args) {
       
        BaoThuc baoThuc = new BaoThuc();
        baoThuc.start();
       
    }
}
