package domain;

public class Need {
    //sms_need
    private Integer Nid;//主键
    private String Nname;//标题
    private Integer Pjtid;//所属项目
    private String Ncreatdate;//创建时间
    private String Nupdate;//更新时间
    private String Ncontent;//备注
    public Need(){}
    public Need(Integer nid, String nname, Integer pjtid, String ncreatdate, String nupdate, String ncontent) {
        Nid = nid;
        Nname = nname;
        Pjtid = pjtid;
        Ncreatdate = ncreatdate;
        Nupdate = nupdate;
        Ncontent = ncontent;
    }

    public Integer getNid() {
        return Nid;
    }

    public String getNname() {
        return Nname;
    }

    public Integer getPjtid() {
        return Pjtid;
    }

    public String getNcreatdate() {
        return Ncreatdate;
    }

    public String getNupdate() {
        return Nupdate;
    }

    public String getNcontent() {
        return Ncontent;
    }

    public void setNid(Integer nid) {
        Nid = nid;
    }

    public void setNname(String nname) {
        Nname = nname;
    }

    public void setPjtid(Integer pjtid) {
        Pjtid = pjtid;
    }

    public void setNcreatdate(String ncreatdate) {
        Ncreatdate = ncreatdate;
    }

    public void setNupdate(String nupdate) {
        Nupdate = nupdate;
    }

    public void setNcontent(String ncontent) {
        Ncontent = ncontent;
    }
}
