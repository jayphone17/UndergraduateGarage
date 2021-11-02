package domain;

import java.util.Date;
import  service.ModuleService;
import domain.Module;

public class Function {
    private Integer Fid;//主键
    private String Fname;//工呢名称
    private String Fdate;//创建时间
    private String Fudate;//更新时间
    private Integer moid;//所属模块，外键关联模块表
    private Integer fpriority;//优先级
    private String Fcontent;//功能描述
    private String fneed;//功能需求
    private String fversion;//需求版本号

    public Function(){}
    public Function(Integer fid, String fname, String fdate, String fudate, Integer moid, Integer fpriority, String fcontent, String fneed, String fversion) {
        Fid = fid;
        Fname = fname;
        Fdate = fdate;
        Fudate = fudate;
        this.moid = moid;
        this.fpriority = fpriority;
        Fcontent = fcontent;
        this.fneed = fneed;
        this.fversion = fversion;
    }

    public Integer getFid() {
        return Fid;
    }

    public void setFid(Integer fid) {
        Fid = fid;
    }

    public String getFname() {
        return Fname;
    }

    public void setFname(String fname) {
        Fname = fname;
    }

    public String getFdate() {
        return Fdate;
    }

    public void setFdate(String fdate) {
        Fdate = fdate;
    }

    public String getFudate() {
        return Fudate;
    }

    public void setFudate(String fudate) {
        Fudate = fudate;
    }

    public Integer getMoid() {
        return moid;
    }

    public void setMoid(Integer moid) {
        this.moid = moid;
    }

    public Integer getFpriority() {
        return fpriority;
    }

    public void setFpriority(Integer fpriority) {
        this.fpriority = fpriority;
    }

    public String getFcontent() {
        return Fcontent;
    }

    public void setFcontent(String fcontent) {
        Fcontent = fcontent;
    }

    public String getFneed() {
        return fneed;
    }

    public void setFneed(String fneed) {
        this.fneed = fneed;
    }

    public String getFversion() {
        return fversion;
    }

    public void setFversion(String fversion) {
        this.fversion = fversion;
    }
    //-----------------
    public String getModuleName(){
        return ModuleService.getModuleName(this.moid);
    }
    //--------------------
    public String getNeedName(){
        return ModuleService.getNeedName(this.moid);
    }
    public String getNeedNid(){
        return ModuleService.getNeedNid(this.moid);
    }
    public String getProjectName(){
        return ModuleService.getProjectName(this.moid);
    }
    public String getNeedContect(){
       return ModuleService.getNeedContent(this.moid);
    }
}