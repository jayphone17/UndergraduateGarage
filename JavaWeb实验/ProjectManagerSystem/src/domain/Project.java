package domain;

public class Project {
    //sms_Project
    private Integer Pjtid;//主键
    private String Pjtname;//项目名称
    private Integer Cid;//客户名称外键关联客户表
    private Integer Usid;//项目经理，关联用户表
    private Integer Pjtdevelop;//开发人数
    private String Pjtsetdate;//立项时间
    private String Pjtupdate;//更新时间
    private Integer Pjtpriority;//优先级
    private Integer Pjtstate;//状态
    private Float Pjtmoney;//项目金额
    private String Pjtfinishdate;//完成日期
    private Float Pjtcost;//总成本
    private String Pjtplanstartdate;//计划开始时间
    private String Pjtplanfinishdate;//计划结束时间
    private String Pjtrealstartdate;//时间开始时间
    private String Pjtrealfinishdate;//实际结束时间
    private String Pjtcontent;//项目备注

    public Project(){}
    public Project(Integer pjtid, String pjtname, Integer cid, Integer usid, Integer pjtdevelop, String pjtsetdate, String pjtupdate, Integer pjtpriority, Integer pjtstate, Float pjtmoney, String pjtfinishdate, Float pjtcost, String pjtplanstartdate, String pjtplanfinishdate, String pjtrealstartdate, String pjtrealfinishdate, String pjtcontent) {
        Pjtid = pjtid;
        Pjtname = pjtname;
        Cid = cid;
        Usid = usid;
        Pjtdevelop = pjtdevelop;
        Pjtsetdate = pjtsetdate;
        Pjtupdate = pjtupdate;
        Pjtpriority = pjtpriority;
        Pjtstate = pjtstate;
        Pjtmoney = pjtmoney;
        Pjtfinishdate = pjtfinishdate;
        Pjtcost = pjtcost;
        Pjtplanstartdate = pjtplanstartdate;
        Pjtplanfinishdate = pjtplanfinishdate;
        Pjtrealstartdate = pjtrealstartdate;
        Pjtrealfinishdate = pjtrealfinishdate;
        Pjtcontent = pjtcontent;
    }

    public Integer getPjtid() {
        return Pjtid;
    }

    public String getPjtname() {
        return Pjtname;
    }

    public Integer getCid() {
        return Cid;
    }

    public Integer getUsid() {
        return Usid;
    }

    public Integer getPjtdevelop() {
        return Pjtdevelop;
    }

    public String getPjtsetdate() {
        return Pjtsetdate;
    }

    public String getPjtupdate() {
        return Pjtupdate;
    }

    public Integer getPjtpriority() {
        return Pjtpriority;
    }

    public Integer getPjtstate() {
        return Pjtstate;
    }

    public Float getPjtmoney() {
        return Pjtmoney;
    }

    public String getPjtfinishdate() {
        return Pjtfinishdate;
    }

    public Float getPjtcost() {
        return Pjtcost;
    }

    public String getPjtplanstartdate() {
        return Pjtplanstartdate;
    }

    public String getPjtplanfinishdate() {
        return Pjtplanfinishdate;
    }

    public String getPjtrealstartdate() {
        return Pjtrealstartdate;
    }

    public String getPjtrealfinishdate() {
        return Pjtrealfinishdate;
    }

    public String getPjtcontent() {
        return Pjtcontent;
    }

    public void setPjtid(Integer pjtid) {
        Pjtid = pjtid;
    }

    public void setPjtname(String pjtname) {
        Pjtname = pjtname;
    }

    public void setCid(Integer cid) {
        Cid = cid;
    }

    public void setUsid(Integer usid) {
        Usid = usid;
    }

    public void setPjtdevelop(Integer pjtdevelop) {
        Pjtdevelop = pjtdevelop;
    }

    public void setPjtsetdate(String pjtsetdate) {
        Pjtsetdate = pjtsetdate;
    }

    public void setPjtupdate(String pjtupdate) {
        Pjtupdate = pjtupdate;
    }

    public void setPjtpriority(Integer pjtpriority) {
        Pjtpriority = pjtpriority;
    }

    public void setPjtstate(Integer pjtstate) {
        Pjtstate = pjtstate;
    }

    public void setPjtmoney(Float pjtmoney) {
        Pjtmoney = pjtmoney;
    }

    public void setPjtfinishdate(String pjtfinishdate) {
        Pjtfinishdate = pjtfinishdate;
    }

    public void setPjtcost(Float pjtcost) {
        Pjtcost = pjtcost;
    }

    public void setPjtplanstartdate(String pjtplanstartdate) {
        Pjtplanstartdate = pjtplanstartdate;
    }

    public void setPjtplanfinishdate(String pjtplanfinishdate) {
        Pjtplanfinishdate = pjtplanfinishdate;
    }

    public void setPjtrealstartdate(String pjtrealstartdate) {
        Pjtrealstartdate = pjtrealstartdate;
    }

    public void setPjtrealfinishdate(String pjtrealfinishdate) {
        Pjtrealfinishdate = pjtrealfinishdate;
    }

    public void setPjtcontent(String pjtcontent) {
        Pjtcontent = pjtcontent;
    }
}
