
package Object;

import java.sql.Time;
import java.sql.Date;


public class CongViec {
    private  int maCV;
    private  String congviec;
    private  String chitiet;
    private String trangthai;
    private Time timeStart;
    private Time timeEnd;
    private Date dateStart;
    private Date dateEnd;
    private String uutien;
    private boolean nhacnho;

    public String getCongviec() {
        return congviec;
    }

    public void setCongviec(String congviec) {
        this.congviec = congviec;
    }

    public String getChitiet() {
        return chitiet;
    }

    public void setChitiet(String chitiet) {
        this.chitiet = chitiet;
    }
   

    public CongViec(String congviec, String chitiet, String trangthai, Time timeStart, Time timeEnd, Date dateStart, Date dateEnd, String uutien, boolean nhacnho) {
        this.congviec = congviec;
        this.chitiet = chitiet;
        this.trangthai = trangthai;
        this.timeStart = timeStart;
        this.timeEnd = timeEnd;
        
        this.dateStart = dateStart;
        this.dateEnd = dateEnd;
        this.uutien = uutien;
        this.nhacnho = nhacnho;
    }

    public CongViec() {
    }

    

    public int getMaCV() {
        return maCV;
    }

    public void setMaCV(int maCV) {
        this.maCV = maCV;
    }

    public String getTrangthai() {
        return trangthai;
    }

    public void setTrangthai(String trangthai) {
        this.trangthai = trangthai;
    }

    
    public String getUutien() {
        return uutien;
    }

    public void setUutien(String uutien) {
        this.uutien = uutien;
    }

   

    public Time getTimeStart() {
        return timeStart;
    }

    public void setTimeStart(Time timeStart) {
        this.timeStart = timeStart;
    }

    public Time getTimeEnd() {
        return timeEnd;
    }

    public void setTimeEnd(Time timeEnd) {
        this.timeEnd = timeEnd;
    }

    public Date getDateStart() {
        return dateStart;
    }

    public void setDateStart(Date dateStart) {
        this.dateStart = dateStart;
    }

    public Date getDateEnd() {
        return dateEnd;
    }

    public void setDateEnd(Date dateEnd) {
        this.dateEnd = dateEnd;
    }


    public boolean isNhacnho() {
        return nhacnho;
    }

    public void setNhacnho(boolean nhacnho) {
        this.nhacnho = nhacnho;
    }

   
    
}
