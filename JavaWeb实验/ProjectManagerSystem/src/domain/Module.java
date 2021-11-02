package domain;

import service.ModuleService;
import service.NeedService;
import service.ProjectService;

import java.util.Date;

public class Module {
    private Integer Moid;//主键
    private  String Moname;//模块名称
    private String Monick;//(简称)标识
    private String Mocreatedate;//创建时间
    private String Moupdate;//更新时间
    private Integer Nid;//需求（外键关联需求表）
    private Integer Mopriority;//优先级别
    private String Mocontent;//模块描述
    private String Moneed;//模块需求
    public Module(){}
    public Module(Integer moid, String moname, String monick, String mocreatedate, String moupdate, Integer nid, Integer mopriority, String mocontent, String moneed) {
        Moid = moid;
        Moname = moname;
        Monick = monick;
        Mocreatedate = mocreatedate;
        Moupdate = moupdate;
        Nid = nid;
        Mopriority = mopriority;
        Mocontent = mocontent;
        Moneed = moneed;
    }

    public Integer getMoid() {
        return Moid;
    }

    public void setMoid(Integer moid) {
        Moid = moid;
    }

    public String getMoname() {
        return Moname;
    }

    public void setMoname(String moname) {
        Moname = moname;
    }

    public String getMonick() {
        return Monick;
    }

    public void setMonick(String monick) {
        Monick = monick;
    }

    public String getMocreatedate() {
        return Mocreatedate;
    }

    public void setMocreatedate(String mocreatedate) {
        Mocreatedate = mocreatedate;
    }

    public String getMoupdate() {
        return Moupdate;
    }

    public void setMoupdate(String moupdate) {
        Moupdate = moupdate;
    }

    public Integer getNid() {
        return Nid;
    }

    public void setNid(Integer nid) {
        Nid = nid;
    }

    public Integer getMopriority() {
        return Mopriority;
    }

    public void setMopriority(Integer mopriority) {
        Mopriority = mopriority;
    }

    public String getMocontent() {
        return Mocontent;
    }

    public void setMocontent(String mocontent) {
        Mocontent = mocontent;
    }

    public String getMoneed() {
        return Moneed;
    }

    public void setMoneed(String moneed) {
        Moneed = moneed;
    }
    public  String  getModuleName(){
        return this.Moname;
    }

    public String getNeedName(){
        return NeedService.getNeedName(this.Moid);
    }
    public String getProjectName(){
        return ModuleService.getProjectName(this.Moid);
    }
    public String getProjectId(){return  ModuleService.getProjectId(this.Moid);}
}
